/* GlobalServ functions.
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
#include "modules/nickserv/nickserv.h"
#include "modules/operserv/operserv.h"
#include <sys/stat.h>

/*************************************************************************/

static Module *module_nickserv;

static char *s_GlobalServ;
static char *desc_GlobalServ;

char * LogChannel;
char * CanalKicks;
char * CanalOpers;
char * CanalAdmins;

static int cb_command   = -1;
static int cb_help      = -1;

static void do_help(User *u);
static void do_global(User *u);
static void do_global_nick(User *u);

static Command cmds[] = {
    {"HELP",      do_help,        NULL,             -1,                  -1,-1},
    {"GLOBAL",    do_global,      NULL,             OPER_HELP_GLOBAL,    -1,-1},
    {"NICK",      do_global_nick, NULL,             GLOBAL_HELP_NICK,       -1,-1},
    /* Fencepost: */
    { NULL }
};

/*************************************************************************/
/*************************** GlobalServ routine ****************************/
/*************************************************************************/

/* Main Ddberv routine. */

static int globalserv(const char *source, const char *target, char *buf)
{
    char *cmd;
    const char *s;
    User *u = get_user(source);

    if (irc_stricmp(target, s_GlobalServ) != 0)
        return 0;

    if (!u) {
        module_log("user record for %s not found", source);
        notice(s_GlobalServ, source,
                getstring(NULL, INTERNAL_ERROR));
        return 1;
    }

    if (!is_oper(u)) {
        notice_lang(s_GlobalServ, u, ACCESS_DENIED);
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
        notice(s_GlobalServ, source, "\1PING %s", s);
    } else {
        if (call_callback_2(cb_command, u, cmd) <= 0)
            run_cmd(s_GlobalServ, u, THIS_MODULE, cmd);
    }

    return 1;
}

/*************************************************************************/

static void do_logchan(const char *source, const char *fmt, ...)
{

    va_list args;
    char buf[BUFSIZE];

    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    send_cmd(source ? source : s_GlobalServ, "PRIVMSG %s :%s", LogChannel, buf);
}

/*************************************************************************/
static void do_canalkicks(const char *source, const char *fmt, ...)
{

    va_list args;
    char buf[BUFSIZE];

    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    send_cmd(source ? source : s_GlobalServ, "PRIVMSG %s :%s", CanalKicks, buf);
}

/*************************************************************************/
static void do_canalopers(const char *source, const char *fmt, ...)
{

    va_list args;
    char buf[BUFSIZE];

    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    send_cmd(source ? source : s_GlobalServ, "PRIVMSG %s :%s", CanalOpers, buf);
}

/*************************************************************************/
static void do_canaladmins(const char *source, const char *fmt, ...)
{

    va_list args;
    char buf[BUFSIZE];

    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    send_cmd(source ? source : s_GlobalServ, "PRIVMSG %s :%s", CanalAdmins, buf);
}

/*************************************************************************/
/**************************** Event callbacks ****************************/
/*************************************************************************/

/* Handler for introducing nicks. */

static int do_introduce(const char *nick)
{
    if (!nick || irc_stricmp(nick, s_GlobalServ) == 0) {
        send_pseudo_nick(s_GlobalServ, desc_GlobalServ, PSEUDO_OPER|PSEUDO_BOT);
        if (nick)
            return 1;
    }
    return 0;
}

/*************************************************************************/


/* Handler for WHOIS's. */

static int do_whois(const char *source, char *who, char *extra)
{
    if (irc_stricmp(who, s_GlobalServ) == 0) {
        send_cmd(ServerName, "311 %s %s %s %s * :%s", source, who,
                 ServiceUser, ServiceHost, desc_GlobalServ);
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

/*************************************************************************/

/* Callback for NickServ REGISTER/LINK check; we disallow
 * registration/linking of the HelpServ pseudoclient nickname.
 */

static int do_reglink_check(const User *u, const char *nick,
                            const char *pass, const char *email)
{
    return irc_stricmp(nick, s_GlobalServ) == 0;
}

/*************************************************************************/
/***************************** Module stuff ******************************/
/*************************************************************************/

ConfigDirective module_config[] = {
    { "GlobalServName",     { { CD_STRING, CF_DIRREQ, &s_GlobalServ },
                            { CD_STRING, 0, &desc_GlobalServ } } },
    { "LogChannel",       { { CD_STRING, CF_DIRREQ, &LogChannel } } },
    { "CanalKicks",       { { CD_STRING, CF_DIRREQ, &CanalKicks } } },
    { "CanalOpers",       { { CD_STRING, CF_DIRREQ, &CanalOpers } } },
    { "CanalAdmins",       { { CD_STRING, CF_DIRREQ, &CanalAdmins } } },


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
    static char old_s_GlobalServ[NICKMAX];
    static char *old_desc_GlobalServ = NULL;

    if (!after_configure) {
        /* Before reconfiguration: save old values. */
        free(old_desc_GlobalServ);
        strbcpy(old_s_GlobalServ, s_GlobalServ);
        old_desc_GlobalServ = strdup(desc_GlobalServ);
    } else {
        /* After reconfiguration: handle value changes. */
        if (strcmp(old_s_GlobalServ, s_GlobalServ) != 0)
            send_nickchange(old_s_GlobalServ, s_GlobalServ);
        if (!old_desc_GlobalServ || strcmp(old_desc_GlobalServ,desc_GlobalServ) != 0)
            send_namechange(s_GlobalServ, desc_GlobalServ);
        free(old_desc_GlobalServ);
        old_desc_GlobalServ = NULL;
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
     || !add_callback(NULL, "m_privmsg", globalserv)
     || !add_callback(NULL, "m_whois", do_whois)
    ) {
        module_log("Unable to register callbacks");
        exit_module(0);
        return 0;
    }

    Module *tmpmod = find_module("nickserv/main");
    if (tmpmod)
        do_load_module(tmpmod, "nickserv/main");

    logchan            = do_logchan;
    canalkicks         = do_canalkicks;
    canalopers         = do_canalopers;
    canaladmins        = do_canaladmins;

    if (linked)
        do_introduce(NULL);

    return 1;
}

/*************************************************************************/

static void do_help(User *u)
{
    char *cmd = strtok_remaining();

    if (!cmd) {
	notice_help(s_GlobalServ, u, HELP_CABECERA, s_GlobalServ, NetworkName, "", "");
        notice_help(s_GlobalServ, u, GLOBAL_HELP);
	notice_help(s_GlobalServ, u, HELP_FOOTER, s_GlobalServ);
    } else {
        help_cmd(s_GlobalServ, u, THIS_MODULE, cmd);
    }
}

/*************************************************************************/

static void do_global(User *u)
{
    char *msg = strtok_remaining();

    if (!msg) {
        syntax_error(s_GlobalServ, u, "GLOBAL", OPER_GLOBAL_SYNTAX);
        return;
    }
    notice_all(s_GlobalServ, "%s", msg);
    privmsg_all(s_GlobalServ, "%s", msg);

}

/*************************************************************************/

static void do_global_nick(User *u)
{
    char *nick = strtok(NULL, " ");
    char *msg = strtok_remaining();
    User *target_user;

    if (!msg) {
        syntax_error(s_GlobalServ, u, "NICK", GLOBAL_NICK_SYNTAX);
        return;
    }
    if (!(target_user = get_user(nick))) {
        send_pseudo_nick(nick, nick, PSEUDO_OPER);
        notice_all(nick, "%s", msg);
        privmsg_all(nick, "%s", msg);
        send_cmd(nick, "QUIT :");
    } else {
        privmsg(s_OperServ, u->nick, "El nick que especificaste se encuentra en uso, utiliza otro.");
    }
}

/*************************************************************************/

int exit_module(int shutdown_unused)
{
    if (linked)
        send_cmd(s_GlobalServ, "QUIT :");

    if (module_nickserv)
        do_unload_module(module_nickserv);

    remove_callback(NULL, "m_whois", do_whois);
    remove_callback(NULL, "m_privmsg", globalserv);
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
