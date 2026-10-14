/* AdminServ functions.
 *
 * IRC Services is copyright (c) 1996-2009 Andrew Church.
 *     E-mail: <achurch@achurch.org>
 * Parts written by Andrew Kempe and others.
 * This program is free but copyrighted software; see the file GPL.txt for
 * details.
 */

#include "services.h"
#include "modules.h"
#include "databases.h"
#include "conffile.h"
#include "language.h"
#include "commands.h"
#include "adminserv.h"
#include "modules/nickserv/nickserv.h"
#include "modules/operserv/operserv.h"
#include <sys/stat.h>

/* Maximum depth for SERVERMAP command */
#define MAXMAPLEVEL     64

/*************************************************************************/

static Module *module_nickserv;

    char *s_AdminServ;
static char *desc_AdminServ;

static int    WallBadOS;

static int cb_command   = -1;
static int cb_help      = -1;

static void do_help(User *u);
static void do_servermap(User *u);
static void do_admin(User *u);
static void do_oper(User *u);
static void do_update(User *u);
static void do_svsmode(User *u);
static void do_restart(User *u);
static void do_shutdown(User *u);
static void do_settime(User *u);

static Command cmds[] = {
    {"HELP",      do_help,      is_services_admin,             -1,                  -1,-1},
    {"SERVERMAP", do_servermap, is_services_admin,  OPER_HELP_SERVERMAP, -1,-1},
    {"ADMIN",     do_admin,     is_services_admin,   OPER_HELP_ADMIN,     -1,-1},
    {"OPER",      do_oper,      is_services_admin,  OPER_HELP_OPER,      -1,-1},
    {"UMODE",     do_svsmode,   is_services_admin,  -1,    -1,-1},
    {"UPDATE",    do_update,    is_services_admin,  OPER_HELP_UPDATE,    -1,-1},
    {"RESTART",   do_restart,   is_services_admin,  OPER_HELP_RESTART,   -1,-1},
    {"SHUTDOWN",  do_shutdown,  is_services_root,   OPER_HELP_RESTART,   -1,-1},
    {"SETTIME",   do_settime,   is_services_admin,  OPER_HELP_RESTART,   -1,-1},
    /* Fencepost: */
    { NULL }
};


/*************************************************************************/
/*************************** NickServ imports ****************************/
/*************************************************************************/

/* This is somewhat inefficient, but since these aren't called often they
 * should do for the time being.
 */

#define get_nickinfo local_get_nickinfo
#define put_nickinfo local_put_nickinfo
#define _get_ngi local__get_ngi
#define put_nickgroupinfo local_put_nickgroupinfo
#define first_nickgroupinfo local_first_nickgroupinfo
#define next_nickgroupinfo local_next_nickgroupinfo

static NickInfo *local_get_nickinfo(const char *nick)
{
    typeof(get_nickinfo) *p_get_nickinfo;

    if (!module_nickserv)
        return NULL;
    p_get_nickinfo = get_module_symbol(module_nickserv, "get_nickinfo");
    if (!p_get_nickinfo)
        return NULL;
    return p_get_nickinfo(nick);
}

static NickInfo *local_put_nickinfo(NickInfo *ni)
{
    typeof(put_nickinfo) *p_put_nickinfo;

    if (!module_nickserv)
        return NULL;
    p_put_nickinfo = get_module_symbol(module_nickserv, "put_nickinfo");
    if (!p_put_nickinfo)
        return NULL;
    return p_put_nickinfo(ni);
}

static NickGroupInfo *local__get_ngi(const NickInfo *ni, const char *file,
                                     int line)
{
    typeof(_get_ngi) *p__get_ngi;

    if (!module_nickserv)
        return NULL;
    if (!check_module_symbol(module_nickserv, "_get_ngi",
                             (void **)&p__get_ngi, NULL)) {
        module_log("Unable to find symbol `_get_ngi' in module"
                   " `nickserv/main' (called from %s:%d)", file, line);
        return NULL;
    }
    return p__get_ngi(ni, file, line);
}

static NickGroupInfo *local_put_nickgroupinfo(NickGroupInfo *ngi)
{
    typeof(put_nickgroupinfo) *p_put_nickgroupinfo;

    if (!module_nickserv)
        return NULL;
    p_put_nickgroupinfo =
        get_module_symbol(module_nickserv, "put_nickgroupinfo");
    if (!p_put_nickgroupinfo)
        return NULL;
    return p_put_nickgroupinfo(ngi);
}

static NickGroupInfo *local_first_nickgroupinfo(void)
{
    typeof(first_nickgroupinfo) *p_first_nickgroupinfo;

    if (!module_nickserv)
        return NULL;
    p_first_nickgroupinfo =
        get_module_symbol(module_nickserv, "first_nickgroupinfo");
    if (!p_first_nickgroupinfo)
        return NULL;
    return p_first_nickgroupinfo();
}

static NickGroupInfo *local_next_nickgroupinfo(void)
{
    typeof(next_nickgroupinfo) *p_next_nickgroupinfo;

    if (!module_nickserv)
        return NULL;
    p_next_nickgroupinfo =
        get_module_symbol(module_nickserv, "next_nickgroupinfo");
    if (!p_next_nickgroupinfo)
        return NULL;
    return p_next_nickgroupinfo();
}

/*************************************************************************/
/*************************** AdminpServ routine ****************************/
/*************************************************************************/

/* Main AdminServ routine. */

static int adminserv(const char *source, const char *target, char *buf)
{
    char *cmd;
    const char *s;
    User *u = get_user(source);

    if (irc_stricmp(target, s_AdminServ) != 0)
        return 0;

    if (!u) {
        module_log("user record for %s not found", source);
        notice(s_AdminServ, source,
                getstring(NULL, INTERNAL_ERROR));
        return 1;
    }

    if (!is_oper(u)) {
        notice_lang(s_AdminServ, u, ACCESS_DENIED);
        if (WallBadOS)
            wallops(s_AdminServ, "Denied access to %s from %s (non-oper)",
                    s_AdminServ, source);
        module_log("Non-oper %s!%s@%s sent: %s",
                   u->nick, u->username, u->host, buf);
        return 1;
    }

    cmd = strtok(buf, " ");
    if (!cmd) {
        return 1;
    } else if (stricmp(cmd, "\1PING") == 0) {
        if (!(s = strtok_remaining()))
            s = "\1";
        notice(s_AdminServ, source, "\1PING %s", s);
    } else {
        if (call_callback_2(cb_command, u, cmd) <= 0)
            run_cmd(s_AdminServ, u, THIS_MODULE, cmd);
    }

    return 1;
}

/*************************************************************************/
/**************************** Event callbacks ****************************/
/*************************************************************************/

/* Handler for introducing nicks. */

static int do_introduce(const char *nick)
{
    if (!nick || irc_stricmp(nick, s_AdminServ) == 0) {
        send_pseudo_nick(s_AdminServ, desc_AdminServ, PSEUDO_INVIS|PSEUDO_BOT|PSEUDO_DEAF);
        if (nick)
            return 1;
    }
    return 0;
}

/*************************************************************************/


/* Handler for WHOIS's. */

static int do_whois(const char *source, char *who, char *extra)
{
    if (irc_stricmp(who, s_AdminServ) == 0) {
        send_cmd(ServerName, "311 %s %s %s %s * :%s", source, who,
                 ServiceUser, ServiceHost, desc_AdminServ);
        send_cmd(ServerName, "312 %s %s %s :%s", source, who,
                 ServerName, ServerDesc);
        send_cmd(ServerName, "317 %s %s 0 :%ld seconds idle, signon time",
                 source, who, start_time);
        send_cmd(ServerName, "318 %s %s End of /WHOIS response.", source, who);
        return 1;
    } else {
        return 0;
    }
}

#define LIST_ADMIN      0
#define LIST_OPER       1

#define MSG_EXISTS      0
#define MSG_EXISTS_NEXT 1
#define MSG_ADDED       2
#define MSG_TOOMANY     3
#define MSG_REMOVED     4
#define MSG_NOTFOUND    5

static int privlist_msgs[2][6] = {
    { OPER_ADMIN_EXISTS,
      0,
      OPER_ADMIN_ADDED,
      OPER_ADMIN_TOO_MANY,
      OPER_ADMIN_REMOVED,
      OPER_ADMIN_NOT_FOUND,
    },
    { OPER_OPER_EXISTS,
      OPER_ADMIN_EXISTS,
      OPER_OPER_ADDED,
      OPER_OPER_TOO_MANY,
      OPER_OPER_REMOVED,
      OPER_OPER_NOT_FOUND,
    },
};

static void privlist_add(User *u, int listid, char *nick)
{
    int16 level = (listid==LIST_ADMIN ? NP_SERVADMIN : NP_SERVOPER);
    int16 nextlevel = (listid==LIST_ADMIN ? 0 : NP_SERVADMIN);
    int *msgs = privlist_msgs[listid];
    NickInfo *ni;
    NickGroupInfo *ngi;
    char buf[BUFSIZE];

    if (!(ni = get_nickinfo(nick))) {
        notice_lang(s_AdminServ, u, NICK_X_NOT_REGISTERED, nick);
        return;
    }
    ngi = get_ngi(ni);
    put_nickinfo(ni);
    if (!ngi) {
        notice_lang(s_AdminServ, u, INTERNAL_ERROR);
        return;
    }
    if (nextlevel && ngi->os_priv >= nextlevel) {
        notice_lang(s_AdminServ, u, msgs[MSG_EXISTS_NEXT], nick);
        put_nickgroupinfo(ngi);
        return;
    } else if (ngi->os_priv >= level) {
        notice_lang(s_AdminServ, u, msgs[MSG_EXISTS], nick);
        put_nickgroupinfo(ngi);
        return;
    }
    ngi->os_priv = level;
    put_nickgroupinfo(ngi);
    if (listid >= 1) {
	bdd_privadd(nick, 2);
	snprintf(buf, sizeof(buf), "%s.oper.%s", strlower(nick), strlower(NetworkDomain));
    } else {
	bdd_privadd(nick, 6);
	snprintf(buf, sizeof(buf), "%s.admin.%s", strlower(nick), strlower(NetworkDomain));
    }
    bdd_addvhost(nick, buf);
    notice_lang(s_AdminServ, u, msgs[MSG_ADDED], nick);
    if (readonly)
        notice_lang(s_AdminServ, u, READ_ONLY_MODE);
}

static void privlist_rem(User *u, int listid, char *nick)
{
    int16 level = (listid==LIST_ADMIN ? NP_SERVADMIN : NP_SERVOPER);
    int16 nextlevel = (listid==LIST_ADMIN ? 0 : NP_SERVADMIN);
    int *msgs = privlist_msgs[listid];
    NickInfo *ni;
    NickGroupInfo *ngi;

    if (!(ni = get_nickinfo(nick))) {
        notice_lang(s_AdminServ, u, NICK_X_NOT_REGISTERED, nick);
        return;
    }
    ngi = get_ngi(ni);
    put_nickinfo(ni);
    if (!ngi) {
        notice_lang(s_AdminServ, u, INTERNAL_ERROR);
        return;
    }
    if (ngi->os_priv < level || (nextlevel && ngi->os_priv >= nextlevel)) {
        notice_lang(s_AdminServ, u, msgs[MSG_NOTFOUND], nick);
        put_nickgroupinfo(ngi);
        return;
    }
    ngi->os_priv = 0;
    put_nickgroupinfo(ngi);
    notice_lang(s_AdminServ, u, msgs[MSG_REMOVED], nick);
    bdd_privrem(nick);
    bdd_delvhost(nick);
    if (readonly)
        notice_lang(s_AdminServ, u, READ_ONLY_MODE);
}

/*************************************************************************/

/* Callback for NickServ REGISTER/LINK check; we disallow
 * registration/linking of the HelpServ pseudoclient nickname.
 */

static int do_reglink_check(const User *u, const char *nick,
                            const char *pass, const char *email)
{
    return irc_stricmp(nick, s_AdminServ) == 0;
}

/*************************************************************************/
/***************************** Module stuff ******************************/
/*************************************************************************/

ConfigDirective module_config[] = {
    { "AdminServName",     { { CD_STRING, CF_DIRREQ, &s_AdminServ },
                            { CD_STRING, 0, &desc_AdminServ } } },
    { "WallBadOS",        { { CD_SET, 0, &WallBadOS } } },
    { NULL }
};

/*************************************************************************/

static int do_load_module(Module *mod, const char *modname)
{
    if (strcmp(modname, "nickserv/main") == 0) {
        module_nickserv = mod;
        if (!add_callback(mod, "REGISTER/LINK check", do_reglink_check))
            module_log("Unable to register NickServ REGISTER/LINK check"
                       " callback");
    }

    return 0;
}

/*************************************************************************/

static int do_unload_module(Module *mod)
{
    if (mod == module_nickserv) {
        remove_callback(module_nickserv, "REGISTER/LINK check",
                        do_reglink_check);
        module_nickserv = NULL;
    }
    return 0;
}

/*************************************************************************/

static int do_reconfigure(int after_configure)
{
    static char old_s_AdminServ[NICKMAX];
    static char *old_desc_AdminServ = NULL;

    if (!after_configure) {
        /* Before reconfiguration: save old values. */
        free(old_desc_AdminServ);
        strbcpy(old_s_AdminServ, s_AdminServ);
        old_desc_AdminServ = strdup(desc_AdminServ);
    } else {
        /* After reconfiguration: handle value changes. */
        if (strcmp(old_s_AdminServ, s_AdminServ) != 0)
            send_nickchange(old_s_AdminServ, s_AdminServ);
        if (!old_desc_AdminServ || strcmp(old_desc_AdminServ,desc_AdminServ) != 0)
            send_namechange(s_AdminServ, desc_AdminServ);
        free(old_desc_AdminServ);
        old_desc_AdminServ = NULL;
    }  /* if (!after_configure) */
    return 0;
}

/*************************************************************************/

int init_module(void)
{

    if (!new_commandlist(THIS_MODULE)
     || !register_commands(THIS_MODULE, cmds)
    ) {
        module_log("Unable to register commands");
        exit_module(0);
        return 0;
    }

    cb_command   = register_callback("command");
    cb_help      = register_callback("HELP");
    if (cb_command < 0 || cb_help < 0) {
	module_log("Unable to register callbacks");
        exit_module(0);
        return 0;
    }

    if (!add_callback(NULL, "load module", do_load_module)
     || !add_callback(NULL, "unload module", do_unload_module)
     || !add_callback(NULL, "reconfigure", do_reconfigure)
     || !add_callback(NULL, "introduce_user", do_introduce)
     || !add_callback(NULL, "m_privmsg", adminserv)
     || !add_callback(NULL, "m_whois", do_whois)
    ) {
        module_log("Unable to register callbacks");
        exit_module(0);
        return 0;
    }

    Module *tmpmod = find_module("nickserv/main");
    if (tmpmod)
        do_load_module(tmpmod, "nickserv/main");

    if (linked)
        do_introduce(NULL);

    return 1;
}


static void do_help(User *u)
{
    char *cmd = strtok_remaining();

    if (!cmd) {
	notice_help(s_AdminServ, u, HELP_CABECERA, s_AdminServ, NetworkName, "", "");
        notice_help(s_AdminServ, u, ADMIN_HELP);
	notice_help(s_AdminServ, u, OPER_HELP_COMMANDS_SESSION);
	 if (is_services_root(u)) {
		notice_help(s_AdminServ, u, ADMIN_ROOT_HELP);
	}
	notice_help(s_AdminServ, u, HELP_FOOTER, s_AdminServ);
    } else {
        help_cmd(s_AdminServ, u, THIS_MODULE, cmd);
    }

}

/*************************************************************************/

/* Server map display. */

static void map_server(User *u, Server *s, int level);  /* defined below */

static void do_servermap(User *u)
{
    Server *root = get_server("");
    if (!root) {
        module_log("BUG: root server not found for SERVERMAP");
        notice_lang(s_AdminServ, u, INTERNAL_ERROR);
        return;
    }
    map_server(u, root, 0);
}


/* Recursively print the server map.  This routine prints the given server
 * at level `level' of indentation (0 = left margin), then prints its
 * children in child->sibling->sibling... order.
 */

static void map_server(User *u, Server *s, int level)
{
    static const char indentstr[] = "  +-- ";
    static const char barstr[]    = "  |   ";
    static const char nobarstr[]  = "      ";
    /* Which levels need a continuation bar?  Note that this must be static
     * so that all values are available acr*/
    static int need_bar[MAXMAPLEVEL];

    char buf[BUFSIZE], *ptr;
    int i;

    ptr = buf;
    *ptr = 0;
    for (i = 0; i < level-1; i++) {
        ptr += snprintf(ptr, sizeof(buf)-(ptr-buf), "%s",
                        need_bar[i] ? barstr : nobarstr);
    }
    if (level)
        ptr += snprintf(ptr, sizeof(buf)-(ptr-buf), "%s", indentstr);
    privmsg(s_AdminServ, u->nick, "%s%s%s", buf,
           s ? (*s->name ? s->name : ServerName) : "...",
           (s && s->fake) ? "(*)" : "");
    if (s && s->child) {
        if (level+1 >= MAXMAPLEVEL) {
            /* Nesting too deep--use a NULL server parameter to display a
             * "..." indicating more servers */
            map_server(u, NULL, level+1);
            return;
        }
        for (s = s->child; s; s = s->sibling) {
            need_bar[level] = (s->sibling != NULL);
            map_server(u, s, level+1);
        }
    }
}

/*************************************************************************/

static void do_admin(User *u)
{
    const char *cmd;
    char *nick;

    if (!module_nickserv) {
        notice_lang(s_AdminServ, u, OPER_ADMIN_NO_NICKSERV);
        return;
    }
    cmd = strtok(NULL, " ");
    if (!cmd)
        cmd = "";

    if (stricmp(cmd, "ADD") == 0) {
        if (!is_services_admin(u)) {
            notice_lang(s_AdminServ, u, PERMISSION_DENIED);
            return;
        }
        nick = strtok(NULL, " ");
        if (nick)
            privlist_add(u, LIST_ADMIN, nick);
  else 
         syntax_error(s_AdminServ, u, "ADMIN", OPER_ADMIN_ADD_SYNTAX);

    } else if (stricmp(cmd, "DEL") == 0) {
        if (!is_services_admin(u)) {
            notice_lang(s_AdminServ, u, PERMISSION_DENIED);
            return;
        }
        nick = strtok(NULL, " ");
        if (nick)
            privlist_rem(u, LIST_ADMIN, nick);
        else
            syntax_error(s_AdminServ, u, "ADMIN", OPER_ADMIN_DEL_SYNTAX);

    } else if (stricmp(cmd, "LIST") == 0) {
        NickGroupInfo *ngi;
        notice_lang(s_AdminServ, u, OPER_ADMIN_LIST_HEADER);
        for (ngi = first_nickgroupinfo(); ngi; ngi = next_nickgroupinfo()) {
            if (ngi->os_priv >= NP_SERVADMIN)
                privmsg(s_AdminServ, u->nick, "%s", ngi_mainnick(ngi));
        }

    } else {
        syntax_error(s_AdminServ, u, "ADMIN", OPER_ADMIN_SYNTAX);
    }
}

/*************************************************************************/

static void do_oper(User *u)
{
    const char *cmd;
    char *nick;

    if (!module_nickserv) {
        notice_lang(s_AdminServ, u, OPER_OPER_NO_NICKSERV);
        return;
    }
    cmd = strtok(NULL, " ");
    if (!cmd)
        cmd = "";

    if (stricmp(cmd, "ADD") == 0) {
        if (!is_services_admin(u)) {
            notice_lang(s_AdminServ, u, PERMISSION_DENIED);
            return;
        }
        nick = strtok(NULL, " ");
        if (nick)
            privlist_add(u, LIST_OPER, nick);
        else
            syntax_error(s_AdminServ, u, "OPER", OPER_OPER_ADD_SYNTAX);

    } else if (stricmp(cmd, "DEL") == 0) {
        if (!is_services_admin(u)) {
            notice_lang(s_AdminServ, u, PERMISSION_DENIED);
            return;
        }
        nick = strtok(NULL, " ");
        if (nick)
            privlist_rem(u, LIST_OPER, nick);
        else
            syntax_error(s_AdminServ, u, "OPER", OPER_OPER_DEL_SYNTAX);

    } else if (stricmp(cmd, "LIST") == 0) {
        NickGroupInfo *ngi;
        notice_lang(s_AdminServ, u, OPER_OPER_LIST_HEADER);
        for (ngi = first_nickgroupinfo(); ngi; ngi = next_nickgroupinfo()) {
            if (ngi->os_priv >= NP_SERVOPER && ngi->os_priv < NP_SERVADMIN)
                privmsg(s_AdminServ, u->nick, "%s", ngi_mainnick(ngi));
        }

    } else {
        syntax_error(s_AdminServ, u, "OPER", OPER_OPER_SYNTAX);
    }
}

/*************************************************************************/

/* Callback and data used to send "update complete" message */
static int do_update_complete(int successful);
static User *update_sender = NULL;

static void do_update(User *u)
{
    char *param = strtok_remaining();

    if (param && *param) {
        if (stricmp(param, "FORCE") != 0) {
            syntax_error(s_AdminServ, u, "UPDATE", OPER_UPDATE_SYNTAX);
            return;
        } else if (!is_services_admin(u)) {
            notice_lang(s_AdminServ, u, PERMISSION_DENIED);
            return;
        }
        switch (is_data_locked()) {
          case 1:
            if (!unlock_data()) {
                module_log_perror("UPDATE FORCE lock removal failed");
                notice_lang(s_AdminServ, u, OPER_UPDATE_FORCE_FAILED);
                return;
            }
            break;
          case -1:
            module_log_perror("UPDATE FORCE lock check failed");
            break;
        }
    }
    notice_lang(s_AdminServ, u, OPER_UPDATING);
    save_data = 1;
    update_sender = u;  /* to send to when the update completes--it's safe
                         * to save this pointer since no more data will be
                         * processed before we use it again */
    add_callback(NULL, "save data complete", do_update_complete);
}

static int do_update_complete(int successful)
{
    if (update_sender) {
        if (successful)
            notice_lang(s_AdminServ, update_sender, OPER_UPDATE_COMPLETE);
        else
            notice_lang(s_AdminServ, update_sender, OPER_UPDATE_FAILED);
        update_sender = NULL;
    } else {
        log("BUG: no sender in do_update_complete()");
    }
    remove_callback(NULL, "save data complete", do_update_complete);
    return 0;
}

/*************************************************************************/

static void do_restart(User *u)
{
    snprintf(quitmsg, sizeof(quitmsg),
             "RESTART command received from %s", u->nick);
    save_data = 1;
    delayed_quit = 1;
    restart = 1;
}

/*************************************************************************/

static void do_svsmode(User *u)
{
    char *nick, *modos;
    User *target_user;
    nick = strtok(NULL, " ");
    modos = strtok(NULL, " ");

    if (!modos) {
        privmsg(s_AdminServ,u->nick, "\2Sintaxis:\2 \00312UMODE usuario +/-modos\003");
        return;
    }

   if (!(target_user = get_user(nick))) {
        notice_lang(s_AdminServ, u, NICK_X_NOT_IN_USE, nick);
        return;
   }

   if ((strchr(modos, 'r') || strchr(modos, 'h'))) {
	privmsg(s_AdminServ,u->nick, "No puedes fijar ni remover los modos \00312r\003 y \00312h\003");
	return;
   }

   if (EnableDebug)
logchan(NULL, "\2ADMINSERV\2 \00312%s\003 utiliza UMODE sobre \00312%s\003 modos: \00312%s\003", u->nick, nick, modos);
   canalopers(NULL, "\2ADMINSERV\2 \00312%s\003 utiliza UMODE sobre \00312%s\003 modos: \00312%s\003", u->nick, nick, modos);
   privmsg(s_AdminServ,u->nick, "Los nuevos modos de \2%s\2 son \00312%s\003", nick, modos);
   send_cmd(NULL, "SVSMODE %s %s", nick, modos);
}
/*************************************************************************/

static void do_shutdown(User *u)
{
    snprintf(quitmsg, sizeof(quitmsg),
            "SHUTDOWN command received from %s", u->nick);
    save_data = 1;
    delayed_quit = 1;
}

/*************************************************************************/

static void do_settime(User *u)
{
    time_t now = time(NULL);
    send_cmd(NULL, "SETTIME %lu", now);
    privmsg(s_AdminServ, u->nick, "SETTIME enviado a toda la red.");
}

/*************************************************************************/

int exit_module(int shutdown_unused)
{
    if (linked)
        send_cmd(s_AdminServ, "QUIT :");

    if (module_nickserv)
        do_unload_module(module_nickserv);

    remove_callback(NULL, "m_whois", do_whois);
    remove_callback(NULL, "m_privmsg", adminserv);
    remove_callback(NULL, "introduce_user", do_introduce);
    remove_callback(NULL, "reconfigure", do_reconfigure);
    remove_callback(NULL, "unload module", do_unload_module);
    remove_callback(NULL, "load module", do_load_module);

    unregister_callback(cb_help);
    unregister_callback(cb_command);

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
