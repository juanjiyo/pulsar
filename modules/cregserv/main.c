/* CregServ functions.
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
#include "encrypt.h"
#include "commands.h"
#include "modules/nickserv/nickserv.h"
#include "modules/chanserv/chanserv.h"
#include "modules/chanserv/cs-local.h"
#include "modules/operserv/operserv.h"

#include "cregserv.h"
#include <sys/stat.h>

/*************************************************************************/

static Module *module_nickserv;

static char *s_CregServ;
static char *desc_CregServ;

static int32  CSDefModeLockOn = CMODE_n | CMODE_t;
static int32  CSDefModeLockOff = CMODE_i | CMODE_k | CMODE_l | CMODE_p | CMODE_s;
static char  *CRSRegNotice;
       time_t CRSAntiguedadNick;
       time_t CRSSigRegistro;

static int cb_command   = -1;
static int cb_help      = -1;

static void do_help(User *u);
static void do_registra(User *u);
static void do_estado(User *u);
static void do_status(User *u);
static void do_info(User *u);
static void do_aprobar(User *u);
static void do_denegar(User *u);
static void do_pendientes(User *u);
static void do_denegados(User *u);
static void do_drop(User *u);

static Command cmds[] = {
    {"HELP",        do_help,        NULL,                  -1,                        -1,-1},
    {"REGISTRA",    do_registra,    NULL,                  CREG_HELP_REGISTER,        -1,-1},
    {"ESTADO",      do_estado,      NULL,                  CREG_HELP_ESTADO,          -1,-1},
    {"STATUS",      do_status,      NULL,                  -1,                        -1,-1},
    {"INFO",        do_info,        is_services_oper,      -1,                        -1,-1},
    {"APROBAR",     do_aprobar,     is_services_oper,      CREG_OPER_HELP_APROBAR,    -1,-1},
    {"DENEGAR",     do_denegar,     is_services_oper,      CREG_OPER_HELP_DENEGAR,    -1,-1},
    {"PENDIENTES",  do_pendientes,  is_services_oper,      -1,                        -1,-1},
    {"DENEGADOS",   do_denegados,   is_services_oper,      -1,                        -1,-1},
    {"DROP",        do_drop,   	    is_services_admin,     -1,                        -1,-1},
    /* Fencepost: */
    { NULL }
};

/*************************************************************************/
/*************************** CregServ routine ****************************/
/*************************************************************************/

/* Main CregServ routine. */

static int cregserv(const char *source, const char *target, char *buf)
{
    char *cmd;
    const char *s;
    User *u = get_user(source);

    if (irc_stricmp(target, s_CregServ) != 0)
        return 0;

    if (!u) {
        module_log("user record for %s not found", source);
        notice(s_CregServ, source,
                getstring(NULL, INTERNAL_ERROR));
        return 1;
    }

    NickInfo *ni = u->ni;
    if (!ni) {
	privmsg(s_CregServ, u->nick, "Has de registrar tu nick para tener acceso al servicio de pre-registro de canales");
        return 0;
    }

    cmd = strtok(buf, " ");
    if (!cmd) {
        return 1;
    } else if (stricmp(cmd, "\1PING") == 0) {
        if (!(s = strtok_remaining()))
            s = "\1";
        notice(s_CregServ, source, "\1PING %s", s);
    } else {
        if (call_callback_2(cb_command, u, cmd) <= 0)
            run_cmd(s_CregServ, u, THIS_MODULE, cmd);
    }

    return 1;
}

#define HASH_STATIC static
#define HASHFUNC(key) DEFAULT_HASHFUNC(key+1)
#include "hash.h"
DEFINE_HASH(creginfo_, CregInfo, name)

EXPORT_FUNC(add_creginfo)
CregInfo *add_creginfo(CregInfo *cr)
{
    add_creginfo_(cr);
    cr->usecount = 1;
    return cr;
}

EXPORT_FUNC(del_creginfo)
void del_creginfo(CregInfo *cr)
{
    del_creginfo_(cr);
    free_creginfo(cr);
}

EXPORT_FUNC(get_creginfo)
CregInfo *get_creginfo(const char *chan)
{
    CregInfo *cr;
    if ((cr = get_creginfo_(chan)) != NULL)
        cr->usecount++;
    return cr;
}

EXPORT_FUNC(put_creginfo)
CregInfo *put_creginfo(CregInfo *cr)
{
    if (cr) {
        if (cr->usecount > 0)
            cr->usecount--;
        else
            module_log_debug(1, "BUG: put_creginfo(%s) with usecount==0",
                             cr->name);
    }
    return cr;
}

EXPORT_FUNC(first_creginfo)
CregInfo *first_creginfo(void)
{
    return first_creginfo_();
}

EXPORT_FUNC(next_creginfo)
CregInfo *next_creginfo(void)
{
    return next_creginfo_();
}

static CregInfo *new_creginfo(void)
{
    CregInfo *cr = scalloc(sizeof(CregInfo), 1);
    return cr;
}

static void free_creginfo(CregInfo *cr)
{
    if (cr) {
        clear_password(&cr->founderpass);
        free(cr->descr);
        free(cr->denegado_motivo);
        free(cr);
    }
}

static void insert_channel(void *record)
{
    CregInfo *cr = add_creginfo(record);
    put_creginfo(cr);
}

#define FIELD(name,type,...) \
    { #name, type, offsetof(CregInfo,name) , ##__VA_ARGS__ }

static DBField creg_dbfields[] = {
    FIELD(name,              DBTYPE_BUFFER, CHANMAX),
    FIELD(foundernick,       DBTYPE_BUFFER, NICKMAX),
    FIELD(founder,           DBTYPE_UINT32),
    FIELD(founderpass,       DBTYPE_PASSWORD),
    FIELD(descr,             DBTYPE_STRING),
    FIELD(time_registered,   DBTYPE_TIME),
    FIELD(time_aprobado,     DBTYPE_TIME),
    FIELD(flags,             DBTYPE_INT32),
    FIELD(nickoper,          DBTYPE_BUFFER, NICKMAX),
    FIELD(denegado_nick,     DBTYPE_BUFFER, NICKMAX),
    FIELD(denegado_motivo,   DBTYPE_STRING),
    FIELD(denegado_time,     DBTYPE_TIME),
    { NULL }
};

static DBTable creg_dbtable = {
    .name    = "creg",
    .newrec  = (void *)new_creginfo,
    .freerec = (void *)free_creginfo,
    .insert  = insert_channel,
    .first   = (void *)first_creginfo,
    .next    = (void *)next_creginfo,
    .fields  = creg_dbfields,
};

CregInfo *makecreg(const char *chan);
CregInfo *makecreg(const char *chan)
{
    CregInfo *cr;

    cr = scalloc(sizeof(CregInfo), 1);
    strbcpy(cr->name, chan);
    cr->time_registered = time(NULL);
    return add_creginfo(cr);
}

int no_habilitado(const char *nick);
int no_habilitado(const char *nick)
{
    CregInfo *cr;
    for (cr = first_creginfo(); cr; cr = next_creginfo()) {
	if (cr->flags & CR_PROCESOREG) {
		if (stricmp(cr->foundernick, nick) == 0)
			return 1;
	}
    }
    return 0;
}

/*************************************************************************/
/**************************** Event callbacks ****************************/
/*************************************************************************/

/* Handler for introducing nicks. */

static int do_introduce(const char *nick)
{
    if (!nick || irc_stricmp(nick, s_CregServ) == 0) {
        send_pseudo_nick(s_CregServ, desc_CregServ, PSEUDO_INVIS|PSEUDO_BOT|PSEUDO_DEAF);
        if (nick)
            return 1;
    }
    return 0;
}

/*************************************************************************/


/* Handler for WHOIS's. */

static int do_whois(const char *source, char *who, char *extra)
{
    if (irc_stricmp(who, s_CregServ) == 0) {
        send_cmd(ServerName, "311 %s %s %s %s * :%s", source, who,
                 ServiceUser, ServiceHost, desc_CregServ);
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
 * registration/linking of the CregServ pseudoclient nickname.
 */

static int do_reglink_check(const User *u, const char *nick,
                            const char *pass, const char *email)
{
    return irc_stricmp(nick, s_CregServ) == 0;
}

/*************************************************************************/
/***************************** Module stuff ******************************/
/*************************************************************************/

ConfigDirective module_config[] = {
    { "CregServName",      { { CD_STRING, CF_DIRREQ, &s_CregServ },
                             { CD_STRING, 0, &desc_CregServ } } },
    { "CRSRegNotice",      { { CD_STRING, CF_DIRREQ, &CRSRegNotice } } },
    { "CRSAntiguedadNick", { { CD_TIME,   0, &CRSAntiguedadNick } } },
    { "CRSSigRegistro",    { { CD_TIME,   0, &CRSSigRegistro } } },
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
    static char old_s_CregServ[NICKMAX];
    static char *old_desc_CregServ = NULL;

    if (!after_configure) {
        /* Before reconfiguration: save old values. */
        free(old_desc_CregServ);
        strbcpy(old_s_CregServ, s_CregServ);
        old_desc_CregServ = strdup(desc_CregServ);
    } else {
        /* After reconfiguration: handle value changes. */
        if (strcmp(old_s_CregServ, s_CregServ) != 0)
            send_nickchange(old_s_CregServ, s_CregServ);
        if (!old_desc_CregServ || strcmp(old_desc_CregServ,desc_CregServ) != 0)
            send_namechange(s_CregServ, desc_CregServ);
        free(old_desc_CregServ);
        old_desc_CregServ = NULL;
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
     || !add_callback(NULL, "m_privmsg", cregserv)
     || !add_callback(NULL, "m_whois", do_whois)
    ) {
        module_log("Unable to register callbacks");
        exit_module(0);
        return 0;
    }

    if (!register_dbtable(&creg_dbtable)) {
        module_log("Unable to register database tables");
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
	notice_help(s_CregServ, u, HELP_CABECERA, s_CregServ, NetworkName, "", "");
        notice_help(s_CregServ, u, CREG_HELP);
        if (is_services_oper(u)) {
            notice_help(s_CregServ, u, CREG_OPER_HELP);
        }
        if (is_services_admin(u)) {
            notice_help(s_CregServ, u, CREG_ADMIN_HELP);
        }
	notice_help(s_CregServ, u, CREG_HELP_FOOTER);
	notice_help(s_CregServ, u, HELP_FOOTER, s_CregServ);
     } else {
             help_cmd(s_CregServ, u, THIS_MODULE, cmd);
     }
}

/*************************************************************************/

static void do_registra(User *u)
{
    char *chan = strtok(NULL, " ");
    char *pass = strtok(NULL, " ");
    char *desc = strtok_remaining();
    NickInfo *ni = u->ni;
    NickGroupInfo *ngi = u->ngi;
    ChannelInfo *ci;
    CregInfo *cr;
    int max;

    if (readonly) {
        notice_lang(s_CregServ, u, CHAN_REGISTER_DISABLED);
        return;
    }

    if (!chan || !pass || !desc) {
	privmsg(s_CregServ, u->nick, "\2Sintaxis:\2 \00312REGISTRA <#Canal> <contraseña> <descripción>\003");
    } else if (strcmp(chan, "#") == 0) {
        notice_lang(s_CregServ, u, CHAN_REGISTER_SHORT_CHANNEL);
    } else if (*chan == '&') {
        notice_lang(s_CregServ, u, CHAN_REGISTER_NOT_LOCAL);
    } else if (*chan != '#') {
        notice_lang(s_CregServ, u, CHAN_REGISTER_INVALID_NAME);
    } else if (!ni) {
        notice_lang(s_CregServ, u, CHAN_MUST_REGISTER_NICK, s_NickServ);
    } else if (!user_identified(u)) {
        notice_lang(s_CregServ, u, CHAN_MUST_IDENTIFY_NICK,
                s_NickServ, s_NickServ);
    } else if ((ci = get_channelinfo(chan)) != NULL) {
	if (ci->flags & CF_VERBOTEN)
		privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no puede ser registrado, elije otro.", ci->name);
	else if (ci->flags & CF_SUSPENDED)
		privmsg(s_CregServ, u->nick, "El canal \00312%s\003 ya se encuentra registrado con \0033%s\003", chan, s_ChanServ);
	else
		privmsg(s_CregServ, u->nick, "El canal \00312%s\003 ya se encuentra registrado con \0033%s\003", chan, s_ChanServ);
        put_channelinfo(ci);
    } else if (!(NoAdminPasswordCheck && is_services_admin(u))
               && (stricmp(pass, chan) == 0
                || stricmp(pass, chan+1) == 0
                || stricmp(pass, u->nick) == 0
                || (StrictPasswords && strlen(pass) < 5))
    ) {
        notice_lang(s_CregServ, u, MORE_OBSCURE_PASSWORD);
    } else if (!is_services_admin(u) && check_channel_limit(ngi, &max) >= 0) {
        notice_lang(s_CregServ, u, ngi->channels_count > max
                                   ? CHAN_EXCEEDED_CHANNEL_LIMIT
                                   : CHAN_REACHED_CHANNEL_LIMIT, max);
    } else if ((cr = get_creginfo(chan)) != NULL) {
        if (cr->flags & CR_DENEGADO)
                privmsg(s_CregServ, u->nick, "El canal \00312%s\003 se encuentra denegado para su registro.", cr->name);
        else
                privmsg(s_CregServ, u->nick, "El canal \00312%s\003 se encuentra en proceso de registro.", cr->name);
	put_creginfo(cr);
    } else {
	time_t dias_req = time(NULL) - (ni->time_registered);
	if ((dias_req / 86400) < (CRSAntiguedadNick / 86400) && !is_services_oper(u)) {
		privmsg(s_CregServ, u->nick, "Se requiere un nick con antiguedad mínima de \00312%s\003 para registrar el canal.", maketime(u->ngi,CRSAntiguedadNick,0));
		return;
	}

    	char bufreg[BUFSIZE];
    	time_t ahora = time(NULL);
    	if (ahora < ngi->creg_time && !is_oper(u)) {
        	strftime_lang(bufreg, sizeof(bufreg), u->ngi,
                   	STRFTIME_DATE_TIME_FORMAT, ngi->creg_time);
        	privmsg(s_CregServ, u->nick, "No ha pasado %s desde tu última solicitud de registro de canal.", maketime(u->ngi,CRSSigRegistro,0));
        	privmsg(s_CregServ, u->nick, "La próxima solicitud la podrás realizar el: \2%s\2", bufreg);
        	return;
    	}


	Password passbuf;
	init_password(&passbuf);

       if (encrypt_password(pass, strlen(pass), &passbuf) != 0) {
            clear_password(&passbuf);
            memset(pass, 0, strlen(pass));
            module_log("Failed to encrypt password for %s (register)", chan);
            notice_lang(s_CregServ, u, CHAN_REGISTRATION_FAILED);
            return;
        }
	cr = makecreg(chan);
	if (!cr) {
		clear_password(&passbuf);
		module_log("makecreg() failed for REGISTER %s", chan);
		notice_lang(s_CregServ, u, CHAN_REGISTRATION_FAILED);
		return;
	}
	strbcpy(cr->foundernick, ni->nick);
	cr->flags |= CR_PROCESOREG;
	cr->founder = u->ngi->id;
	copy_password(&cr->founderpass, &passbuf);
        clear_password(&passbuf);
        cr->descr = sstrdup(desc);
        memset(pass, 0, strlen(pass));

    	time_t prox_solicitud;
    	prox_solicitud = CRSSigRegistro;
    	prox_solicitud += time(NULL);
    	ngi->creg_time = prox_solicitud;

	if (EnableDebug)
		logchan(NULL, "\2CREGSERV\2 \00312%s\003 ha solicitado el registro del canal \00312%s\003.", u->nick, chan);

	privmsg(s_CregServ, u->nick, "Has solicitado el registro del canal \00312%s\003.", chan);
	privmsg(s_CregServ, u->nick, "En el transcurso del día un operador de servicios evaluará la solicitud.");
	privmsg(s_CregServ, u->nick, "Para conocer el estado de su canal durante el proceso de registro escriba: \2/MSG %s ESTADO %s\2", s_CregServ, chan);
    }
}

static void do_pendientes(User *u)
{
    CregInfo *cr;
    char timebuf[BUFSIZE];

    int x=0;

    for (cr = first_creginfo(); cr; cr = next_creginfo()) {
        if (cr->flags & CR_PROCESOREG) {
		strftime_lang(timebuf, sizeof(timebuf), u->ngi,
                              STRFTIME_DATE_TIME_FORMAT, cr->time_registered);
		privmsg(s_CregServ, u->nick, "\2Canal:\2 %s, \2Fundador:\2 %s, \2Fecha:\2 %s, \2Descripcion:\2 %s", cr->name, cr->foundernick, timebuf, cr->descr);
		x++;
        }
    }

    if (x > 0)
	privmsg(s_CregServ, u->nick, "Fin de la Lista.");
    else
	privmsg(s_CregServ, u->nick, "No hay canales pendientes de evaluacion");
}

static void do_denegados(User *u)
{
    CregInfo *cr;

    int x=0;

    for (cr = first_creginfo(); cr; cr = next_creginfo()) {
        if (cr->flags & CR_DENEGADO) {
                privmsg(s_CregServ, u->nick, "\2Canal:\2 %s, \2Motivo:\2 %s", cr->name, cr->denegado_motivo);
                x++;
        }
    }

    if (x > 0)
        privmsg(s_CregServ, u->nick, "Fin de la Lista.");
    else
        privmsg(s_CregServ, u->nick, "No hay canales denegados.");

}


static void do_aprobar(User *u)
{
    char *chan = strtok(NULL, " ");
    NickInfo *ni = NULL;
    ChannelInfo *ci;
    Channel *c;
    CregInfo *cr;
    struct u_chaninfolist *uc;
    User *target_user;

    if (readonly) {
        notice_lang(s_CregServ, u, CHAN_REGISTER_DISABLED);
        return;
    }
    if (!chan) {
        privmsg(s_CregServ, u->nick, "\2Sintaxis:\2 \00312APROBAR <#Canal>\003");
    } else if (*chan != '#') {
	privmsg(s_CregServ, u->nick, "El nombre del canal debe empezar por un \2#\2");
    } else if ((ci = get_channelinfo(chan)) != NULL) {
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 ya se encuentra registrado con \0033%s\003", chan, s_ChanServ);
    } else if ((cr = get_creginfo(chan)) == NULL) {
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no se encuentra en proceso de registro", chan);
	return;
    } else if (cr &&  (cr->flags & CR_REGISTRADO)) {
	 privmsg(s_CregServ, u->nick, "El canal \00312%s\003 ya se encuentra registrado", chan);
    } else if (cr &&  (cr->flags & CR_DENEGADO)) {
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no puede ser registrado porque esta marcado como \00304DENEGADO\003", cr->name);
    } else {
	if (!(ni = get_nickinfo(cr->foundernick))) {
        	notice_lang(s_CregServ, u, NICK_X_NOT_REGISTERED, cr->foundernick);
        	notice_lang(s_CregServ, u, CHAN_DROPPED, cr->name);
		del_creginfo(cr);
		return;
	}

	ci = makechan(chan);
	if (!ci) {
		module_log("makechan() failed for REGISTER %s", chan);
		notice_lang(s_CregServ, u, CHAN_REGISTRATION_FAILED);
		return;
	}

	if (!(c = get_channel(chan))) {
		privmsg(s_CregServ, u->nick, "El canal \00312%s\003 se encuentra vacío, por favor ingresa al canal para poder aprobarlo.", chan);
		return;
	}

	c->ci = ci;
	ci->c = c;
	cr = get_creginfo(chan);
	ci->mlock.on = CSDefModeLockOn;
	ci->mlock.off = CSDefModeLockOff;
	ci->flags = CSDefFlags;
	ci->last_used = time(NULL);
	ci->founder = cr->founder;
	copy_password(&ci->founderpass, &cr->founderpass);
	ci->desc = sstrdup(cr->descr);
	ci->entry_message = sstrdup(CRSRegNotice);
	count_chan(ci);
	target_user = get_user(u->nick);
	if (target_user) {
		uc = smalloc(sizeof(*uc));
		LIST_INSERT(uc, target_user->id_chans);
		strbcpy(uc->chan, ci->name);
	}
	check_modes(ci->c);
	bdd_regchan(ci->name);
	if (EnableDebug)
		logchan(NULL, "\2CREGSERV\2 \00312%s\003 ha aprobado el registro del canal \00312%s\003.", u->nick, cr->name);

	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 ha sido correctamente registrado para \00312%s\003.", cr->name, cr->foundernick);
        cr->flags &= ~CR_PROCESOREG;
        cr->flags |= CR_REGISTRADO;
	strbcpy(cr->nickoper, u->nick);
	cr->time_aprobado = time(NULL);
	//del_creginfo(cr);
    }
}

static void do_denegar(User *u)
{
    char *chan = strtok(NULL, " ");
    char *reason = strtok_remaining();
    CregInfo *cr;

    if (!chan || !reason) {
	privmsg(s_CregServ, u->nick, "\2Sintaxis:\2 \00312DENEGAR <#canal> <motivo>\003");
    } else if (!(cr = get_creginfo(chan))) {
	 privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no tiene ningún proceso de registro.", chan);
    } else if (cr->flags & CR_REGISTRADO) {
	privmsg(s_CregServ, u->nick, "No se pueden denegar canales ya registrados y aprobados.");
    } else if (cr->flags & CR_DENEGADO) {
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 ya se encuentra denegado.", chan);
    } else {
	strbcpy(cr->denegado_nick, u->nick);
	cr->denegado_motivo  = sstrdup(reason);
	cr->denegado_time = time(NULL);
	cr->flags &= ~CR_PROCESOREG;
	cr->flags |= CR_DENEGADO;
	if (EnableDebug)
		 logchan(NULL, "\2CREGSERV\2 \00312%s\003 ha denegado el registro del canal \00312%s\003.", u->nick, chan);
	privmsg(s_CregServ, u->nick, "Se ha denegado el registro del canal \2%s\2.", cr->name);
    }
}

static void do_drop(User *u)
{
    char *chan = strtok(NULL, " ");
    CregInfo *cr;

    if (!chan) {
        privmsg(s_CregServ, u->nick, "\2Sintaxis:\2 \00312DROP <#canal>\003");
    } else if (!(cr = get_creginfo(chan))) {
        privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no esta registrado con \00303%s\003.", chan, s_CregServ);
    } else {
	if (EnableDebug)
		logchan(NULL, "\2CREGSERV\2 \00312%s\003 ha eliminado el canal \00312%s\003.", u->nick, chan);
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 se ha eliminado de \00303%s\003.", cr->name, s_CregServ);
	del_creginfo(cr);
	return;
    }
}


static void do_info(User *u)
{
    char *chan = strtok(NULL, " ");
    CregInfo *cr;
    char timebufreg[BUFSIZE], timebufden[BUFSIZE], timebufaprob[BUFSIZE];

    if (!chan) {
        privmsg(s_CregServ, u->nick, "\2ESTADO:\2 \00312INFO <#canal>\003");
        return;
    } else if (!(cr = get_creginfo(chan))) {
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no se encuentra registrado con \00303%s\003.", chan, s_CregServ);
    } else {
	privmsg(s_CregServ, u->nick, "Información del canal \00312%s\003", cr->name);
	if (cr->flags & CR_PROCESOREG)
		notice_lang(s_CregServ, u, CREG_ESTADO_ENPROCESO_REG);
	else if (cr->flags & CR_REGISTRADO)
		notice_lang(s_CregServ, u, CREG_ESTADO_REGISTRADO);
	else
		notice_lang(s_CregServ, u,CREG_ESTADO_DENEGADO);
	privmsg(s_CregServ, u->nick, "Fundador : %s", cr->foundernick);
	privmsg(s_CregServ, u->nick, "Descripción : %s", cr->descr);
	strftime_lang(timebufreg, sizeof(timebufreg), u->ngi,
		STRFTIME_DATE_TIME_FORMAT, cr->time_registered);
	privmsg(s_CregServ, u->nick, "Solicitado el : %s", timebufreg);
	if (cr->flags & CR_REGISTRADO) {
		 strftime_lang(timebufaprob, sizeof(timebufaprob), u->ngi,
			STRFTIME_DATE_TIME_FORMAT, cr->time_aprobado);
		privmsg(s_CregServ, u->nick, "Aprobado el : %s", timebufaprob);
		privmsg(s_CregServ, u->nick, "Aceptado por: %s", cr->nickoper);
	}
	if (cr->flags & CR_DENEGADO) {
		privmsg(s_CregServ, u->nick, "Denegado por : %s", cr->denegado_nick);
		privmsg(s_CregServ, u->nick, "Denegado el : %s", timebufden);
                strftime_lang(timebufden, sizeof(timebufden), u->ngi,
                              STRFTIME_DATE_TIME_FORMAT, cr->denegado_time);
		privmsg(s_CregServ, u->nick, "Motivo : %s", cr->denegado_motivo);
	}
    }
    privmsg(s_CregServ, u->nick, "Fin de INFO del canal \00312%s\003.", chan);
}

static void do_estado(User *u)
{
    char *chan = strtok(NULL, " ");
    ChannelInfo *ci;
    CregInfo *cr;

    if (!chan) {
        privmsg(s_CregServ, u->nick, "\2ESTADO:\2 \00312ESTADO <#canal>\003");
	return;
    } else if ((ci = get_channelinfo(chan)) != NULL) {
        if (ci->flags & CF_VERBOTEN)
                privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no puede ser registrado o utilizado.", ci->name);
        else if (ci->flags & CF_SUSPENDED)
                privmsg(s_CregServ, u->nick, "El canal \00312%s\003 se encuentra temporalmente \00304SUSPENDIDO\003.", chan);
        else
                privmsg(s_CregServ, u->nick, "El canal \00312%s\003 se encuentra registrado con \0033%s\003", chan, s_ChanServ);
        put_channelinfo(ci);
    } else if (!(cr = get_creginfo(chan))) {
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no tiene ningún proceso de registro.", chan);
    } else {
	if (cr) {
		if (cr->flags & CR_PROCESOREG) {
			privmsg(s_CregServ, u->nick, "El canal \00312%s\003 se encuentra en proceso de registro, a la espera de la revisión de algun OPERador de Servicios.", cr->name);
		} else if (cr->flags & CR_DENEGADO) {
			privmsg(s_CregServ, u->nick, "El canal \00312%s\003 está denegado.", cr->name);
			privmsg(s_CregServ, u->nick, "Motivo : %s", cr->denegado_motivo);
		}
	}
    }
}

static void do_status(User *u)
{
    char *chan = strtok(NULL, " ");
    ChannelInfo *ci;
    CregInfo *cr;

    if (!chan) {
        privmsg(s_CregServ, u->nick, "\2TSATUS:\2 \00312<#canal>\003");
        return;
    } else if ((ci = get_channelinfo(chan)) != NULL) {
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no puede ser solicitado para registro.", chan);
    } else if ((cr = get_creginfo(chan)) != NULL) {
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 no puede ser solicitado para registro.", chan);
    } else {
	privmsg(s_CregServ, u->nick, "El canal \00312%s\003 puede ser solicitado para registro.", chan);
    }
}

/*************************************************************************/

int exit_module(int shutdown_unused)
{
    if (linked)
        send_cmd(s_CregServ, "QUIT :");

    if (module_nickserv)
        do_unload_module(module_nickserv);

    unregister_dbtable(&creg_dbtable);

    remove_callback(NULL, "m_whois", do_whois);
    remove_callback(NULL, "m_privmsg", cregserv);
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
