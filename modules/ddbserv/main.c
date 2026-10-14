/* DdbServ functions.
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

static char *s_DdbServ;
static char *desc_DdbServ;

static int    WallBadOS;

static int cb_command   = -1;
static int cb_help      = -1;

static void do_help(User *u);
static void do_compactar(User *u);
static void do_gencifrado(User *u);
static void do_jailchan(User *u);
static void do_maxclones(User *u);
static void do_quitclones(User *u);
static void do_serverhide(User *u);
static void do_autoinv(User *u);
static void do_msgquit(User *u);
static void do_pseudonick(User *u);
static void do_uline(User *u);
static void do_set_p09(User *u);
static void do_set_devel(User *u);
static void do_set_preoper(User *u);
static void do_set_bot(User *u);
static void do_set_blackhole(User *u);
static void do_set_unbot(User *u);

static Command cmds[] = {
    {"HELP",      do_help,       NULL,             -1,                  -1,-1},
    {"COMPACTAR", do_compactar,  is_services_admin, -1,-1,-1},
    {"GENCIFRADO", do_gencifrado,  is_services_admin, -1,-1,-1},
    /* Root */
    {"JAILCHAN",   do_jailchan,    is_services_root, -1,-1,-1},
    {"MAXCLONES",  do_maxclones,   is_services_root, -1,-1,-1},
    {"QUITCLONES", do_quitclones,  is_services_root, -1,-1,-1},
    {"SERVERHIDE", do_serverhide,  is_services_root, -1,-1,-1},
    {"AUTOINV",    do_autoinv,     is_services_root, -1,-1,-1},
    {"MSGQUIT",    do_msgquit,     is_services_root, -1,-1,-1},
    {"PSEUDONICK", do_pseudonick,  is_services_root, -1,-1,-1},
    {"ULINE", do_uline,  is_services_root, -1,-1,-1},
    {"P09", do_set_p09,  is_services_root, -1,-1,-1},
    {"DEVEL", do_set_devel,  is_services_admin, -1,-1,-1},
    {"PREOPER", do_set_preoper,  is_services_admin, -1,-1,-1},
    {"BOT", do_set_bot,  is_services_admin, -1,-1,-1},
    {"BLACKHOLE", do_set_blackhole,  is_services_admin, -1,-1,-1},
    {"UNBOT", do_set_unbot,  is_services_admin, -1,-1,-1},
    /* Fencepost: */
    { NULL }
};

/*************************************************************************/
/*************************** DdbServ routine ****************************/
/*************************************************************************/

/* Main Ddberv routine. */

static int ddbserv(const char *source, const char *target, char *buf)
{
    char *cmd;
    const char *s;
    User *u = get_user(source);

    if (irc_stricmp(target, s_DdbServ) != 0)
        return 0;

    if (!u) {
        module_log("user record for %s not found", source);
        notice(s_DdbServ, source,
                getstring(NULL, INTERNAL_ERROR));
        return 1;
    }

    if (!is_oper(u)) {
        notice_lang(s_DdbServ, u, ACCESS_DENIED);
        if (WallBadOS)
            wallops(s_DdbServ, "Denied access to %s from %s (non-oper)",
                    s_DdbServ, source);
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
        notice(s_DdbServ, source, "\1PING %s", s);
    } else {
        if (call_callback_2(cb_command, u, cmd) <= 0)
            run_cmd(s_DdbServ, u, THIS_MODULE, cmd);
    }

    return 1;
}

/*************************************************************************/
/**************************** Event callbacks ****************************/
/*************************************************************************/

/* Handler for introducing nicks. */

static int do_introduce(const char *nick)
{
    if (!nick || irc_stricmp(nick, s_DdbServ) == 0) {
        send_pseudo_nick(s_DdbServ, desc_DdbServ, PSEUDO_INVIS|PSEUDO_BOT|PSEUDO_DEAF);
        if (nick)
            return 1;
    }
    return 0;
}

/*************************************************************************/


/* Handler for WHOIS's. */

static int do_whois(const char *source, char *who, char *extra)
{
    if (irc_stricmp(who, s_DdbServ) == 0) {
        send_cmd(ServerName, "311 %s %s %s %s * :%s", source, who,
                 ServiceUser, ServiceHost, desc_DdbServ);
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
    return irc_stricmp(nick, s_DdbServ) == 0;
}

/*************************************************************************/
/***************************** Module stuff ******************************/
/*************************************************************************/

ConfigDirective module_config[] = {
    { "DdbServName",     { { CD_STRING, CF_DIRREQ, &s_DdbServ },
                            { CD_STRING, 0, &desc_DdbServ } } },
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
    static char old_s_DdbServ[NICKMAX];
    static char *old_desc_DdbServ = NULL;

    if (!after_configure) {
        /* Before reconfiguration: save old values. */
        free(old_desc_DdbServ);
        strbcpy(old_s_DdbServ, s_DdbServ);
        old_desc_DdbServ = strdup(desc_DdbServ);
    } else {
        /* After reconfiguration: handle value changes. */
        if (strcmp(old_s_DdbServ, s_DdbServ) != 0)
            send_nickchange(old_s_DdbServ, s_DdbServ);
        if (!old_desc_DdbServ || strcmp(old_desc_DdbServ,desc_DdbServ) != 0)
            send_namechange(s_DdbServ, desc_DdbServ);
        free(old_desc_DdbServ);
        old_desc_DdbServ = NULL;
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
     || !add_callback(NULL, "m_privmsg", ddbserv)
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
	notice_help(s_DdbServ, u, HELP_CABECERA, s_DdbServ, NetworkName, "", "");
        notice_help(s_DdbServ, u, DDB_HELP);
	 if (is_services_root(u)) {
		notice_help(s_DdbServ, u, DDB_ROOT_HELP);
	}
	notice_help(s_DdbServ, u, DDB_FOOTER_HELP);
	notice_help(s_DdbServ, u, HELP_FOOTER, s_DdbServ);
    } else {
        help_cmd(s_DdbServ, u, THIS_MODULE, cmd);
    }

}

/*************************************************************************/

static void do_compactar(User *u)
{
    bdd_compactar();
    privmsg(s_DdbServ, u->nick, "Compactando tablas...");
}

/*************************************************************************/

static void do_gencifrado(User *u)
{
    bdd_gen_cifrado();
    privmsg(s_DdbServ, u->nick, "Se ha generado una nueva clave de cifrado.");
}


/*************************************************************************/

void do_jailchan(User *u)
{
    char *opcion = strtok(NULL, " ");

    if (!opcion) {
        privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312JAILCHAN [ON|OFF]\003");
        return;
    }

    if (stricmp(opcion, "OFF") == 0) {
	bdd_chan_jail(JailChan, 0);
	privmsg(s_DdbServ, u->nick, "Se ha eliminado el \2JAILCHAN\2 de la DDB.");
        return;
    } else if (stricmp(opcion, "ON") == 0) {
	bdd_chan_jail(JailChan, 1);
	privmsg(s_DdbServ, u->nick, "Se ha activado el canal \00312%s\003", JailChan);
    } else {
	privmsg(s_DdbServ, u->nick, "Opción inválida.");
    }
}

/*************************************************************************/

void do_maxclones(User *u)
{
    char *cantidad = strtok(NULL, " ");
    int maxn;

    if (!cantidad) {
	privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312MAXCLONES número\003");
	return;
    }
    maxn = (cantidad && isdigit(*cantidad)) ? atoi(cantidad) : -1;
    if (maxn < 1) {
	privmsg(s_DdbServ, u->nick, "Límite de clones inválido.");
	return;
    }
    bdd_maxclones(maxn);
    privmsg(s_DdbServ, u->nick, "El nuevo límite de clones de la red es: \00312%d\003", maxn);
}

/*************************************************************************/

void do_quitclones(User *u)
{
    char *opcion = strtok(NULL, " ");
    char *msgquit = strtok_remaining();

    if (!opcion) {
	privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312QUITCLONES [SET|UNSET] Mensaje\003");
	return;
    }

    if (stricmp(opcion, "UNSET") == 0) {
	bdd_quitclones(NULL);
	return;
    }

    if (!msgquit) {
	privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312QUITCLONES SET Mensaje\003");
	return;
    }

    bdd_quitclones(msgquit);
    privmsg(s_DdbServ, u->nick, "Nuevo mensaje de salida de clones: %s", msgquit);
}

/*************************************************************************/

void do_serverhide(User *u)
{
    char *opcion = strtok(NULL, " ");
    if (!opcion) {
	privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312SERVERHIDE [ON|OFF]\003");
	return;
    }

    if (stricmp(opcion, "ON") == 0) {
	bdd_serverhide(1);
	privmsg(s_DdbServ, u->nick, "El modo ofuscación ha sido activado");
	return;
    } else if (stricmp(opcion, "OFF") == 0) {
	bdd_serverhide(0);
	privmsg(s_DdbServ, u->nick, "El modo ofuscación ha sido desactivado");
	return;
    } else {
	privmsg(s_DdbServ, u->nick, "%s es una opción no válida.", opcion);
    }
}

/*************************************************************************/

void do_autoinv(User *u)
{
    char *opcion = strtok(NULL, " ");
    if (!opcion) {
        privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312AUTOINV [ON|OFF]\003");
        return;
    }

    if (stricmp(opcion, "ON") == 0) {
        bdd_autoinv(1);
        return;
    } else if (stricmp(opcion, "OFF") == 0) {
        bdd_autoinv(0);
        return;
    } else {
        privmsg(s_DdbServ, u->nick, "%s es una opción no válida.", opcion);
    }
}

/*************************************************************************/

void do_msgquit(User *u)
{
    char *server = strtok(NULL, " ");
    char *msg = strtok(NULL, " ");
/*    char buf[BUFSIZE]; */
    if (!msg) {
        privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312MSGQUIT [Mensaje|None]\003");
        return;
    }

/*    snprintf(buf, sizeof(buf), "quit:%s", server); */

    if (stricmp(msg, "NONE") == 0) {
        bdd_msgquit(server, NULL);
        return;
    }

    bdd_msgquit(server, msg);

    privmsg(s_DdbServ, u->nick, "Mensaje de salida para \2%s\2 %s.", server, msg);

}

/*************************************************************************/

void do_pseudonick(User *u)
{
    char *nickservicio = strtok(NULL, " ");
    char *nickvirtual = strtok(NULL, " ");

    if (!nickvirtual) {
        privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312PSEUDONICK nick-servicio nick-virtual!ident@mascara\003");
        privmsg(s_DdbServ, u->nick, "Para mas información escribe, \00312/MSG %s HELP PSEUDONICK\003", s_DdbServ);
        return;
    }

    if (stricmp(nickvirtual, "NONE") == 0)
	nickvirtual = NULL;

    if (stricmp(nickservicio, "NickServ") == 0) {
        bdd_pseudonick("NickServ", nickvirtual);
	privmsg(s_DdbServ, u->nick, "Bot virtual NickServ: \00312%s\003", nickvirtual);
        return;
    } else if (stricmp(nickservicio, "ChanServ") == 0) {
        bdd_pseudonick("ChanServ", nickvirtual);
	privmsg(s_DdbServ, u->nick, "Bot virtual ChanServ: \00312%s\003", nickvirtual);
        return;
    } else {
	privmsg(s_DdbServ, u->nick, "\2%s\2, no es un nick de servicio válido", nickservicio);
    }

}

/*************************************************************************/

void do_uline(User *u)
{
    char *opcion = strtok(NULL, " ");
    char *servername = strtok(NULL, " ");

    if (!servername) {
	privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312ULINE [ADD|DEL] [nick/server]\003");
	return;
    }

    if (stricmp(opcion, "ADD") == 0) {
	bdd_uline(servername, 1);
	privmsg(s_DdbServ, u->nick, "\2%s\2 ha sido agregado como uline", servername);
	return;
    } else if (stricmp(opcion, "DEL") == 0) {
	bdd_uline(servername, 0);
        privmsg(s_DdbServ, u->nick, "\2%s\2 ha sido borrado como uline", servername);
        return;
    } else {
	privmsg(s_DdbServ, u->nick, "\2%s\2 opción no válida.", opcion);
   }
}

void do_set_p09(User *u)
{
    char *opcion = strtok(NULL, " ");
    char *servername = strtok(NULL, " ");
    char *numerico = strtok(NULL, " ");

    if (!servername || !numerico) {
        privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312P09 [ADD|DEL] <server> <numerico>\003");
        return;
    }

    if (stricmp(opcion, "ADD") == 0) {
        bdd_set_p09(servername, atoi(numerico));
        privmsg(s_DdbServ, u->nick, "El servidor \2%s\2 ha sido establecido como nodo P09 con el numerico %d.", servername, atoi(numerico));
        return;
    } else if (stricmp(opcion, "DEL") == 0) {
	bdd_set_p09(servername, 0);
        privmsg(s_DdbServ, u->nick, "El servidor \2%s\2 ha desmarcado como nodo P09.", servername);
        return;
    } else {
        privmsg(s_DdbServ, u->nick, "\2%s\2 opción no válida.", opcion);
   }
}

/*************************************************************************/

void do_set_devel(User *u)
 {
char *nick = strtok(NULL, " ");
 char buf[BUFSIZE];
 NickInfo *ni;
if (!nick) {
 privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312DEVEL nick\003");
 return;
 } else if (!(ni = get_nickinfo(nick))) {
 privmsg(s_DdbServ, u->nick, "%s no esta registrao", nick);
 return;
}
bdd_privadd(nick, 4);
snprintf(buf, sizeof(buf), "%s.devel.naturchat.es", nick);
 bdd_addvhost(nick, buf);
 privmsg(s_DdbServ, u->nick, "\2%s\2 ha sido agregado como devel en la bdd del IRCU.", nick);
return;
 }

/*************************************************************************/

void do_set_preoper(User *u)
 {
char *nick = strtok(NULL, " ");
 char buf[BUFSIZE];
 NickInfo *ni;
if (!nick) {
 privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312PREOPER nick\003");
 return;
 } else if (!(ni = get_nickinfo(nick))) {
 privmsg(s_DdbServ, u->nick, "%s no esta registrao", nick);
 return;
}
bdd_privadd(nick, 3);
snprintf(buf, sizeof(buf), "%s.preoper.naturchat.es", nick);
 bdd_addvhost(nick, buf);
 privmsg(s_DdbServ, u->nick, "\2%s\2 ha sido agregado como preoper en la bdd del IRCU.", nick);
return;
 }
/*************************************************************************/
void do_set_unbot(User *u)
 {
char *nick = strtok(NULL, " ");
 NickInfo *ni;
if (!nick) {
 privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312unBOT nick\003");
 return;
 } else if (!(ni = get_nickinfo(nick))) {
 privmsg(s_DdbServ, u->nick, "%s no esta registrao", nick);
 return;
}
bdd_privrem(nick);
bdd_delvhost(nick);
 privmsg(s_DdbServ, u->nick, "\2%s\2 ha sido eleminado en la bdd del IRCU.", nick);
return;
 }

/*************************************************************************/
void do_set_bot(User *u)
 {
char *nick = strtok(NULL, " ");
 char buf[BUFSIZE];
 NickInfo *ni;
if (!nick) {
 privmsg(s_DdbServ, u->nick, "\2Sintaxis:\2 \00312BOT nick\003");
 return;
 } else if (!(ni = get_nickinfo(nick))) {
 privmsg(s_DdbServ, u->nick, "%s no esta registrao", nick);
 return;
}
bdd_privadd(nick, 8);
snprintf(buf, sizeof(buf), "%s.bot.naturchat.es", nick);
 bdd_addvhost(nick, buf);
 privmsg(s_DdbServ, u->nick, "\2%s\2 ha sido agregado como bot en la bdd del IRCU.", nick);
return;
 }

/*************************************************************************/
void do_set_blackhole(User *u)
 {
///system("/home/irc/blackhole/./blackhole.pl");
system("cd /home/irc/blackhole && ./blackhole.pl");
 privmsg(s_DdbServ, u->nick, "\2Black.Hole\2 arrancando");
return;
 }

/*************************************************************************/

int exit_module(int shutdown_unused)
{
    if (linked)
        send_cmd(s_DdbServ, "QUIT :");

    if (module_nickserv)
        do_unload_module(module_nickserv);

    remove_callback(NULL, "m_whois", do_whois);
    remove_callback(NULL, "m_privmsg", ddbserv);
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
