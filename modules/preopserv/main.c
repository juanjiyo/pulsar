/* PreopServ functions.
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

static char *s_PreopServ;
static char *desc_PreopServ;

static int    WallBadOS;

static int cb_command   = -1;
static int cb_help      = -1;

static void do_help(User *u);
static void do_os_op(User *u);
static void do_os_deop(User *u);
static void do_os_invite(User *u);
static void do_set_bot(User *u);
static void do_set_unbot(User *u);

static Command cmds[] = {
    {"HELP",      do_help,       NULL,             -1,                  -1,-1},
    {"BOT", do_set_bot,  is_services_root, -1,-1,-1},
    {"UNBOT", do_set_unbot,  is_services_root, -1,-1,-1},
    {"OP",        do_os_op,     is_services_oper, -1,      -1,-1},
    {"DEOP",      do_os_deop,   is_services_oper, -1,      -1,-1},
    {"INVITE",    do_os_invite, is_services_oper, -1,      -1,-1},

    /* Fencepost: */
    { NULL }
};

/*************************************************************************/
/*************************** PreopServ routine ****************************/
/*************************************************************************/

/* Main Ddberv routine. */

static int preopserv(const char *source, const char *target, char *buf)
{
    char *cmd;
    const char *s;
    User *u = get_user(source);

    if (irc_stricmp(target, s_PreopServ) != 0)
        return 0;

    if (!u) {
        module_log("user record for %s not found", source);
        notice(s_PreopServ, source,
                getstring(NULL, INTERNAL_ERROR));
        return 1;
    }

    if (!is_oper(u)) {
        notice_lang(s_PreopServ, u, ACCESS_DENIED);
        if (WallBadOS)
            wallops(s_PreopServ, "Denied access to %s from %s (non-oper)",
                    s_PreopServ, source);
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
        notice(s_PreopServ, source, "\1PING %s", s);
    } else {
        if (call_callback_2(cb_command, u, cmd) <= 0)
            run_cmd(s_PreopServ, u, THIS_MODULE, cmd);
    }

    return 1;
}

/*************************************************************************/
/**************************** Event callbacks ****************************/
/*************************************************************************/

/* Handler for introducing nicks. */

static int do_introduce(const char *nick)
{
    if (!nick || irc_stricmp(nick, s_PreopServ) == 0) {
        send_pseudo_nick(s_PreopServ, desc_PreopServ, PSEUDO_INVIS|PSEUDO_BOT|PSEUDO_DEAF);
        if (nick)
            return 1;
    }
    return 0;
}

/*************************************************************************/


/* Handler for WHOIS's. */

static int do_whois(const char *source, char *who, char *extra)
{
    if (irc_stricmp(who, s_PreopServ) == 0) {
        send_cmd(ServerName, "311 %s %s %s %s * :%s", source, who,
                 ServiceUser, ServiceHost, desc_PreopServ);
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
    return irc_stricmp(nick, s_PreopServ) == 0;
}

/*************************************************************************/
/***************************** Module stuff ******************************/
/*************************************************************************/

ConfigDirective module_config[] = {
    { "PreopServName",     { { CD_STRING, CF_DIRREQ, &s_PreopServ },
                            { CD_STRING, 0, &desc_PreopServ } } },
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
    static char old_s_PreopServ[NICKMAX];
    static char *old_desc_PreopServ = NULL;

    if (!after_configure) {
        /* Before reconfiguration: save old values. */
        free(old_desc_PreopServ);
        strbcpy(old_s_PreopServ, s_PreopServ);
        old_desc_PreopServ = strdup(desc_PreopServ);
    } else {
        /* After reconfiguration: handle value changes. */
        if (strcmp(old_s_PreopServ, s_PreopServ) != 0)
            send_nickchange(old_s_PreopServ, s_PreopServ);
        if (!old_desc_PreopServ || strcmp(old_desc_PreopServ,desc_PreopServ) != 0)
            send_namechange(s_PreopServ, desc_PreopServ);
        free(old_desc_PreopServ);
        old_desc_PreopServ = NULL;
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
     || !add_callback(NULL, "m_privmsg", preopserv)
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

/*************************************************************************/

static void do_help(User *u)
{
    char *cmd = strtok_remaining();

    if (!cmd) {
	notice_help(s_PreopServ, u, HELP_CABECERA, s_PreopServ, NetworkName, "", "");
        notice_help(s_PreopServ, u, PREOP_HELP);
	notice_help(s_PreopServ, u, PREOP_FOOTER_HELP);
	notice_help(s_PreopServ, u, HELP_FOOTER, s_PreopServ);
    } else {
        help_cmd(s_PreopServ, u, THIS_MODULE, cmd);
    }

}

/*************************************************************************/

static void do_os_op(User *u)
{
    char *chan, *nick;
    Channel *c;
    User *target_user;

    chan = strtok(NULL, " ");
    nick = strtok(NULL, " ");


    if (!chan || !nick) {
	privmsg(s_PreopServ, u->nick, "\2Sintaxis:\2 \00312OP #canal nick\003");
        return;
    }

    if (!(c = get_channel(chan))) {
        notice_lang(s_PreopServ, u, CHAN_X_NOT_IN_USE, chan);
	return;
    }

    if (!(target_user = get_user(nick))) {
        notice_lang(s_PreopServ, u, NICK_X_NOT_IN_USE, nick);
        return;
    }

    struct c_userlist *cu;
    LIST_SEARCH_SCALAR(c->users, user, target_user, cu);
    if (!cu) {
        notice_lang(s_PreopServ, u, NICK_X_NOT_ON_CHAN_X, nick, chan);
        return;
    }
    privmsg(s_PreopServ, u->nick, "Ok, hecho.!\003");
    send_cmd(s_PreopServ, "MODE %s +o %s", chan, nick);
}

/*************************************************************************/

static void do_os_deop(User *u)
{
    char *chan, *nick;
    Channel *c;
    User *target_user;

    chan = strtok(NULL, " ");
    nick = strtok(NULL, " ");


    if (!chan || !nick) {
	privmsg(s_PreopServ, u->nick, "\2Sintaxis:\2 \00312DEOP #canal nick\003");
        return;
    }

    if (!(c = get_channel(chan))) {
        notice_lang(s_PreopServ, u, CHAN_X_NOT_IN_USE, chan);
	return;
    }

    if (!(target_user = get_user(nick))) {
        notice_lang(s_PreopServ, u, NICK_X_NOT_IN_USE, nick);
        return;
    }

    struct c_userlist *cu;
    LIST_SEARCH_SCALAR(c->users, user, target_user, cu);
    if (!cu) {
        notice_lang(s_PreopServ, u, NICK_X_NOT_ON_CHAN_X, nick, chan);
        return;
    }
    privmsg(s_PreopServ, u->nick, "Ok, hecho.!\003");
    send_cmd(s_PreopServ, "MODE %s -o %s", chan, nick);
}

/*************************************************************************/

static void do_os_invite(User *u)
{
    char *chan, *nick;
    Channel *c;
    User *target_user;

    nick = strtok(NULL, " ");
    chan = strtok(NULL, " ");


    if (!chan || !nick) {
	privmsg(s_PreopServ, u->nick, "\2Sintaxis:\2 \00312INVITE nick #canal\003");
        return;
    }

    if (!(c = get_channel(chan))) {
        notice_lang(s_PreopServ, u, CHAN_X_NOT_IN_USE, chan);
	return;
    }

    if (!(target_user = get_user(nick))) {
        notice_lang(s_PreopServ, u, NICK_X_NOT_IN_USE, nick);
        return;
    }
    privmsg(s_PreopServ, u->nick, "Ok, hecho.!\003");
    send_cmd(s_PreopServ, "INVITE %s %s", nick, chan);
}

/*************************************************************************/
void do_set_unbot(User *u)
 {
char *nick = strtok(NULL, " ");
 NickInfo *ni;
if (!nick) {
 privmsg(s_PreopServ, u->nick, "\2Sintaxis:\2 \00312unBOT nick\003");
 return;
 } else if (!(ni = get_nickinfo(nick))) {
 privmsg(s_PreopServ, u->nick, "%s no esta registrao", nick);
 return;
}
bdd_privrem(nick);
bdd_delvhost(nick);
 privmsg(s_PreopServ, u->nick, "\2%s\2 ha sido eleminado en la bdd del IRCU.", nick);
return;
 }

/*************************************************************************/
void do_set_bot(User *u)
 {
char *nick = strtok(NULL, " ");
 char buf[BUFSIZE];
 NickInfo *ni;
if (!nick) {
 privmsg(s_PreopServ, u->nick, "\2Sintaxis:\2 \00312BOT nick\003");
 return;
 } else if (!(ni = get_nickinfo(nick))) {
 privmsg(s_PreopServ, u->nick, "%s no esta registrao", nick);
 return;
}
bdd_privadd(nick, 8);
snprintf(buf, sizeof(buf), "%s.bot.naturchat.es", nick);
 bdd_addvhost(nick, buf);
 privmsg(s_PreopServ, u->nick, "\2%s\2 ha sido añadido como bot en la bdd del IRCU.", nick);
return;
 }

/*************************************************************************/

int exit_module(int shutdown_unused)
{
    if (linked)
        send_cmd(s_PreopServ, "QUIT :");

    if (module_nickserv)
        do_unload_module(module_nickserv);

    remove_callback(NULL, "m_whois", do_whois);
    remove_callback(NULL, "m_privmsg", preopserv);
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
