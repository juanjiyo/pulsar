/* HostServ functions.
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

#ifdef IRC_HISPANO

static Module *module_nickserv;

static char *s_HostServ;
static char *desc_HostServ;

static int cb_command   = -1;
static int cb_help      = -1;

void strip_color (const char *src, int maxlength, char *dst);

void strip_color (const char *src, int maxlength, char *dst)
{
  int rcol = 0, bgcol = 0;
  int pos=0;

  while (*src && pos<(maxlength - 1))
    {
      if (rcol > 0 && (isdigit ((unsigned char)*src) ||
          (*src == ',' && isdigit ((unsigned char)src[1]) && !bgcol)))
        {
          if (src[1] != ',') rcol--;
          if (*src == ',')
            {
              rcol = 2;
              bgcol = 1;
            }
        } else
          {
            rcol = bgcol = 0;
            switch (*src)
            {
            case '\003':
              rcol = 2;
            case '\010':
            case '\007':
            case '\017':
            case '\026':
            case '\002':
            case '\037':
            case '\035':
              break;
            default:
              //pass_char:
              *dst++ = *src;
            }
          }
      src++;
      pos++;
    }
  *dst = 0;
}

static void do_help(User *u);
static void do_vhost(User *u);
static void do_activar(User *u);
static void do_anular(User *u);

static Command cmds[] = {
    {"HELP",      do_help,       NULL,             HOST_HELP,                  -1,-1},
    {"ACTIVAR",   do_activar,    NULL,             HOST_HELP_ACTIVAR,    		-1,-1},
    {"ANULAR",    do_anular,     NULL,             HOST_HELP_ANULAR,                  -1,-1},
    {"VHOST",   do_vhost,    is_services_admin,             -1,                  -1,HOST_OPER_HELP_VHOST},
    /* Fencepost: */
    { NULL }
};

/*************************************************************************/
/*************************** HelpServ routine ****************************/
/*************************************************************************/

/* Main HelpServ routine. */

static int hostserv(const char *source, const char *target, char *buf)
{
    char *cmd;
    const char *s;
    User *u = get_user(source);

    if (irc_stricmp(target, s_HostServ) != 0)
        return 0;

    if (!u) {
        module_log("user record for %s not found", source);
        notice(s_HostServ, source,
                getstring(NULL, INTERNAL_ERROR));
        return 1;
    }

    NickInfo *ni = u->ni;
    if (!ni) {
	privmsg(s_HostServ, u->nick, "Has de registrar tu nick para tener acceso al servicio de IP's virtuales");
        return 0;
    }

    cmd = strtok(buf, " ");
    if (!cmd) {
        return 1;
    } else if (stricmp(cmd, "\1PING") == 0) {
        if (!(s = strtok_remaining()))
            s = "\1";
        notice(s_HostServ, source, "\1PING %s", s);
    } else {
        if (call_callback_2(cb_command, u, cmd) <= 0)
            run_cmd(s_HostServ, u, THIS_MODULE, cmd);
    }

    return 1;
}

/*************************************************************************/
/**************************** Event callbacks ****************************/
/*************************************************************************/

/* Handler for introducing nicks. */

static int do_introduce(const char *nick)
{
    if (!nick || irc_stricmp(nick, s_HostServ) == 0) {
        send_pseudo_nick(s_HostServ, desc_HostServ, PSEUDO_INVIS|PSEUDO_BOT|PSEUDO_DEAF);
        if (nick)
            return 1;
    }
    return 0;
}

/*************************************************************************/


/* Handler for WHOIS's. */

static int do_whois(const char *source, char *who, char *extra)
{
    if (irc_stricmp(who, s_HostServ) == 0) {
        send_cmd(ServerName, "311 %s %s %s %s * :%s", source, who,
                 ServiceUser, ServiceHost, desc_HostServ);
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
    return irc_stricmp(nick, s_HostServ) == 0;
}

/*************************************************************************/
/***************************** Module stuff ******************************/
/*************************************************************************/

ConfigDirective module_config[] = {
    { "HostServName",     { { CD_STRING, CF_DIRREQ, &s_HostServ },
                            { CD_STRING, 0, &desc_HostServ } } },
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
    static char old_s_HostServ[NICKMAX];
    static char *old_desc_HostServ = NULL;

    if (!after_configure) {
        /* Before reconfiguration: save old values. */
        free(old_desc_HostServ);
        strbcpy(old_s_HostServ, s_HostServ);
        old_desc_HostServ = strdup(desc_HostServ);
    } else {
        /* After reconfiguration: handle value changes. */
        if (strcmp(old_s_HostServ, s_HostServ) != 0)
            send_nickchange(old_s_HostServ, s_HostServ);
        if (!old_desc_HostServ || strcmp(old_desc_HostServ,desc_HostServ) != 0)
            send_namechange(s_HostServ, desc_HostServ);
        free(old_desc_HostServ);
        old_desc_HostServ = NULL;
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
     || !add_callback(NULL, "m_privmsg", hostserv)
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
	notice_help(s_HostServ, u, HELP_CABECERA, s_HostServ, NetworkName, "", "");
        notice_help(s_HostServ, u, HOST_HELP, NetworkName);
        if (is_services_admin(u)) {
            notice_help(s_HostServ, u, HOST_OPER_HELP);
        }
	notice_help(s_HostServ, u, HELP_FOOTER, s_HostServ);
     } else {
             help_cmd(s_HostServ, u, THIS_MODULE, cmd);
     }
}

static void do_activar(User *u)
{
    NickInfo *ni = u->ni;
    NickGroupInfo *ngi = NULL;
    char *vhost = strtok(NULL, " ");

    if (!(ngi = get_ngi(ni))) {
        notice_lang(s_NickServ, u, INTERNAL_ERROR);
	return;
    }

    if (!vhost) {
	privmsg(s_HostServ, u->nick, "\2Sintaxis:\2 ACTIVAR tu.vhost.aqui");
	return;
    }

    char buf[BUFSIZE];
    time_t ahora = time(NULL);
    if (ahora < ngi->vhost_time && !is_oper(u)) {
        strftime_lang(buf, sizeof(buf), u->ngi,
                   STRFTIME_DATE_TIME_FORMAT, ngi->vhost_time);
	privmsg(s_HostServ, u->nick, "No han pasado 24 horas desde el último cambio de IP virtual");
	privmsg(s_HostServ, u->nick, "El próximo cambio se podrá realizar el: \2%s\2", buf);
	return;
    }

    if (strlen(vhost) > 63) {
	privmsg(s_HostServ, u->nick, "Como maximo puede tener 63 caracteres");
	return;
    }

    char *p;
    for (p=vhost; *p; p++) {
    	if (!isalnum(*p) && (*p != '_') && (*p != '-') && (*p != '.')) {
		privmsg(s_HostServ, u->nick, "El vhost solamente admite caracteres entre a-z, y 0-9 incluidas el guion y el punto.");
		return;
	}
    }

    if (vhost[0] == '.' || vhost[0] == '-' || vhost[0] == '_') {
	privmsg(s_HostServ, u->nick, "No puede comenzar por . - _ ni contener 2 o más . _ - seguidos ni ._. ni .-. ni acabar en .");
	return;
    }

    if ((strstr(vhost, "root")) || (strstr(vhost, "admin")) || (strstr(vhost, "coadmin")) ||
		(strstr(vhost, "devel")) || (strstr(vhost, "oper")) ||
			(strstr(vhost, "ircop")) || (strstr(vhost, "portalzona")) ||
				(strstr(vhost, ".net.")) || (strstr(vhost, ".com.")) || (strstr(vhost, ".org.")) ||
			(strstr(vhost, ".es.")) || (strstr(vhost, "..")) || (strstr(vhost, "--")) ||
				(strstr(vhost, "__")) || (strstr(vhost, ".info.")) || (strstr(vhost, ".biz."))) {
	 privmsg(s_HostServ, u->nick, "La IP virtual especificada no puede ser utilizada.");
	 return;
    }

    if (!strstr(vhost,".") && strlen(vhost) < 4) {
	privmsg(s_HostServ, u->nick, "Si el vhost no contiene ningun '.' debera contener 4 caracteres o más.");
	return;
    }

    char *no_domain;
    no_domain = strrchr(vhost, '.');
    if (no_domain) {
	if (strlen(no_domain) < 5) {
    		privmsg(s_HostServ, u->nick, "El grupo de letras tras el último '.' ha de ser de 4 caracteres o más");
    		return;
	}
	if (no_domain[0] == '_' || no_domain[0] == '-' || strstr(no_domain, "org")) {
		privmsg(s_HostServ, u->nick, "El grupo de letras tras el último '.' no debe contener _ - ni empezar por 'org'");
		return;
	}
    }

    if (vhost[strlen(vhost) - 1] == '.') {
        privmsg(s_HostServ, u->nick, "El vHost no puede acabar en punto '.'");
        return;
    }

    time_t sgte_cambio;
    sgte_cambio = dotime("1440m");
    sgte_cambio += time(NULL);
    ngi->vhost_time = sgte_cambio;

    free(ngi->virtual_host);
    ngi->virtual_host = sstrdup(vhost);
    free(u->vhostper);
    u->vhostper = sstrdup(ngi->virtual_host);
    bdd_addvhost(ni->nick, vhost);
    strftime_lang(buf, sizeof(buf), u->ngi,
               STRFTIME_DATE_TIME_FORMAT, ngi->vhost_time);
    if (EnableDebug)
	logchan(NULL, "\2HOSTSERV\2 \00312%s\003 activa el vHost \00312%s\003", u->nick, vhost);
    privmsg(s_HostServ, u->nick, "IP virtual activada correctamente, tu IP es ahora: \2%s\2", vhost);
    privmsg(s_HostServ, u->nick, "Recuerda que no podrás activar una nueva IP virtual hasta el \2%s\2", buf);

}

static void do_anular(User *u)
{
    NickInfo *ni = u->ni;
    NickGroupInfo *ngi = NULL;
    char *param = strtok(NULL, " ");

    if (!(ngi = get_ngi(ni))) {
        notice_lang(s_NickServ, u, INTERNAL_ERROR);
        return;
    }

    if (!param) {
        privmsg(s_HostServ, u->nick, "\2Sintaxis:\2 ANULAR ahora");
        return;
    }

    if (stricmp(param, "AHORA") != 0) {
	privmsg(s_HostServ, u->nick, "Opción incorrecta.");
        return;
    }

    if (!(ngi->virtual_host)) {
	privmsg(s_HostServ, u->nick, "No tienes IP virtual personalizada");
	return;
    }

    char buf[BUFSIZE];
    time_t ahora = time(NULL);
    if (ahora < ngi->cancelar_time && !is_oper(u)) {
        strftime_lang(buf, sizeof(buf), u->ngi,
                   STRFTIME_DATE_TIME_FORMAT, ngi->cancelar_time);
        privmsg(s_HostServ, u->nick, "No han pasado 24 horas desde la última anulacion de IP Virtual.");
        privmsg(s_HostServ, u->nick, "La próxima anulación se podrá realizar el: \2%s\2", buf);
        return;
    }

    time_t sgte_cambio;
    sgte_cambio = dotime("1440m");
    sgte_cambio += time(NULL);
    ngi->cancelar_time = sgte_cambio;

    free(ngi->virtual_host);
    bdd_delvhost(ni->nick);
    strftime_lang(buf, sizeof(buf), u->ngi,
               STRFTIME_DATE_TIME_FORMAT, ngi->vhost_time);
    privmsg(s_HostServ, u->nick, "IP virtual \2%s\2 anulada correctamente.", ngi->virtual_host);
    privmsg(s_HostServ, u->nick, "Te recordamos que no podrás activar una nueva IP virtual hasta el \2%s\2", buf);
    ngi->virtual_host = NULL;
    free(u->vhostper);
    u->vhostper = NULL;


}

static void do_vhost(User *u)
{
    char *cmd = strtok(NULL, " ");
    char *nick = strtok(NULL, " ");
    char *vhost = strtok(NULL, " ");
    char buffer_nocolor[1024];
    NickInfo *ni = NULL;
    NickGroupInfo *ngi = NULL;

    if (!cmd)
        cmd = "";

    if (stricmp(cmd, "SET") == 0) {
	if (nick && vhost) {
		if (!(ni = get_nickinfo(nick))) {
			notice_lang(s_HostServ, u, NICK_X_NOT_REGISTERED, nick);
		} else if (!(ngi = get_ngi(ni))) {
			notice_lang(s_HostServ, u, INTERNAL_ERROR);
		} else {
			char *p;
    			for (p=vhost; *p; p++) {
    				if (!isalnum(*p) && (*p != '_') && (*p != '-') && (*p != '.') && (*p != '') && (*p != '')) {
					privmsg(s_HostServ, u->nick, "El vhost solamente admite caracteres entre a-z, y 0-9 incluidas el guion y el punto.");
					return;
				}
    			}
    			if (vhost[0] == '.' || vhost[0] == '-' || vhost[0] == '_') {
				privmsg(s_HostServ, u->nick, "No puede comenzar por . - _ ni contener 2 o más . _ - seguidos ni ._. ni .-. ni acabar en .");
				return;
    			}
			free(ngi->virtual_host);
    			ngi->virtual_host = sstrdup(vhost);
			strip_color(vhost, sizeof(buffer_nocolor), buffer_nocolor);
			bdd_addvhost(ni->nick, buffer_nocolor);
			bdd_addvhostvip(ni->nick, vhost);
			privmsg(s_HostServ, u->nick, "Cambiado el VHOST del usuario \00312%s\003 a %s", ni->nick, vhost);
			if (EnableDebug)
        			logchan(NULL, "\2HOSTSERV\2 \00312%s\003 establece sobre \00312%s\003 el vHost \00312%s\003", u->nick, ni->nick, vhost);
		}
    	} else {
			privmsg(s_HostServ, u->nick, "\2Sintaxis:\2 \00312VHOST SET <nick> <vhost>\003");
	}
    } else if (stricmp(cmd, "DEL") == 0) {
	if (nick) {
               if (!(ni = get_nickinfo(nick))) {
                        notice_lang(s_HostServ, u, NICK_X_NOT_REGISTERED, nick);
                } else if (!(ngi = get_ngi(ni))) {
                        notice_lang(s_HostServ, u, INTERNAL_ERROR);
                } else {
    			free(ngi->virtual_host);
    			bdd_delvhost(ni->nick);
			bdd_delvhostvip(ni->nick);
			ngi->virtual_host = NULL;
			privmsg(s_HostServ, u->nick, "Eliminado el VHOST de \00312%s\003", ni->nick);
			if (EnableDebug)
				logchan(NULL, "\2HOSTSERV\2 \00312%s\003 elimina el vHost de \00312%s\003", u->nick, ni->nick);
		}
	} else {
		privmsg(s_HostServ, u->nick, "\2Sintaxis:\2 \00312VHOST DEL <nick>\003");
	}
    } else {
		privmsg(s_HostServ, u->nick, "\2Sintaxis:\2 \00312VHOST [SET|DEL] <nick> [vhost]\003");
    }
}

/*************************************************************************/

int exit_module(int shutdown_unused)
{
    if (linked)
        send_cmd(s_HostServ, "QUIT :");

    if (module_nickserv)
        do_unload_module(module_nickserv);

    remove_callback(NULL, "m_whois", do_whois);
    remove_callback(NULL, "m_privmsg", hostserv);
    remove_callback(NULL, "introduce_user", do_introduce);
    remove_callback(NULL, "reconfigure", do_reconfigure);
    remove_callback(NULL, "unload module", do_unload_module);
    remove_callback(NULL, "load module", do_load_module);

    unregister_callback(cb_help);
    unregister_callback(cb_command);

    return 1;
}

#endif 
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
