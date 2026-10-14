/* Exceptions module.
 * Based on code copyright (c) 1999-2000 Andrew Kempe (TheShadow)
 *     E-mail: <andrewk@isdial.net>
 *
 * IRC Services is copyright (c) 1996-2009 Andrew Church.
 *     E-mail: <achurch@achurch.org>
 * Parts written by Andrew Kempe and others.
 * This program is free but copyrighted software; see the file GPL.txt for
 * details.
 */

#include "services.h"
#include "modules.h"
#include "conffile.h"
#include "commands.h"
#include "databases.h"
#include "language.h"

#include "adminserv.h"
#include "modules/operserv/operserv.h"
#include "modules/operserv/maskdata.h"
#include "modules/operserv/akill.h"

/*************************************************************************/

static Module *module_adminserv;
static Module *module_operserv;
static Module *module_akill;

/* create_kill() imported from operserv/akill */
static void (*p_create_akill)(char *mask, const char *reason, const char *who,
                              time_t expiry);

static int WallOSEline;
static time_t ElineExpiry;
static int    WallElineExpire;
static void do_eline(User *u);

static Command cmds[] = {
    {"ELINE",   do_eline,   is_services_admin, OPER_HELP_EXCLUDE,   -1,-1},
    {NULL}
};

/*************************************************************************/
/************************ Manipulacion de Elines *************************/
/*************************************************************************/

static void do_eline_add(User *u);
static void do_eline_del(User *u);
static void do_eline_clear(User *u);
static void do_eline_list(User *u, int is_view);
static int eline_del_callback(int num, va_list args);
static int eline_list(User *u, MaskData *except, int *count, int skip,
                          int is_view);
static int eline_list_callback(int num, va_list args);

static void do_eline(User *u)
{
    const char *cmd = strtok(NULL, " ");

    if (!cmd)
        cmd = "";

    if (stricmp(cmd, "ADD") == 0) {
        do_eline_add(u);
    } else if (stricmp(cmd, "DEL") == 0) {
        do_eline_del(u);
    } else if (stricmp(cmd, "CLEAR") == 0) {
        do_eline_clear(u);
    } else if (stricmp(cmd, "LIST") == 0 || stricmp(cmd, "VIEW") == 0) {
        do_eline_list(u, stricmp(cmd,"VIEW")==0);
    } else if (stricmp(cmd, "COUNT") == 0) {
        int count = maskdata_count(MD_ELINE);
        if (count)
            notice_lang(s_AdminServ, u, OPER_EXCLUDE_COUNT, count);
        else
            notice_lang(s_AdminServ, u, ADMIN_ELINE_EMPTY);
    } else {
        syntax_error(s_AdminServ, u, "ELINE", OPER_MASKDATA_SYNTAX);
    }
}

/*************************************************************************/

static void do_eline_add(User *u)
{
    char *mask, *reason, *expiry;
    char *user, *host;
    time_t expires;
    int i;
    MaskData *except;
    time_t now = time(NULL);

    if (maskdata_count(MD_ELINE) >= MAX_MASKDATA) {
        notice_lang(s_AdminServ, u, OPER_TOO_MANY_EXCLUDES);
        return;
    }

    mask = strtok(NULL, " ");
    if (mask && *mask == '+') {
        expiry = mask+1;
        mask = strtok(NULL, " ");
    } else {
        expiry = NULL;
    }
    reason = strtok_remaining();

    if (!mask || !reason) {
        syntax_error(s_AdminServ, u, "ELINE", OPER_MASKDATA_ADD_SYNTAX);
        return;
    }

    expires = expiry ? dotime(expiry) : ElineExpiry;
    if (expires < 0) {
        notice_lang(s_AdminServ, u, BAD_EXPIRY_TIME);
        return;
    } else if (expires > 0) {
        expires += now;
    }

    if (!(host = strchr(mask, '@'))) {
	user = "*";
	host = mask;
    } else {
	user = mask;
	*(host++) = '\0';
    }

    if (!(isValidIpAddress(host))) {
	notice_lang(s_AdminServ, u, BAD_USERHOST_MASK);
	return;
    }

    char buf[BUFSIZE];
    snprintf(buf, sizeof(buf), "%s@%s", user, host);
    if (put_maskdata(get_maskdata(MD_ELINE, strlower(buf)))) {
        notice_lang(s_AdminServ, u, OPER_EXCLUDE_EXISTS, buf);
    } else {
        /* Get highest maskdata number */
        i = 0;
        for (except = first_maskdata(MD_ELINE); except;
             except = next_maskdata(MD_ELINE)
        ) {
            if (except->num > i)  /* should be in order, but let's be safe */
                i = except->num;
        }
        /* Add exception with next number */
        except = scalloc(1, sizeof(*except));
        except->mask = sstrdup(buf);
        except->reason = sstrdup(reason);
        except->time = now;
        strbcpy(except->who, u->nick);
        except->expires = expires;
        except->num = i+1;
        add_maskdata(MD_ELINE, except);
        bdd_eline_add(user,host);
        notice_lang(s_AdminServ, u, OPER_EXCLUDE_ADDED, buf);
        if (readonly)
            notice_lang(s_AdminServ, u, READ_ONLY_MODE);
    }
}

/*************************************************************************/

static void do_eline_del(User *u)
{
    char *mask;
    char *host;
    MaskData *except;
    int deleted = 0;

    mask = strtok(NULL, " ");
    if (!mask) {
        syntax_error(s_AdminServ, u, "ELINE", OPER_MASKDATA_DEL_SYNTAX);
        return;
    }
    if (isdigit(*mask) && strspn(mask, "1234567890,-") == strlen(mask)) {
        int count, last = -1;
        deleted = process_numlist(mask, &count, eline_del_callback, &last);
        if (deleted == 0) {
            if (count == 1) {
                notice_lang(s_AdminServ, u, OPER_EXCLUDE_CHECK_NO_MATCH, last);
            } else {
                notice_lang(s_AdminServ, u, OPER_EXCLUDE_LIST_NO_MATCH);
            }
        } else if (deleted == 1) {
            notice_lang(s_AdminServ, u, ADMIN_ELINE_DELETED_ONE);
        } else {
            notice_lang(s_AdminServ, u, ADMIN_ELINE_DELETED_SEVERAL,
                        deleted);
        }
    } else {
        for (except = first_maskdata(MD_ELINE); except;
             except = next_maskdata(MD_ELINE)
        ) {
            if (stricmp(mask, except->mask) == 0) {
		if (!(host = strchr(mask, '@'))) {
			host = mask;
		} else {
			*(host++) = '\0';
		}
		bdd_eline_del(host);
                del_maskdata(MD_ELINE, except);
                notice_lang(s_AdminServ, u, OPER_EXCEPTION_DELETED, mask);
                deleted = 1;
                break;
            }
        }
        if (deleted == 0)
            notice_lang(s_AdminServ, u, OPER_EXCLUDE_NOT_FOUND, mask);
    }
    if (deleted && readonly)
        notice_lang(s_AdminServ, u, READ_ONLY_MODE);

}


static int eline_del_callback(int num, va_list args)
{
    MaskData *except;
    int *last = va_arg(args, int *);

    *last = num;
    if ((except = get_eline_by_num(num)) != NULL) {
        del_maskdata(MD_ELINE, except);
        return 1;
    } else {
        return 0;
    }
}

/*************************************************************************/

static void do_eline_clear(User *u)
{
    char *mask, *host;
    MaskData *except;

    mask = strtok(NULL, " ");
    if (!mask || stricmp(mask,"ALL") != 0) {
        syntax_error(s_AdminServ, u, "ELINE", OPER_MASKDATA_CLEAR_SYNTAX);
        return;
    }
    for (except = first_maskdata(MD_ELINE); except;
         except = next_maskdata(MD_ELINE)
    ) {
	if (!(host = strchr(mask, '@'))) {
		host = mask;
	} else {
		*(host++) = '\0';
	}
        bdd_eline_del(host);
        del_maskdata(MD_ELINE, except);
    }
    notice_lang(s_AdminServ, u, OPER_EXCLUDE_CLEARED);
    if (readonly)
        notice_lang(s_AdminServ, u, READ_ONLY_MODE);
}

/*************************************************************************/

static void do_eline_list(User *u, int is_view)
{
    char *mask = strtok(NULL, " ");
    char *s;
    MaskData *except;
    int count = 0, skip = 0;
    int noexpire = 0;


    if (mask && *mask == '+') {
        skip = (int)atolsafe(mask+1, 0, INT_MAX);
        if (skip < 0) {
            syntax_error(s_AdminServ, u, "ELINE",
                         OPER_MASKDATA_LIST_SYNTAX);
            return;
        }
        mask = strtok(NULL, " ");
    }

    if (mask)
        strlower(mask);

    if ((s = strtok(NULL," ")) != NULL && stricmp(s,"NOEXPIRE") == 0)
        noexpire = 1;

    if (mask && strspn(mask, "1234567890,-") == strlen(mask)) {
        if (skip) {
            syntax_error(s_AdminServ, u, "ELINE",
                         OPER_MASKDATA_LIST_SYNTAX);
            return;
        }
        process_numlist(mask, NULL, eline_list_callback, u,
                        &count, skip, noexpire, is_view);
    } else {
        for (except = first_maskdata(MD_ELINE); except;
             except = next_maskdata(MD_ELINE)
        ) {
            if ((!mask || match_wild(mask, except->mask))
             && (!noexpire || !except->expires))
                eline_list(u, except, &count, skip, is_view);
        }
    }
    if (!count)
        notice_lang(s_AdminServ, u,
                    mask ? ADMIN_ELINE_NO_MATCH : ADMIN_ELINE_EMPTY);
}


static int eline_list(User *u, MaskData *except, int *count, int skip,
                          int is_view)
{
    if (!*count) {
        notice_lang(s_AdminServ, u, ADMIN_ELINE_LIST_HEADER);
        if (!is_view)
            notice_lang(s_AdminServ, u, ADMIN_ELINE_LIST_COLHEAD);
    }
    (*count)++;
    if (*count > skip && *count <= skip+ListMax) {
        if (is_view) {
            char timebuf[BUFSIZE], expirebuf[BUFSIZE];
            strftime_lang(timebuf, sizeof(timebuf), u->ngi,
                          STRFTIME_SHORT_DATE_FORMAT, except->time);
            expires_in_lang(expirebuf, sizeof(expirebuf), u->ngi,
                            except->expires);
	    notice_lang(s_AdminServ, u, ADMIN_ELINE_VIEW_FORMAT,
                        except->num, except->mask,
			*except->who ? except->who : "<desconocido>",
			timebuf, expirebuf, except->reason);
        } else { /* list */
            notice_lang(s_AdminServ, u, ADMIN_ELINE_LIST_FORMAT,
                        except->num, except->mask);
        }
    }
    return 1;
}


static int eline_list_callback(int num, va_list args)
{
    User *u = va_arg(args, User *);
    int *count = va_arg(args, int *);
    int skip = va_arg(args, int);
    int noexpire = va_arg(args, int);
    int is_view = va_arg(args, int);
    MaskData *except;
    int retval = 0;

    if ((except = get_eline_by_num(num)) != NULL) {
        if (!noexpire || !except->expires)
            retval = eline_list(u, except, count, skip, is_view);
        put_maskdata(except);
    }
    return retval;
}

/*************************************************************************/


/*************************************************************************/
/*************************** Callback routines ***************************/
/*************************************************************************/

/*************************************************************************/

/* Callback for exception expiration. */

static int do_expire_maskdata(uint32 type, MaskData *md)
{
    if (type == MD_ELINE) {
	char *host;
        if (WallElineExpire)
            wallops(s_AdminServ, "E-line para %s ha expirado",
                    md->mask);
	if (!(host = strchr(md->mask, '@'))) {
		host = md->mask;
	} else {
		*(host++) = '\0';
	}
	bdd_eline_del(host);
    }
    return 0;
}

/*************************************************************************/

/* Callback for OperServ STATS ALL command. */

static int do_stats_all(User *u)
{
    int32 count, mem;
    MaskData *md;

    count = mem = 0;
    for (md = first_maskdata(MD_ELINE); md;
         md = next_maskdata(MD_ELINE)
    ) {
        count++;
        mem += sizeof(*md);
        if (md->mask)
            mem += strlen(md->mask)+1;
        if (md->reason)
            mem += strlen(md->reason)+1;
    }
    notice_lang(s_OperServ, u, OPER_STATS_ALL_ELINE_MEM,
                count, (mem+512) / 1024);

    return 0;
}

/*************************************************************************/
/**************************** Database stuff *****************************/
/*************************************************************************/

static void insert_eline(void *md) {
    MaskData *except;
    int num = 0;
    for (except = first_maskdata(MD_ELINE); except;
         except = next_maskdata(MD_ELINE)
    ) {
        if (except->num > num)  /* should be in order, but let's be safe */
            num = except->num;
    }
    ((MaskData *)md)->num = num+1;
    add_maskdata(MD_ELINE, md);
}
static void *first_eline(void)
    { return first_maskdata(MD_ELINE); }
static void *next_eline(void)
    { return next_maskdata(MD_ELINE); }

static DBField eline_dbfields[] = {
    { "mask",     DBTYPE_STRING, offsetof(MaskData,mask) },
    { "reason",   DBTYPE_STRING, offsetof(MaskData,reason) },
    { "who",      DBTYPE_BUFFER, offsetof(MaskData,who), NICKMAX },
    { "time",     DBTYPE_TIME,   offsetof(MaskData,time) },
    { "expires",  DBTYPE_TIME,   offsetof(MaskData,expires) },
    { "lastused", DBTYPE_TIME,   offsetof(MaskData,lastused) },
    { NULL }
};
static DBTable eline_dbtable = {
    .name    = "eline",
    .newrec  = new_maskdata,
    .freerec = free_maskdata,
    .insert  = insert_eline,
    .first   = first_eline,
    .next    = next_eline,
    .fields  = eline_dbfields,
};

/*************************************************************************/
/***************************** Module stuff ******************************/
/*************************************************************************/

ConfigDirective module_config[] = {
    { "ElineExpiry",  { { CD_TIME, 0, &ElineExpiry } } },
    { "WallExceptionElineepire",{{CD_SET, 0, &WallElineExpire } } },
    { "WallOSEline",  { { CD_SET, 0, &WallOSEline } } },
    { NULL }
};

/*************************************************************************/

static int do_load_module(Module *mod, const char *name)
{
    if (strcmp(name, "operserv/akill") == 0) {
        p_create_akill = get_module_symbol(mod, "create_akill");
        if (p_create_akill)
            module_akill = mod;
        else
            module_log("Symbol `create_akill' not found, automatic autokill"
                       " addition will not be available");
    }
    return 0;
}

/*************************************************************************/

static int do_unload_module(Module *mod)
{
    if (mod == module_akill) {
        p_create_akill = NULL;
        module_akill = NULL;
    }
    return 0;
}

/*************************************************************************/

int init_module()
{
    module_operserv = find_module("operserv/main");
    if (!module_operserv) {
        module_log("Main OperServ module not loaded");
        return 0;
    }
    use_module(module_operserv);

    module_adminserv = find_module("adminserv/main");
    if (!module_adminserv) {
        module_log("Main AdminServ module not loaded");
        return 0;
    }
    use_module(module_adminserv);

    if (!register_commands(module_adminserv, cmds)) {
        module_log("Unable to register commands");
        exit_module(0);
        return 0;
    }

    /* Add user check callback at priority -10 so it runs after all the
     * autokill/S-line/whatever checks (otherwise we get users added to
     * sessions and then killed by S-lines, leaving the session count
     * jacked up).
     */
    if (!add_callback(NULL, "load module", do_load_module)
     || !add_callback(NULL, "unload module", do_unload_module)
     || !add_callback(module_operserv, "expire maskdata", do_expire_maskdata)
     || !add_callback(module_operserv, "STATS ALL", do_stats_all)
    ) {
        module_log("Unable to add callbacks");
        exit_module(0);
        return 0;
    }

    module_akill = find_module("operserv/akill");
    if (module_akill)
        do_load_module(module_akill, "operserv/akill");

    if (!register_dbtable(&eline_dbtable)) {
        module_log("Unable to register database table");
        exit_module(0);
        return 0;
    }

    return 1;
}

/*************************************************************************/

int exit_module(int shutdown_unused)
{

    unregister_dbtable(&eline_dbtable);

    if (module_akill)
        do_unload_module(module_akill);

    remove_callback(NULL, "unload module", do_unload_module);
    remove_callback(NULL, "load module", do_load_module);

    if (module_adminserv) {
        remove_callback(module_operserv, "STATS ALL", do_stats_all);
        remove_callback(module_adminserv, "expire maskdata",do_expire_maskdata);
        unregister_commands(module_adminserv, cmds);
        unuse_module(module_adminserv);
        module_adminserv = NULL;
    }

    return 1;
}

/*************************************************************************/

/*
 * Local variables:
 *   c-file-style: "stroustrup"
 *   c-file-offsets: ((case-label . *) (statement-case-intro . *))
 *   indent-tabs-mode: nil
 * End:
 *
 * vim: expandtab shiftwidth=4:
 */
