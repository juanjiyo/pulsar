# Emacs: -*- mode: fundamental; coding: binary -*-

# Spanish language file.
#
# IRC Services is copyright (c) 1996-2009 Andrew Church.
#     E-mail: <achurch@achurch.org>
# Parts written by Andrew Kempe and others.
# This program is free but copyrighted software; see the file GPL.txt for
# details.

# When translating this file to another language, keep in mind that the
# order of parameters for sprintf() is fixed in the source code, so your
# messages need to take the same parameters in the same order as the
# English messages do.  (Obviously, this doesn't hold for the strftime()
# format lines immediately below.)  If you can't get a natural translation
# of a message without changing the order of the parameters, please inform
# the Services developers.
#
# In help messages, "%S" (capital S, not lowercase) refers to the name of
# the service sending the message; for example, in NickServ help messages,
# "%S" is replaced by "NickServ" (or whatever it is renamed to in
# config.h).  The %S's do not count as sprintf() parameters, so they can be
# rearranged, removed, or added as necessary.
#
# Also in help messages, please try to limit line lengths to 60 characters
# of text (not including the leading tab).  This length was chosen because
# it does not cause line wrap under default settings on most current IRC
# clients.  Remember that format characters (control-B, control-_) are not
# included in that 60-character limit (since they don't show on the user's
# screen).  Also remember that format specifiers (%S, etc.) will expand
# when displayed, so remember to take this into account; you can assume
# that the length of a pseudoclient name (%S replacement) will be eight
# characters, so reduce the maximum line length by 6 for every %S on a
# line.
#
# Finally, remember to put a tab at the beginning of every line of text
# (including empty lines).  This has to be a tab, not spaces.

###########################################################################
#
# Name and character set of this language
#
###########################################################################

# Language name.
# For languages other than English, this string should have the following
# format:
#     language-name-in-language (language-name-in-English)
# For example, "Español (Spanish)" or "Français (French)".

LANG_NAME
	Castellano (Spanish - Nick/Canal)

# Character set used by this language.  This should be a "charset" value
# understood by mailreader or web browser software.

LANG_CHARSET
	iso-8859-1

###########################################################################
#
# General messages
#
###########################################################################

# strftime() format strings.  man 3 strftime for information on the
# meanings of the format specifiers.  Short version:
#	%a = weekday name (short)	%H = hour
#	%b = month name (short)		%M = minute
#	%d = day of month		%S = second
#	%Y = year			%Z = time zone

# This is used as the format string for strftime() for a date and time
# together.
STRFTIME_DATE_TIME_FORMAT
	%H:%M:%S %d/%b/%Y
# This is used as the format string for strftime() for a date alone in long
# format (English: including weekday).
STRFTIME_LONG_DATE_FORMAT
	%a %b %d %Y
# This is used as the format string for strftime() for a date alone in
# short format (English: without weekday).
STRFTIME_SHORT_DATE_FORMAT
	%b %d %Y

# These tell our strftime() what the names of months and days are.  If you
# don't use %a, %A, %b, or %B in your strftime() strings above, you can
# leave these empty.  However, if you enter names, they MUST stay in order,
# one per line, and the list MUST be complete!

# %a
STRFTIME_DAYS_SHORT
	Dom
	Lun
	Mar
	Mie
	Jue
	Vie
	Sab
# %A
STRFTIME_DAYS_LONG
	Domingo
	Lunes
	Martes
	Miercoles
	Jueves
	Viernes
	Sabado
# %b
STRFTIME_MONTHS_SHORT
	Ene
	Feb
	Mar
	Abr
	May
	Jun
	Jul
	Ago
	Sep
	Oct
	Nov
	Dic
# %B
STRFTIME_MONTHS_LONG
	Enero
	Febrero
	Marzo
	Abril
	Mayo
	Junio
	Julio
	Agosto
	Septiembre
	Octubre
	Noviembre
	Diciembre


# "day", "hour", "minute", and "second" in singular and plural.
# These must be preceded by spaces if the language requires them
# (e.g. in English: "10 hours", not "10hours").
STR_DAY
	 día
STR_DAYS
	 días
STR_HOUR
	 hora
STR_HOURS
	 horas
STR_MINUTE
	 minuto
STR_MINUTES
	 minutos
STR_SECOND
	 segundo
STR_SECONDS
	 segundos
# Separator used between units of time; in English, a comma followed by a
# space (the ", " in "3 hours, 10 minutes").
STR_TIMESEP
	, 

# This is used in ChanServ/NickServ INFO displays, and is a comma followed
# by a space (", " -- trailing space is significant), or the equivalent in
# the language's character set.
COMMA_SPACE
	, 


# Various error messages.
INTERNAL_ERROR
	Error Interno - imposible procesar comando.
SERVICES_IS_BUSY
	Los servicios están muy ocupados en este momento, por favor intentelo de nuevo mas tarde.

UNKNOWN_COMMAND
	Comando desconocido 12%s.
UNKNOWN_COMMAND_HELP
	Comando desconocido 12%s. Escriba 12/msg %s HELP para obtener ayuda.
SYNTAX_ERROR
	Sintaxis: 12%s
MORE_INFO
	Escriba 12/msg %s HELP %s para más información.
NO_HELP_AVAILABLE
	No existe ayuda disponible para 12%s.
MISSING_QUOTE
	Faltan las doble comillas (").

BAD_EMAIL
	La dirección de correo electrónico debe ser en el formato 12Usuario@ProveedorWeb.  No debes usar colores, negritas, subrayado, ni reverso, o alguno de estos caracteres: , : ; | \ " ( ) < > [ ]
REJECTED_EMAIL
	Lo sentimos, esa dirección de correo electrónico no puede ser usada.
BAD_URL
	URLs deben ser en el formato 12http://ProveedorWeb[:puerto]/... (o ftp://, etc.).
BAD_USERHOST_MASK
	La máscara debe contener el formato 12ident@host.
BAD_NICKUSERHOST_MASK
	Máscara debe ser en el formato 12nick!Usuario@ProveedorWeb.
BAD_EXPIRY_TIME
	Fecha de expiración incorrecta.

SENDMAIL_NO_RESOURCES
	El sistema está actualmente demasiado ocupado para enviar correo, Por favor intentelo de nuevo más tarde.
READ_ONLY_MODE
	04NOTICIA: ¡Los Servicios están en modo de leer solamente, los cambios no serán grabados!
PASSWORD_INCORRECT
	04Contraseña incorrecta.

PASSWORD_WARNING
	04ADVERTENCIA: Despues de una contraseña incorrecta más usted será desconectado.

# What's the difference between "Access denied" and "Permission denied"?
# Very little; you can safely make them the same message with no real loss
# of meaning.  If you want to make a distinction, "Access denied" is
# usually used more generally; for example, a non-oper trying to access
# OperServ gets "Access denied", while a non-Services admin trying to use
# NickServ SET NOEXPIRE gets "Permission denied".
ACCESS_DENIED
	04Acceso denegado!.
PERMISSION_DENIED
	04Permiso denegado!.

MORE_OBSCURE_PASSWORD
	Por favor trate de nuevo con una contraseña más difícil. Las contraseñas deben ser de 5 caracteres mínimo y no debe ser algo fácil de descifrar. (Ejemplo: su verdadero nombre o su nick).

NICK_NOT_REGISTERED
	Su nick no está registrado.
NICK_NOT_REGISTERED_HELP
	Su nick no está registrado.  Escriba 12/msg %s HELP para más información de como registrar su nick.
NICK_TOO_LONG
	Los nicks no deben tener más de 12%d caracteres de largo.
NICK_INVALID
	12%s es un nick incorrecto.
NICK_X_NOT_REGISTERED
	El nick 12%s no está registrado.
NICK_X_ALREADY_REGISTERED
	¡El nick 12%s ya se encuentra registrado!
NICK_X_NOT_IN_USE
	El nick 12%s no está en uso en este momento.
NICK_X_FORBIDDEN
	El nick 12%s no puede ser registrado o utilizado.
NICK_X_SUSPENDED
	El nick 12%s está suspendido y no se puede utilizar o identificarse por él.
NICK_X_SUSPENDED_MEMOS
	El nick 12%s está suspendido y no puede recibir mensajes.
NICK_IDENTIFY_REQUIRED
	Es necesario estár identificando su contraseña para usar ese comando.
	Vuelva a intentarlo después de escribir 12/msg %s IDENTIFY Contraseña.
NICK_PLEASE_AUTH
	Su nick aún está sin autentificar. Por favor autentifique su nick usando el código de verificación incluido en el correo electrónico enviado a: 12%s
NICK_X_NOT_ON_CHAN_X
	El nick 12%s no está actualmente en el canal 12%s.

CHAN_INVALID
	12%s es un nombre incorrecto de canal.
CHAN_X_NOT_REGISTERED
	El canal 12%s no está registrado.
CHAN_X_NOT_IN_USE
	El canal 12%s no existe (está vacio).
CHAN_X_FORBIDDEN
	El canal 12%s no puede ser registrado o utilizado.
CHAN_X_SUSPENDED
	El canal 12%s está suspendido y no se puede utilizar o identificarse por él.
CHAN_X_SUSPENDED_MEMOS
	El canal 12%s está suspendido y no puede recibir mensajes.
CHAN_IDENTIFY_REQUIRED
	Es necesario identificarse con su contraseña para usar ese comando.
	Vuelva a intentarlo después de escribir 12/msg %s IDENTIFY %s Contraseña.

SERV_X_NOT_FOUND
	El servidor 12%s no fue encontrado.

EXPIRES_NONE
	no expira
EXPIRES_NOW
	expiró
EXPIRES_IN
	expira en 12%s
LIST_RESULTS
	Fin del listado; 12%d/%d asociaciones visibles.

###########################################################################
#
# NickServ messages
#
###########################################################################

# Automatic messages
NICK_IS_REGISTERED
	Este nick pertence a otra persona. Por favor escoja otro.  (Si este es su nick, escriba 12/msg %s IDENTIFY Contraseña.)
NICK_IS_SECURE
	Este nick está registrado y protegido.  Si es su nick, escriba 12/msg %s IDENTIFY Contraseña. De lo contrario, debe escoger un nick diferente.
NICK_MAY_NOT_BE_USED
	Este nick no puede utilizarse. Por favor escoja otro.
DISCONNECT_IN_1_MINUTE
	Si no cambia su nick dentro de 12un minuto, será desconectado.
DISCONNECT_IN_20_SECONDS
	Si no cambia su nick dentro de 1220 segundos, será desconectado.
DISCONNECT_NOW
	Este nick ha sido registrado y no lo puedes utilizar. Por favor escoja otro nick antes de reconectar.
FORCENICKCHANGE_IN_1_MINUTE
	Si no cambia su nick dentro de 12un minuto, le será cambiado automáticamente.
FORCENICKCHANGE_IN_20_SECONDS
	Si no cambia su nick dentro de 1220 segundos, le será cambiado automáticamente.
FORCENICKCHANGE_NOW
	Este nick ha sido registrado y no lo puedes utilizar. Su nick está ahóra siendo cambiado a 12%s.
NICK_EXPIRES_SOON
	04NOTA: El registro de su nick expirará en 12%s. Si usted desea continuar utilizando su nick, por favor identifiquese a 12%s Escribiendo: 12/msg %s IDENTIFY Contraseña
NICK_EXPIRED
	12NOTA: El registro de su nick ha expirado. Por favor re-registre su nick si usted desea continuar utilizandolo.

# REGISTER responses
NICK_REGISTER_SYNTAX
	12REGISTER  12direccion@correo.electrónico
NICK_REGISTER_REQ_EMAIL_SYNTAX
	12REGISTER 12direccion@correo.electrónico 
NICK_REGISTRATION_DISABLED
	Lo sentimos, el regístro de nicks está temporaralmente deshabilitado.
NICK_REGISTRATION_FAILED
	Lo sentimos, el registró falló.
NICK_REG_PLEASE_WAIT
	Por favor espere 12%s antes de utilizar nuevamente el comando 12REGISTER.
NICK_REG_PLEASE_WAIT_FIRST
	Por favor espere 12%s antes de utilizar el comando 12REGISTER.
NICK_CANNOT_BE_REGISTERED
	El nick 12%s no puede ser registrado.
NICK_REGISTER_EMAIL_UNAUTHED
	La dirección de correo electrónico (E-mail) que usted provió no ha sido aún autenticada. Por favor use el comando 12AUTH para autenticar la dirección antes de registrar un nuevo nick con ella.
NICK_REGISTER_TOO_MANY_NICKS
	Usted tiene demasiados nicks registrados (12%d, máximo de 12%d).  No puede registrarse más a menos que cancele algunos de sus nicks actuales.
NICK_REGISTERED
	El nick 12%s ha sido registrado por usted.
NICK_PASSWORD_IS
	Su contraseña es 12%s -- recuerde esto para usos posteriores.

# IDENTIFY responses
NICK_IDENTIFY_SYNTAX
	12IDENTIFY 12Contraseña
NICK_IDENTIFY_FAILED
	Lo sentimos, la identificación falló.
NICK_IDENTIFY_EMAIL_MISSING
	Usted debe fijar una dirección de correo electrónico para su nick antes de continuar usandolo. Por favor fije una ahóra con el comando: 12/msg %s SET EMAIL Dirección
NICK_IDENTIFY_SUCCEEDED
	03Contraseña aceptada. Bienvenid@ a casa ;).

# DROP responses
NICK_DROP_SYNTAX
	12DROP Contraseña
NICK_DROP_WARNING
	04NOTA: ¡El comando 12DROP cancelará todos sus nicks asociados!
NICK_DROP_DISABLED
	Lo sentimos, la cancelación de nicks ha sido temporaralmente deshabilatada.
NICK_DROP_FAILED
	Lo sentimos, la cancelación del nick falló.
NICK_DROPPED
	Su nick ha sido cancelado.
NICK_DROPPED_LINKS
	Su nick y todos los nicks asociados han sido cancelados.

# DROPNICK responses
NICK_DROPNICK_SYNTAX
	12DROPNICK nick
NICK_X_DROPPED
	El nick 12%s ha sido cancelado.
NICK_X_DROPPED_LINKS
	El nick 12%s y todos los nicks asociados han sido cancelados.

# DROPEMAIL and DROPEMAIL-CONFIRM responses
NICK_DROPEMAIL_SYNTAX
	12DROPEMAIL Patrón
NICK_DROPEMAIL_PATTERN_TOO_LONG
	El patrón dado es demaciado largo (12%d caractéres máximo).
NICK_DROPEMAIL_NONE
	Ningún nick tiene una dirección de correo electrónico que concuerde con el patrón especificado.
NICK_DROPEMAIL_COUNT
	12%d nicks tienen direcciónes de correo electrónico que concuerdan con el patrón especificado.
	Para cancelar estos nicks, escriba: 12/msg %s DROPEMAIL-CONFIRM %s
NICK_DROPEMAIL_CONFIRM_SYNTAX
	12DROPEMAIL-CONFIRM Patrón
NICK_DROPEMAIL_CONFIRM_UNKNOWN
	El patrón especificado no es reconocido.  Por favor utilice el comando 12DROPEMAIL nuevamente con este patrón antes de usar el comando 12DROPEMAIL-CONFIRM.
NICK_DROPEMAIL_CONFIRM_DROPPING
	Cancelando 12%d nicks...
NICK_DROPEMAIL_CONFIRM_DROPPED
	Cancelación de nicks completado.

# SET responses
NICK_SET_SYNTAX
	12SET Opción Parámetros
NICK_SET_OPER_SYNTAX
	12SET [!nick] Opción Parámetros
NICK_SET_DISABLED
	Lo sentimos, la configuración de opciones del nick está temporalmente deshabilitada.
NICK_SET_UNKNOWN_OPTION
	Opción SET desconocida 12%s.

# SET PASSWORD responses
NICK_SET_PASSWORD_FAILED
	Lo sentimos, la contraseña no se pudo cambiar.
NICK_SET_PASSWORD_CHANGED
	Contraseña cambiada.
NICK_SET_PASSWORD_CHANGED_TO
	Contraseña cambiada a 12%s.

# SET LANGUAGE responses
NICK_SET_LANGUAGE_SYNTAX
	12SET LANGUAGE Número
NICK_SET_LANGUAGE_UNKNOWN
	Número 12%d de lenguaje desconocido.  Escriba 12/msg %s HELP SET LANGUAGE para ver la lista de lenguajes disponibles.
NICK_SET_LANGUAGE_CHANGED
	Lenguaje cambiado a 12%s.

# SET URL responses
NICK_SET_URL_CHANGED
	URL para 12%s cambiado a 12%s.

# SET EMAIL responses
NICK_SET_EMAIL_PLEASE_WAIT
	Por favor espere 12%s antes de usar el comando 12SET EMAIL nuevamente.
NICK_SET_EMAIL_UNAUTHED
	La dirección de correo electrónico que usted proporcionó no ha sido aún autenticada. Por favor use el comando 12AUTH para autenticar la dirección primeramente.
NICK_SET_EMAIL_TOO_MANY_NICKS
	%s ya tiene %d nicks registrados (máximo de %d).  El cambio de correo-electrónico falló
NICK_SET_EMAIL_CHANGED
	Correo electrónico (EMAIL) para 12%s cambiado a 12%s.

# SET INFO responses
NICK_SET_INFO_CHANGED
	Información para 12%s cambiada.

# SET KILL responses
NICK_SET_KILL_SYNTAX
	12SET KILL {ON | QUICK | OFF}
NICK_SET_KILL_IMMED_SYNTAX
	12SET KILL {ON | QUICK | IMMED | OFF}
NICK_SET_KILL_ON
	Protección de KILL ahóra 03Activada (ON).
NICK_SET_KILL_QUICK
	Protección de KILL ahóra 03Activada (ON), con una espera reducida.
NICK_SET_KILL_IMMED
	Protección de KILL 03Activada (ON), sin espera reducida.
NICK_SET_KILL_IMMED_DISABLED
	La opción 12IMMED no está disponible en esta red.
NICK_SET_KILL_OFF
	Protección de KILL está ahóra 04Desactivada (OFF).

# SET SECURE responses
NICK_SET_SECURE_SYNTAX
	12SET SECURE {ON | OFF}
NICK_SET_SECURE_ON
	Opción SECURE ahóra 03Activada (ON).
NICK_SET_SECURE_OFF
	Opción SECURE ahóra 04Desactivada (OFF).

# SET PRIVATE responses
NICK_SET_PRIVATE_SYNTAX
	12SET PRIVATE {ON | OFF}
NICK_SET_PRIVATE_ON
	Opción PRIVATE ahóra 03Activada (ON).
NICK_SET_PRIVATE_OFF
	Opción PRIVATE ahóra 04Desactivada (OFF).

# SET NOOP responses
NICK_SET_NOOP_SYNTAX
	12SET NOOP {ON | OFF}
NICK_SET_NOOP_ON
	Opción NOOP ahóra 3Activada (ON).
NICK_SET_NOOP_OFF
	Opción NOOP ahora 4Desactivada (OFF).

# SET HIDE responses
NICK_SET_HIDE_SYNTAX
	12SET HIDE {EMAIL | USERMASK | QUIT} {ON | OFF}
NICK_SET_HIDE_EMAIL_ON
	Su correo electrónico será ahóra ocultada en la opción de 12%s INFO.
NICK_SET_HIDE_EMAIL_OFF
	Su correo electrónico será ahóra visible en la opción de 12%s INFO.
NICK_SET_HIDE_MASK_ON
	Su última máscara de Usuario@ProveedorWeb será ahóra ocultada en la opción de 12%s INFO.
NICK_SET_HIDE_MASK_OFF
	Su última máscara de Usuario@ProveedorWeb será ahóra visible en la opción de 12%s INFO.
NICK_SET_HIDE_QUIT_ON
	Su último mensaje de salida será ahóra ocultado en la opción de 12%s INFO.
NICK_SET_HIDE_QUIT_OFF
	Su último mensaje de salida será ahóra visible en la opción de 12%s INFO.

# SET TIMEZONE responses
NICK_SET_TIMEZONE_SYNTAX
	12SET TIMEZONE {UTC-Más/Menos | Uso-Horario | DEFAULT}
NICK_SET_TIMEZONE_TO
	Su uso horario ha sido ajustado a 12UTC%c%d:%02d.
	La hora actual en este uso horario es 12%s.
NICK_SET_TIMEZONE_DEFAULT
	Su uso horario ha sido re-ajustado al uso horario de los Servicios.

# SET MAINNICK responses
NICK_SET_MAINNICK_NOT_FOUND
	El nick 12%s no está asociado al nick de usted.
NICK_SET_MAINNICK_CHANGED
	Su nick principal ha sido cambiado a 12%s.

# SET NOEXPIRE responses
NICK_SET_NOEXPIRE_SYNTAX
	12SET [!nick] NOEXPIRE {ON | OFF}
NICK_SET_NOEXPIRE_ON
	El nick 12%s no expirará.
NICK_SET_NOEXPIRE_OFF
	El nick 12%s si expirará.

# Respuestas de SET
NICK_SET_OPCION_YA_ACTIVADA
	Ya tienes activada la opción 12%s para tu nick.
NICK_SET_OPCION_ACTIVADA
	La opción 12%s ha sido activada para tu nick.
NICK_SET_OPCION_NO_ACTIVADA
	No tienes activada la opción 12%s para tu nick.
NICK_SET_OPCION_DESACTIVADA
	La opción 12%s ha sido desactivada para tu nick.
NICK_SET_PARAMETRO_INVALIDO
	Parámetro incorrecto para 12%s

# UNSET responses
NICK_UNSET_SYNTAX
	12UNSET {URL | EMAIL | INFO}
NICK_UNSET_SYNTAX_REQ_EMAIL
	12UNSET {URL | INFO}
NICK_UNSET_OPER_SYNTAX
	12UNSET [!nick] {URL | EMAIL | INFO}
NICK_UNSET_OPER_SYNTAX_REQ_EMAIL
	12UNSET [!nick] {URL | INFO}
NICK_UNSET_URL
	URL para 12%s está ahóra Indefinido (Unset).
NICK_UNSET_EMAIL
	Correo electrónico (EMAIL) para 12%s está ahóra Indefinido (Unset).
NICK_UNSET_INFO
	Información para 12%s está ahóra Indefinida (Unset).
NICK_UNSET_EMAIL_BAD
	Usted no puede remover su correo electrónico (EMAIL).
NICK_UNSET_EMAIL_OTHER_BAD
	El correo electrónico de los nicks no puede ser removida.

# ACCESS responses
NICK_ACCESS_SYNTAX
	12ACCESS {ADD | DEL | LIST} [Máscara]
NICK_ACCESS_DISABLED
	Lo sentimos, modificación a la lista de acceso del nick está temporalmente deshabilitada.
NICK_ACCESS_ALREADY_PRESENT
	Máscara 12%s ya existe en su lista de acceso.
NICK_ACCESS_REACHED_LIMIT
	Lo sentimos, solamente puede tener 12%d entradas de acceso para su nick.
NICK_ACCESS_NO_NICKS
	04ADVERTENCIA: Las máscaras de acceso de nicks no deben incluír nicks.  Por favor verifique y asegurarse de que ha ingresado la máscara 12Usuario@Proveedor correctamente.
NICK_ACCESS_ADDED
	12%s añadido a su lista de acceso.
NICK_ACCESS_NOT_FOUND
	12%s no fue encontrado en su lista de acceso.
NICK_ACCESS_DELETED
	12%s eliminado de su lista de acceso.
NICK_ACCESS_LIST_EMPTY
	Su lista de acceso está vacía.
NICK_ACCESS_LIST
	Lista de acceso:
NICK_ACCESS_LIST_X_EMPTY
	Lista de acceso para 12%s está vacía.
NICK_ACCESS_LIST_X
	Lista de acceso para 12%s:

# LINK responses
NICK_OLD_LINK_SYNTAX
	12LINK nick Contraseña
NICK_LINK_SYNTAX
	12LINK nick
NICK_LINK_DISABLED
	Lo sentimos, el asociado de nicks esta temporalmente deshabilitado.
NICK_LINK_FAILED
	Lo sentimos, asocia de nick falló.
NICK_CANNOT_BE_LINKED
	El nick 12%s no puede ser asociado.
NICK_OLD_LINK_SAME
	¡No puede asociar su nick actual!
NICK_LINK_SAME
	¡No puede asociar su nick actual!
NICK_LINK_ALREADY_LINKED
	El nick 12%s ya está asociado al nick de usted.
NICK_LINK_IN_USE
	El nick 12%s está siendo usado en este momento.
NICK_LINK_TOO_MANY
	Usted no puede tener más de 12%d nicks asociados a una misma asocia.
NICK_LINK_TOO_MANY_NICKS
	Usted ya tiene 12%d nicks registrados (el máximo es 12%d).  la asocia falló.
NICK_OLD_LINK_TOO_MANY_CHANNELS
	No fue posible asociar el nick 12%s: demasiados canales registrados (combinación máxima 12%d).
NICK_OLD_LINKED
	Su nick ha sido asociado a 12%s.
NICK_LINKED
	El nick 12%s ha sido asociado a su nick actual.

# UNLINK responses
NICK_OLD_UNLINK_SYNTAX
	12UNLINK [nick Contraseña]
NICK_UNLINK_SYNTAX
	12UNLINK nick
NICK_UNLINK_OPER_SYNTAX
	12UNLINK nick [FORCE]
NICK_UNLINK_DISABLED
	Lo sentimos, el desasociado de nicks esta temporalmente deshabilitado.
NICK_UNLINK_FAILED
	Lo sentimos, la asocia no pudo ser removida.
NICK_UNLINK_SAME
	¡Usted no puede remover una asocia de un nick mientras lo está usando!
NICK_OLD_UNLINK_NOT_LINKED
	Su nick no está asociado.
NICK_UNLINK_NOT_LINKED_YOURS
	El nick 12%s no está asociado a su nick.
NICK_UNLINK_NOT_LINKED
	El nick 12%s no está asociado.
NICK_OLD_UNLINKED
	Su nick ha sido desasociado de 12%s.
NICK_UNLINKED
	El nick 12%s ha sido desasociado del nick de usted.
NICK_X_UNLINKED
	El nick 12%s ha sido desasociado de 12%s.

# LISTLINKS responses
NICK_OLD_LISTLINKS_SYNTAX
	12LISTLINKS nick
NICK_LISTLINKS_SYNTAX
	12LISTLINKS
NICK_LISTLINKS_HEADER
	Lista de nicks asociados a 12%s:
NICK_LISTLINKS_FOOTER
	12%d nicks asociados.

# INFO responses
NICK_INFO_SYNTAX
	12INFO nicks
NICK_INFO_REALNAME
	12%s es 12%s
NICK_INFO_ADDRESS
	  Última dirección vista: 12%s
NICK_INFO_ADDRESS_ONLINE
	  Está en línea usando: 12%s
NICK_INFO_ADDRESS_ONLINE_NOHOST
	12%s está actualmente en línea.
NICK_INFO_ADDRESS_OTHER_NICK
	Está usando el nick: 12%s
NICK_INFO_TIME_REGGED
	Fecha de registro: 12%s
NICK_INFO_LAST_SEEN
	Ultima hora por la red: 12%s
NICK_INFO_LAST_QUIT
	Último mensaje de salida: 12%s
NICK_INFO_URL
	URL: 12%s
NICK_INFO_EMAIL
	Correo electrónico: 12%s
NICK_INFO_EMAIL_UNAUTHED
	Correo electrónico: 12%s (No-Verificado)
NICK_INFO_INFO
	Información: 12%s
NICK_INFO_OPTIONS
	Opciones: 12%s
# These strings MUST NOT be empty
NICK_INFO_OPT_KILL
	Protección de KILL
NICK_INFO_OPT_SECURE
	Seguro
NICK_INFO_OPT_PRIVATE
	Privado
NICK_INFO_OPT_NOOP
	No-op
NICK_INFO_OPT_NONE
	Ninguna
NICK_INFO_NO_EXPIRE
	Este nick no expirará.
NICK_INFO_SUSPEND_DETAILS
	Suspendido por 12%s en 12%s (12%s).
NICK_INFO_SUSPEND_REASON
	Razón: 12%s
NICK_INFO_SHOW_ALL
	Para más información, escriba: 12/msg %s INFO %s ALL

# LISTCHANS responses
NICK_LISTCHANS_SYNTAX
	12LISTCHANS
NICK_LISTCHANS_NONE
	12%s no ha registrado canal alguno.
NICK_LISTCHANS_HEADER
	Canales registrados por 12%s:
NICK_LISTCHANS_END
	Fin del listado (12%d canales registrados).

# LIST responses
NICK_LIST_SYNTAX
	12%s [+Inicio] Patrón
NICK_LIST_OPER_SYNTAX
	12%s [+Inicio] Patrón [FORBIDDEN] [NOEXPIRE] [SUSPENDED]
NICK_LIST_OPER_SYNTAX_AUTH
	12%s [+Inicio] Patrón [FORBIDDEN] [NOEXPIRE] [SUSPENDED] [NOAUTH]
NICK_LIST_HEADER
	Lista de entradas similares a 12%s:
NICK_LIST_NO_MATCH
	No se encontraron nicks similares
NICK_LISTEMAIL_NONE
	(Ninguno fijado)

# RECOVER responses
NICK_RECOVER_SYNTAX
	12RECOVER nick [Contraseña]
NICK_NO_RECOVER_SELF
	¡Usted no puede utilizar el comando 12RECOVER en usted mismo!
NICK_RECOVERED
	El usuario que reclamaba su nick ha sido desconectado.
	Escriba 12/msg %s RELEASE %s Contraseña para recuperarlo ahóra y no esperar a un minuto.

# RELEASE responses
NICK_RELEASE_SYNTAX
	12RELEASE nick [Contraseña]
NICK_RELEASE_NOT_HELD
	El nick 12%s no está siendo retenido.
NICK_RELEASED
	La retención de su nick por los Servicios ha sido liberada.

# GHOST responses
NICK_GHOST_SYNTAX
	12GHOST nick [Contraseña]
NICK_NO_GHOST_SELF
	¡No puede usar el comando 12GHOST en usted mismo!
NICK_GHOST_KILLED
	El invisible con su nick ha sido desconectado.

# GETPASS responses
NICK_GETPASS_SYNTAX
	12GETPASS nick
NICK_GETPASS_UNAVAILABLE
	El comando 12GETPASS no está disponible para el nick 12%s porque se está usando encripción.
NICK_GETPASS_PASSWORD_IS
	Contraseña para 12%s es 12%s.

# FORBID responses
NICK_FORBID_SYNTAX
	12FORBID nick
NICK_FORBID_SUCCEEDED
	El nick 12%s está ahóra prohibido.
NICK_FORBID_FAILED
	¡No se pudo prohibir el nick 12%s!

# UNFORBID responses
NICK_UNFORBID_SYNTAX
	12UNFORBID nick
NICK_UNFORBID_SUCCEEDED
	El nick 12%s ha sido eliminado.	

# SUSPEND responses
NICK_SUSPEND_SYNTAX
	12SUSPEND [+Expiración] nick Razón
NICK_SUSPEND_SUCCEEDED
	El nick 12%s, ha sido suspendido.
NICK_SUSPEND_ALREADY_SUSPENDED
	El nick 12%s ya está suspendido.

# UNSUSPEND responses
NICK_UNSUSPEND_SYNTAX
	12UNSUSPEND nick
NICK_UNSUSPEND_SUCCEEDED
	El nick 12%s ya no está suspendido.
NICK_UNSUSPEND_NOT_SUSPENDED
	El nick 12%s no está suspendido.

################ autojoin module messages/responses

# AJOIN responses
NICK_AJOIN_SYNTAX
	12AJOIN {ADD | DEL | LIST} [canal]
NICK_AJOIN_ADD_SYNTAX
	12AJOIN ADD canal
NICK_AJOIN_DEL_SYNTAX
	12AJOIN DEL canal
NICK_AJOIN_DISABLED
	Lo sentimos, modificación a la lista de Auto-Ingreso está temporalmente deshabilitada.
NICK_AJOIN_ALREADY_PRESENT
	El canal %s ya está presente en su lista autojoin (Auto-Ingreso).
NICK_AJOIN_LIST_FULL
	Lo sentimos, solo puedes tener %d entradas de autojoin (Auto-Ingreso) por cada nick.
NICK_AJOIN_ADDED
	12%s agregado a su lista autojoin (Auto-Ingreso).
NICK_AJOIN_NOT_FOUND
	12%s no fue encontrado en su lista autojoin (Auto-Ingreso).
NICK_AJOIN_DELETED
	12%s removido de su lista autojoin (Auto-Ingreso).
NICK_AJOIN_LIST_EMPTY
	Su lista autojoin (Auto-Ingreso) está vacía.
NICK_AJOIN_LIST
	Lista Autojoin (Auto-Ingreso):
NICK_AJOIN_LIST_X_EMPTY
	Lista Autojoin (Auto-Ingreso) para 12%s está vacía.
NICK_AJOIN_LIST_X
	Lista Autojoin (Auto-Ingreso) para 12%s:
NICK_AJOIN_AUTO_REMOVE
	El canal 12%s ha sido removido de su lista de auto-ingreso porque no es un nombre de canal válido..

################ mail-auth module messages/responses

# General-purpose messages
NICK_AUTH_SENDING
	Un código de autenticación para su nick está siendo enviando a 12%s.
NICK_AUTH_FOR_REGISTER
	Cuando reciba este mensaje, escriba 12/msg %s AUTH Código (reemplace Código por el código de autenticación incluido en el mensaje) para completar la registración de su nick.
NICK_AUTH_FOR_SET_EMAIL
	Cuando reciba este mensaje, escriba 12/msg %s AUTH Código (reemplace Código por el código de autenticación incluido en el mensaje) para completar el cambio a su dirección E-mail (Correo-electrónico)
	Por favor que usted no podrá continuar usando su nick a menos que complete el cambio.
NICK_AUTH_NOT_NEEDED
	No existe nada que necesite autenticación en este momento.
NICK_AUTH_NO_AUTHCODE
	El nick 12%s no tiene código de autenticación.
NICK_AUTH_HAS_AUTHCODE
	El nick 12%s ya tiene un código de autenticación.
PASSWORD_WARNING_FOR_AUTH
	04ADVERTENCIA: Despues de otro código de autenticación incorrecto usted será desconectado.

# Mail text.  The last "%s" (before the user@host) in the body text is
# replaced by one of the NICK_AUTH_MAIL_TEXT_* messages.
NICK_AUTH_MAIL_SUBJECT
	Código de autenticación para %s
NICK_AUTH_MAIL_BODY
	El código de autenticación para su nick (%s) es: %09d
	Favor de ingresar este código a %s con el comando:
	    /msg %s AUTH %09d
	
	Este mensaje fue enviado por %s en respuesta a %s
	%s@%s.
NICK_AUTH_MAIL_TEXT_REG
	registración por
NICK_AUTH_MAIL_TEXT_EMAIL
	un cambio de E-mail (Correo-Electrónico) por
NICK_AUTH_MAIL_TEXT_SENDAUTH
	un comando SENDAUTH de
NICK_AUTH_MAIL_TEXT_REAUTH
	un comando REAUTH de
NICK_AUTH_MAIL_BODY_SETAUTH
	El código de autenticación para su nick (%s) es: %09d
	Favor de ingresar este código a %s con el comando:
	    /msg %s AUTH %09d

# AUTH responses
NICK_AUTH_SYNTAX
	12AUTH Código
NICK_AUTH_DISABLED
	Lo sentimos, La autenticación de nicks está temporaralmente deshabilatada.
NICK_AUTH_FAILED
	Ese código de autenticación es incorrecto.
NICK_AUTH_SUCCEEDED_REGISTER
	Autenticación exitosa; la registración de su nick ha sido completada.
NICK_AUTH_SUCCEEDED_SET_EMAIL
	Autenticación exitosa; su cambio de E-mail (Correo-Electrónico) ha sido completado.
NICK_AUTH_SUCCEEDED_REAUTH
	Autenticación exitosa; te has identificado por tu nick ahora.
NICK_AUTH_SUCCEEDED_SETAUTH
	Autenticación exitosa; puedes continuar usando tu nick ahóra.

# SENDAUTH responses
NICK_SENDAUTH_SYNTAX
	12SENDAUTH
NICK_SENDAUTH_TOO_SOON
	Por favor espere 12%s antes de usar el comando 12SENDAUTH nuevamente.
NICK_SENDAUTH_NORESOURCES
	El mensaje que contenía su código de autenticación no pudo ser enviado porque el sistema está muy ocupado. Por favor intentelo de nuevo mas tarde o contacte con un administrador de la red.
NICK_SENDAUTH_ERROR
	El mensaje que contenía su código de autenticación no pudo ser enviado debido a un problema en el sistema. Por favor intentelo de nuevo mas tarde o contacte con un administrador de la red.

# REAUTH responses
NICK_REAUTH_SYNTAX
	12REAUTH
NICK_REAUTH_HAVE_AUTHCODE
	Un código de autenticación está ya fijado para su nick.
NICK_REAUTH_NO_EMAIL
	Su nick no tiene fijada una dirección de correo electrónico.
NICK_REAUTH_AUTHCODE_SET
	Un nuevo código de autenticación ha sido fijado para su nick, y le será enviado en breve.  Use ese código con el comando AUTH para indentificarse por su nick.

# RESTOREMAIL responses
NICK_RESTOREMAIL_SYNTAX
	12RESTOREMAIL Contraseña
NICK_RESTOREMAIL_NOT_NOW
	12RESTOREMAIL solo puede usarse despues de cambiar su dirección de correo electrónico , y antes de autenticar la dirección nueva.
NICK_RESTOREMAIL_DONE
	Su dirección previa de correo electrónico 12%s ha sido restaurada.

# SETAUTH responses
NICK_SETAUTH_SYNTAX
	12SETAUTH nick
NICK_SETAUTH_NO_EMAIL
	El nick 12%s no tiene un E-mail (Correo-Electrónico) establecido.
NICK_SETAUTH_AUTHCODE_SET
	Un nuevo código de autenticación (12%09d) ha sido fijado para el nick 12%s.
NICK_SETAUTH_SEND_REFUSED
	Advertencia: no fue posible enviar correo a %s (el mensaje fue bloqueado por el servidor de correo).
NICK_SETAUTH_SEND_TIMEOUT
	04ADVERTENCIA: no fue posible enviar correo a 12%s (fue imposible conectar o enviar al servidor de correo).
NICK_SETAUTH_SEND_NORESOURCES
	04ADVERTENCIA: no fue posible enviar correo a 12%s (insuficientes recursos).
NICK_SETAUTH_SEND_ERROR
	04ADVERTENCIA: no fue posible enviar correo a 12%s (error desconocido).
NICK_SETAUTH_USER_NOTICE
	Usted debe autenticar su nick antes de continuar usandolo.  Un código de autenticación ha sido enviado a su E-mail (Correo-Electrónico): 12%s
	Escriba: 12/msg %s HELP AUTH para más información.

# GETAUTH responses
NICK_GETAUTH_SYNTAX
	12GETAUTH nick
NICK_GETAUTH_AUTHCODE_IS
	El código de autenticación para el nick 12%s es: 12%09d

# CLEARAUTH responses
NICK_CLEARAUTH_SYNTAX
	12CLEARAUTH nick
NICK_CLEARAUTH_CLEARED
	El código de autenticación para el nick 12%s ha sido removido.

NICK_EMAIL_REGISTER
	Hola %s,
	 
	Bienvenido a %s. Gracias al registro en nuestro chat podrás:
	 
	1. Chatear en tiempo real con tus conocidos o conocer gente nueva.
	2. Crear tus propias salas de chat o comunidades en la red.
	3. Tener acceso a servicios avanzados dentro del chat.
	 
	--------------------------------------------------------------------------------
	 
	INFORMACIÓN DE REGISTRO:
	 
	E-Mail de registro: %s
	Nick: %s
	Contraseña: %s
	  
	+ Para identificarte escribe: /nick %s:%s
	+ Para cambiar la clave por otra que prefieras: /msg %s SET PASSWORD nueva_clave
	+ En caso olvides tu clave escribe: /msg %s RESETPASS %s %s
	  
	INFORMACIÓN LEGAL DEL REGISTRO:
	  
	Para completar el registro deberás acceder a nuestra red de chat con tu nick y la contraseña temporal que te hemos facilitado.
	En caso no ingreses en un plazo maximo de 24 horas tu pre-registro sera eliminado de nuestro sistema.	
	 
	Para mas información puedes visitar nuestro sitio web %s 
	 	 
	Atentamente el equipo de %s.

NICK_EMAIL_REQPASSWORD
	Hola %s,
	  
	Has solicitado restablecer la contraseña del nick %s en %s porque has olvidado la contraseña.
	Si no has hecho esta solicitud, por favor ignora este mensaje. Expirará y se volvera inutilizable en 24 horas.
	 
	Para restablecer tu contraseña, por favor escribe lo siguiente:
	/msg %s CONFIRMRESET %s %09d
	 
	Cuando lo escribas, tu contraseña será restablecida, y la nueva contraseña se te enviará por correo.
	 
	 
	Saludos Cordiales,
	Equipo de %s.

NICK_EMAIL_GETNEWPASS
	Hola %s,
	 
	Conforme a tu solicitud, tu contraseña se ha restablecida.
	 
	--------------------------------------------------------------------------------
	 
	INFORMACIÓN DE IDENTIFICACION:
	 
	Nick: %s
	Contraseña: %s
	 
	+ Para identificarte escribe: /nick %s:%s
	+ Para cambiar la clave por otra que prefieras: /msg %s SET PASSWORD nueva_clave
	 
	 
	Atentamente el equipo de %s.

###########################################################################
#
# ChanServ messages
#
###########################################################################

# Access level descriptions
CHAN_LEVEL_AUTOOP
	Status de operador de canal (autoop) automático
CHAN_LEVEL_AUTOVOICE
	Modo +v automático
CHAN_LEVEL_INVITE
	Se Permite la utilización del comando INVITE
CHAN_LEVEL_AKICK
	Se Permite la utilización del comando AKICK
CHAN_LEVEL_SET
	Se Permite la utilización del comando SET (no siendo FUNDADOR)
CHAN_LEVEL_CLEAR
	Se Permite usar comando CLEAR
CHAN_LEVEL_UNBAN
	Se Permite usar comando UNBAN
CHAN_LEVEL_OPDEOP
	Se Permite usar comandos OP/DEOP
CHAN_LEVEL_ACCESS_LIST
	Se Permite ver lista de acceso
CHAN_LEVEL_ACCESS_CHANGE
	Se Permite modificar lista de acceso
CHAN_LEVEL_MEMO
	Se Permite recibir mensajes del canal
CHAN_LEVEL_VOICE
	Se Permite usar comandos VOICE/DEVOICE	
CHAN_LEVEL_AUTOHALFOP
	Estatus MedioOP (+h) automático
CHAN_LEVEL_HALFOP
	Permitido usar los comandos HALFOP/DEHALFOP (MitadOP/No-MitadOP)
CHAN_LEVEL_AUTOPROTECT
	Estatus de Protección de canal (+a) automático
CHAN_LEVEL_PROTECT
	Permitido usar los comandos PROTECT/DEPROTECT (Proteger/Desproteger)
CHAN_LEVEL_KICK
	Se Permite usar comando KICK
CHAN_LEVEL_STATUS
	Se Permite usar comando STATUS
CHAN_LEVEL_TOPIC
	Permitido usar el comando TOPIC

# Automatic responses
CHAN_IS_REGISTERED
	Este canal ha sido registrado con 12%s.
CHAN_MAY_NOT_BE_USED
	Este canal no puede ser utilizado.
CHAN_NOT_ALLOWED_TO_JOIN
	No le es permitido ingresar a este canal.

# Multi-purpose responses
CHAN_MUST_IDENTIFY_NICK
	Por favor identifiquese con 12%s primero, usando el comando:
	12/msg %s IDENTIFY Contraseña
CHAN_BOUNCY_MODES
	Lo sentimos, el comando 12%s está temporaralmente deshabilitado.

# REGISTER responses
CHAN_REGISTER_SYNTAX
	12REGISTER Canal Contraseña Descripcción
CHAN_REGISTER_DISABLED
	Lo sentimos, la registración de canales está temporalmente deshabilitada.
CHAN_REGISTER_SHORT_CHANNEL
	El canal 12# no puede ser registrado.
CHAN_REGISTER_NOT_LOCAL
	Canales locales no pueden ser registrados.
CHAN_REGISTER_INVALID_NAME
	Solo puedes registrar nombres de canales que comiencen con el signo 12#.
CHAN_MUST_REGISTER_NICK
	Usted debe registrar su nick primeramente. Escriba 12/msg %s HELP para información sobre como registrar nicks.
CHAN_MAY_NOT_BE_REGISTERED
	El canal 12%s no puede ser registrado.
CHAN_ALREADY_REGISTERED
	¡El canal 12%s ya está registrado!
CHAN_MUST_BE_CHANOP
	Usted debe ser operador del canal para poder registrarlo.
CHAN_REACHED_CHANNEL_LIMIT
	Lo sentimos, usted ya ha alcazado su límite de 12%d canales.
CHAN_EXCEEDED_CHANNEL_LIMIT
	Lo sentimos, usted ya ha excedido su límite de 12%d canales.
CHAN_REGISTRATION_FAILED
	Lo sentimos, la registración falló.
CHAN_REGISTERED
	Canal 12%s registrado bajo su nick: 12%s
CHAN_PASSWORD_IS
	La contraseña de su canal es 12%s - recuerdela para uso posterior.

# IDENTIFY responses
CHAN_IDENTIFY_SYNTAX
	12IDENTIFY #Canal Contraseña
CHAN_IDENTIFY_FAILED
	Lo sentimos, la identificación falló.
CHAN_IDENTIFY_SUCCEEDED
	Contraseña aceptada - usted ahóra tiene acceso a nivel de fundador con 12%s.

# DROP responses
CHAN_DROP_SYNTAX
	12DROP #Canal Contraseña
CHAN_DROP_DISABLED
	Lo sentimos, la cancelación de regístro de canal está temporalmente deshabilitada.
CHAN_DROPPED
	El canal 12%s ha sido cancelado.

# DROPCHAN responses
CHAN_DROPCHAN_SYNTAX
	12DROP #Canal

# SET responses
CHAN_SET_SYNTAX
	12SET Canal Opción Parámetros
CHAN_SET_DISABLED
	Lo sentimos, el ajuste de opciones de canal está temporalmente deshabilitada.
CHAN_SET_UNKNOWN_OPTION
	Opción 12SET %s desconocida.

# SET FOUNDER responses
CHAN_SET_FOUNDER_TOO_MANY_CHANS
	12%s tiene demasiados canales registrados.
CHAN_FOUNDER_CHANGED
	Fundador de 12%s cambiado a 12%s.

# SET SUCCESSOR responses
CHAN_SUCCESSOR_CHANGED
	Sucesor para 12%s cambiado a 12%s.
CHAN_SUCCESSOR_IS_FOUNDER
	Usted no puede convertir al fundador de un canal también en sucesor.

# SET PASSWORD responses
CHAN_SET_PASSWORD_FAILED
	Lo sentimos, fue imposible establecer la contraseña.
CHAN_PASSWORD_CHANGED
	Contraseña para 12%s cambiada.
CHAN_PASSWORD_CHANGED_TO
	Contraseña para 12%s cambiada a 12%s.

# SET DESC responses
CHAN_DESC_CHANGED
	Descripción de 12%s cambiada a 12%s.

# SET URL responses
CHAN_URL_CHANGED
	URL para 12%s cambiado a 12%s.
CHAN_INFORMA_CHANGED
	INFORMACION para 12%s cambiado a 12%s.
# SET EMAIL responses
CHAN_EMAIL_CHANGED
	Correo electrónico para 12%s cambiado a 12%s.

# SET ENTRYMSG responses
CHAN_ENTRY_MSG_CHANGED
	Mensaje de entrada para 12%s cambió.

# SET MLOCK responses
CHAN_SET_MLOCK_NEED_PLUS_MINUS
	Lista de Modos debe comenzar con un + (más) o - (menos).
CHAN_SET_MLOCK_NEED_PARAM
	Parámetro requerido para 12MLOCK +%c.
CHAN_SET_MLOCK_NEED_POSITIVE
	Parámetro para 12MLOCK +%c debe ser un número positivo.
CHAN_SET_MLOCK_MODE_REG_BAD
	Modo 12+%c es siempre establecido en canales registrados, y no puede ser usado con 12MLOCK (Opción Candado).
CHAN_SET_MLOCK_LINK_BAD
	Parámetro para 12MLOCK +%c no es un nombre válido de canal.
CHAN_SET_MLOCK_LINK_SAME
	Parámetro para 12MLOCK +%c debe ser canal diferente.
CHAN_SET_MLOCK_REQUIRES
	12MLOCK +%c requiere que se fije 12MLOCK +%c también.
CHAN_SET_MLOCK_BAD_PARAM
	Parámetro inválido para 12MLOCK +%c.
CHAN_SET_MLOCK_UNKNOWN_CHAR
	Modo con caractér 12%c es desconocido e ignorado.
CHAN_SET_MLOCK_CANNOT_LOCK
	Modo 12%c no puede ser fijado con la opción candado (12MLOCK).
CHAN_MLOCK_CHANGED
	Modo de candado en canal 12%s cambiado a 12%s.
CHAN_MLOCK_REMOVED
	Modo de candado en canal 12%s removido.

# SET HIDE responses
CHAN_SET_HIDE_SYNTAX
	12SET #Canal HIDE {EMAIL | TOPIC | MLOCK} {ON | OFF}
CHAN_SET_HIDE_EMAIL_ON
	La dirección electrónica (E-mail) del canal 12%s será ahóra ocultada de el comando 12%s INFO.
CHAN_SET_HIDE_EMAIL_OFF
	La dirección electrónica (E-mail) del canal 12%s será ahóra mostrada en el comando 12%s INFO.
CHAN_SET_HIDE_TOPIC_ON
	El tópico del canal 12%s será ahóra ocultado de el comando 12%s INFO.
CHAN_SET_HIDE_TOPIC_OFF
	El tópico del canal 12%s será ahóra mostrado en el comando 12%s INFO.
CHAN_SET_HIDE_MLOCK_ON
	El modo de candado del canal 12%s será ahóra ocultado de el comando 12%s INFO.
CHAN_SET_HIDE_MLOCK_OFF
	El modo de candado del canal 12%s será ahóra mostrado en el comando 12%s INFO.

# SET KEEPTOPIC responses
CHAN_SET_KEEPTOPIC_SYNTAX
	12SET #Canal KEEPTOPIC {ON | OFF}
CHAN_SET_KEEPTOPIC_ON
	Opción de retención de tópico ahóra 03ACTIVADA (ON).
CHAN_SET_KEEPTOPIC_OFF
	Opción de retención de tópico ahóra 04DESACTIVADA (OFF).

# SET TOPICLOCK responses
CHAN_SET_TOPICLOCK_SYNTAX
	12SET #Canal TOPICLOCK {ON | OFF}
CHAN_SET_TOPICLOCK_ON
	Opción de candado en tópico 03ACTIVADA (ON).
CHAN_SET_TOPICLOCK_OFF
	Opción de candado en tópico 04DESACTIVADA (OFF).

# SET PRIVATE responses
CHAN_SET_PRIVATE_SYNTAX
	12SET #Canal PRIVATE {ON | OFF}
CHAN_SET_PRIVATE_ON
	Opción de privacidad 03ACTIVADA (ON).
CHAN_SET_PRIVATE_OFF
	Opción de privacidad 04DESACTIVADA (OFF).

# SET SECUREOPS responses
CHAN_SET_SECUREOPS_SYNTAX
	12SET #Canal SECUREOPS {ON | OFF}
CHAN_SET_SECUREOPS_ON
	Opción de SecureOPs (OPs Seguros) 03ACTIVADA (ON).
CHAN_SET_SECUREOPS_OFF
	Opción de SecureOPs (OPs Seguros) 04DESACTIVADA (OFF).

# SET LEAVEOPS responses
CHAN_SET_LEAVEOPS_SYNTAX
	12SET #Canal LEAVEOPS {ON | OFF}
CHAN_SET_LEAVEOPS_ON
	Opción de LeaveOPs (OPs Dejados) 03ACTIVADA (ON).
CHAN_SET_LEAVEOPS_OFF
	Opción de LeaveOPs (OPs Dejados) 04DESACTIVADA (OFF).

# SET RESTRICTED responses
CHAN_SET_RESTRICTED_SYNTAX
	12SET #Canal RESTRICTED {ON | OFF}
CHAN_SET_RESTRICTED_ON
	Opción de acceso restringido 03ACTIVADA (ON).
CHAN_SET_RESTRICTED_OFF
	Opción de acceso restringido 04DESACTIVADA (OFF).

# SET SECURE responses
CHAN_SET_SECURE_SYNTAX
	12SET #Canal SECURE {ON | OFF}
CHAN_SET_SECURE_ON
	Opción Secure (Seguro) ahóra 03ACTIVADA (ON).
CHAN_SET_SECURE_OFF
	Opción Secure (Seguro) ahóra 04DESACTIVADA (OFF).

# SET DEBUG responses
CHAN_SET_DEBUG_SYNTAX
	12SET #Canal DEBUG {ON | OFF}
CHAN_SET_DEBUG_ON
	Opción de Debug (Nota a OPs) ahóra 03ACTIVADA (ON).
CHAN_SET_DEBUG_OFF
	Opción de Debug (Nota a OPs) ahóra 04DESACTIVADA (OFF).

# SET ENFORCE responses
CHAN_SET_ENFORCE_SYNTAX
	12SET #Canal ENFORCE {ON | OFF}
CHAN_SET_ENFORCE_ON
	Opción de Enforce (Implementar) está ahóra 03ACTIVADA (ON).
CHAN_SET_ENFORCE_OFF
	Opción de Enforce (Implementar) está ahóra 04DESACTIVADA (OFF).

# SET MEMO-RESTRICTED responses
CHAN_SET_MEMO_RESTRICTED_SYNTAX
	12SET #Canal MEMO-RESTRICTED {ON | OFF}
CHAN_SET_MEMO_RESTRICTED_ON
	Opción de Restricción de Memo está ahora 3ACTIVADA
CHAN_SET_MEMO_RESTRICTED_OFF
	Opción de Restricción de Memo está ahora 4DESACTIVADA

# SET NOEXPIRE responses
CHAN_SET_NOEXPIRE_SYNTAX
	12SET #Canal NOEXPIRE {ON | OFF}
CHAN_SET_NOEXPIRE_ON
	El canal 12%s no expirará.
CHAN_SET_NOEXPIRE_OFF
	El canal 12%s si expirará.

# UNSET responses
CHAN_UNSET_SYNTAX
	12UNSET #Canal {SUCCESSOR | URL | EMAIL | ENTRYMSG}
CHAN_SUCCESSOR_UNSET
	Sucesor para 12%s ahóra indefinido.
CHAN_URL_UNSET
	URL para 12%s ahóra indefinido.
CHAN_INFORMA_UNSET
	INFORMACION para 12%s ahóra indefinido.
CHAN_EMAIL_UNSET
	Correo electrónico (EMAIL) para 12%s ahóra indefinida.
CHAN_ENTRY_MSG_UNSET
	Mensaje de entrada para 12%s ahóra indefinido.

# ACCESS messages
CHAN_ACCESS_SYNTAX
	12ACCESS #Canal {ADD | DEL | LIST | LISTLEVEL | COUNT} [Parámetros]
CHAN_ACCESS_ADD_SYNTAX
	12ACCESS #canal ADD nick nivel
CHAN_ACCESS_DEL_SYNTAX
	12ACCESS #canal DEL nick
CHAN_ACCESS_LIST_SYNTAX
	12ACCESS #canal LIST [+Inicio] [máscara]
CHAN_ACCESS_LISTLEVEL_SYNTAX
	12ACCESS #canal LISTLEVEL [+Inicio] nivel
CHAN_ACCESS_COUNT_SYNTAX
	12ACCESS canal COUNT
CHAN_ACCESS_DISABLED
	Lo sentimos, modificación a la lista de acceso de canal está temporalmente deshabilitada.
CHAN_ACCESS_LEVEL_NONZERO
	Nivel de acceso debe ser diferente a cero.
CHAN_ACCESS_LEVEL_RANGE
	Nivel de acceso debe estar entre 12%d y 12%d.
CHAN_ACCESS_NICKS_ONLY
	La lista de acceso del canal deberá contener solamente nicks registrados.
CHAN_ACCESS_REACHED_LIMIT
	Lo sentimos, usted solamente puede tener 12%d entradas de acceso en un canal.
CHAN_ACCESS_NOOP
	12%s no puede ser agregado a lista de accesos.
CHAN_ACCESS_LEVEL_UNCHANGED
	Nivel de acceso para 12%s en 12%s no cambio de 12%d.
CHAN_ACCESS_LEVEL_CHANGED
	Nivel de acceso para 12%s en 12%s fue cambiado a 12%d.
CHAN_ACCESS_ADDED
	12%s agregado a la lista de acceso de 12%s con nivel 12%d.
CHAN_ACCESS_NOT_FOUND
	12%s no fue encontrado en la lista de acceso de 12%s.
CHAN_ACCESS_DELETED
	12%s borrado de la lista de acceso de 12%s.
CHAN_ACCESS_LIST_EMPTY
	La lista de acceso de 12%s está vacía.
CHAN_ACCESS_NO_MATCH
	No existe entrada alguna en la lista de acceso de 12%s.
CHAN_ACCESS_LIST_HEADER
	Lista de acceso para 12%s:
	  Niv  nick
CHAN_ACCESS_LIST_FORMAT
	 12%4d  %s
CHAN_ACCESS_COUNT
	La lista de acceso de 12%s tiene 12%d entradas.

# XOP (SOP/AOP/etc.) responses
CHAN_SOP_SYNTAX
	12SOP Canal {ADD | DEL | LIST | COUNT} [Parámetros]
CHAN_AOP_SYNTAX
	12AOP Canal {ADD | DEL | LIST | COUNT} [Parámetros]
CHAN_HOP_SYNTAX
	12HOP Canal {ADD | DEL | LIST | COUNT} [Parámetros]
CHAN_VOP_SYNTAX
	12VOP Canal {ADD | DEL | LIST | COUNT} [Parámetros]
CHAN_NOP_SYNTAX
	12NOP Canal {ADD | DEL | LIST | COUNT} [Parámetros]
CHAN_SOP_LIST_SYNTAX
	12SOP Canal {ADD | DEL | LIST | COUNT} [+Inicio] [Máscara]
CHAN_AOP_LIST_SYNTAX
	12AOP Canal {ADD | DEL | LIST | COUNT} [+Inicio] [Máscara]
CHAN_HOP_LIST_SYNTAX
	12HOP Canal {ADD | DEL | LIST | COUNT} [+Inicio] [Máscara]
CHAN_VOP_LIST_SYNTAX
	12VOP Canal {ADD | DEL | LIST | COUNT} [+Inicio] [Máscara]
CHAN_NOP_LIST_SYNTAX
	12NOP Canal {ADD | DEL | LIST | COUNT} [+Inicio] [Máscara]
CHAN_XOP_ADDED
	12%s agregado a la lista de 12%s 12%s.
CHAN_XOP_LEVEL_CHANGED
	12%s movido a la lista de 12%s 12%s.
CHAN_XOP_LEVEL_UNCHANGED
	12%s ya está en la lista de 12%s 12%s.
CHAN_XOP_NICKS_ONLY
	Las listas de 12SOP, 12AOP, 12VOP, y 12NOP solo pueden contener nicks registrados.
CHAN_XOP_NOOP
	12%s no puede ser agregado a listas de accessos.
CHAN_XOP_NICKS_ONLY_HOP
	Las listas de 12SOP, 12AOP, 12HOP, 12VOP, y 12NOP solo pueden contener nicks registrados.
CHAN_XOP_REACHED_LIMIT
	Lo sentimos, el número de entradas en sus listas de 12SOP, 12AOP, 12VOP y 12NOP no puede sobrepasar más de 12%d entradas.  Límite excedido.
CHAN_XOP_REACHED_LIMIT_HOP
	Lo sentimos, el número de entradas en sus listas de 12SOP, 12AOP, 12HOP, 12VOP y 12NOP no puede sobrepasar más de 12%d entradas.  Límite excedido.
CHAN_XOP_NOT_FOUND
	12%s no fue encontrado en la lista de 12%s 12%s.
CHAN_XOP_DELETED
	12%s borrado de la lista de 12%s 12%s.
CHAN_XOP_LIST_EMPTY
	La lista de 12%s 12%s está vacía.
CHAN_XOP_NO_MATCH
	No existe entrada alguna en la lista de 12%s 12%s.
CHAN_XOP_LIST_HEADER
	Lista de 12%s para 12%s:
CHAN_XOP_COUNT
	La lista de 12%s 12%s tiene 12%d entradas.

# AKICK responses
CHAN_AKICK_SYNTAX
	12AKICK #Canal {ADD | DEL | LIST | VIEW | COUNT | ENFORCE} [Parámetros]
CHAN_AKICK_LIST_SYNTAX
	12AKICK #Canal LIST [+Inicio] [Máscara]
CHAN_AKICK_VIEW_SYNTAX
	12AKICK #canal VIEW [+Inicio] [mask]
CHAN_AKICK_DISABLED
	Lo sentimos, modificación a la lista de pateo automático de canal está temporalmente deshabilitada.
CHAN_AKICK_ALREADY_EXISTS
	12%s ya existe en la lista de pateo automático de 12%s.
CHAN_AKICK_REACHED_LIMIT
	Lo sentimos, usted solo puede tener %d máscaras de pateo automático en un canal.
CHAN_AKICK_ADDED
	12%s agregado a la lista de pateo automático de 12%s.
CHAN_AKICK_NOT_FOUND
	12%s no se encuentra en la lista de pateo automático de 12%s.
CHAN_AKICK_DELETED
	12%s borrado de la lista de pateo automático de 12%s.
CHAN_AKICK_LIST_EMPTY
	Lista de pateo automático de 12%s está vacía.
CHAN_AKICK_NO_MATCH
	No existe entrada alguna en la lista de pateo automático de 12%s.
CHAN_AKICK_LIST_HEADER
	Lista de pateo automático para 12%s:
# mask, set-by, set-time, last-used, reason
CHAN_AKICK_VIEW_FORMAT
	    12%s (por 12%s en 12%s; última vez usado 12%s)
	        12%s
# mask, set-by, set-time, reason
CHAN_AKICK_VIEW_UNUSED_FORMAT
	    12%s (por 12%s en 12%s; nunca usado)
	        12%s
CHAN_AKICK_COUNT
	12%s tiene 12%d entradas en su lista de Auto Pateo.
CHAN_AKICK_ENFORCE_DONE
	Implementación de auto pateo para 12%s completado; 12%d usuarios fueron afectados.

# LEVELS responses
CHAN_LEVELS_SYNTAX
	12LEVELS #Canal {SET | DIS[ABLE] | LIST | RESET} [Articulo [Nivel]]
CHAN_LEVELS_READONLY
	Lo sentimos, modificación a la lista de nivel de privilegios del canal está actualmente deshabilitada.
CHAN_LEVELS_RANGE
	Nivel debe de estar entre 12%d y 12%d.
CHAN_LEVELS_CHANGED
	Nivel para 12%s en canal 12%s cambiado a 12%d.
CHAN_LEVELS_UNKNOWN
	Opción 12%s desconocida. Escriba 12/msg %s HELP LEVELS DESC para ver la lista de opciones válidas.
CHAN_LEVELS_DISABLED
	12%s deshabilitado en canal 12%s.
CHAN_LEVELS_LIST_HEADER
	Configuración de nivel de prilegios para el canal 12%s:
CHAN_LEVELS_LIST_DISABLED
	    12%-*s  (deshabilitado)
CHAN_LEVELS_LIST_FOUNDER
	    12%-*s  (fundador solamente)
CHAN_LEVELS_LIST_NORMAL
	    12%-*s  %4d
CHAN_LEVELS_RESET
	Niveles de privilegios para el canal 12%s reconfigurados a los niveles originales.

# INFO responses
CHAN_INFO_SYNTAX
	12INFO #Canal [ALL]
CHAN_INFO_HEADER
	Información del canal 12%s:
CHAN_INFO_FOUNDER
	Fundador: %s
CHAN_INFO_SUCCESSOR
	Sucesor: %s
CHAN_INFO_DESCRIPTION
	Descripción: %s
CHAN_INFO_ENTRYMSG
	Mensaje de Entrada: %s
CHAN_INFO_TIME_REGGED
	Registrado: %s
CHAN_INFO_LAST_USED
	Último uso: %s
CHAN_INFO_LAST_TOPIC
	Último tópico: %s
CHAN_INFO_TOPIC_SET_BY
	Tópico ajustado por: %s
CHAN_INFO_URL
	URL: 12%s
CHAN_INFO_INFORMA
	Canal de caracter: 12%s

CHAN_INFO_EMAIL
	Correo electrónico: 12%s
CHAN_INFO_OPTIONS
	Opciones: %s
CHAN_INFO_OPT_PRIVATE
	Privado
CHAN_INFO_OPT_KEEPTOPIC
	Retención de tópico
CHAN_INFO_OPT_TOPICLOCK
	Candado de tópico
CHAN_INFO_OPT_SECUREOPS
	Secure Ops
CHAN_INFO_OPT_LEAVEOPS
	OPs Dejados
CHAN_INFO_OPT_RESTRICTED
	Acceso restringido
CHAN_INFO_OPT_SECURE
	Seguro
CHAN_INFO_OPT_DEBUG
	Chivato
CHAN_INFO_OPT_ENFORCE
	Implementar
CHAN_INFO_OPT_MEMO_RESTRICTED
	Restricción de Memo
CHAN_INFO_OPT_NONE
	Ninguna
CHAN_INFO_MODE_LOCK
	Candado de Modo: %s
CHAN_INFO_NO_EXPIRE
	Este canal NO EXPIRARÁ.
CHAN_INFO_SUSPEND_DETAILS
	Suspendido por 12%s en 12%s (12%s).
CHAN_INFO_SUSPEND_REASON
	Razón: 12%s
CHAN_INFO_SHOW_ALL
	Para más información, Escriba: 12/msg %s INFO %s ALL

# LIST responses
CHAN_LIST_SYNTAX
	12LIST [+Inicio] Patrón
CHAN_LIST_OPER_SYNTAX
	12LIST [+Inicio] Patrón [FORBIDDEN] [NOEXPIRE] [SUSPENDED]
CHAN_LIST_HEADER
	Lista de entradas similares a 12%s:
CHAN_LIST_NO_MATCH
	No se encontraron canales similares.

# INVITE responses
CHAN_INVITE_SYNTAX
	12INVITE #Canal
CHAN_INVITE_OK
	Invitando 12%s al canal 12%s.

# OP/DEOP/VOICE/DEVOICE responses
CHAN_OPVOICE_SYNTAX
	12%s #Canal [nick]
CHAN_OP_SUCCEEDED
	OPs dadas a 12%s en el canal 12%s.
CHAN_OP_ALREADY
	12%s ya tiene OPs en el canal 12%s.
CHAN_OP_FAILED
	Imposible dar OPs a 12%s en el canal 12%s.
CHAN_DEOP_SUCCEEDED
	OPs removidas de 12%s en el canal 12%s.
CHAN_DEOP_ALREADY
	Ya le fueron removidas los OPs a %s en el canal %s.
CHAN_DEOP_FAILED
	Imposible remover OPs de 12%s en el canal 12%s.
CHAN_VOICE_SUCCEEDED
	Voz dada a 12%s en el canal 12%s.
CHAN_VOICE_ALREADY
	12%s ya tiene voz en el canal 12%s.
CHAN_VOICE_FAILED
	Imposible dar voz a 12%s en el canal 12%s.
CHAN_DEVOICE_SUCCEEDED
	Voz removida de 12%s en el canal 12%s.
CHAN_DEVOICE_ALREADY
	Ya se le ha removido la voz a 12%s en el canal 12%s.
CHAN_DEVOICE_FAILED
	Imposible remover voz de 12%s en el canal 12%s.
CHAN_HALFOP_SUCCEEDED
	Mitad-OPs dadas a 12%s en el canal 12%s.
CHAN_HALFOP_ALREADY
	12%s ya tiene estatus de Mitad-OPs en el canal 12%s.
CHAN_HALFOP_FAILED
	Imposible dar mitad-OPs a 12%s en el canal 12%s.
CHAN_DEHALFOP_SUCCEEDED
	Mitad-OPs removidas de 12%s en el canal 12%s.
CHAN_DEHALFOP_ALREADY
	Ya le fue removido el estatus de Mitdad-OPs a 12%s en el canal 12%s.
CHAN_DEHALFOP_FAILED
	Imposible remover mitad-OPs de 12%s en el canal 12%s.
CHAN_PROTECT_SUCCEEDED
	Protegido 12%s en el canal 12%s.
CHAN_PROTECT_ALREADY
	12%s ya ha sido protegido en el canal 12%s.
CHAN_PROTECT_FAILED
	Imposible proteger a 12%s en el canal 12%s.
CHAN_DEPROTECT_SUCCEEDED
	Desprovisto de protección 12%s en el canal 12%s.
CHAN_DEPROTECT_ALREADY
	12%s ya está desprovisto de protección en el canal 12%s.
CHAN_DEPROTECT_FAILED
	Imposible desproteger a 12%s en el canal 12%s.

# UNBAN responses
CHAN_UNBAN_SYNTAX
	12UNBAN #Canal
CHAN_UNBANNED
	Has sido desbaneado de 12%s.

# KICK responses
CHAN_KICK_SYNTAX
	12KICK #Canal nick [Razón]
CHAN_KICK_PROTECTED
	12%s no puede ser pateado en el canal 12%s.
CHAN_KICKED
	12%s pateado de el canal 12%s.

# TOPIC responses
CHAN_TOPIC_SYNTAX
	12TOPIC #Canal Tópico

# CLEAR responses
CHAN_CLEAR_SYNTAX
	12CLEAR #Canal Opción
CHAN_CLEARED_BANS
	Todos los bloqueos en el canal 12%s han sido removidos.
CHAN_CLEARED_EXCEPTIONS
	Todas las excepciones en el canal 12%s han sido removidas.
CHAN_CLEARED_INVITES
	Todas las máscaras de invitación en el canal 12%s han sido removidas.
CHAN_CLEARED_MODES
	Todos los modos en el canal 12%s han sido borrados.
CHAN_CLEARED_OPS
	Modo +o ha sido desactivado en el canal 12%s.
CHAN_CLEARED_HALFOPS
	Modo +h ha sido desactivado en el canal 12%s.
CHAN_CLEARED_VOICES
	Modo +v ha sido desactivado en el canal 12%s.
CHAN_CLEARED_USERS
	Todos los usuarios han sido pateados del canal 12%s.

# GETPASS responses
CHAN_GETPASS_SYNTAX
	12GETPASS Canal
CHAN_GETPASS_UNAVAILABLE
	El comando 12GETPASS no está disponible para el canal 12%s porque se está usando encripción.
CHAN_GETPASS_PASSWORD_IS
	Contraseña para el canal 12%s es 12%s.

# FORBID responses
CHAN_FORBID_SYNTAX
	12FORBID #Canal
CHAN_FORBID_SHORT_CHANNEL
	El canal 12# no puede ser prohibido.
CHAN_FORBID_SUCCEEDED
	El canal 12%s está ahóra prohibido.
CHAN_FORBID_FAILED
	¡No fue posible prohibir el canal 12%s!

# SUSPEND responses
CHAN_SUSPEND_SYNTAX
	12SUSPEND [+Expiración] #Canal Razón
CHAN_SUSPEND_SUCCEEDED
	El canal 12%s ha sido suspendido.
CHAN_SUSPEND_ALREADY_SUSPENDED
	El canal 12%s ya está suspendido.

# UNSUSPEND responses
CHAN_UNSUSPEND_SYNTAX
	12UNSUSPEND #Canal
CHAN_UNSUSPEND_SUCCEEDED
	Suspensión del canal 12%s ha sido desactivada.
CHAN_UNSUSPEND_NOT_SUSPENDED
	El canal 12%s no está suspendido.

###########################################################################
#
# MemoServ messages
#
###########################################################################

# Automatic messages
MEMO_HAVE_NEW_MEMO
	Usted tiene 121 nuevo mensaje.
MEMO_HAVE_NEW_MEMOS
	Usted tiene 12%d nuevos mensajes.
MEMO_TYPE_READ_LAST
	Escriba 12/msg %s READ LAST para leerlo.
MEMO_TYPE_READ_NUM
	Escriba 12/msg %s READ %d para leerlo.
MEMO_TYPE_LIST_NEW
	Escriba 12/msg %s LIST NEW para listarlos.
MEMO_AT_LIMIT
	04¡AVISO!: Usted ha alcanzado su número máximo de mensajes (12%d). No podrá recibir mensajes nuevos hasta que borre algunos de los que ahóra tiene.
MEMO_OVER_LIMIT
	04¡AVISO!: Usted ha pasado su número máximo de mensajes (12%d). No podrá recibir mensajes nuevos hasta que borre algunos de los que ahóra tiene.
MEMO_NEW_MEMO_ARRIVED
	Usted tiene un nuevo mensaje de 12%s.
	Escriba 12/msg %s READ %d para leerlo.
MEMO_NEW_CHAN_MEMO_ARRIVED
	Usted tiene un nuevo mensaje de 12%s para 12%s.
	Escriba 12/msg %s READ %d para leerlo.

# Multi-use responses
MEMO_HAVE_NO_MEMOS
	Usted no tiene mensajes.
MEMO_HAVE_NO_NEW_MEMOS
	Usted no tiene nuevos mensajes.
MEMO_DOES_NOT_EXIST
	¡El mensaje 12%d no existe!
MEMO_LIST_NOT_FOUND
	Ningún mensaje similar fue encontrado.

# SEND responses
MEMO_SEND_SYNTAX
	12SEND {nick | #Canal} Mensaje
MEMO_SEND_DISABLED
	Lo sentimos, el envío de mensajes está temporalmente deshabilitado.
MEMO_SEND_PLEASE_WAIT
	Favor de esperar %s antes de utilizar el comando 12SEND nuevamente.
MEMO_SEND_CHAN_NOT_AVAIL
	Lo sentimos, los mensajes del canal no están disponibles.
MEMO_X_GETS_NO_MEMOS
	12%s no puede recibir mensajes.
MEMO_X_HAS_TOO_MANY_MEMOS
	12%s tiene demasiados mensajes actualmente y no puede recibir más.
MEMO_SENT
	Mensaje enviado a 12%s.
MEMO_SEND_FAILED
	El mensaje no pudo ser enviado a 12%s.

# LIST responses
MEMO_LIST_SYNTAX
	12LIST [Número | List | NEW]
MEMO_LIST_MEMOS
	Mensajes para 12%s. Para leerlos, Escriba: 12/msg %s READ Número
MEMO_LIST_NEW_MEMOS
	Nuevos mensajes para 12%s. Para leerlos, Escriba: 12/msg %s READ Número
MEMO_LIST_HEADER
	   Núm  Envia             Fecha/Hora
MEMO_LIST_FORMAT
	%c%c%c%3d  %-16s  %s

# READ responses
MEMO_READ_SYNTAX
	12READ {Número | List | LAST | NEW}
MEMO_HEADER
	Mensaje 12%d de 12%s (%s). Para borrarlo, Escriba: 12/msg %s DEL %d
MEMO_CHAN_HEADER
	Mensaje 12%d de 12%s para 12%s (%s). Para borrarlo, Escriba: 12/msg %s DEL %d

# SAVE responses
MEMO_SAVE_SYNTAX
	12SAVE {Número | List}
MEMO_SAVED_ONE
	Mensaje 12%d marcado para que no expire.
MEMO_SAVED_SEVERAL
	12%d mensajes marcados para que no expiren.

# DEL responses
MEMO_DEL_SYNTAX
	12DEL {Número | List | ALL}
MEMO_DELETED_NONE
	Ningún mensaje fue borrado.
MEMO_DELETED_ONE
	Mensaje 12%d ha sido borrado.
MEMO_DELETED_SEVERAL
	12%d mensajes han sido borrados.
MEMO_DELETED_ALL
	Todos sus mensajes han sido borrados.

# RENUMBER responses
MEMO_RENUMBER_ONLY_YOU
	Solo puede usar el comando 12RENUMBER en usted mismo.
MEMO_RENUMBER_DONE
	Sus mensajes han sido re-enumerados.

# SET responses
MEMO_SET_SYNTAX
	12SET Opción Parámetros
MEMO_SET_DISABLED
	Lo sentimos, la opción de ajuste de mensajes está temporalmente deshabilitada.
MEMO_SET_UNKNOWN_OPTION
	Opción 12SET %s desconocida.

# SET NOTIFY responses
MEMO_SET_NOTIFY_SYNTAX
	12SET NOTIFY {ON | LOGON | NEW | OFF}
MEMO_SET_NOTIFY_ON
	12%s le notificará ahóra de sus mensajes cuando se conecte o cuando le sean enviados.
MEMO_SET_NOTIFY_LOGON
	12%s le notificará ahóra de sus mensajes cuando se conecte o cancele su modo /AWAY.
MEMO_SET_NOTIFY_NEW
	12%s le notificará ahóra de sus mensajes cuando le sean enviados.
MEMO_SET_NOTIFY_OFF
	12%s no le eviará notificación alguna de mensajes.

# SET LIMIT responses
MEMO_SET_LIMIT_SYNTAX
	12SET LIMIT Límite
MEMO_SET_LIMIT_OPER_SYNTAX
	12SET LIMIT [nick] {Límite | NONE} [HARD]
MEMO_SET_YOUR_LIMIT_FORBIDDEN
	No le es permitido cambiar su límite de mensajes.
MEMO_SET_LIMIT_FORBIDDEN
	El límite de mensajes para 12%s no puede ser cambiado.
MEMO_SET_YOUR_LIMIT_TOO_HIGH
	Usted no puede ajustar su límite de mensajes a más de 12%d.
MEMO_SET_LIMIT_TOO_HIGH
	Usted no puede ajustar el límite de mensajes para 12%s a más de 12%d.
MEMO_SET_LIMIT_OVERFLOW
	Límite de mensajes muy alto; lo hemos limitado a 12%d.
MEMO_SET_YOUR_LIMIT
	Su límite de mensajes ha sido ajustado a 12%d.
MEMO_SET_YOUR_LIMIT_ZERO
	No le será posible recibir más mensajes.
MEMO_SET_YOUR_LIMIT_DEFAULT
	Su límite de mensajes ha sido fijado a la Configuración Original (12%d).
MEMO_UNSET_YOUR_LIMIT
	Su límite de mensajes ha sido dishabilitado.
MEMO_SET_LIMIT
	Límite de mensajes para 12%s ajustado a 12%d.
MEMO_SET_LIMIT_ZERO
	Límite de mensajes para 12%s ajustado a 120.
MEMO_SET_LIMIT_DEFAULT
	Límite de mensajes para 12%s fijado a la Configuración Original (12%d).
MEMO_UNSET_LIMIT
	Límite de mensajes Deshabilitado para 12%s.

# INFO responses
MEMO_INFO_NO_MEMOS
	Actualmente usted no tiene mensajes.
MEMO_INFO_MEMO
	Actualmente usted tiene 121 mensaje.
MEMO_INFO_MEMO_UNREAD
	Actualmente usted tiene 121 mensaje, y no ha sido aún leído.
MEMO_INFO_MEMOS
	Actualmente usted tiene 12%d mensajes.
MEMO_INFO_MEMOS_ONE_UNREAD
	Actualmente usted tiene 12%d mensajes, de los cuales 121 no ha sido leído.
MEMO_INFO_MEMOS_SOME_UNREAD
	Actualmente usted tiene 12%d mensajes, de los cuales 12%d no han sido leídos.
MEMO_INFO_MEMOS_ALL_UNREAD
	Actualmente usted tiene 12%d mensajes; ninguno ha sido leído.
MEMO_INFO_LIMIT
	Su límite de mensajes es 12%d.
MEMO_INFO_HARD_LIMIT
	Su límite de mensajes es 12%d, y no puede ser cambiado.
MEMO_INFO_LIMIT_ZERO
	Su límite de mensajes es 120; usted no recibirá ningún nuevo mensaje.
MEMO_INFO_HARD_LIMIT_ZERO
	Su límite de mensajes es 120; usted no recibirá ningún nuevo mensaje.  Usted no puede cambiar este límite.
MEMO_INFO_NO_LIMIT
	Usted no tiene límite en la cantidad de mensajes que puede guardar.
MEMO_INFO_NOTIFY_OFF
	Usted no será notificado de nuevos mensajes.
MEMO_INFO_NOTIFY_ON
	Usted será notificado de nuevos mensajes al conectarse y cuando estos lleguen.
MEMO_INFO_NOTIFY_RECEIVE
	Usted será notificado cuando nuevos mensajes lleguen.
MEMO_INFO_NOTIFY_SIGNON
	Usted será notificado de nuevos mensajes al conectarse a la red de IRC.
MEMO_INFO_X_NO_MEMOS
	12%s no tiene mensajes actualmente.
MEMO_INFO_X_MEMO
	12%s actualmente tiene 121 mensaje.
MEMO_INFO_X_MEMO_UNREAD
	12%s actualmente tiene 121 mensaje, y aún está por ser leído.
MEMO_INFO_X_MEMOS
	12%s actualmente tiene 12%d mensajes.
MEMO_INFO_X_MEMOS_ONE_UNREAD
	12%s actualmente tiene 12%d mensajes, de los cuales 121 está aún sin leer.
MEMO_INFO_X_MEMOS_SOME_UNREAD
	12%s actualmente tiene 12%d mensajes, de los cuales 12%d están aún sin leer.
MEMO_INFO_X_MEMOS_ALL_UNREAD
	12%s actualmente tiene 12%d mensajes; todos los cuales están sin leer.
MEMO_INFO_X_LIMIT
	El límite de mensajes para 12%s es 12%d.
MEMO_INFO_X_HARD_LIMIT
	El límite de mensajes para 12%s es 12%d, y no puede ser cambiado.
MEMO_INFO_X_NO_LIMIT
	12%s no tiene límite de mensajes.
MEMO_INFO_X_NOTIFY_OFF
	12%s no es notificado de nuevos mensajes.
MEMO_INFO_X_NOTIFY_ON
	12%s es notificado de nuevos mensajes al conectarse y cuando estos llegan.
MEMO_INFO_X_NOTIFY_RECEIVE
	12%s es notificado cuando llegan nuevos mensajes.
MEMO_INFO_X_NOTIFY_SIGNON
	12%s es notificado de nuevos mensajes al conectarse.

################ forward module messages/responses

# Mail format
MEMO_FORWARD_MAIL_SUBJECT
	Mensaje para 12%s
MEMO_FORWARD_MULTIPLE_MAIL_SUBJECT
	Mensajes para %s
MEMO_FORWARD_MAIL_BODY
	Mensaje para %s (%s)
	%s
MEMO_FORWARD_CHANMEMO_MAIL_BODY
	Mensaje de %s para %s (%s)
	%s

# FORWARD responses
MEMO_FORWARD_SYNTAX
	12FORWARD {Número | List | ALL}
MEMO_FORWARD_NEED_EMAIL
	Usted debe fijar una dirección de correo electrónico (E-mail) antes de que los mensajes puedan ser reexpedidos a usted.
MEMO_FORWARD_PLEASE_WAIT
	Favor de esperar 12%s antes de usar el comando 12FORWARD nuevamente.
MEMO_FORWARD_FAILED
	Lo sentimos, el reexpedido de mensaje falló.
MEMO_FORWARDED_NONE
	Ningún mensaje fue reexpedido.
MEMO_FORWARDED_ONE
	Mensaje 12%d ha sido reexpedido.
MEMO_FORWARDED_SEVERAL
	12%d mensajes han sido reexpedidos.
MEMO_FORWARDED_ALL
	Todos sus mensajes han sido reexpedidos.

# SET FORWARD responses
MEMO_SET_FORWARD_SYNTAX
	12SET FORWARD {ON | COPY | OFF}
MEMO_SET_FORWARD_ON
	Sus mensajes serán ahóra reexpedidos a su dirección de correo electrónico: 12%s
MEMO_SET_FORWARD_COPY
	Sus mensajes serán ahóra reexpedidos a su dirección de correo electrónico: 12%s
	Sus mensajes ahóra también serán grabados por el sistema (Services).
MEMO_SET_FORWARD_OFF
	Sus mensajes no serán reexpedidos a su dirección de correo electrónico (E-mail).

################ ignore module messages/responses

# IGNORE responses
MEMO_IGNORE_SYNTAX
	12IGNORE {ADD | DEL | LIST} [nick | Máscara]
MEMO_IGNORE_ADD_SYNTAX
	12IGNORE ADD nick | Máscara
MEMO_IGNORE_DEL_SYNTAX
	12IGNORE DEL nick | Máscara
MEMO_IGNORE_LIST_FULL
	Su lista de ignore está llena.
MEMO_IGNORE_ALREADY_PRESENT
	12%s ya está presente en su lista de ignore.
MEMO_IGNORE_ADDED
	12%s agregado a su lista de ignore.
MEMO_IGNORE_NOT_FOUND
	%s no fue encontrado en su lista de ignorar.
MEMO_IGNORE_DELETED
	12%s borrado de su lista de ignore.
MEMO_IGNORE_LIST_EMPTY
	Su lista de ignore está vacía.
MEMO_IGNORE_LIST
	Lista De Ignore:
MEMO_IGNORE_LIST_X_EMPTY
	Lista de ignore para 12%s está vacía.
MEMO_IGNORE_LIST_X
	Lista de ignorar para 12%s:

###########################################################################
#
# OperServ messages
#
###########################################################################

# General messages
OPER_BOUNCY_MODES
	Los servicios no pueden cambiar modos.  ¿Están sus servidores configurados correctamente?
OPER_BOUNCY_MODES_U_LINE
	Los servicios no pueden cambiar modos.  ¿Están las U:lines de sus servidores configurados correctamente?

# GLOBAL responses
OPER_GLOBAL_SYNTAX
	12GLOBAL Mensaje

# STATS responses
OPER_STATS_UNKNOWN_OPTION
	Opción 12STATS %s desconocida.
OPER_STATS_RESET_USER_COUNT
	La cantidad máxima de usuarios ha sido re-ajustada.

OPER_STATS_CURRENT_USERS
	Usuarios actuales: 12%d (12%d ops)
OPER_STATS_MAX_USERS
	Máximo de usuarios: 12%d (12%s)
# Parameters: days, STR_DAYS or STR_DAY, hours, minutes
OPER_STATS_UPTIME_DHM
	Servicios activos 12%d%s, 12%02d:%02d
# If >= 1 hour, hours and minutes; if < 1 hour, minutes and seconds
OPER_STATS_UPTIME_HM_MS
	Servicios activos 12%s

OPER_STATS_KBYTES_READ
	Data recibida: 12%10u kB
OPER_STATS_KBYTES_WRITTEN
	Data enviada:  12%10u kB
OPER_STATS_NETBUF_SOCK
	Prelecturas de enchufe de servidor: 12%5u kB
OPER_STATS_NETBUF_SOCK_PERCENT
	Prelecturas de Enchufe de servidor: 12%5u kB (%d%%)
OPER_STATS_NETBUF_TOTAL
	Total de prelecturas de enchufe:    12%5u kB
OPER_STATS_NETBUF_TOTAL_PERCENT
	Total de prelecturas de enchufe:    12%5u kB (12%d%%)

OPER_STATS_ALL_USER_MEM
	Usuarios           : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_CHANNEL_MEM
	Canales            : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_SERVER_MEM
	Servidores         : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_NICKGROUPINFO_MEM
	Grupos De nicks   : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_NICKINFO_MEM
	nicks             : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_CHANSERV_MEM
	ChanServ           : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_STATSERV_MEM
	StatServ           : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_NEWS_MEM
	Notícias        : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_AKILL_MEM
	Auto-desconexiones: 12%6d regístros, 12%5d kB
OPER_STATS_ALL_EXCEPTION_MEM
	Clones Permitidos         : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_SGLINE_MEM
	SGlines            : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_SQLINE_MEM
	SQlines            : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_SZLINE_MEM
	SZlines            : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_SESSION_MEM
	Conexiones           : 12%6d regístros, 12%5d kB
OPER_STATS_ALL_ELINE_MEM
	E-Lines             : 12%6d registros, 12%5d kB

# GETKEY responses
OPER_GETKEY_SYNTAX
	12GETKEY Canal
OPER_GETKEY_KEY_IS
	La llave para el canal 12%s es: 12%s
OPER_GETKEY_NO_KEY
	El canal 12%s no tiene fijada una llave.

# MODE responses
OPER_MODE_SYNTAX
	12MODE #Canal Modos

# CLEARMODES responses
OPER_CLEARMODES_SYNTAX
	12CLEARMODES Canal [ALL]
OPER_CLEARMODES_DONE
	Todos los modos de canal han sido removidos del canal 12%s.
OPER_CLEARMODES_ALL_DONE
	Todos los modos de canal y usuario han sido removidos del canal 12%s.

# CLEARCHAN responses
OPER_CLEARCHAN_SYNTAX
	12CLEARCHAN #Canal
OPER_CLEARCHAN_DONE
	Todos los usuarios removidos del canal 12%s.

# KICK responses
OPER_KICK_SYNTAX
	12KICK #Canal Usuario Razón

# ADMIN responses
OPER_ADMIN_SYNTAX
	12ADMIN {ADD | DEL | LIST} [nicks]
OPER_ADMIN_ADD_SYNTAX
	12ADMIN ADD nick
OPER_ADMIN_DEL_SYNTAX
	12ADMIN DEL nick
OPER_ADMIN_NO_NICKSERV
	NickServ está deshabilitado en este momento; el comando 12ADMIN no está disponible.
OPER_ADMIN_EXISTS
	12%s ya existe en la lista de Administradores de Servicios.
OPER_ADMIN_ADDED
	12%s agregado a la lista de Administradores de Servicios.
OPER_ADMIN_TOO_MANY
	Demasiadas entradas (12%d) en la lista de Administradores de Servicios; imposible agregar más.
OPER_ADMIN_REMOVED
	12%s removido de la lista de Administradores de Servicios.
OPER_ADMIN_NOT_FOUND
	12%s no encontrado en la lista de administradores de Servicios.
OPER_ADMIN_LIST_HEADER
	Lista de Adminisradores de Servicios:

# OPER responses
OPER_OPER_SYNTAX
	12OPER {ADD | DEL | LIST} [nick]
OPER_OPER_ADD_SYNTAX
	12OPER ADD nick
OPER_OPER_DEL_SYNTAX
	12OPER DEL nick
OPER_OPER_NO_NICKSERV
	NickServ está deshabilitado en este momento; el comando 12OPER no está disponible.
OPER_OPER_EXISTS
	12%s ya existe en la lista de Operadores de Servicios.
OPER_OPER_ADDED
	12%s agregado a la lista de Operadores de Servicios.
OPER_OPER_TOO_MANY
	Demasiadas entradas (12%d) en la lista de Operadores de Servicios; imposible agregar más.
OPER_OPER_REMOVED
	12%s removido de la lista de Operadores de Servicios.
OPER_OPER_NOT_FOUND
	12%s no encontrado en la lista de Operadores de Servicios.
OPER_OPER_LIST_HEADER
	Lista de Operadores de Servicios:

# AKILL/EXCLUDE/SxLINE common responses
OPER_MASKDATA_SYNTAX
	12%s {ADD | DEL | CLEAR | LIST | VIEW | COUNT} [Parámetros]
OPER_MASKDATA_ADD_SYNTAX
	12%s ADD [+Expiración] Máscara Razón
OPER_MASKDATA_DEL_SYNTAX
	12%s DEL Máscara
OPER_MASKDATA_CLEAR_SYNTAX
	12%s CLEAR Máscara
OPER_MASKDATA_LIST_SYNTAX
	12%s {LIST | VIEW} [+Inicio] [Patrón] [NOEXPIRE]
OPER_MASKDATA_CHECK_SYNTAX
	12%s CHECK Máscara
# mask, reason
OPER_MASKDATA_LIST_FORMAT
	%-32s  %s
# mask, set-by, set-time, last-used, expires, reason
OPER_MASKDATA_VIEW_FORMAT
	12%s (por 12%s en 12%s, última vez usada 12%s; 12%s)
	    %s
# mask, set-by, set-time, expires, reason
OPER_MASKDATA_VIEW_UNUSED_FORMAT
	12%s (por 12%s en 12%s, nunca usada; 12%s)
	    %s

# AKILL responses
OPER_TOO_MANY_AKILLS
	¡La lista 12AKILL está llena!
OPER_AKILL_EXISTS
	12%s ya existe en la lista de auto-desconexión (12AKILL).
OPER_AKILL_NO_NICK
	04NOTA: Las máscaras de auto-desconexión (12AKILL) no pueden contener nicks; asegurese que usted no ha incluido una porción con nick en su máscara.
OPER_AKILL_MASK_TOO_GENERAL
	La máscara de auto-desconexión (12AKILL) es demasiado general.
OPER_AKILL_EXPIRY_LIMITED
	Solamente es posible fijar una fecha de expiración de 12%s.
OPER_AKILL_ADDED
	12%s agregado a la lista de auto-desconexión (12AKILL).
OPER_AKILL_REMOVED
	12%s removido de la lista de auto-desconexión (12AKILL).
OPER_AKILL_CLEARED
	La lista de auto-desconexión (12AKILL) ha sido eliminada.
OPER_AKILL_NOT_FOUND
	12%s no encontrado en la lista de auto-desconexión (12AKILL).
OPER_AKILL_LIST_HEADER
	Lista actual de auto-desconexión (12AKILL):
OPER_AKILL_LIST_EMPTY
	La lista de auto-desconexión (12AKILL) está vacía.
OPER_AKILL_LIST_NO_MATCH
	No se encontraron máscaras similares en la lista de auto-desconexión (12AKILL).
OPER_AKILL_CHECK_NO_MATCH
	No se encontraron máscaras similares a 12%s en la lista de auto-desconexión (12AKILL).
OPER_AKILL_CHECK_HEADER
	Máscaras similares a 12%s en la lista de auto-desconexión (12AKILL):
OPER_AKILL_CHECK_TRAILER
	12%d máscaras similares fueron encontradas.
OPER_AKILL_COUNT
	Existen 12%d máscaras de proveedor web en la lista de auto-desconexión (12AKILL).

# AKILLCHAN responses
OPER_AKILLCHAN_SYNTAX
	12AKILLCHAN [KILL] [+Expiración] Canal Razón
OPER_AKILLCHAN_AKILLED
	12%d usuarios fueron agregados a la lista de auto-desconexión (12AKILL).
OPER_AKILLCHAN_KILLED
	12%d usuarios fueron desconectados.
OPER_AKILLCHAN_AKILLED_ONE
	121 usuario fue agregado a la lista de auto-desconexión (12AKILL).
OPER_AKILLCHAN_KILLED_ONE
	121 usuario fue auto-desconectado.

# EXCLUDE responses
OPER_TOO_MANY_EXCLUDES
	¡La lista de 12E-Lines está llena!
OPER_EXCLUDE_EXISTS
	La máscara 12%s ya existe en la lista de E-Lines.
OPER_EXCLUDE_ADDED
	La máscara 12%s ha sido agregada a la lista de E-Lines.
OPER_EXCLUDE_REMOVED
	La máscara 12%s ha sido borrada de la lista de E-Lines.
OPER_EXCLUDE_CLEARED
	La lista de E-Lines ha sido limpiada.
OPER_EXCLUDE_NOT_FOUND
	La máscara 12%s no fue encontrada en la lista de E-Lines.
OPER_EXCLUDE_LIST_HEADER
	Lista actual de exclusión de auto-desconexión (12AKILL):
OPER_EXCLUDE_LIST_EMPTY
	La lista de exclusión de auto-desconexión (12AKILL) está vacía.
OPER_EXCLUDE_LIST_NO_MATCH
	No se encontraron máscaras similares en la lista de E-Lines.
OPER_EXCLUDE_CHECK_NO_MATCH
	No se encontraron máscaras similares a 12%d en la lista de E-Lines.
OPER_EXCLUDE_CHECK_HEADER
	Máscaras similares a 12%s en la lista de E-Lines:
OPER_EXCLUDE_CHECK_TRAILER
	Se encontraron 12%d máscaras similares.
OPER_EXCLUDE_COUNT
	Existen 12%d registros en la lista de E-Lines.

# SxLINE responses
OPER_TOO_MANY_SLINES
	¡La lista 12%s está llena!
OPER_SLINE_EXISTS
	12%s ya existe en la lista 12%s.
OPER_SLINE_MASK_TOO_GENERAL
	La máscara de 12%s es demasiado general.
OPER_SLINE_ADDED
	12%s agregado a la lista 12%s.
OPER_SLINE_REMOVED
	12%s removido de la lista 12%s.
OPER_SLINE_CLEARED
	La lista 12%s ha sido limpiada.
OPER_SLINE_NOT_FOUND
	12%s no fue encontrado en la lista 12%s.
OPER_SLINE_LIST_HEADER
	Lista 12%s actual:
OPER_SLINE_LIST_EMPTY
	La lista 12%s está vacía.
OPER_SLINE_LIST_NO_MATCH
	No se encontraron máscaras 12%s en la lista de auto-desconexión (Autokill).
OPER_SLINE_CHECK_NO_MATCH
	No se encontraron máscaras similares a 12%s en la lista 12%s.
OPER_SLINE_CHECK_HEADER
	Máscaras similares a 12%s en la lista 12%s:
OPER_SLINE_CHECK_TRAILER
	Se encontraron 12%d máscaras similares.
OPER_SLINE_COUNT
	Existen 12%d entradas en la lista 12%s.
OPER_SZLINE_NOT_AVAIL
	12SZLINE no está disponible con este servidor de IRC.

# SU responses
OPER_SU_SYNTAX
	12SU Contraseña
OPER_SU_NO_PASSWORD
	El comando 12SU no está disponible porque ninguna contraseña de super-usuario ha sido fijada.
OPER_SU_SUCCEEDED
	Usted tiene en este momento privilegios de super-usuario de los servicios.
OPER_SU_FAILED
	Fue imposible verificar la contraseña.

# SET responses
OPER_SET_SYNTAX
	12SET Opción Ajuste
OPER_SET_IGNORE_ON
	Código Ignore será usado.
OPER_SET_IGNORE_OFF
	Código Ignore no será usado.
OPER_SET_IGNORE_ERROR
	Parámetro para 12IGNORE debe ser 12ON u 12OFF.
OPER_SET_READONLY_ON
	Los Servicios están ahóra en modo de Leer-solamente (Read-Only).
OPER_SET_READONLY_OFF
	Los Servicios están ahóra en modo de Leer-Escribir (Read-Write).
OPER_SET_READONLY_ERROR
	Parámetro para 12READONLY debe ser 12ON u 12OFF.
OPER_SET_DEBUG_ON
	Los Servicios están ahóra en modo debug (Detección De Errores).
OPER_SET_DEBUG_OFF
	Los Servicios están ahóra en modo de non-debug (No Detectando Errores).
OPER_SET_DEBUG_LEVEL
	Los Servicios están ahóra en modo de debug (nivel 12%d).
OPER_SET_DEBUG_ERROR
	Parámetro para 12DEBUG debe ser 12ON, 12OFF, o un número positivo.
OPER_SET_SUPASS_FAILED
	Imposible fijar la contraseña para el Super-Usuario de los servicios.
OPER_SET_SUPASS_OK
	Contraseña para el Super-Usuario de los servicios ha sido cambiada.
OPER_SET_SUPASS_NONE
	Contraseña para el Super-Usuario de los servicios ha sido dishabilitada.
OPER_SET_UNKNOWN_OPTION
	Opción 12%s desconocida.

# JUPE responses
OPER_JUPE_SYNTAX
	12JUPE Nombre-Del-Servidor [Razón]
OPER_JUPE_INVALID_NAME
	El nombre de servidor es inválido (los nombres de servidores deben contener un punto).
OPER_JUPE_ALREADY_JUPED
	Ya se ha ejecutado el comando 12JUPE en el servidor 12%s.

# RAW responses
OPER_RAW_SYNTAX
	12RAW Texto

# UPDATE responses
OPER_UPDATE_SYNTAX
	12UPDATE [FORCE]
OPER_UPDATE_FORCE_FAILED
	Fue imposible abrir las bases de datos.
OPER_UPDATING
	Actualizando las bases de datos...
OPER_UPDATE_COMPLETE
	La actualización de la base de datos ha completado.
OPER_UPDATE_FAILED
	La actualización de la base de datos falló.

# REHASH responses
OPER_REHASHING
	Re-leyendo los ajustes a la configuración.
OPER_REHASHED
	Todos los ajustes a la configuración fueron exitosamente actualizados.
OPER_REHASH_ERROR
	Un error occurrio mientras se re-leian los ajustes a la configuración. Por favor examine el fichero de archivo de los Servicios (log) para más detalles.

# KILLCLONES responses
OPER_KILLCLONES_SYNTAX
	Sintaxis: 12KILLCLONES nick
OPER_KILLCLONES_UNKNOWN_NICK
	Imposible encontrar el usuario 12%s.
OPER_KILLCLONES_KILLED
	12%s utilizo 12KILLCLONES para 12%s desconectando 12%d clones.
OPER_KILLCLONES_KILLED_AKILL
	12%s utilizo 12KILLCLONES para 12%s desconectando 12%d clones. Un 12AKILL temporario ha sido agregado para 12%s.


###########################################################################
#
# Session limiting and exception messages
#
###########################################################################

# EXCEPTION responses
OPER_EXCEPTION_SYNTAX
	12CLONES {ADD | DEL | CLEAR | LIST | VIEW | COUNT} [Parámetros]
OPER_EXCEPTION_ADD_SYNTAX
	12CLONES ADD [+Expiración] Dirección-IP Límite Razón
OPER_EXCEPTION_DEL_SYNTAX
	12CLONES DEL {Dirección-IP | List}
OPER_EXCEPTION_CLEAR_SYNTAX
	12CLONES CLEAR ALL
OPER_EXCEPTION_MOVE_SYNTAX
	12CLONES MOVE Núm Nuevo-Núm
OPER_EXCEPTION_LIST_SYNTAX
	12CLONES {LIST | VIEW} [[+Inicio] Patrón | lista]
OPER_EXCEPTION_ALREADY_PRESENT
	La dirección IP 12%s ya existe en la lista de clones permitidos.
OPER_EXCEPTION_TOO_MANY
	La lista de clones permitidos se encuentra llena!.
OPER_EXCEPTION_ADDED
	Límite de clones para 12%s establecido a 12%d.
OPER_EXCEPTION_MOVED
	Excepción para 12%s (12#%d) movido al número 12%d.
OPER_EXCEPTION_NO_SUCH_ENTRY
	No existe ninguna entrada con el índice 12#%d.
OPER_EXCEPTION_NOT_FOUND
	La dirección IP 12%s no existe en a lista de clones permitidos.
OPER_EXCEPTION_NO_MATCH
	No se encontraron coincidencias en la lista de clones permitidos. 
OPER_EXCEPTION_EMPTY
	La lista de clones permitidos se encuentra vacía.
OPER_EXCEPTION_DELETED
	La dirección IP 12%s ha sido borrada de la lista de clones permitidos.
OPER_EXCEPTION_DELETED_ONE
	Se ha eliminado 121 una entrada de la lista de clones permitidos.
OPER_EXCEPTION_DELETED_SEVERAL
	Se ha eliminado 12%d entradas de la lista de clones permitidos.
OPER_EXCEPTION_CLEARED
	La lista de clones permitidos ha sido purgada.
OPER_EXCEPTION_LIST_HEADER
	Lista de clones permitidos actual:
# number, limit, host
OPER_EXCEPTION_LIST_COLHEAD
	12Índice   12Límite  12Dirección IP 
OPER_EXCEPTION_LIST_FORMAT
	%3d     %4d       %s
# number, mask, set-by, set-time, expires, limit, reason
OPER_EXCEPTION_VIEW_FORMAT
	%3d.  12%s  (Agregado por 12%s el %s; %s) Límite: 12 %-4d
	       Motivo: 12%s
OPER_EXCEPTION_CHECK_SYNTAX
	12EXCEPTION CHECK dirección-ip
OPER_EXCEPTION_CHECK_NO_MATCH
	No se encontraron máscaras similares a 12%s en la lista de clones permitidos.
OPER_EXCEPTION_CHECK_HEADER
	Direcciones IP similares a 12%s en la lista de clones permitidos:
OPER_EXCEPTION_CHECK_TRAILER
	Se encontraron 12%d máscaras similares.
OPER_EXCEPTION_COUNT
	Existen 12%d entradas en la lista de clones permitidos.
OPER_EXCEPTION_INVALID_LIMIT
	Límite de clones inválido; el límite debe ser al menos 1 y no mayor que 12%d.
OPER_EXCEPTION_INVALID_HOSTMASK
	La dirección IP que ingresaste no es válida.

# SESSION responses
OPER_SESSION_SYNTAX
	12CONEXIONES {LIST Límite | VIEW Dirección-IP}
OPER_SESSION_LIST_SYNTAX
	12CONEXIONES LIST Límite
OPER_SESSION_VIEW_SYNTAX
	12CONEXIONES VIEW Dirección-IP
OPER_SESSION_INVALID_THRESHOLD
	El límite ingresado es inválido; el límite debe ser un entero mayor que 121.
OPER_SESSION_NOT_FOUND
	No se encontraron coincidencias para la IP 12%s .
OPER_SESSION_LIST_HEADER
	IPs con al menos 12%d conexiones simultáneas activas:
OPER_SESSION_LIST_COLHEAD
	Conexiones    IP
# Límite, Proveedor
OPER_SESSION_LIST_FORMAT
	%6d           %s
# provee, sesiones, límite
OPER_SESSION_VIEW_FORMAT
	La IP 12%s  tiene actualmente 12%d conexiones simultáneas activas, (Límite contratado: 12%d).


###########################################################################
#
# News system messages
#
###########################################################################

NEWS_LOGON_TEXT
	[Notícias - %s] %s
NEWS_OPER_TEXT
	[Notícias De Operador - %s] %s

NEWS_LOGON_SYNTAX
	12LOGONNEWS {ADD | DEL | LIST} [Texto | Núm]
NEWS_LOGON_LIST_HEADER
	Listado De Notícias:
NEWS_LOGON_LIST_ENTRY
	%5d (%s por %s)
	    %s
NEWS_LOGON_LIST_NONE
	No existen artículos noticiosos.
NEWS_LOGON_ADD_SYNTAX
	12LOGONNEWS ADD Texto
NEWS_LOGON_ADD_FULL
	¡La lista de notícias está llena!
NEWS_LOGON_ADDED
	Nuevo artículo notícioso agregado (12#%d).
NEWS_LOGON_DEL_SYNTAX
	12LOGONNEWS DEL {Núm | ALL}
NEWS_LOGON_DEL_NOT_FOUND
	¡El artículo notícioso 12#%d no fue encontrado!
NEWS_LOGON_DELETED
	Artículo notícioso 12#%d borrado.
NEWS_LOGON_DEL_NONE
	¡No existe artículo notícioso alguno que borrar!
NEWS_LOGON_DELETED_ALL
	Todos los artículo notícioso borrados.

NEWS_OPER_SYNTAX
	12OPERNEWS {ADD | DEL | LIST} [Texto | Núm]
NEWS_OPER_LIST_HEADER
	Artículos notíciosos para operadores:
NEWS_OPER_LIST_ENTRY
	%5d (%s por %s)
	    %s
NEWS_OPER_LIST_NONE
	No existen artículos noticiosos para los Operadores.
NEWS_OPER_ADD_SYNTAX
	12OPERNEWS ADD Texto
NEWS_OPER_ADD_FULL
	¡La lista de notícias está llena!
NEWS_OPER_ADDED
	Nuevo artículo notícioso de Operadores agregado (12#%d).
NEWS_OPER_DEL_SYNTAX
	12OPERNEWS DEL {Num | ALL}
NEWS_OPER_DEL_NOT_FOUND
	¡El artículo notícioso de Operadores 12#%d no fue encontrado!
NEWS_OPER_DELETED
	Artículo notícioso de Operadores 12#%d borrado.
NEWS_OPER_DEL_NONE
	¡No existe artículo notícioso de Operadores alguno que borrar!
NEWS_OPER_DELETED_ALL
	Todos los artículos notíciosos de Operadores borrados.

NEWS_HELP_LOGON
	Sintaxis: 12LOGONNEWS ADD Texto
	        12LOGONNEWS DEL {Núm | ALL}
	        12LOGONNEWS LIST
	
	Edita o muestra la lista de artículos notíciosos.  Cuando los
	usuarios se conectan a la red, estos mensajes serán enviados
	a ellos.  (Sin embargo, no más de tres mensajes les serán
	enviados para asi evitar un ahógo (flood) del usuario.  Si hay
	más de tres mensajes notíciosos, solo los tres más recientes
	serán enviados.)
	
	12LOGONNEWS LIST puede ser usado por cualquier operador de IRC para
	listar los mensajes notíciosos actuales.  ADD y DEL solo pueden ser
	usados por los Operadores de los Servicios.

NEWS_HELP_OPER
	Sintaxis: 12OPERNEWS ADD Texto
	        12OPERNEWS DEL {Núm | ALL}
	        12OPERNEWS LIST
	
	Edita o muestra la lista de mensajes notíciosos de operadores.
	Cuando un usuario se hace Operador (con el comando 12/OPER), estos
	mensajes le serán enviados.  (Sin embargo, no más de tres mensajes
	serán enviados asi evitando un ahógo (flood) del usuario.  Si hay
	más de tres mensajes notíciosos, solo los tres más recientes
	serán enviados.)
	
	12OPERNEWS LIST puede ser usado por cualquier operador de IRC para
	listar los mensajes notíciosos al Operador actuales.  12ADD y 12DEL solo
	pueden ser usandos por los Operadores de los Servicios.


###########################################################################
#
# StatServ messages
#
############################################################################

# General SERVERS responses
STAT_SERVERS_REMOVE_SERV_FIRST
	Servidor 12%s está en línea. Remuevalo de la red y trate nuevamente.
STAT_SERVERS_SERVER_EXISTS
	Servidor 12%s ya existe.

# SERVERS command syntax
STAT_SERVERS_SYNTAX
	12SERVERS Opción Parámetros

# STATS responses
STAT_SERVERS_STATS_TOTAL
	Total de Servidores: 12%2d
STAT_SERVERS_STATS_ON_OFFLINE
	       En línea: 12%2d (12%d%%)  No en línea: 12%2d (12%d%%)
STAT_SERVERS_LASTQUIT_WAS
	    Última Desconexión: 12%-30s 12%s

# LIST responses
STAT_SERVERS_LIST_HEADER
	Servidor                       Usuarios   Operadores
STAT_SERVERS_LIST_FORMAT
	%-30s %3d (%2d%%)  %3d (%2d%%)
STAT_SERVERS_LIST_RESULTS
	Fín del listado -- 12%d/12%d servidores en línea mostrados.

# VIEW responses
STAT_SERVERS_VIEW_HEADER_ONLINE
	12%-30s  (En línea)
STAT_SERVERS_VIEW_HEADER_OFFLINE
	12%-30s  (Fuera de línea)
STAT_SERVERS_VIEW_LASTJOIN
	    Última conexión: 12%s
STAT_SERVERS_VIEW_LASTQUIT
	    Última desconexión: 12%s
STAT_SERVERS_VIEW_QUITMSG
	 Mensaje de salida: 12%s
STAT_SERVERS_VIEW_USERS_OPERS
	        Usuarios: 12%3d (12%2d%%)  Operadores: 12%3d (12%2d%%)
STAT_SERVERS_VIEW_RESULTS
	Fín del listado -- 12%d/12%d servidores mostrados.

# DELETE responses
STAT_SERVERS_DELETE_SYNTAX
	12SERVERS DELETE Servidor
STAT_SERVERS_DELETE_DONE
	Estadísticas para el servidor 12%s han sido borradas.

# COPY responses
STAT_SERVERS_COPY_SYNTAX
	12SERVERS COPY Servidor Nuevo-Nombre
STAT_SERVERS_COPY_DONE
	Estadísticas para el servidor 12%s copiadas a 12%s.

# RENAME responses
STAT_SERVERS_RENAME_SYNTAX
	12SERVERS RENAME Servidor Nuevo-Nombre
STAT_SERVERS_RENAME_DONE
	Estadísticas para el servidor 12%s renombradas a 12%s.

# USERS responses
STAT_USERS_SYNTAX
	USERS STATS
STAT_USERS_TOTUSERS
	             Total de usuarios: 12%d
STAT_USERS_TOTOPERS
	             Total de operadores: 12%d
STAT_USERS_SERVUSERS
	Average de usuarios por servidor: 12%d
STAT_USERS_SERVOPERS
	Average de operadores por servidor: 12%d.%d

###########################################################################
#
# AdminServ system messages
#
###########################################################################
ADMIN_ELINE_VIEW_FORMAT
	%d    %s (Agregado por 12%s el %s expira en 12%s)
	    Motivo: 12%s
ADMIN_ELINE_LIST_FORMAT
	   %d     %s
ADMIN_ELINE_LIST_HEADER
	Lista de E-Lines
ADMIN_ELINE_LIST_COLHEAD
	12Indice     12Mascara
ADMIN_ELINE_DELETED_ONE
	Se ha eliminado 121 registro de la lista de E-Lines.
ADMIN_ELINE_DELETED_SEVERAL
	Se borraron 12%s registros de la lista de E-Lines.
ADMIN_ELINE_DELETED
	La máscara 12%s ha sido borrada de la lista de E-Lines.	
ADMIN_ELINE_NO_MATCH
	No existe ningún registro que concuerde en la lista de E-Lines.
ADMIN_ELINE_EMPTY
	La lista de E-Lines se encuentra vacía.

###########################################################################
#
#
# NickServ messages
#
###########################################################################

CREG_ESTADO_REGISTRADO
	Estado : 3REGISTRADO
CREG_ESTADO_ENPROCESO_REG
	Estado : En proceso de registro.
CREG_ESTADO_DENEGADO
	Estado : 4DENEGADO
	
###########################################################################
#
# NickServ help messages
#
###########################################################################

NICK_HELP
	3%S le permite "registrar" un nick y previene el que
	otros hagan uso de él.
	Los siguientes comandos permiten el registro y mantenimiento de
	nicks; para utilizarlos, escribe 12/msg %S comando.
	 
	Para más información sobre un comando
	específico, escriba 12/msg %S HELP Comando.
	 
	Registro
	    12REGISTER   Registra un nick
	 
	Identificación y uso del nick
	     12GHOST      Desconecta una sesión fantasma de tu nick
	 
	Gestion de contraseñas
	    12SET PASSWORD       Cambia la contraseña de tu nick.
	    12SENDPASS        Envía la contraseña del nick al e-mail asociado al nick
	    12GETNEWPASS      Genera una nueva contraseña de alta calidad para el nick
	                               que ejecuta el comando
	 
	Gestión de e-mail
	    12SET EMAIL  Cambia la cuenta de e-mail asociada al nick que ejecuta el comando.
	 
	Administración de opciones
	    12SET         Para ajustar opciones asociadas al nick.
	 
	Otros Comandos
	    12INFO       Muestra la información de un nick dado
	    12LISTCHANS  Lista los canales donde tienes acceso.
	    12STATUS     Informa del estado de un nick (registrado, suspendido, utilizado)
	    12VERIFY      Informa si un nick es representante de la RED
NICK_HELP_EXPIRES
	
	Si el nick NO se utiliza durante 12%s, caducará el registro y
	el nick estará disponible para que cualquier persona lo vuelva a
	utilizar.
NICK_HELP_WARNING
	
	4NOTA: Este servicio está diseñado para proveer un modo en que los usuarios del IRC
	aseguran que su identidad no sea suplantada. Su intención 4NO es facilitar el "robo"
	de nicks o otras acciones mal intencionadas. Todo abuso de 3%S resultara en la pérdida
	de el/los nick(s) abusivo(s).

NICK_HELP_COMMANDS
	Los siguientes comandos pueden ser utilizados con 12%S:
	
	    12REGISTER     Registre un nick
	    12IDENTIFY     Identifiquese con su contraseña
	    12DROP         Cancele el regístro de un nick
NICK_HELP_COMMANDS_AUTH
	    12AUTH         Autentique el regístro de un nick
	    12SENDAUTH     Envie a sí mismo el código de autenticación de un nick
	    12REAUTH       Genere un nuevo código si usted olvido su contraseña
	    RESTOREMAIL  Restaure la última dirección autenticada de correo electrónico
NICK_HELP_COMMANDS_LINK
	    12LINK         Ligue otro nick al suyo
	    12UNLINK       Cancele un nick asociado previamente
	    12LISTLINKS    Aliste todos los nicks que usted ha asociado
NICK_HELP_COMMANDS_ACCESS
	    12ACCESS       Modifique la lista de direcciones autorizadas
NICK_HELP_COMMANDS_AJOIN
	    12AJOIN        Modifique su lista de auto-ingreso (autojoin)
NICK_HELP_COMMANDS_SET
	    12SET          Ajuste opciones, incluyendo protección de kill
	    12UNSET        Re-configure la información del nick
	    12RECOVER      Desconecte otro usuario que este usando su nick
	    12RELEASE      Tome custodia de su nick después de utilizar RECOVER
	    12GHOST        Desconecte una sesión "fantasma"
	    12INFO         Muestra información sobre un nick
NICK_HELP_COMMANDS_LIST
	    12LIST         Alista todos los nicks que concuerden con una máscara dada
	    12LISTEMAIL    Alista nicks segun su dirección electrónica (E-Mail)
NICK_HELP_COMMANDS_LISTCHANS
	    12LISTCHANS    Alista todos los canales que usted posee
	    12STATUS       Asegurese si se han identificado correctamente por un nick dado

NICK_HELP_REGISTER
	Sintaxis: 12REGISTER direccion@correo.electronico
	 
	Uso: Registra tu nick la base de datos de 3%S.

	La dirección de correo que especifiques debe ser una a la cual tengas acceso, para que
	puedas recibir el mensaje con la clave del nick que registres.
	Si en 1224 horas no utilizas el nick que registraste éste expirará y estará disponible para registro nuevamente.	
NICK_HELP_REGISTER_EMAIL
	
	Usted puede incluír una dirección de correo electrónico (e-mail)
	cuando registre su nick; también puede fijar una más tarde usando
	el comando 12SET EMAIL.
NICK_HELP_REGISTER_EMAIL_REQ
	
	Usted debe incluír una dirección de correo Electrónico (e-mail)
	cuando registre su nick. Usted puede prevenir que su correo
	electrónico sea mostrado a otros usuarios con el comando 12SET HIDE
	(Escriba 12/msg %S HELP SET HIDE para más información).
NICK_HELP_REGISTER_EMAIL_AUTH
	
	Usted debe incluír una dirección válida de correo electrónico
	cuando registre su nick; %S enviará un mensaje con un código
	de autenticación a esta dirección, el cual usted deberá usar con
	el comando 12AUTH para completar su registración.  Usted puede
	prevenir que su correo electrónico (E-mail) sea mostrado a otros
	usuarios con el comando 12SET HIDE (Escriba 12/msg %S HELP SET HIDE
	para más información).
NICK_HELP_REGISTER_END
	
	Sugerencias para escoger contraseñas:
	
	Contraseñas no deben ser fácil de adivinar.  Por ejemplo,
	usar su verdadero nombre como contraseña es una mala idea.
	Usar su nick como contraseña es una idea peor ;) y, por
	supuesto que, %S no lo permitirá.  También, contraseñas
	cortas son vulnerables a búsquedas de prueba y error, por lo
	que usted debe escoger una contraseña de por lo menos 5
	caracteres.

NICK_HELP_IDENTIFY
	Sintaxis: 12IDENTIFY Contraseña
	
	Notifica a %S que usted es el verdadero dueño de este
	nick.  Muchos de los comandos requieren que usted se
	identifique con este comando antes de poder utilizarlos.  La
	contraseña debe ser la misma que utilizó con el comando
	12REGISTER.

NICK_HELP_DROP
	Sintaxis: 12DROP Contraseña
	
	Cancela (borra) su nick de la base de datos de 12%S.
	Un nick que ha sido borrado está disponible para que
	cualquier persona lo vuelva a registrar.
NICK_HELP_DROP_LINK
	
	Note que cuando usted cancele un nick, todos los nicks asociados a este
	serán borrados también. Para cancelar la asocia de solamente un nick,
	utilice el comando 12UNLINK.
NICK_HELP_DROP_END
	
	Para prevenir el uso accidental de este comando, usted debe entrar
	su contraseña para poder cancelar (borrar) su nick.

NICK_HELP_AUTH
	Sintaxis: 12AUTH Código
	
	Autentica la registración o cambio de correo para un nick.
	Para asegurarse que su correo electrónico es correcto, 12%S
	enviará un mensaje que contendrá un código de autenticación
	a la dirección electrónica dada cuando registre su nick o
	cambie su dirección electrónica con el comando 12SET EMAIL.
	Este comando le permite a usted confirmar que ha recibido el
	mensaje y continuar usando su nick normalmente.  Reemplace
	Código en el comando con el código de autenticación de nueve
	dígitos especificado en el mensaje electrónico (E-mail).
	
NICK_HELP_SENDAUTH
	Sintaxis: 12SENDAUTH
	
	Le envia a usted una copia del código de autenticación para
	su nick despues de un 12REGISTER o 12SET EMAIL.  Si por accidente
	usted borra o pierde el mensaje con el código de autenticación,
	usted puede utilizar este comando para recibir una copia extra.
	
	Para prevenir abuso, este comando solo puede ser usado una vez
	cada 24 horas.

NICK_HELP_REAUTH
	Sintaxis: 12REAUTH
	
	Establece un código de autenticación el cual usted puede usar
	para identificarse por su nick.  Si se olvida de la contraseña
	de su nick, use este comando para generar un nuevo código de
	autenticación, entonces provea este código (el cual le será
	enviado) con el comando 12AUTH para identificarse por su nick;
	despues le será posible cambiar la contraseña con el comando
	12SET PASSWORD como se hace usualmente.

NICK_HELP_RESTOREMAIL
	Sintaxis: 12RESTOREMAIL Contraseña
	
	Recobra la última dirección de correo electrónico autenticada
	para su nick.  Si usted accidentalmente indica una dirección
	erronea con el comando 12SET EMAIL, puede utilizar este comando
	para recobrar la dirección de correo electrónico usada
	previamente y eliminar el código de autenticación para su
	nick, permitiendole a usted identificarse por el nick
	nuevamente. Usted debe proveer la contraseña para su nick
	con este comando.
	
	12RESTOREMAIL solo puede ser usado despues de 12SET EMAIL y antes
	de entrar el nuevo código de autenticación con el comando 12AUTH.

NICK_HELP_LINK
	Sintaxis: 12LINK nick
	
	asocia un nuevo nick al nick que usted está usando, creando
	asi un nuevo "alias" para su nick. El nuevo nick será
	equivalente a su nick actual en terminos de privilegios de
	acceso y mensajes; por ejemplo, usted puede leer mensajes
	enviados a uno de sus nicks asociados mientras usa cualquiera
	de sus otros nicks, y si uno de sus nicks tiene privilegios
	de auto-op en un canal, usted obtendrá estatus de operador sin
	importar cual de sus nicks asociados esté utilizando.
	
	Para cancelar una asocia, use el comando 12UNLINK.
	
	Para poder utilizar este comando, usted debe identificarse por
	su nick actual (usando el comando 12IDENTIFY), ademas el nick
	que será asociado no puede estar registrado o encontrarse en uso
	en este momento.

NICK_HELP_UNLINK
	Sintaxis: 12UNLINK nick
	
	Remueve una asocia (alias) de su nick creada con el comando
	12LINK. Usted no puede desasociar el nick que está utilizando
	actualmente; cambiese a otro de sus nicks asociados primeramente
	antes de usar este comando.
	
	Si usted desasocia el "main nick" (nick Principal) que seleccionó
	usando el comando 12SET MAINNICK, su nick actual será automáticamente
	seleccionado como el nick principal (main nick).

NICK_HELP_LISTLINKS
	Sintaxis: 12LISTLINKS
	
	Alista todos los nicks que esten asociados a su nick. El nick
	principal para el grupo de nicks asociados será indicado por un
	signo "*" a la izquierda del nick.

NICK_HELP_ACCESS
	Sintaxis: 12ACCESS ADD Máscara
	          12ACCESS DEL Máscara
	          12ACCESS LIST
	
	Modifica o muestra la lista de acceso para su nick. Esta es la
	lista de direcciones usuario@proveedor que serán automáticamente
	reconocidas por %S como autorizadas para usar el nick.  Si usted
	se conecta a IRC con una dirección incluída en dicha lista, usted no
	será afectado por la configuración 12SET KILL fijada en su nick, y si
	la opción SECURE está disahabilitada, le será posible recibir los
	privilegios de auto-op y otros privilegios en los canales sin utilizar
	el comando 12IDENTIFY.
	
	La Máscara dada con los comandos 12ADD y 12DEL pueden contener
	comodínes (12* o el signo 12?).
	
	Ejemplos:
	
	    12ACCESS ADD achurch@*.dragonfire.net
	        Permite acceso al usuario 12achurch desde cualquier
	        computadora en el dominio 12dragonfire.net.
	
	    12ACCESS DEL achurch@*.dragonfire.net
	        Hace lo contrario al comando anterior.
	
	    12ACCESS LIST
	        Muestra la lista de acceso actual.

NICK_HELP_REQUESTPASSWORD
	Sintaxis: 12RESETPASS nick correo@electronico
	 
	Uso: Envía un código de autorizacíon al correo del nick para el restablecimiento de la contraseña.
	Si en 1224 horas no se hace uso del código de autorización éste expirará y no tendrá validés.
	  
	4NOTA: El correo que se especifique debe ser el mismo con el que se registro el nick.
NICK_HELP_SET
	Sintaxis: 12SET Opción Parámetros
	
	Uso: Ajusta varios parámetros del nick. Una opción puede ser:
	 
	Opciones de seguridad
	    12PASSWORD   Ajusta la contraseña de tu nick
	 
	Opciones de Información
	    12URL        Asocia una URL con tu nick
	    12EMAIL      Cambia la cuenta de e-mail asociada al nick que ejecuta el comando.
	    12HIDEMAIL   Oculta tu e-mail de registro en un INFO
	    12TIMEZONE   Ajusta el uso horario a utilizarse para mostrar la hora
	 	 
	Opciones para Canales
	    12NEVEROP    Previene que seas agregado a una lista de acceso.
	 
	Escribe 12/MSG %S HELP SET opción para mas información sobre una opción específica.
NICK_HELP_SET_OPTION_MAINNICK
	    MAINNICK   Fija el nick mostrado en las listas de acceso de canales
NICK_HELP_SET_END
	
	Para utilizar este comando es necesario identificarse antes
	con su contraseña. Escriba (12/msg %S HELP IDENTIFY para
	mayor información).
	
	Escriba 12/msg %S HELP SET Opción para mayor información
	sobre una opción especifica.

NICK_HELP_SET_PASSWORD
	Sintaxis: 12SET PASSWORD Nueva-Contraseña
	
	Cambia la contraseña que utiliza para identificarse como el
	dueño del nick.

NICK_HELP_SET_LANGUAGE
	Sintaxis: 12SET LANGUAGE Número
	
	Cambia el lenguaje que los Servicios utilizan cuando envían
	mensajes a usted (por ejemplo cuando responden a un comando
	que usted envió). Número debe ser escogido de la siguiente
	lista de lenguajes disponibles:
	

NICK_HELP_SET_URL
	Sintaxis: 12SET URL url
	
	Asocia el URL dado con su nick.  Este URL será  mostrado
	cuando alguien solicite información sobre su nick con el
	comando 12INFO.

NICK_HELP_SET_EMAIL
	Sintaxis: 12SET EMAIL Dirección
	
	Asocia la dirección de E-mail (Correo-Electrónico) dada con su nick.
	Esta dirección será mostrada cuando alguien solicite información
	sobre su nick con el comando 12INFO.

NICK_HELP_SET_HIDEMAIL
	Sintaxis: 12SET HIDEMAIL {ON | OFF}
	 
	Activa/desactiva la opción de poder esconder tu dirección de correo desde un 12INFO.

NICK_HELP_SET_INFO
	Sintaxis: 12INFO nick
	 
	Uso: Muestra información sobre un nick dado, como el quien es
	el dueño, última dirección utilizada y hora, y las
	diferentes opciones del nick. Si se identificó por el nick dado,
	se le mostrará toda la información;
	independientemente si está escondida o no.

NICK_HELP_SET_KILL
	Sintaxis: 12SET KILL {ON | QUICK | IMMED | OFF}
	
	Activa/desactiva la protección de kill para su nick. Con
	protección de kill activada, si algún otro usuario intenta
	utilizar su nick, se le dará un minuto para que cambie a
	otro, o será removido forzosamente de IRC por 12%S.
	
	Si selecciona 12QUICK, el usuario solo tendrá 20 segundos para
	cambiar de nick en lugar de lo usual (60 segundos).  Si
	seleccionas 12IMMED, el usuario será desconectado (killed)
	inmediatamente sin ser avisado primero o darle una
	oportunidad de cambiar de nick, favor de no utilizar esta
	opción a menos que sea verdaderamente necesario.  Los
	Administradores de la red pueden haber deshabilitado esta opción.

NICK_HELP_SET_NEVEROP
	Sintaxis: 12SET NEVEROP {ON | OFF}
	 
	Cuando esta activado previene ser aregado a listas de acceso de canales.

NICK_HELP_SET_SECURE
	Sintaxis: 12SET SECURE {ON | OFF}
	
	Activa/desactiva las funciones de seguridad de 12%S para
	su nick. Con 12SECURE activado, usted deberá enviar su
	contraseña antes de que se le reconozca como el dueño de
	el nick, sin importar si su dirección este o no en la lista
	de acceso.  Sin embargo, si aparece en la lista de acceso,
	%S no lo desconectará automáticamente, independientemente
	de como este la opción de 12KILL.

NICK_HELP_SET_PRIVATE
	Sintaxis: 12SET PRIVATE {ON | OFF}
	
	Activa/desactiva la opción privacidad de 12%S sobre su
	nick. Con 12PRIVATE activado, su nick no aparecerá en las
	listas de nicks generadas con el comando 12%S LIST.
	(Sin embargo, cualquiera que conozca su nick puede obtener
	información usando el comando 12INFO.)

NICK_HELP_SET_NOOP
	Sntaxis: 12SET PRIVATE NOOP {ON | OFF}

NICK_HELP_SET_HIDE
	Sintaxis: 12SET HIDE {EMAIL | USERMASK | QUIT} {ON | OFF}
	
	Permite que usted evite que ciertos datos e información
	sean mostradas cuando alguien usa el comando 12%S INFO en su
	nick. Usted puede esconder su correo electrónico (12EMAIL),
	última máscara usuario@host (12USERMASK), o su último mensaje
	de salida (12QUIT).  El segundo parámetro especifica cual
	información debe ser mostrada (12OFF) o escondida (12ON).

NICK_HELP_SET_TIMEZONE
	Sintaxis: 12SET TIMEZONE {UTC-Más/Menos | Uso-Horario | DEFAULT}
	
	Ajusta el uso horario a utilizarse para mostrar la hora (Como por
	ejemplo la última vez que un canal fue usado), en lugar de utilizar
	el uso horario en el cual los servicios operan; la opcción 12DEFAULT
	puede usarse para retornar al uso horario original de los Servicios.
	El uso horario puede ser especificado en una de estas dos formas:
	
	   - Como en 12UTC Más/Menos, la diferencia de hora entre su hora
	     local y la UTC (Tiempo Universal Coordinado, también conocido
	     como GMT, Greenwich Mean Time). La diferencia "más" o "menos"
	     es dada con los signos "+" o "-" indicando antes (este) o detras
	     (oeste) de UTC, seguido por o bien un número completo de horas o
	     por una linea en el formato "12hh:mm".
	
	   - Como en Nombre de uso horario, tal como "12GMT" o "12EDT".  No todos
	     los nombres de usos horarios están disponibles en los Servicios, y
	     los usos horarios de algunos paises tienen el mismo nombre, asi es
	     que si usted recibe un error o si el uso horario mostrado por los
	     servicios es incorrecto, use un UTC más/menos en lugar de un nombre.
	
	Note que los Servicios no se ajustarán a si mismos automáticamente para
	el horario de verano; usted necesitará ajustar el uso horario de su
	preferencia manualmente.
	
	Ejemplos:
	
	    12SET TIMEZONE -5
	        Ajuste el uso horario a 5 horas detras de UTC.
	
	    12SET TIMEZONE +3:30
	        Ajuste el uso horario a 3 horas, 30 minutos antes de UTC.
	
	    12SET TIMEZONE JST
	        Ajuste el uso horario al Horario Estandar Japones (UTC+9:00).

NICK_HELP_SET_MAINNICK
	Sintaxis: 12SET MAINNICK nick
	
	Cuando usted tiene multiples nicks asociados, este comando le permite
	seleccionar cual se muestra en las listas de acceso de canales.  Si
	usted desasocia este nick posteriormente, entonces uno diferente
	será seleccionado automáticamente.

NICK_HELP_UNSET
	Sintaxis: 12UNSET {URL | EMAIL | INFO}
	
	Le permite borrar el URL (12URL), correo electrónico (12EMAIL),
	o el texto de la información (12INFO) asociada a su nick.

NICK_HELP_UNSET_REQ_EMAIL
	Sintaxis: 12UNSET {URL | INFO}
	
	Le permite borrar el URL (12URL) o texto de la información (12INFO)
	asociada a su nick.

NICK_HELP_RECOVER
	Sintaxis: 12RECOVER nick [Contraseña]
	
	Permite que usted recupere su nick si alguien más lo ha
	tomado; esto es lo mismo que %S hace automáticamente si
	alguien intenta utilizar un nick protegido con kill.
	
	Cuando usted envía este comando, %S conectará en línea
	a un usuario falso con el mismo nick del usuario del cual
	usted desea recuperar su nick. Esto causará que los
	servidores de IRC desconecten al otro usuario. Este usuario
	falso permanecerá en línea por %s para asegurar que
	el otro usuario no se reconecte inmediatamente; después de
	ese tiempo, usted puede reclamar su nick.  Alternativamente,
	use el comando 12RELEASE (12/msg %S HELP RELEASE) para obtener
	su nick más rápidamente.
	
	Para poder usar el comando 12RECOVER para un nick, usted debe
	suplir la contraseña correcta para ese nick, o usted debe haberse
	ya identificado por un nick asociado a el nick dado.

NICK_HELP_RELEASE
	Sintaxis: 12RELEASE nick [Contraseña]
	
	Instruye a %S que elimine cualquier retención en su
	nick causada por un kill automático de protección o por el
	uso de el comando 12RECOVER Normalmente, la espera dura
	%s; este comando lo libera más rápidamente.
	
	Para poder usar el comando 12RELEASE para un nick, usted debe
	suplir la contraseña correcta para ese nick, o usted debe haberse
	ya identificado por un nick asociado a el nick dado.

NICK_HELP_GHOST
	Sintaxis: 12GHOST nick [Contraseña]
	
	Termina una sesión "fantasma" de IRC que este utilizando su
	nick.  Una sesión "fantasma" es aquella que no está
	realmente conectada, pero que el servidor de IRC acredita
	como activa por una razón u otra.  Típicamente esto sucede
	si su computadora se atora o su conexión a Internet se
	desconecta muy brevemente mientras usted está en IRC.
	
	Para poder usar el comando 12GHOST para un nick, usted debe
	suplir la contraseña correcta para ese nick, o usted debe haberse
	ya identificado por un nick asociado a el nick dado.

NICK_HELP_INFO
	Sintaxis: 12INFO nick
	
	Muestra información sobre el nick dado, como quien es
	el dueño, última dirección utilizada y hora, y las
	diferentes opciones del nick. Si se identificó por el nick
	del cual está reclamando información y 12ALL es especificado,
	se le mostrará toda la información; independientemente de si
	esta esté escondida o no.
NICK_HELP_INFO_AUTH
	
	Si el correo electrónico del nick no ha sido aún confirmado con
	el comando AUTH, no será mostrado a nadie excepto a el dueño de el
	nick y a los Administradores de los Servicios, independientemente
	de la configuración SET HIDE EMAIL estableciada para el nick.

NICK_HELP_LISTCHANS
	Sintaxis: 12LISTCHANS
	
	Lista los nombres y el número total de canales que usted
	ha registrado bajo su nick.

NICK_HELP_LIST
	Sintaxis: 12LIST [+Inicio] Patrón
	
	Alista todos los nicks registrados para los cuales o bien el nick
	mismo o la  última dirección vista (en el formato Usuario@Proveedor-web)
	concuerdan con el patrón dado.  nicks con la opción PRIVATE activada no
	serán mostrados. Si el parámetro "Inicio" es dado, se está especificando
	cuantas entradas similares han de ser ignoradas antes de mostrar los resultados
	(por ejemplo, +50 causaria que las primeras 50 entradas similares fueran
	ignoradas).
	
	Ejemplos:
	
	    12LIST joeuser@foo.com
	        Lista todos los nicks registrados que fueron usados últimamente
	        por joeuser@foo.com.
	
	    12LIST *Bot*!*@*
	        Lista todos los nicks registrados que contengan Bot en sus
	        nombres (no importan las mayúsculas).
	
	    12LIST *@*.bar.org
	        Lista todos los nicks registrados que fueron  usados últimamente por
	        usuarios del dominio bar.org.
NICK_HELP_LIST_OPERSONLY
	
	Solamente los operadores de IRC pueden utilizar este comando.

NICK_HELP_LISTEMAIL
	Sintaxis: 12%s
	
	Alista nicks registrados al igual que el comando 12LIST, pero lo hace
	basado en la dirección de correo electrónico en lugar de Usuario@proveedor-web.
	Vea el comando de ayuda para LIST (12/msg %S HELP LIST) para obtener
	más información.

NICK_HELP_STATUS
	Sintaxis: 12STATUS nick...
	
	Informa si el usuario de un nick es reconocido como el dueño
	del mismo.  La respuesta tiene el siguiente formato:
	
	    nick código-De-Estatus
	
	donde 12nick es el nick enviado con el comando,
	12Código-De-Estatus es uno de los siguientes:
	
	    0 - usuario no está conectado o nick no está registrado
	    1 - usuario no reconocido como dueño del nick
	    2 - usuario reconocido por la lista de acceso solamente
	    3 - usuario reconocido por identificación con contraseña
	
	Hasta 16 nicks pueden ser enviados con cada comando; el
	resto serán ignorados. No se genera mensaje de error alguno si
	no se envía un nick.

NICK_HELP_AJOIN
	Sintaxis: 12AJOIN ADD Canal
	          12AJOIN DEL Canal
	          12AJOIN LIST
	
	Modifica o muestra la lista de auto ingreso (autojoin) para
	su nick.  Esta es la lista de canales a los cuales le
	gustaria ser llevado automáticamente, y va a surtir efecto
	cuando usted se identifica a %S.  Note que usted
	solamente puede incluír nombres de canales que comiencen con
	"#" en la lista de auto ingreso (canales locales no pueden
	ser incluidos).
	
NICK_HELP_AJOIN_END
	Note que el servidor de IRC pudiera prohibirle el ingreso a
	algunos de los canales en la lista de auto ingreso, tales
	canales incluyen aquellos a los cuales le ha sido fijado una
	llave (modo +k) o que se han fijado como invitación-solamente
	(modo +i).
NICK_HELP_AJOIN_END_CHANSERV
	Note que el servidor de IRC pudiera prohibirle el ingreso a
	algunos de los canales en la lista de auto ingreso, tales
	canales incluyen aquellos a los cuales le ha sido fijado una
	llave (modo +k) o que se han fijado como invitación-solamente
	(modo +i).  Sin embargo, si usted tiene acceso al comando
	INVITE de %s en un canal registrado, %S le
	invitará automáticamente a usted para que pueda ingresar al
	canal.

NICK_OPER_HELP_COMMANDS
	 
	Comandos para Operadores de Servicios
	    12SUSPEND        Suspende el nick para que no pueda usar los privilegios
	    12UNSUSPEND    Levanta la suspensión del nick
NICK_OPER_HELP_COMMANDS_DROPEMAIL
	    12DROPEMAIL    Cancela todos los nicks que concuerden con una
	                    dirección de correo electrónico especificada
NICK_OPER_HELP_COMMANDS_GETPASS
	    12GETPASS      Muestra la contraseña para un nick
	                    (solo si encripción está desactivada)
NICK_OPER_HELP_COMMANDS_FORBID
	    12FORBID           Previene que un nick pueda ser utilizado 
	    12UNFORBID      Levanta la prohibición de uso de un nick 
NICK_OPER_HELP_COMMANDS_SETAUTH
	    12SETAUTH      Fija un nuevo código de autenticación para un nick
	    12GETAUTH      Muestra el código de autenticación para un nick
	    12CLEARAUTH    Cancela el código de autenticación para un nick
NICK_OPER_HELP_COMMANDS_END
	
	Administradores de Servicios también pueden usar los siguientes
	comandos en cualquier nick sin necesidad de identificarse:
	
	    12SET, 12ACCESS LIST, 12INFO ALL
	
	Vea la ayuda para cada comando para detalles específicos.

NICK_OPER_HELP_DROPNICK
	Sintaxis: 12DROPNICK nick
	
	Remueve el nick dado de la base de datos de 12%S, asi como
	cualquier nick asociado a este.
	
	Límitado a los 04Administradores de servicios.

NICK_OPER_HELP_DROPEMAIL
	Syntax: 12DROPEMAIL Patrón
	        12DROPEMAIL-CONFIRM Patrón
	
	Cancela todos los nicks con una dirección de correo
	electrónico que concuerde con el Patrón dado.  Si Patrón es el
	simple caractér "-", entonces cancelará todos los nicks sin
	una dirección de correo electrónico.
	
	Para prevenir el que accidentalmente se cancelen nicks via
	este comando, se deberá entrar dos veces: primero usando el
	comando llamado 12DROPEMAIL, y despues usando 12DROPEMAIL-CONFIRM
	con el mismo patrón.  El comando 12DROPEMAIL-CONFIRM debe ser
	ejecutado dentro de %s de y por la misma persona que
	ejecutó el comando DROPEMAIL.  Si se dan mas de 4 ejecuciones
	del comando DROPEMAIL continuamente, la mas antigua será
	ignorada y no se le reconoserá mas para una ejecución del
	comando DROPEMAIL-CONFIRM.
	
	Limitado a los 04Administradores De Servicios.

NICK_OPER_HELP_SET
	
	Administradores de Servicios pueden seleccionar la opción
	12NOEXPIRE, con la cual se puede prevenir que algunos nicks
	expiren.  Adicionalmente, los Administradores de Servicios
	pueden establecer opciones para cualquier nick sin necesidad
	de proveer una contraseña, utilizando el formato
	12SET !nick Opción Parámetros.

NICK_OPER_HELP_SET_NOEXPIRE
	Sintaxis: 12SET [!nick] NOEXPIRE {ON | OFF}
	
	Define si el nick dado expirará.  Si se define 12ON previene
	que el nick expire.  Si no se incluye un nick, entonces se
	aplica a tu propio nick.
	
	Limitado a los 04Administradores De Servicios.

NICK_OPER_HELP_UNSET
	
	Administradores de Servicios pueden usar el comando UNSET en
	cualquier nick por medio de añadir !nick antes del nombre
	de la opción, como en el comando SET.

NICK_OPER_HELP_OLD_UNLINK
	
	Administradores de Servicios pueden desasociar cualquier nick sin
	necesidad de enviar una contraseña.

NICK_OPER_HELP_UNLINK
	Sintaxis: 12UNLINK nick [FORCE]
	
	Remueve una asociación (alias) de su nick creada con el
	comando 12LINK.  Usted no puede desasociar el nick que está
	usando actualmente; cambie a otro nick asociado primeramente
	antes de utilizar este comando.
	
	Si usted desasocia el "main nick" (nick Principal) que seleccionó
	usando el comando SET MAINNICK, su nick actual será automáticamente
	seleccionado como el nick principal (main nick).
	
	Los Administradores de servicios pueden agregar la opcción 12FORCE,
	la cual permite remover una asocia de un nick que no les pertenese.

NICK_OPER_HELP_OLD_LISTLINKS
	Sintaxis: 12LISTLINKS nick
	
	Alista los nicks que estén asociados al nick dado.
	
	Limitado a los 04Administradores De Servicios.

NICK_OPER_HELP_LISTLINKS
	Sintaxis: 12LISTLINKS [nick]
	
	Alista todos los nicks que esten asociados a su nick.  El nick
	principal para el grupo de nicks asociados será indicado por un
	signo "*" a la izquierda del nick.  Operadores de Servicios
	pueden alistar asocias para cualquier nick cuando especifican el
	nick en el comando.

NICK_OPER_HELP_ACCESS
	
	Los Administradores de Servicios pueden dar un nick como parámetro en
	el comando LIST para mostrar la lista de acceso de cualquier nick.

NICK_OPER_HELP_INFO
	
	Administradores de Servicios pueden usar parámetro 12ALL en cualquier nick.

NICK_OPER_HELP_LISTCHANS
	
	Administradores de Servicios pueden alistar canales para cualquier nick
	usando el nick con el comando (por ejemplo,
	12/msg %S LISTCHANS Cualquier-nick).

NICK_OPER_HELP_LIST
	Sintaxis: 12LIST [+Inicio] Patrón [FORBIDDEN] [NOEXPIRE] [SUSPENDED]
	
	Alista todos los nicks registrados para los cuales o bien el nick
	mismo o la  última dirección vista (en el formato Usuario@Proveedor-web)
	concuerdan con el patrón dado.  nicks con la opción PRIVATE activada
	serán solamente mostrados a los Administradores de los servicios.  Ellos,
	verán que los nicks con la opción NOEXPIRE activada tendrán un signo !
	antes del nick y aquellos que están suspendidos estarán prefijados con el
	signo * antes del nick.
	
	Si las opciones 12FORBIDDEN, 12SUSPENDED o 12NOEXPIRE son dadas, entonces
	solamente los nicks que, respectivamente, están prohibidos, suspendidos,
	o que tienen la opción NOEXPIRE activada será mostrados.  Las opciones
	pueden ser utilizadas en cualquier orden y en cualquier combinación.
	Estas opciones están limitadas a los 04Administradores de Servicios.
NICK_OPER_HELP_LIST_AUTH
	Sintaxis: 12LIST [+Inicio] Patrón [FORBIDDEN] [NOEXPIRE] [SUSPENDED] [NOAUTH]
	
	Alista todos los nicks registrados para los cuales o bien el nick
	mismo o la  última dirección vista (en el formato Usuario@Proveedor-web)
	concuerdan con el patrón dado.  nicks con la opción PRIVATE activada
	serán solamente mostrados a los Administradores de los servicios.  Ellos,
	verán que los nicks con la opción NOEXPIRE activada tendrán un signo !
	antes del nick, los que están suspendidos estarán prefijados con el signo *
	antes del nick, y aquellos que aún no han sido autenticados (con el comando
	AUTH) tendrán un signo ? antes del nick.
	
	Si las opciones 12FORBIDDEN, 12SUSPENDED, 12NOEXPIRE o 12NOAUTH son dadas,
	solamente los nicks que, respectivamente, están prohibidos, suspendidos, que
	tienen la opción NOEXPIRE activada, o que que no han sido aún autenticados
	será mostrados.  Las opciones pueden ser utilizadas en cualquier orden y en
	cualquier combinación.  Estas opciones están limitadas a los
	04Administradores De Servicios.
NICK_OPER_HELP_LIST_END
	
	Si el parámetro "Inicio" es dado, este especifica cuantas entradas
	similares serán ignoradas antes de mostrar los resultados (por ejemplo, +50
	causaria que las primeras 50 entradas similares fueran ignoradas).
	
	Ejemplos:
	
	    12LIST joeuser@foo.com
	        Alista todos los nicks registrados que fueron usados últimamente
	        por joeuser@foo.com.
	
	    12LIST *Bot*!*@*
	        Alista todos los nicks registrados que contengan Bot
	        en su nombre (no importa mayúsculas).
	
	    12LIST * NOEXPIRE
	        Alista todos los nicks registrados que han sido fijados
	        como nicks que no expirarán.

NICK_OPER_HELP_GETPASS
	Sintaxis: 12GETPASS nick
	
	Muestra la contraseña para el nick dado. Note que cuando
	este comando es utilizado, un mensaje incluyendo el nick de
	la persona que lo utiliza, y el nick sobre el cual se interroga
	es grabado en el archivo de services y enviado como un mensaje global
	(WALLOPS/GLOBOPS).
	
	Este comando pudiera no estar disponible cuando la red está usando encripción,
	dependiendo de el tipo de encripción utilizada.
	
	Limitado a los 04Administradores De Servicios.

NICK_OPER_HELP_UNFORBID
	Sintaxis: 12UNFORBID nick
	 
	Elimina la prohibición de un nick.
	 
	Limitado a los 04Administradores de Servicios.

NICK_OPER_HELP_FORBID
	Sintaxis: 12FORBID nick
	
	Prohibe a todos el regístro y el uso de un nick. Se puede
	revertir utilizando el comando DROP.
	
	Limitado a los 04Administradores De Servicios.

NICK_OPER_HELP_SUSPEND
	Sintaxis: 12SUSPEND [+Expiración] nick Razón
	
	Previene que un nick, y todos aquellos nicks con el mismo
	nick raíz, sean utilizados o que alguien se identifique por
	ellos.  Puede lograrse que un nick deje de estar suspendido
	por medio del comando 12UNSUSPEND, lo cual permitirá que sea
	usado como antes.  El parámetro Expiración es interpretado
	en la misma manera que para el comando 12%s AKILL.
	
	Limitado a los 04Administradores De Servicios.

NICK_OPER_HELP_UNSUSPEND
	Sintaxis: 12UNSUSPEND nick
	
	Permite a los usuarios el uso y habilidad de identificarse por
	un nick previamente SUSPENDido.
	
	Limitado a los 04Administradores De Servicios.

NICK_OPER_HELP_AJOIN
	
	Administradores de servicios pueden ver la lista de auto ingreso (autojoin)
	para cualquier nick con el formato 12LIST nick.

NICK_OPER_HELP_SETAUTH
	Sintaxis: 12SETAUTH nick
	
	Establece un nuevo código de autenticación para el nick dado. El dueño
	del nick tendrá que utilizar el comando AUTH para el nick antes de
	que le sea permitido identificarse nuevamente.   Si el nick está en uso
	actualmente, una notificación (notice) le será enviada al usuario del
	nick y esta persona no será ya más tratada como si se hubiese
	identificado previamente por el nick.
	
	Limitado a los 04Administradores De Servicios.

NICK_OPER_HELP_GETAUTH
	Sintaxis: 12GETAUTH nick
	
	Recobra el código de autenticación asociado con el  nickname,
	si es que realmente existe un código para dicho nick.
	
	Limitado a los 04Administradores De Servicios.

NICK_OPER_HELP_CLEARAUTH
	Sintaxis: 12CLEARAUTH nick
	
	Remueve cualquier código de autenticación asociado con el  nick,
	permitiendo que el nick pueda ser usado normalmente.
	
	Limitado a los 04Administradores De Servicios.

NICK_ADMIN_HELP_COMMANDS
	 
	Comandos para Administradores de Servicios:
	    12BOT                Administra la lista de BOTS Oficiales
	    12AMODES          Administra modos automaticos en nicks
	    12NOEXPIRE      Se establece o no que un nick expire.
	    12FREGISTER     Registra un nick sin pedir confirmación.
	    12DROPNICK      Elimina un nick de la base de datos.

###########################################################################
#
# HostServ help messages
#
###########################################################################

HOST_HELP
	12%S - Servicio de activación de IP's virtuales
	El bot %S te permite activar una IP virtual sobre tu nick
	(ej: soy.el.mejor). De este modo podrás personalizar tu
	apariencia en %s con la IP virtual que más se adecúe a tu
	personalidad.
	 
	Para más información sobre un comando
	específico, escriba 12/msg %S HELP Comando
	 
	Comandos disponibles:
	 
	    - 12ACTIVAR    Este comando te permite activar tu IP virtual
	    - 12ANULAR     Anula tu IP virtual
	 

HOST_HELP_ACTIVAR
	Este comando realiza la activación de tu IP virtual.
	Para tener por ejemplo una virtual que sea soy.el.mejor
	has de poner:
	 
	12/msg ipvirtual activar soy.el.mejor
	 
	La IP virtual ha de satisfacer las siguientes condiciones:
	 
	* Longitud máxima de 63 caracteres
	* Caracteres válidos: a-z, 0-9, - _ . (Espacios y el símbolo @ no se permiten)
	* No puede comenzar por . - _ ni contener 2 o más . _ - seguidos ni ._. ni .-. ni acabar en .
	* No puede contener http www ftp .com .org .net .info ni acabar en org
	* No puede contener "portalzona" ni otros términos reservados ni ser una IP real
	* No puede estar formada sólamente por números
	* El grupo de letras tras el último "." ha de ser de 4 caracteres o más y no contener _ - ni empezar por "org"
	* Si no tiene un "." al menos, ha de tener como mínimo 4 caracteres de longitud y no contener - _
	 
	Sólo se permite un cambio de IP virtual cada 24 horas a contar desde el último cambio
	 
	4**************************************************************************************
	4 El intento de engaño a través del servicio de ipvirtual personalizada puede acarrear
	4la pérdida del nick en la red o del acceso al servicio de IP's virtuales.
	4Asimismo, el abuso del servicio podrá dar lugar a la suspensión del acceso al mismo
	4**************************************************************************************
	 
	 
HOST_HELP_ANULAR
	Sintaxis: 12ANULAR ahora
	 
	Uso: Este comando elimina la IP virtual que tengas configurada.
	Para quitar la IP virtual, escribe:
	 
	12/msg %S anular ahora
	 
	Una vez anulada, no podrás activar una nueva hasta que hayan pasado 24 horas
	 

HOST_OPER_HELP
	Comando para Administradores de Servicios	
	    - 12VHOST    Permite establecer o borrar un vhost a un nick.
	 

HOST_OPER_HELP_VHOST
	Sintaxis: 12VHOST [SET|NONE] nick vhost
	 
	Uso: Permite establecer o eliminar el vhost de un usuario opciones disponibles:
	 
	12SET - Establecer un vhost para un nick.
	12NONE - Elimina el vhost de un usuario.
	 

###########################################################################
#
# ChanServ help messages
#
###########################################################################

# Used in OP/VOICE/etc for required access levels for commands
CHAN_HELP_REQSOP_LEVXOP
	nivel 100 (SOP)
CHAN_HELP_REQSOP_LEV
	level 100
CHAN_HELP_REQSOP_XOP
	SOP
CHAN_HELP_REQAOP_LEVXOP
	nivel 50 (AOP)
CHAN_HELP_REQAOP_LEV
	nivel 50
CHAN_HELP_REQAOP_XOP
	AOP
CHAN_HELP_REQHOP_LEVXOP
	nivel 40 (HOP)
CHAN_HELP_REQHOP_LEV
	nivel 40
CHAN_HELP_REQHOP_XOP
	HOP
CHAN_HELP_REQVOP_LEVXOP
	nivel 30 (VOP)
CHAN_HELP_REQVOP_LEV
	nivel 30
CHAN_HELP_REQVOP_XOP
	VOP

# Real help messages start here
CHAN_HELP
	3%S permite controlar varios aspectos de los canales. 3%S puede
	prevenir que usuarios malintencionados puedan "tomar" el control limitando
	a quién se permite privilegios de operador del canal.
	Los comandos disponibles son los siguientes.  Para utilizarlos,
	escriba /msg 12%S comando.
	Para obtener más información de un comando específico, 
	escriba /msg 12%S HELP comando.
	 
	Comandos de administración de canal
	    12IDENTIFY     Para identificarse como fundador del canal
	    12ACCESS       Modifica la lista de usuarios privilegiados
	    12LEVELS       Redefine los niveles de accesos
	    12SET          Fija opciones e información del canal
	    12UNSET        Elimina información del canal
	    12AKICK        Mantiene la lista de Auto-Kick
	    12CLEAR        Limpia ciertas opciones del canal
	    12DELSUCCESSOR Permite renunciar a ser el sucesor
	 
	Comandos para operadores de canales
	    12INVITE       Te invita a un canal
	    12VOICE        Da VOZ en un canal
	    12DEVOICE      Quita VOZ en un canal
	    12OP           Da OP en un canal
	    12DEOP         Quita OP en un canal
	    12UNBAN        Quita BANs que te afectan en un canal
	    12DELACCESS    Permite borrar tu registro a un canal
	 
	Comandos informativos
	    12INFO         Muestra información referente a un canal
CHAN_HELP_EXPIRES
	
	4ATENCION: si un canal no es utilizado por 12%s (es decir que
	ningún usuario en la lista de acceso del canal entra en ese
	periodo de tiempo) será automáticamente cancelado.

CHAN_HELP_COMMANDS
	Los siguientes comandos pueden ser utilizados con %S:
	
	    12REGISTER   Registre un canal
	    12IDENTIFY   Identifiquese con su contraseña
	    12DROP       Cancele la registración de un canal
	    12SET        Fija opciones e información del canal
	    12UNSET      Remueve información del canal
	    12INFO       Muestra opciones e información del canal
CHAN_HELP_COMMANDS_LIST
	    12LIST       Alista canales registrados
CHAN_HELP_COMMANDS_AKICK
	    12AKICK      Mantiene la lista de AutoKick (AutoPateo)
CHAN_HELP_COMMANDS_LEVELS
	    12ACCESS     Mantiene la lista general de acceso al canal
	    12LEVELS     Fije los niveles de privilegio de acceso al canal en una manera más detallada
CHAN_HELP_COMMANDS_XOP
	    12SOP        Mantiene la lista de SuperOp
	    12AOP        Mantiene la lista de AutoOp
CHAN_HELP_COMMANDS_HOP
	    12HOP        Mantiene la lista AutoHalfop (Auto Mitad OP)
CHAN_HELP_COMMANDS_XOP_2
	    12VOP        Mantiene la lista de AutoVoice (Auto Voz)
	    NOP        Mantiene la lista de NeverOp (Nunca OP)
CHAN_HELP_COMMANDS_OPVOICE
	    12OP         Le da a un usuario estatus de operador de canal (+o)
	    12DEOP       Remueve el estatus de operador de canal (+o)
	    12VOICE      Le da a un usuario el estatus de voz (voice) (+v)
	    12DEVOICE    Remueve el estatus de voz (voice) (+v)
CHAN_HELP_COMMANDS_HALFOP
	    12HALFOP     Le da a un usuario estatus de MitadOP(halfop) (+h)
	    12DEHALFOP   Remueve el estatus de MitadOP (halfop) (+h)
CHAN_HELP_COMMANDS_PROTECT
	    12PROTECT    Le da a un usuario estatus de protegido (+a)
	    12DEPROTECT  Remueve el estatus de protegido (+a)
CHAN_HELP_COMMANDS_INVITE
	    12INVITE     Invitese usted mismo a un canal
	    12UNBAN      Remueva un bloqueo a usted mismo de un canal
	    12KICK       Patee (kick) a un usuario de un canal
	    12TOPIC      Cambie el tópico de un canal
	    12CLEAR      Remueva los modos de un canal o haga un pateo masivo de sus usuarios
	    12STATUS     Muestre el nivel de acceso de un usuario en un canal

CHAN_HELP_REGISTER
	El registro de los canales se hace a través del bot 3CReG.
	Para más información escriba 12/msg CReG HELP.
	 
CHAN_HELP_REGISTER_ADMINONLY
	
	Limitado a los 04Administradores De Servicios.

CHAN_HELP_IDENTIFY
	Sintaxis: 12IDENTIFY #canal Contraseña
	
	Uso: Este comando, te identifica ante 3%S como el fundador
	canal. Muchos comandos requieren que te identifiques de esta manera
	antes de poder utilizarlos. La contraseña debe ser la misma que se ingresó
	al momento de registrar el canal o la que haya especificado posteriormente
	mediante el comando 12SET PASSWORD.
	Únicamente pueden identificarse como fundadores de canales los nicks
	registrados (+r) que no se encuentren suspendidos (+S).

CHAN_HELP_DROP
	Sintaxis: 12DROP Canal Contraseña
	
	Elimina la registración del canal nombrado.  Esto puede ser utilizado
	únicamente por el fundador del canal, La contraseña debe ser suplida
	para asi evitar la eliminación accidental del canal.

CHAN_HELP_SET
	Sintaxis: 12SET Canal Opción Parámetros
	
	Uso: Permite al fundador de un canal establecer las opciones,
	información y características del mismo. Si se pretende ejecutar
	este comando desde un nick que no sea el fundador del canal, tendrá
	que identificarse previamente mediante el comando 12IDENTIFY.
	 
	Opciones informativas:
	    12DESC         Cambia la descripción del canal
	    12URL          Asocia al canal una página web o dirección URL
	    12EMAIL        Asocia al canal una dirección de correo electrónico
	    12ENTRYMSG     Fija un mensaje de bienvenida que se mostrará a los
	                           a los usuarios al entrar
	    12TOPIC        Cambia el Tema del canal
	 
	Opciones de seguridad:
	 
	    12KEEPTOPIC    Retiene el topic cuando el canal no está en uso
	    12TOPICLOCK    Bloquea el topic y sólo podrá ser cambiado mediante 12SET TOPIC
	    12DEBUG        Activa/desactiva la opción de que 3%S muestre determinadas
	                         acciones sobre un canal (Chivato).
	    12MLOCK        Fija los modos del canal que no deben ser modificados
	    12RESTRICTED   Restringe el acceso al canal
	    12PRIVATE      Oculta el info de un canal a los usuarios (comando 12INFO)
	    12SECURE       Activa los rasgos de seguridad de 3%S
	    12SECUREOPS    Control estricto de Status de operador
	 
	Opciones administrativas:
	Estas opciones sólo puede cambiarlas el fundador del canal.
	 
	    12NAME        Ajusta las minúsculas y mayúsculas en el nombre del canal
	    12FOUNDER     Cambia el fundador del canal
	    12SUCCESSOR   Cambia el sucesor del canal
	    12PASSWORD    Cambia la contraseña del canal con la que identifica el fundador
	 
	Escriba 12/msg %S HELP opción para obtener más información de
	una opción en particular.

CHAN_HELP_SET_FOUNDER
	Sintaxis: 12SET #canal FOUNDER nick
	
	Uso: Cambia el fundador del canal.  El nick dado, que será el
	nuevo fundador del canal, debe estar registrado.

CHAN_HELP_SET_SUCCESSOR
	Sintaxis: 12SET #canal SUCCESSOR nick
	
	Uso: Cambia el sucesor del canal.  El nick dado, será el
	nuevo fundador del canal en caso de expirar el nick del 
	fundador.

CHAN_HELP_SET_PASSWORD
	Sintaxis: 12SET #canal PASSWORD Contraseña
	
	Uso: Cambia la clave de administración del canal por la especificada.
	Hay que estar identificado como fundador para ejecutar este comando.

CHAN_HELP_SET_DESC
	Sintaxis: 12SET #canal DESC Descripción
	
	Uso: Fija la descripción del canal, la cual será mostrada cuando
	se utilicen los comandos LIST e 12INFO.  Sea breve y concreto.

CHAN_HELP_SET_URL
	Sintaxis: 12SET #canal URL url
	
	Uso: Asocia una URL al canal, la cual será visualizada cuando
	se solicite información del canal (vía comando 12INFO).
	Habitualmente se utiliza para indicar la dirección de la
	página web del canal.
CHAN_HELP_SET_INFORMA
	Sintaxis: 12SET #canal INFORMA informacion

CHAN_HELP_SET_EMAIL
	Sintaxis: 12SET #canal EMAIL Dirección
	
	Uso: Asocia la dirección de correo dada al canal.  Esta dirección
	será mostrada cuando alguien solicite (vía comando 12INFO)
	información del canal.  Es muy útil, por ejemplo, para que
	los usuarios tengan una vía de comunicación con el fundador
	y/u operadores del canal.

CHAN_HELP_SET_ENTRYMSG
	Sintaxis: 12SET #canal ENTRYMSG Mensaje
	
	Uso: Establece el mensaje que será enviado a los usuarios (vía
	notice) cuando ellos ingresen al canal.  Si mensaje no se
	ingresa, nada será enviado a los usuarios cuando ingresen.

CHAN_HELP_SET_KEEPTOPIC
	Sintaxis: 12SET #canal KEEPTOPIC {ON | OFF}
	
	Uso: Habilita o deshabilita la opción de retención del tema para
	el canal.  Cuando retención del tema está en ON (habilitada),
	el tema del canal será recordado por 3%S aún después que el último
	usuario se haya retirado, y se restaurará la próxima vez que alguien
	ingrese al canal.

CHAN_HELP_SET_TOPICLOCK
	Sintaxis: 12SET #canal TOPICLOCK {ON | OFF}
	
	Uso: Habilita o deshabilita la opción de candado del tema para
	el canal.  Cuando candado del tema está en ON (habilitada),
	el tema del canal únicamente será cambiado por medio del comando
	12SET TOPIC.

CHAN_HELP_SET_MLOCK
	Sintaxis: 12SET Canal MLOCK Modos
	
	Fija el parámetro modo-candado para el canal.  %S le permite a
	usted definir ciertos modos en el canal para que esten siempre
	activados (o desactivados).  Todos los modos binarios (n, s, t,
	k, l, ect) pueden ser fijados permanentemente; cada modo puede
	ser activado, desactivado, o no fijado.  El parámetro Modos es
	construido exactamente en la misma forma que se ejecuta un
	comando 12/MODE; lo cual significa que, los modos seguidos por
	un signo + son activados, y los modos seguidos por - son
	desactivados.
	
	04ADVERTENCIA: ¡Si usted fija una llave con el modo-candado, como
	en el segundo ejemplo abajo, entonces deberá también fijar la
	opción 12RESTRICTED para el canal (vea 12HELP SET RESTRICTED), de
	lo contrario a cualquier usuario que ingrese al canal cuando
	este esté vacío le sera posible ver la llave del canal!
	Igualmente MLOCK +i no preveerá el que los usuarios ingresen
	al canal cuando está vacío sin haber sido invitados.
	
	Ejemplos:
	
	    12SET #Canal MLOCK +nt-ikl
	        Impone los modos n y t como activos, y los modos i, k,
	        y l como innactivos.  Todos los otros modos son
	        liberados para estár bien activos o innactivos.
	
	    12SET #Canal MLOCK +knst-ilmp My-Contraseña
	        Impone los modos k, n, s, y t como activos, y los modos
	        i, l, m, y p como innactivos.  También establece la
	        contraseña del canal como "My-Contraseña".
	
	    12SET #Canal MLOCK +
	        Remueve el modo-candado; todos los modos en el canal
	        son liberados para estár o bien activados o
	        desactivados (innactivos).

CHAN_HELP_SET_HIDE
	Sintaxis: 12SET Canal HIDE {EMAIL | TOPIC | MLOCK} {ON | OFF}
	
	Le permite a usted prevenir que ciertos datos e información
	sean mostrados cuando alguien ejecuta un 12%S INFO en el
	canal especificado.  Usted puede esconder el correo electrónico
	(12EMAIL) para un canal, el último tópico (12TOPIC), y el modo-candado
	(12MLOCK).  El segundo parámetro especifica si la información deberia
	ser mostrada (12OFF) o escondida (12ON).
	
	Note que el tópico será siempre ocultada si el canal tiene activados
	los modos-candado +p o +s.

CHAN_HELP_SET_PRIVATE
	Sintaxis: 12SET #canal PRIVATE {ON | OFF}
	
	Uso: Habilita o deshabilita la opción de privacidad para el canal.
	Cuando esta opción está activada, el comando 12/MSG %S INFO no
	mostrara información del canal.

CHAN_HELP_SET_RESTRICTED
	Sintaxis: 12SET #canal RESTRICTED {ON | OFF}
	
	Uso: Habilita o deshabilita la opción de acceso restringido para
	el canal.  Cuando el acceso restringido está activo (ON),
	usuarios que normalmente no tienen privilegio de operadores
	cuando entran al canal (usuarios con nivel de acceso
	negativo y, si secure ops está activada, usuarios que NO
	están en la lista de acceso) serán expulsados (y se les
	prohibirá el acceso) al canal.

CHAN_HELP_SET_SECURE
	Sintaxis: 12SET #canal SECURE {ON | OFF}
	
	Uso: Habilita o deshabilita la seguridad de 3%S para el
	canal.  Cuando SECURE está ACTIVO, SOLO los usuarios que
	están identificados (status 3) podrán utilizar los privilegios
	según los levels del canal, aún estando algún level a -1.

CHAN_HELP_SET_SECUREOPS
	Sintaxis: 12SET #canal SECUREOPS {ON | OFF}
	
	Uso: Habilita o deshabilita la opción de operadores seguros para
	el canal.  Cuando operadores seguros está activada (ON),
	usuarios que NO estén en la lista de usuarios del canal NO
	podrán obtener status de operadores.

CHAN_HELP_SET_LEAVEOPS
	Sintaxis: 12SET #canal LEAVEOPS {ON | OFF}
	
	Uso: Habilita o deshabilita la opción de LEAVE OPS para el
	canal. Cuando LEAVE OPS está activada (ON), 3%S dejará OPs del
	servidor incluso si el usuario no tiene level de auto-op.

CHAN_HELP_SET_DEBUG
	Sintaxis: 12SET #canal DEBUG {ON | OFF}
	 
	Uso: Habilita o deshabilita la opción del modo chivato para el
	canal.  Cuando modo chivato está activada (ON), CHaN anunciará
	mediante un notice informativo cuando ocurre una de las siguientes acciones:
	 
	 - Modificaciones de la lista ACCESS del canal (siempre se mostrará por seguridad)
	 - Identificación (correcta/incorrecta) como Fundador.
	 - OP/DEOP mediante 3%S.
	 - VOICE/DEVOICE mediante 3%S.

CHAN_HELP_SET_ENFORCE
	Sintaxis: 12SET #canal ENFORCE {ON | OFF}
	
	Uso: Habilita o deshabilita la opción de IMPONER para el canal.
	Cuando ENFORCE está activada (ON),  3%S impondrá los niveles de
	auto-op y auto-voice para todos los usuarios.  Por ejemplo, si a
	un usuario con privilegios de auto-op se le quita la OP, 3%S
	automáticamente le dará OP al usuario de nuevo, y 3%S tampoco
	permitirá que el comando DEOP sea usado en aquel usuario.

CHAN_HELP_SET_MEMO_RESTRICTED
	Sintaxis: 12SET #canal MEMO-RESTRICTED {ON | OFF}

CHAN_HELP_SET_NAME
	Sintaxis: 12SET #canal NAME nombrecanal
	 
	Uso: Ajusta el nombre del canal poniendo las mayúsculas para
	tener un nombre de canal estéticamente más atractivo.
	El nombre de canal ha de ser equivalente al nombre del canal
	registrado en el sistema.

CHAN_HELP_SET_TOPIC
	Sintaxis: 12SET #canal TOPIC texto
	 
	Uso: Causa que %S fije el tema del canal al indicado en
	texto.  Esta orden es muy útil en conjunción con
	12SET TOPICLOCK.

CHAN_HELP_UNSET
	Sintaxis: 12UNSET #canal opción
	 
	Uso: Borra los ajustes especificados de un canal que hayan
	sido especificados vía 12SET.
	 
	Opciones disponibles:
	 
	    12SUCCESSOR    Borra el sucesor del canal
	    12URL          Borra la página web del canal
	    12EMAIL        Borra el correo asignado al canal
	    12ENTRYMSG     Borra el mensaje de entrada del canal

CHAN_HELP_SOP
	Sintaxis: 12SOP Canal ADD nick
	          12SOP Canal DEL nick
	          12SOP Canal LIST [+Inicio] [Máscara]
	          12SOP Canal COUNT
	
CHAN_HELP_SOP_MID1
	Mantiene la lista de SuperOp (SOP) para un canal.
	Usuarios con el estatus 12SOP reciben OPs automáticamente
	(reciben modo +o) cuando estos ingresan al canal.
CHAN_HELP_SOP_MID1_CHANPROT
	Mantiene la lista de SuperOp (SOP) para un canal.
	Usuarios con el estatus 12SOP reciben OPs automáticamente
	(reciben modo +o) y son protegidos (modo +a) cuando estos
	ingresan al canal.
CHAN_HELP_SOP_MID2
	
	Un 12SOP puede modificar las listas 12AOP, 12VOP, y 12NOP.
	Solamente el fundador del canal puede modificar la lista de
	12SOP.
CHAN_HELP_SOP_MID2_HALFOP
	
	Un 12SOP puede modificar las listas 12AOP, 12HOP, 12VOP, y 12NOP.
	Solamente el fundador del canal puede modificar la lista 12SOP.
CHAN_HELP_SOP_END
	
	Los subcomandos 12ADD, 12DEL, 12LIST, y 12COUNT funcionan de la
	misma manera que el comando 12AOP.

CHAN_HELP_AOP
	Sintaxis: 12AOP Canal ADD nick
	          12AOP Canal DEL nick
	          12AOP Canal LIST [+Inicio] [Máscara]
	          12AOP Canal COUNT
	
	Mantiene la lista AutoOp (AOP) para un canal.
	Usuarios con estatus 12AOP reciben OPs automáticamente
	(reciben modo +o) cuando ingresan al canal.
CHAN_HELP_AOP_MID
	
	Un 12AOP puede modificar las listas 12VOP y 12NOP; los 12SOPs pueden
	modificar la lista 12AOP.
CHAN_HELP_AOP_MID_HALFOP
	
	Un 12AOP puede modificar las listas 12HOP, 12VOP, y 12NOP; los 12SOPs
	pueden modificar la lista 12AOP.
CHAN_HELP_AOP_END
	
	El comando 12AOP ADD añade un usuario a la lista 12AOP, y el comando
	12AOP DEL remueve un usuario de la lista 12AOP.  Notese que un usuario
	solo puede estar en la lista de acceso de un canal una vez; si el
	usuario especificado en un comando 12AOP ADD se encuentra ya en otra
	lista de acceso al canal, por ejemplo la lista 12VOP, este será removido
	de aquella lista primeramente.  (Si no le fuese permitido a usted el
	modificar aquella lista--por ejemplo, si el usuario ya está en la
	lista SOP y usted no es el fundador del canal--entonces el comando
	AOP ADD fallará.)
	
	El comando 12AOP LIST muestra la lista 12AOP.  Si una máscara de comodín
	(signo *) es insertada, solamente aquellas entradas que concuerden con
	esa máscara son mostradas. Si el parámetro "Inicio" es dado este
	especifica cuántas entradas similares serán ignoradas antes de mostrar
	los resultados (por ejemplo, 12+50 causaria que las primeras 50
	entradas sean ignoradas).
	
	El comando 12AOP COUNT retorna el número de entradas que
	existen en la lista AOP.

CHAN_HELP_HOP
	Sintaxis: 12HOP Canal ADD nick
	          12HOP Canal DEL nick
	          12HOP Canal LIST [+Inicio] [Máscara]
	          12HOP Canal COUNT
	
	Mantiene la lista HalfOp (HOP) para un canal.  Usuarios
	con estatus 12HOP reciben privilegios de Mitad-OP (reciben
	modo +h) automáticamente cuando estos ingresan al canal.
	
	Un 12HOP puede modificar las listas 12VOP y 12NOP; 12SOPs y 12AOPs
	pueden modificar la lista 12HOP.
	
	Los subcomandos 12ADD, 12DEL, 12LIST, y 12COUNT funcionan de la
	misma manera que con el comando 12AOP.

CHAN_HELP_VOP
	Sintaxis: 12VOP Canal ADD nick
	          12VOP Canal DEL nick
	          12VOP Canal LIST [+Inicio] [Máscara]
	          12VOP Canal COUNT
	
	Mantiene la lista VoiceOp (VOP) para un canal.
	Usuarios con estatus 12VOP reciben vóz automáticamente
	(reciben modo +v) cuando estos ingresan al canal.
	
	Los subcomandos 12ADD, 12DEL, 12LIST, y 12COUNT funcionan de la
	misma manera que con el comando 12AOP.

CHAN_HELP_NOP
	Syntax: 12NOP canal ADD nick
	        12NOP canal DEL nick
	        12NOP canal LIST [+Inicio] [Máscara]
	        12NOP canal COUNT
	
	Mantiene la lista NeverOp (NOP) (NuncaOP) para un canal. A los usuarios
	con el estatus 12NOP no les es permitido recibir estatus de operador de canal
	(modo +o), y ChanServ removerá el modo +o de tales usuarios
	cuando sea que este le sea dado a ellos.
	
	Los subcomandos 12ADD, 12DEL, 12LIST, y 12COUNT funcionan de la
	misma manera que con el comando 12AOP.

CHAN_HELP_ACCESS
	12Sintaxis: 12ACCESS #Canal ADD nick Nivel
	          12ACCESS #Canal DEL nick
	          12ACCESS #Canal LIST [+Inicio] [Máscara]
	          12ACCESS #Canal COUNT
	
	Uso: Mantiene la lista de accesos del canal.  La lista de accesos
	establece qué usuarios están habilitados a ser operadores
	del canal o acceder a comandos de 3CHaN en el canal.  Se pueden
	establecer diferentes niveles de usuarios para acceder a
	diferentes privilegios; utiliza 12/msg %S HELP ACCESS LEVELS
	para obtener información más específica.  Cualquier nick que
	no esté en la lista de acceso tiene nivel de usuario 0
	(cero).
	 
	El comando 12ACCESS ADD agrega al nick con el nivel indicado a la
	lista de acceso; si el usuario ya existe en la lista, se
	reemplazará su nivel.  El nivel especificado debe ser menor
	que el que tiene el usuario que está ingresando el comando,
	y si el nick está actualmente en la lista, el nivel actual
	de dicho nick debe ser menor que el nivel del usuario que
	está ingresando el comando.
	 
	El comando 12ACCESS DEL elimina un usuario de la lista de
	accesos.  Se puede eliminar un usuario ingresando su nick o
	ingresando el número de orden que ocupa en la lista de accesos.
	 
	El comando 12ACCESS LIST muestra la lista de accesos al canal;
	se pueden utilizar caracteres comodines o máscaras, en cuyo
	caso sólo las coincidencias concurrentes serán listadas.
	 
	El comando 12ACCESS COUNT muestra el número de entradas que
	existen en la lista de acceso.
CHAN_HELP_ACCESS_XOP
	
	Note que la lista de acceso puede también ser manipulada con los
	comandos 12SOP, 12AOP, 12VOP, y 12NOP, los cuales corresponden a los
	niveles de 12%d, 12%d, 12%d, y 12%d respectivamente.
CHAN_HELP_ACCESS_XOP_HALFOP
	
	Note que la lista de acceso puede ser también manipulada con los
	comandos 12SOP, 12AOP, 12HOP, 12VOP, y 12NOP, los cuales corresponden
	a los niveles de 12%d, 12%d, 12%d, 12%d, y 12%d respectivamente.

CHAN_HELP_ACCESS_LEVELS
	12Niveles de acceso para usuarios
	 
	Por defecto, los siguientes niveles son definidos:
	 
	   12FUNDADOR  Acceso FULL a las funciones de 3%S.
	            Privilegio de operador al ingresar al canal.
	            Note que únicamente una sola persona puede
	            tener acceso de fundador del canal (no se
	            puede dar acceso de founder con el comando
	            12ACCESS).
	 
	       12500   Acceso a los comandos SET, CLEAR, AKICK,
	             MEMO, ACCESS, UNBAN, KICK, OP-DEOP, VOICE-DEVOICE,
	             y INVITE; operador automático al entrar al canal
	 
	       12450   Acceso a los comandos AKICK, MEMO, ACCESS, 
	             UNBAN, KICK, OP-DEOP, VOICE-DEVOICE y INVITE;
	             operador automático al entrar al canal.
	 
	       12400   Acceso a los comandos MEMO-READ, ACCESS-LIST,
	             UNBAN, OP-DEOP, VOICE-DEVOICE y INVITE; operador
	             automático al entrar al canal.
	 
	       12300   Acceso a los comandos ACCESS-LIST, UNBAN, OP-DEOP,
	             VOICE-DEVOICE y INVITE; operador automático al entrar al canal.
	 
	       12100   Acceso a los comandos ACCESS-LIST y VOICE-DEVOICE;
	             estado de VOZ automático (+v) al entrar al canal.
	 
	        120   No tiene privilegios especiales; puede obtener
	             status de operador dado por otro operador
	             (a menos que 12SECUREOPS esté activado).
	 
	        12<0   No puede ser operador.
	 
CHAN_HELP_ACCESS_LEVELS_HALFOP
	   12%4d   Obtención automática de MitadOP.
CHAN_HELP_ACCESS_LEVELS_END
	Estos niveles pueden ser cambiados, o nuevos pueden ser
	agregados utilizando el comando 12LEVELS; escriba
	/msg %S HELP LEVELS para más información.

CHAN_HELP_LEVELS
	Sintaxis: 12LEVELS #Canal SET Tipo Nivel
	          12LEVELS #Canal {DIS | DISABLE} Tipo
	          12LEVELS #Canal LIST
	          12LEVELS #Canal RESET
	
	Uso: El comando 12LEVELS permite ajustar los niveles requeridos para
	poder ejecutar comandos de control de 3%S por los usuarios registrados
	en la lista de acceso.
	Los comandos 12SET FOUNDER, 12SET SUCCESSOR, 12SET NAME, 12SET PASSWORD,
	12SET DEBUG, así como éste comando están siempre restringidos
	al fundador.
CHAN_HELP_LEVELS_XOP
	
	¡Cuidado!:  ¡Este comando es solo para usuarios avanzados!  Cambiar
	las opciones de nivel con este comando puede causar que los comandos
	SOP, AOP, VOP, y NOP dejen de funcionar correctamente.
CHAN_HELP_LEVELS_XOP_HOP
	
	¡Cuidado!:  ¡Este comando es solo para usuarios avanzados!  Cambiar
	las opciones de nivel con este comando puede causar que los comandos
	SOP, AOP, HOP, VOP, y NOP dejen de funcionar correctamente.
CHAN_HELP_LEVELS_END
	
	12LEVELS SET habilita una función o grupo de funciones, y establece
	el valor numérico requerido para poderla utilizar.
	 
	12LEVELS DISABLE (o 12DIS en forma abreviada) deshabilita una
	función o grupo de funciones para cualquier usuario que no sea el fundador
	del canal.
	 
	12LEVELS LIST muestra los valores numéricos actuales requeridos
	para cada función o grupo de funciones.
	 
	12LEVELS RESET restablece todos los valores a su configuración
	inicial por defecto, es decir, los mismos que cuando se registra por
	primera vez un canal (ver 12HELP ACCESS LEVELS).
	 
	Para visualizar un listado de todas las funciones que pueden ser
	configuradas ejecuta el comando 12HELP LEVELS DESC.

CHAN_HELP_LEVELS_DESC
	Los siguientes nombres de valores/funciones son entendidos:

CHAN_HELP_AKICK
	Sintaxis: 12AKICK #canal ADD máscara [razón]
	          12AKICK #canal DEL máscara
	          12AKICK #canal LIST [+página] [máscara]
	          12AKICK #canal VIEW [+página] [máscara]
	          12AKICK #canal COUNT
	          12AKICK #canal ENFORCE
	
	Uso:
	Definimos 12AKICK como "Expulsión automática".
	Definimos 12BAN como "Entrada prohibida".
	 
	Este comando, mantiene la lista de 12AKICK del canal.  Si un
	usuario está en la lista de 12AKICK e intenta entrar al canal,
	3%S automáticamente agrega dicho usuario a la lista BAN del
	canal, y luego lo expulsa del canal.
	 
	El comando 12AKICK ADD agrega un usuario a la lista de AKICK.
	Si una razón es dada con el comando, entonces la razón será 
	utilizada por 3%S cuando expulse a dicho usuario; si no, el
	mensaje que se utilizará por defecto, es "No te quiero en el canal".
	 
	El comando 12AKICK DEL elimina al usuario de la lista de
	12AKICK.  Este comando no remueve el BAN que pueda existir en
	el canal, el cual deberá ser removido manualmente.
	 
	El comando 12AKICK LIST muestra la lista de usuarios en la
	lista de 12AKICK.  Opcionalmente, solo lista aquellos
	suministrados con la mascara dada.
	12AKICK VIEW es similar, pero muestra más detalles como quién puso
	el akick, la hora y la hora del último uso del akick.
	Si el parámetro +página es especificado mostrará la página en
	el caso de que haya más de 0 entradas.
	 
	El comando 12AKICK COUNT muestra cuantas entradas existen
	en la lista de 12AKICK.
	 
	El comando 12AKICK ENFORCE causa que 3%S imponga la lista 12AKICK
	actual por medio de expulsar aquellos usuarios que concuerdan con
	una máscara 12AKICK.
	 
	4Nota: Una máscara es el sistema que utiliza el IRC para identificar a
	un usuario, esta compuesta de 12nick!ident@host, donde 12nick es el
	nick del usuario, ident es el 12ident y 12host es la ip virtual.
	Los caracteres 12! y 12@ son los separadores de los respectivos campos.
	Una máscara acepta caracteres "comodín" que son el 12* que sustituye
	cualquier número de caracteres en su posición y 12? que sustituye un
	único carácter.
	 
	
CHAN_HELP_INFO
	Sintaxis: 12INFO #canal
	 
	Uso: Provee información acerca del canal (o informa que no está
	registrado).  Lista el fundador, hora y fecha de registración, última
	vez que se utilizó, descripción, y modos del canal (si los hubiese).

CHAN_HELP_LIST
	Sintaxis: 12LIST [+Inicio] Patrón
	
	Lista todos los canales registrados que coincidan con el patrón dado.
	(Canales con la opción 12PRIVATE fijada no son alistados.)
	Si el parámetro Inicio es dado, entonces especifica cuantas
	entradas ignorar antes de mostrar los resultados (por ejemplo, 12+50
	causará que las primeras 50 entradas sean ignoradas).
CHAN_HELP_LIST_OPERSONLY
	
	Solamente los operadores de IRC pueden utilizar este comando.

CHAN_HELP_OP
	Sintaxis: 12OP #canal nick
	 
	Uso: Convierte en Operador al usuario indicado en el canal
	indicado.  Se requiere tener nivel de OPDEOP para tener acceso
	al comando.

CHAN_HELP_DEOP
	Sintaxis: 12DEOP #canal nick
	 
	Uso: Quita el estado de Operador al usuario indicado en el canal
	indicado.  Se requiere tener nivel de OPDEOP para tener acceso
	al comando.
	 
	Si el canal tiene la opción de LEVELS activada no se podrá quitar la OP
	sobre nicks con un nivel en el canal superior al del nick que ejecuta el comando.

CHAN_HELP_VOICE
	Sintaxis: 12VOICE #canal nick
	 
	Uso: Convierte en Moderador al usuario indicado en el canal
	indicado.  Se requiere tener nivel de 12VOICE-DEVOICE para tener
	acceso al comando.

CHAN_HELP_DEVOICE
	Sintaxis: 12DEVOICE #canal nick
	 
	Uso: Quita el estado de Moderador al usuario indicado en el canal
	indicado.  Se requiere tener nivel de 12VOICE-DEVOICE para tener
	acceso al comando.

CHAN_HELP_HALFOP
	Sintaxis: 12HALFOP Canal [nick]
	
	Da acceso MitadOP (modo +h) a un nick seleccionado en un canal.  Si nick
	no es especificado, le da acceso de MitadOP a usted.  Originalmente,
	limitado a usuarios con acceso %s o superior en el canal.

CHAN_HELP_DEHALFOP
	Sintaxis: 12DEHALFOP Canal [nick]
	
	Remueve el acceso de MitadOP (modo +h) de un nick seleccionado en un canal. Si
	nick no es especificado, entonces le remueve el acceso MitadOP a usted mismo.
	Originalmente, limitado a usuarios con acceso %s o superior en el canal.

CHAN_HELP_PROTECT
	Sintaxis: 12PROTECT Canal [nick]
	
	Da estatus de protegido en el canal (modo +a) a un nick seleccionado en un
	canal.  Si nick no es especificado, le da estatus de protegido en el canal
	a usted mismo.  Originalmente, limitado a usuarios con acceso %s o superior
	en el canal.

CHAN_HELP_DEPROTECT
	Sintaxis: 12DEPROTECT Canal [nick]
	
	Remueve el estatus de protegido en el canal (modo +a) de un nick seleccionado
	en un canal.  Si nick no es especificado, entonces le remueve el estatus de
	protegido en el canal a usted mismo.  Originalmente, limitado a usuarios con
	acceso %s o superior en el canal.

CHAN_HELP_INVITE
	Sintaxis: 12INVITE #canal
	
	Uso: Le dice a 3%S que lo invite a usted al canal indicado.
	Se requiere tener nivel de 12INVITE para tener acceso al comando.

CHAN_HELP_UNBAN
	Sintaxis: 12UNBAN #canal
	 
	Uso: Le dice a 3%S que elimine todos los accesos prohibidos (bans)
	previniendo su ingreso a dicho canal.  Se requiere tener nivel de UNBAN para
	tener acceso al comando.

CHAN_HELP_KICK
	Sintaxis: 12KICK #canal nick [motivo]
	 
	Uso: Le dice a 3%S que ejecute un kick (expulsión) al nick indicado
	en el canal indicado. El mensaje incluido en el kick mostrará quién ha
	utilizado el comando 12KICK como el motivo dado, si está especificado.
	Se requiere tener nivel de 12KICK para tener acceso al comando.

CHAN_HELP_KICK_PROTECTED
	
	Note que los usuarios protegidos (+a) no pueden ser pateados
	con este comando, ni siquiera por el fundador del canal.

CHAN_HELP_TOPIC
	Sintaxis: 12SET #canal TOPIC texto
	 
	Uso: Causa que 3%S fije el tema del canal al indicado en
	texto.  Esta orden es muy útil en conjunción con
	12SET TOPICLOCK.

CHAN_HELP_CLEAR
	Sintaxis: 12CLEAR #canal opción
	
	Uso: Le dice a 3%S que elimine ciertos parámetros del canal.
	que puede ser uno de los siguientes:
	
	    12MODES       Resetea todos los modos del canal (ejemplo,
	                    limpia los modos i,k,l,m,n,p,s,t).
	    12BANS        Elimina todos los accesos prohibidos al canal.
CHAN_HELP_CLEAR_EXCEPTIONS
	    12EXCEPTIONS  Borra todas las excepciones en el canal.
CHAN_HELP_CLEAR_INVITES
	    12INVITES     Remueve todas las máscaras de invitación en el canal.
CHAN_HELP_CLEAR_MID
	    12OPS         Remueve el estatus de operador de canal (modo +o)
	                    de todos los usuarios.
CHAN_HELP_CLEAR_HALFOPS
	    12HALFOPS     Remueve estatus MitadOP (modo +h) de todos los usuarios.
CHAN_HELP_CLEAR_END
	     12OPS        Elimina (quita) el privilegio de operador a
	                       todos los operadores (modo +o) del canal.
	    12VOICES      Elimina (quita) el privilegio de "voz" (modo
	                      +v) a cualquiera del canal que lo tuviese.
	    12USERS       Elimina (Patea -kicks-) TODOS los usuarios del canal
	
	Se requiere tener nivel de CLEAR para tener acceso al comando.

CHAN_HELP_STATUS
	Sintaxis: 12STATUS Canal nick
	
	Muestra el nivel de acceso curriente del nick dado en el
	canal dado.  La repuesta es en el formato:
	
	    12STATUS Canal nick Nivel-De-Acceso
	
	Si ocurre un error, la respuesta será en el formato:
	
	    12STATUS Canal nick ERROR Mensaje-De-Error
	
	Originalmente, limitado a usuarios con acceso %s o superior
	en el canal.

CHAN_HELP_DELSUCCESSOR
	Sintaxis: 12DELSUCCESSOR #canal
	 
	Uso: Hace la renuncia de ser el sucesor del canal para sustituir
	al fundador en el caso de que se borre o se expire el nick de éste.

CHAN_OPER_HELP_COMMANDS
	
	Comandos para Administradores de Servicios
	    12DROP    Elimina un canal de la DB de 3CHaN
	    12NOEXPIRE      Se establece o no que un canal expire
CHAN_OPER_HELP_COMMANDS_FORBID
	    12FORBID          Previene que un canal pueda ser utilizado
	    12UNFORBID      Levanta la prohibición de uso de un canal
CHAN_OPER_HELP_COMMANDS_GETPASS
	 
	Comandos para Operadores de Servicios
	    12SUSPEND        Prevenga el que un canal registrado sea usado
	    12UNSUSPEND   Cancele la suspensión de un canal
CHAN_OPER_HELP_COMMANDS_END
	
	Administradores de Servicios también pueden pueden ver las listas
	de acceso, 12AKICK, y de ajuste de niveles o utilizar el comando
	12STATUS para cualquier canal.

CHAN_OPER_HELP_DROPCHAN
	Sintaxis: 12DROP #canal
	
	Uso: Da de baja al canal nombrado en la base de datos de 12%S.
	
	Limitado a los 04Administradores De Los Servicios.


CHAN_OPER_HELP_SET
	
	Administradores de Servicios también pueden fijar la opción 12NOEXPIRE,
	con la cual se puede prevenir el que los canales expiren. Adicionalmente,
	los Administradores de Servicios pueden fijar opciones para cualquier
	canal sin identificarse via contraseña por el canal.

CHAN_OPER_HELP_SET_NOEXPIRE
	Sintaxis: 12SET Canal NOEXPIRE {ON | OFF}
	
	Ajusta si el canal especificado expirará o no. Ajustar esta opción
	a ON previene que el canal expire.
	
	Limitado a los 04Administradores De Servicios.

CHAN_OPER_HELP_UNSET
	
	Igual que con el comando 12SET, los Administradores de Servicios pueden
	borrar ajustes para cualquier canal sin identificarse por el canal.

CHAN_OPER_HELP_INFO
	
	Administradores de Servicios pueden usar el parámetro 12ALL con cualquier canal.

CHAN_OPER_HELP_LIST
	Sintaxis: 12LIST [+Inicio]Patrón [FORBIDDEN] [NOEXPIRE] [SUSPENDED]
	
	Lista todos los canales registrados que concuerden con el patrón dado.
	Canales con la opción 12PRIVATE activada solamente serán mostrados a
	los administradores de Servicios. Canales con la opción 12NOEXPIRE activada
	tendrán un signo 12! antecediendo al nombre del canal, Esto en el caso de
	los administradores de servicios.
	
	Si el parámetro "Inicio" es dado, este especifica cuantas entradas
	similares serán ignoradas antes de mostrar los resultados (por ejemplo, +50
	causaria que las primeras 50 entradas similares fueran ignoradas).
	
	Si las opciones 12FORBIDDEN, 12SUSPENDED o 12NOEXPIRE son dadas, solo
	aquellos canales que, respectivamente, tienen las opciones FORBID, SUSPEND
	o que tienen el modo NOEXPIRE activado serán mostrados. Las opciones pueden
	ser utilizadas en cualquier orden y en cualquier combinación. Estas opciones
	están limitadas a los 04Administradores de Servicios.

CHAN_OPER_HELP_GETPASS
	Sintaxis: 12GETPASS Canal
	
	Retorna la contraseña para el canal indicado.  Note que
	siempre que este comando es usado, un mensaje incluyendo la
	persona que ejuctó el comando y el canal para el cual fue
	usado será archivado y enviado en forma de WALLOPS/GLOBOPS.
	
	Si encripción está en uso, este comando puediera no estar disponible
	dependiendo del tipo de encripción que se este usando en la red.
	
	Limitado a los 04Administradores De Servicios.

CHAN_OPER_HELP_FORBID
	Sintaxis: 12FORBID #canal
	
	Uso: Deshabilita el que alguien registre o utilice el canal indicado.
	Esto puede ser revertido por medio de eliminar el canal (drop).
	
	Limitado a los 04Administradores De Servicios.

CHAN_OPER_HELP_SUSPEND
	Sintaxis: 12SUSPEND [+Expiración] Canal Razón
	
	Uso: Previene el que un canal sea utilizado o que alguien se
	identifique por él.  Se puede lograr que el canal se utilice
	nuevamente por medio del comando 12UNSUSPEND, lo cual
	permitirá su uso como antes.  El parámetro Expiración es
	interpretado en la misma manera que el comando 12%s AKILL.
	
	Limitado a los 04Administradores De Servicios.

CHAN_OPER_HELP_UNSUSPEND
	Sintaxis: 12UNSUSPEND Canal
	
	Uso: Permite a los usuarios el uso y el que se identifiquen por un
	canal que habia sido previamente suspendido (suspend).
	
	Limitado a los 04Administradores De Servicios.

###########################################################################
#
# CregServ help messages
#
###########################################################################

CREG_HELP
	3CReG le permite realizar una petición de registro de un canal
	e introducir a éste en la fase de registro.
	Los siguientes comandos le permiten manejar el pre-registro de un
	canal; para utilizarlos, escriba 12/msg CReG comando.
	Para más información  sobre un comando específico, escriba
	12/msg CReG HELP comando.
	 
	    12REGISTRA   Realiza una petición de registro de un canal.
	    12ESTADO     Permite consultar el estado de un canal.
	 

CREG_HELP_REGISTER
	Sintaxis: 12REGISTRA #canal contraseña descripción
	 
	Uso: Realiza una petición de registro de un nuevo canal.
	 
	#canal: Se trata del canal a registrar, debe comenzar por el
	carácter #, no debe estar previamente registrado (Verifíquelo
	mediante el comando 12STATUS #canal de 3CReG), no debe exceder
	los 1230 caracteres contando la # y no debe comenzar por una vocal con tilde.
	 
	contraseña: La contraseña que proporcione servirá para que
	pueda identificarse como fundador del canal sin estar con su
	nick habitual, siempre que éste se encuentre registrado en el
	bot 3NiCK.
	 
	descripción: En este parámetro, se explica cual es la temática
	del canal, debe tener unas dos líneas y de lo expuesto en la
	descripción dependerá en gran medida la aceptación del canal.
	 
	Tras ejecutar con éxito este comando, el canal pasara a fase
	de estudio, con una duración no superior a las 1272 horas, tras
	la cual se aceptará, denegará o rechazará el canal.
	 
	Se requiere tener nick con una antigüedad mínima de 127 días
	para poder hacer operaciones sobre canales.
	 
	4NOTA: Sólo puede realizar UNA operación sobre canales al día. Esto
	es, únicamente puede utilizar el comando 12REGISTRA una vez cada
	veinticuatro horas. Antes de utilizarlo, piense sabiamente y
	no lo use en vano, ya que no existen excepciones posibles a esta
	limitación.

CREG_HELP_FOOTER
	4AVISO: 3CReG realiza únicamente funciones de pre-registro de
	un canal, siendo cada petición revisada por la administración
	de la red. La red se reserva el derecho a denegar el registro a
	cualquier canal si sus usuarios se comportan indebidamente o si
	el canal no se ajusta a las normas de registro para los canales.

CREG_HELP_ESTADO
	Sintaxis: 12ESTADO #canal
	 
	Uso: Muestra el estado actual del canal que especifique.
	 
	Los posibles estados de un canal son los siguientes:
	 
	    12ENREGISTRO   La petición de registro del canal está siendo
	         revisada por la administración de canales de la
	         red.
	    12DENEGADO     La petición de registro ha sido denegada.
	    12REGISTRADO   El canal ya está actualmente registrado.
	    12SUSPENDIDO   El registro del canal ha sido suspendido.

CREG_OPER_HELP
	Comandos para Operadores de Servicios
	    12INFO     Muestra información referente a un canal.
	    12PENDIENTES     Muestra la lista de canales solicitados para registro.
	    12APROBAR     Aprueba la solicitud de registro de un canal.
	    12DENEGAR     Deniega el registro de un canal.
	 
CREG_ADMIN_HELP
	Comandos para Administradores de Servicios
	    12DROP    Elimina el registro en 3CReG de un canal.
	 

CREG_OPER_HELP_APROBAR
	Sintaxis: 12APROBAR #canal
	 
	Uso: Aprueba la solicitud de registro de un canal.
	 
	Antes de aprobar el registro de un canal se debe estar seguro que cumpla
	con las normas de canales registrables.

CREG_OPER_HELP_DENEGAR
	Sintaxis: 12DENEGAR #canal motivo
	 
	Uso: Deniega el registro de un canal.
	 
	Para remover de la DB de 3Creg un canal denegado utiliza el comando DROP
	12/MSG CReG DROP #canal
	 
###########################################################################
#
# MemoServ help messages
#
###########################################################################

MEMO_HELP
	3%S es una utilidad que permite a usuarios de IRC
	enviar mensajes cortos a otros usuarios de IRC,
	independientemente de si están en línea o no, igualmente se
	puede enviar mensajes a canales(*).  Ambos nicks (remitente
	y destinatario) deben de estar registrados, así mismo el
	canal debe de estar registrado si se desea enviar un mensaje
	a este.
	Los comandos disponibles son los siguientes. Para utilizarlos,
	escriba 12/msg %S comando.
	Para obtener más información de un comando específico,
	escriba 12/msg %S comando.
	 
	Comandos de listado, enviado y borrado de memos:
	    12SEND     Envía un mensaje a un nick/canal
	    12LIST     Lista todos tus mensajes
	    12READ     Lee un mensaje o mensajes
	    12DEL      Borra un mensaje o mensajes
	    12RENUMBER Renumera tus mensajes
	 
	Comandos de configuración:
	    12SET      Define opciones relacionadas con mensajes
	    12IGNORE   Ignora los mensajes de ciertos usuarios
	 
	Comandos de información:
	    12INFO     Muestra información sobre tu buzón	
MEMO_HELP_EXPIRES
	
	Nota:  Los mensajes expirarán ( automáticamente borrados)
	%s despues de haber sido enviados, a menos que se hayan marcado
	como para no expirar con el comando SAVE.
MEMO_HELP_END_LEVELS
	
	(*) Originalmente, los mensajes del canal son enviados a todos los usuarios
	    (incluyendo el fundador) siempre que estos tengan al menos acceso 12MEMO-RECV en el canal.
	    Esto puede ser cambiado con el comando 12%s LEVELS.
MEMO_HELP_END_XOP
	
	(*) Los mensajes del canal serán enviados al fundador del canal y
	    a todos los usuarios en la lista SOP del canal.

MEMO_HELP_COMMANDS
	Los siguientes comandos pueden ser utilizados con %S:
	
	    12SEND   Envie un mensaje a un nick o canal
	    12LIST   Liste sus mensajes
	    12READ   Lea un mensaje o mensajes
MEMO_HELP_COMMANDS_FORWARD
	    12FORWARD   Reexpida mensajes a su dirección e-mail
MEMO_HELP_COMMANDS_SAVE
	    12SAVE      Define el que ciertos mensajes no expiren
MEMO_HELP_COMMANDS_DEL
	    12DEL    Borre un mensaje o mensajes
	    12RENUMBER  Renumere sus mensajes
	    12SET    Ajuste opciones relacionadas a los mensajes
	    12INFO   Muestra información relacionada a los mensajes
MEMO_HELP_COMMANDS_IGNORE
	    12IGNORE    Ignore los mensajes de ciertos usuarios

MEMO_HELP_SEND
	Sintaxis: 12SEND {nick | #canal} mensaje
	 
	Uso: Envía un mensaje al usuario/canal especificado.
	Si el destinatario es un usuario recibirá una noticia de que tiene un nuevo mensaje.  Lo
	recibirá inmediatamente si se encuentra en línea, o si no al momento de indentificarse
	la próxima vez que se conecte.
	 
	Ejemplos:
	         /msg %S SEND pepito Hola, nos vamos a tomar algo?
	 
	         /msg %S SEND #micanal Hola a todos!
	
MEMO_HELP_LIST
	Sintaxis: 12LIST {Número | Lista | NEW}
	
	Uso: Lista los mensajes que tengas actualmente en tu buzón.
	Si se indica el parámetro 12NEW, solo los nuevos mensajes (los no
	leídos) serán mostrados. Los mensajes no leídos están marcados
	con un "*" a la izquierda del numero de memo, los mensajes del 
	canal son marcados con un "#" y los memos masivos de la Red con
	Se puede especificar una lista de números como en el siguiente
	ejemplo:
	 
	   LIST 2-5,7-9
	    Lista los mensajes enumerados del 2 al 5 y del 7 al 9.

MEMO_HELP_LIST_EXPIRE
	Sintaxis: 12LIST [Núm | List | NEW]
	
	Alista todos sus mensajes actuales. Con 12NEW, alista solo los mensajes
	nuevos (sin leer).  Mensajes aún sin leer son marcados con un signo "*"
	a la inzquierda de el número del mensaje; los mensajes del canal son
	marcados con el signo "#", asi también los mensajes que no expirarán son
	marcados con un signo "+".  Usted también puede especificar una lista de
	númmeros, como en el siguiente ejemplo:
	
	   12LIST 2-5,7-9
	      Alista mensajes enumberados de 2 hasta el 5 y 7 hasta el 9.

MEMO_HELP_READ
	Sintaxis: 12READ {Número | Lista | LAST | NEW}
	
	Uso: Muestra el contenido de los mensajes especificados.
	Si se especifica 12LAST, se mostrará el último mensaje recibido.
	Si se especifica 12NEW, muestra todos los mensajes nuevos y si
	se especifica un número, se mostrará el mensaje asociado al número.
	También se puede especificar una lista de números como el siguiente
	ejemplo:
	 
	   READ 2-5,7-9
	      Muestra los mensajes enumerados del 2 al 5 y del 7 al 9.

MEMO_HELP_SAVE
	Sintaxis: 12SAVE {Número | Lista}
	
	Uso: Marca el mensaje o mensajes dados para que no se expirarán.
	Puedes reemplazar un único número por un rango de números para
	marcar múltiples mensajes simultáneamente, tal como se verá
	en el segundo ejemplo.
	Ejemplos:
	 
	   SAVE 1
	      Marca su primer mensaje.
	 
	   SAVE 2-5,7-9
	      Marca los mensajes del 2 al 5 y del 7 al 9.

MEMO_HELP_DEL
	Sintaxis: 12DEL {Número | Lista | ALL}
	
	Uso: Borra uno o los mensajes especificados. 
	Si un numero 12num es dado, elimina dicho mensaje. Puedes
	reemplazar un único número por un rango de números para
	eliminar múltiples mensajes simultáneamente, tal como se verá
	en el segundo ejemplo.
	 
	Si se ingresa 12ALL se eliminaran TODOS los mensajes.
	 
	Ejemplos:
	 
	    DEL
	      Elimina su primer mensaje.
	 
	    DEL 2-5,7-9
	      Elimina los mensajes del 2 al 5 y del 7 al 9.
	 
	04ADVERTENCIA: ¡Una vez que un mensaje ha sido borrado, no se
	puede recuperar!

MEMO_HELP_RENUMBER
	Sintaxis: 12RENUMBER
	
	Uso: Renumera su lista de mensajes, borrando "huecos" en la sequencia de
	números generada al borrar mensajes.

MEMO_HELP_SET
	Sintaxis: 12SET Opción Parámetros
	
	Uso: Establece varias opciones para los mensajes. Las opciones pueden ser:
	
	    12NOTIFY      Cambia cuándo será usted notificado de
	                    nuevos mensajes.
	    12LIMIT       Fija el número máximo de mensajes que
	                    usted puede recibir
MEMO_HELP_SET_OPTION_FORWARD
	    12FORWARD     Establece el que si los mensajes serán
	                automáticamente reexpedidos a usted
MEMO_HELP_SET_END
	
	Escriba 12/msg %S HELP SET opción para más información
	sobre una opción específica.

MEMO_HELP_SET_NOTIFY
	Sintaxis: 12SET NOTIFY {ON | LOGON | NEW | OFF}
	
	Uso: Establece CUANDO debe ser notificado de nuevos mensajes:
	
	    12ON      Usted será notificado de mensajes cuando se
	               conecte, cuando desactive /AWAY, y cuando
	               estos le sean enviados a usted.
	    12LOGON   Usted será notificado de mensajes solamente al
	               conectarse o cuando desactive /AWAY.
	    12NEW     Usted será notificado de mensajes solamente
	               cuando estos le sean enviados.
	    12OFF     No recibirás notificación alguna de mensajes.
	
	12ON es básicamente la combinación de 12LOGON y 12NEW simultáneamente.
	
MEMO_HELP_SET_LIMIT
	Sintaxis: 12SET LIMIT Límite
	
	Uso: Establece el máximo número de mensajes que puedes tener.
	Si establece limite a 0 (cero) nadie podrá enviarte memos.
	De todos modos, no puedes establecer limite más alto que 12%d.
	
MEMO_HELP_INFO
	Sintaxis: 12INFO
	
	Uso: Muestra información de la cantidad de mensajes que tienes,
	cuantos están sin leer, cuantos mensajes puedes recibir y cuando será
	notificado de nuevos mensajes.

MEMO_OPER_HELP_COMMANDS
	
	Administradores de servicios pueden usar los comandos 12SET
	12LIMIT y 12INFO con nicks que no sean los suyos propios.

MEMO_OPER_HELP_SET_LIMIT
	Sintaxis: 12SET LIMIT [nick] {Límite | NONE | DEFAULT} [HARD]
	
	Fija el número máximo permitido de mensajes que un nick puede
	tener. Si se fija el límite a 120 previene que el nick reciba
	mensaje alguno; fijandolo a 12NONE le permitirá al nick recibir y
	mantener cuantos mensajes desee; y fijandolo a 12DEFAULT restaurá
	el límite a el valor original (%d).  Si usted no indica
	un nick, su propio límite es ajustado
	
	Agregar 12HARD previene que el usuario cambie el límite. No
	agregar 12HARD tiene el efecto opuesto, permitiendo entonces
	que el usuario cambie el límite (inclusive si un límite previo
	fue fijado con 12HARD).
	
	Este uso del comando 12SET LIMIT es limitado a los 04Administradores
	04De Servicios. Otros usuarios solo pueden establecer su propio límite, no
	pueden remover su límite o fijarlo a lo original, no pueden fijar un límite
	superior a 12%d, y no pueden fijar un límite duro (12HARD).

MEMO_OPER_HELP_INFO
	Sintaxis: 12INFO [nick]
	
	Sin un parámetro, muestra información sobre el número de
	mensajes que usted tiene, cuántos están sin leer, cuántos
	mensajes en total usted puede recibir y cuándo es que se
	le notifica a usted de nuevos mensajes.
	
	Con un parámetro de nick, muestra la misma información para
	el nick indicado.  Este comando está limitado a los
	04Administradores De Servicios.

MEMO_HELP_FORWARD
	Sintaxis: 12FORWARD {Núm | List | ALL}
	
	Reexpide uno o más de sus mensajes a su correo electrónico.  Usted debe
	haber fijado una dirección de correo electrónico válida para su nick
	para que le sea posible utilizar este comando.  Mensajes a canales no
	pueden ser reexpedidos.

MEMO_HELP_SET_FORWARD
	Sintaxis: 12SET FORWARD {ON | COPY | OFF}
	
	Fija si %S automáticamente reexpide los mensajes enviados a usted
	a su dirección de correo electrónico. Fijado a 12ON,  reexpide los
	mensajes enviados a usted a el correo electrónico acreditado a su
	nick en lugar de enviarlos a usted en IRC. 12COPY es similar, pero
	también instruye a 12%S que mantenga una copia del mensaje para
	leerlo en linea. Fijado a 12OFF, sus mensajes serán almancenados en
	linea como es usual. Incluso si usted fija esta opción a 12ON, usted
	aún podrá recibir mensajes en linea si los servicios son incapaces de
	reexpedirlos a usted.
	
	Note que cuando esta opción es fijada a 12COPY y usted ha recibido
	el número  máximo de mensajes que le son permitidos, no le será
	posible a usted recibir mensaje nuevo alguno (incluyendo por correo
	electrónico) hasta que haya borrado algunos mensajes viejos usando
	el comando 12DEL.

MEMO_HELP_IGNORE
	Sintaxis: 12IGNORE {ADD | DEL | LIST} [nick | Máscara]
	
	Uso: Controla la lista de usuarios "ignorados"; los usuarios de los cuales
	el nick o una máscara de nicks concuerden con una entrada en esta lista
	no les será permitido enviarle mensajes a ti.
	 
	12IGNORE ADD agrega el nick dado o la máscara a tu lista de ignorados.
	 
	12IGNORE DEL borra el nick dado o la máscara de dicha lista.
	 
	12IGNORE LIST muestra to lista actual de ignorados.
	 
	Note que el nick o máscara dada en el comando 12ADD puede contener los
	signos "*" o "?", y esto no es sensible a mayúsculas o minúsculas; por
	ejemplo, "*Evil*" concuerda con "EvilNick", "AN_EVIL_USER" y también con
	"devil".

###########################################################################
#
# OperServ help messages
#
###########################################################################

OPER_HELP
	12%S le permite a los operadores de servicio realizar sus labores de una manera eficiente.
	Para obtener más información de un comando específico,
	escriba 12/msg HELP %S comando
	 
	Comandos de información:
	    12VIEWIP               Muestra la IP de un usuario
	    12WHOIS                Da los datos del origen de una IP
	    12STATS                Muestra cierta información de la red
	 
	Comandos para actuar en Canales:
	    12OP                       Hace OP en un canal
	    12DEOP                  Quita OP en un canal
	    12INVITE                Invita a un usuario a entrar en un canal
	    12MODE                  Modifica los Modos en un canal
	    12KICK                    Expulsa a un usuario de un canal
	    12HACK                  Simula operaciones hechas por el servidor
	    12TAKEOVER          DEOP masivo a un canal conflictivo
	    12EXTERMINATE    KILL masivo a un canal conflictivo
	    12CLEARUSERS      KICK masivo a un canal conflictivo
	 
	Comandos para actuar en Nicks:
	    12KILL                    Expulsa a un usuario de la red
	    12LISTCLONES       Lista los clones de un usuario 
	    12KILLCLONES       Expulsa a un usuario y sus clones de la red
	    12BLOCK                Expulsa temporalmente a un usario de la red
	    12SVSNICK             Cambia el nick a un usuario 
	    12SVSJOIN             Introduce a un usuario en un canal 
	    12SVSPART            Saca un usuario de un canal 
	 
	Comandos asociados a Gline:
	    12UNGLINE            Quita una gline
	    12AKILL                  Gestiona la lista de autoexpulsiones de la red 
OPER_HELP_COMMANDS
	Comandos de 12%S:
	    12GLOBAL      Envie un mensaje a todos los usuarios
	    12STATS       Muestra el estatus de los Servicios y red
	    12SERVERMAP   Muestra un mapa de los servidores en la red
	    12OPER LIST   Lista todos los Operadores de Servicios
	    12ADMIN LIST  Lista todos los Administradores de Servicios
OPER_HELP_COMMANDS_SERVOPER
	
	Comandos solo para Administradores y Operadores de Servicios:
	    12MODE        Cambia los modos de un canal
	    12KICK        Patea (kicks) a un usuario de un canal
	    12CLEARMODES  Remueve ciertos modos de un canal
	    12CLEARCHAN   Remueve todos los usuarios de un canal (pateo masivo)
	    12KILLCLONES  Desconecta (kills) todos los usuarios con cierta máscara
OPER_HELP_COMMANDS_AKILL
	    12AKILL       Manipula la lista de auto-desconeccíon (AKILL)
	    12AKILLCHAN   Auto-desconecta todos los usuarios en un canal
OPER_HELP_COMMANDS_EXCLUDE
	    12EXCLUDE     Manipula la lista de exclusión de auto-desconexión (AKILL)
OPER_HELP_COMMANDS_SLINE
	    12SGLINE      Manipula la lista SGLINE
	    12SQLINE      Manipula la lista SQLINE
	    12SZLINE      Manipula la lista SZLINE
OPER_HELP_COMMANDS_SESSION
	Gestion de Clones
	    12CLONES        Permite manipular el limite de clones permitidos para una IP.
	    12CONEXIONES   Permite seguir las conexiones de una IP de la lista de clones permitidos.
	 
	4NOTA: ¡Todos los comandos enviados a 12%S son archivados!
	 
OPER_HELP_COMMANDS_NEWS
	    12LOGONNEWS   Define mensajes que ven los usuarios al conectarse
	    12OPERNEWS    Define mensajes que ven los usuarios que usan /OPER
OPER_HELP_COMMANDS_SERVADMIN
	
	Comandos para Administradores de Servicios
	    12STATS                  Muestra el estado de los servicios de red
	    12FORBID               Previene que un nick pueda ser utilizado
	    12UNFORBID          Levanta la prohibición de uso de un nick
OPER_HELP_COMMANDS_SERVROOT
	
	Comandos disponibles solo al Super-Usuario de los Servicios:
	    12ADMIN       Modifica la lista de Administradores De Los Servicios
OPER_HELP_COMMANDS_RAW
	 
	4Nota: ¡Todos los comandos enviados a 12%S son archivados!
OPER_HELP_GLOBAL
	Sintaxis: 12GLOBAL Mensaje
	
	Uso: Envía un mensaje a todos los usuarios del IRC 
OPER_HELP_STATS
	Sintaxis: 12STATS [RESET | NETWORK | ALL]
	
	Sin ninguna opción, muestra el número corriente de usuarios y IRCops
	en línea (excluyendo los Servicios), el número mas alto de usuarios en
	línea desde que los Servicios comenzaron, asi como la cantidad de
	tiempo que ha pasado desde que los Servicios han estado corriendo.
	
	Con la opción 12RESET, reajusta la cuenta máxima de usuarios a la
	del número de usuarios corrientes en línea.
	
	Con la opción 12NETWORK, muestra la cantidad de data enviada a
	y recibida desde el servidor remoto, asi como la cantidad de memoria
	usada por las prelecturas de enchufe de la red. El rátio de uso de la
	memoria de prelectura corriente contra la dimensión del límite de la
	prelectura es también mostrado en porcentage si se configuró un límite.
	
	La opción 12ALL está disponible solamente a los administradores de Servicios,
	y muestra información sobre la cantidad de memoria usada por los Servicios.
	utilizar esta opción puede conjelar los Servicios por un corto periodo de tiempo
	en redes muy grandes, por lo tanto ¡no la sobreuse!
	
	12UPTIME puede ser utilizado como un sinónimo de 12STATS.

OPER_HELP_SERVERMAP
	Sintaxis: 12SERVERMAP
	
	Muestra un mapa de los servidores conectados a la red, desde el punto
	de vista de los servicios.  Servidores "Falsos" los servicios mismos o
	cualquier otro  servidor que ha sido sacado de la red con el comando JUPE
	tienen un signo "(*)" que se muestra detras del nombre de el servidor.

OPER_HELP_OPER
	Sintaxis: 12OPER ADD nick
	          12OPER DEL nick
	          12OPER LIST
	
	Habilita a los Administradores de los Servicios para agregar
	(12ADD) o a borrar (12DEL) usuarios de la lista de operadores.
	Un usuario que se encuentre en la lista de operadores y
	que se identifique ante %s podrá acceder a los comandos
	de Operador de Servicios.
	
	Cualquiera de los operadores de IRC (IRCops) puede utilizar
	el comando 12OPER LIST. Todos los otros comandos solo pueden
	ser utilizados por los 04Administradores de Servicios.

OPER_HELP_ADMIN
	Sintaxis: 12ADMIN ADD nick
	          12ADMIN DEL nick
	          12ADMIN LIST
	
	Habilita a los súper-usuarios de los Servicios a agregar (12ADD)
	o a eliminar (12DEL) usuarios de la lista de los administradores.
	Un usuario que se encuentre en la lista de operadores y que se
	identifique ante %s podrá acceder a los comandos de los
	Administrador de Servicios.
	
	Cualquiera de los operadores de IRC (IRCops) puede utilizar
	el comando 12ADMIN LIST.  Todos los otros comandos solo pueden
	ser utilizados por el 04súper-usuarios de los Servicios.

OPER_HELP_GETKEY
	Sintaxis: 12GETKEY Canal
	
	Muestra la contraseña de canal fijada en el canal dado, si es que esta existe.
	
	Limitado a los 04Operadores De Los Servicios.

OPER_HELP_MODE
	Sintaxis: 12MODE Canal Modos
	
	Habilita a los operadores de Servicios a establecer los
	modos para cualquier canal.  Los parámetros son los mismos
	que se utilizan en la forma estándar de /MODE.
	
	Solo disponible para los 04Operadores de Servicios.

OPER_HELP_CLEARMODES
	Sintaxis: 12CLEARMODES Canal [ALL]
	
	Elimina los modos de canal (n,s,t,k,l,b ect) de un canal. Si el
	parámetro 12ALL es dado, también remueve todos los modos de usuario
	(tales como +o y +v) del canal. Mas sin embargo, si el canal está
	registrado, sus modos de candado (12MLOCK) aún estarán en efecto.
	
	Solo disponible a los 04Operadores De Servicios.

OPER_HELP_CLEARCHAN
	Sintaxis: 12CLEARCHAN Canal
	
	Remueve todos los usuarios de un canal (pateo masivo).
	
	Limitado a los 12Operadores De Servicios.

OPER_HELP_KICK
	Sintaxis: 12KICK Canal Usuario Razón
	
	Habilita a un IRCop a sacar a un usuario de cualquier canal.
	Los parámetros son los mismos que para un 12/KICK común.  El
	mensaje de kick mostrará al usuario el nombre del IRCop que
	está enviando el comando. Por ejemplo:
	
	*** SpamMan has been kicked off channel #my_channel by %S (Alcan (Flood))
	
	Solo disponible para los 04Operadores de Servicios.

OPER_HELP_AKILL
	Sintaxis: 12AKILL ADD [+Expiración] Máscara Razón
	          12AKILL DEL Máscara
	          12AKILL CLEAR ALL
	          12AKILL LIST [+Inicio] [Patrón] [NOEXPIRE]
	          12AKILL VIEW [+Inicio] [Patrón] [NOEXPIRE]
	          12AKILL CHECK Máscara
	          12AKILL COUNT
	 
	Uso:
	Permite a los Operadores de servicios manipular la lista 12AKILL.
	Si un usuario que figura en dicha lista, intenta conectarse, los
	Servicios impondrán un 12KILL para el usuario y darán instrucciones
	a todos los servidores donde esta opción sea disponible, que agreguen
	un ban (k-line) para la máscara que coincida con la del usuario.
	
	12AKILL ADD agrega el usuario dado con la máscara usuario@hospedaje a la
	lista de akill. La razón debe describir el porqué es agregada la entrada;
	dependiendo de cómo esten configurados los servicios, esta pudiera también
	ser mostrada a los usuarios en los mensajes AKILL. Una fecha de
	expiración también puede ser especificada, como se describe abajo.
	
	12AKILL DEL remueve la máscara dada de la lista AKILL si la misma
	está presente.
	
	12AKILL CLEAR elimina (remueve) todas las máscaras de la lista
	autokill (12AKILL).  El parámetro ALL es mandatorio, para evitar
	el uso accidental de este comando.
	
	12AKILL LIST muestra las entradas actuales en la lista autokill;
	si el patrón opcional es dado, entonces listado estará limitado a
	aquellas entradas similares al patrón dado.  Si el parámetro "Inicio"
	es dado entonces especifica cuantas entradas similares ignorar antes de
	mostrar los resultados (por ejemplo, 12+50 causaria que las primeras 50
	entradas similares fueran ignoradas). Adicionalmente, 12NOEXPIRE se puede
	usar para limitar el listado a aquellas entradas que no expiran.
	
	12AKILL VIEW es más explícito que 12AKILL LIST, dado que muestra quién
	agregó un AKILL, la fecha en que fue añadido, cuándo expira, asi como
	también la máscara usuario@hospedaje utilizada y la razón.
	
	12AKILL CHECK mostrará todas las entradas en la lista autokill en
	las que la máscara usuario@hospedaje dada sean similares; esto se
	puede utilizar para determinar cuál autokill causó que un usuario
	en particular fuese desconectado.
	
	12AKILL COUNT simplemente muestra el número de autokills en
	la lista AKILL.
	
	Opcionalmente, una fecha de expiración también puede ser
	suministrada con el comando 12AKILL ADD.  La fecha de
	expiración PRECEDE a la máscara usuario@hospedaje y deberá
	ser especificado como un entero seguido o bien por d (días),
	h (horas), o por m (minutos). Combinaciones (como 1h30m) son
	también permitidas.  Si un especificador de unidades no es
	incluido, originalmente se asumen DIAS (entonces, poner 12+30
	sin nada, significa 30 días).  Para agregar un 12AKILL que NO
	expira, utilice 12+0.  Si la máscara de usuario comienza con
	+, un período de expiración deberá ser indicado, aún si es
	el mismo período que el asignado originalmente.
OPER_HELP_AKILL_OPERMAXEXPIRY
	
	Los Operadores De Servicios pueden fijar una fecha de expiración de solamente
	12%s; Mientras que los Administradores De Servicios pueden fijar cualquier
	fecha de expiración.
OPER_HELP_AKILL_END
	
	Limitado a los 04Operadores De Servicios.

OPER_HELP_AKILLCHAN
	Sintaxis: 12AKILLCHAN [KILL] [+Expiración] Canal Razón
	
	Añade auto-desconecciones para todos los usuarios excepto para los operadores de
	IRC en el canal especificado, y opcionalmente (si KILL es especificado)
	los remueve de la red.  La Razón será recordada en cada auto-desconexión,
	y puede ser mostrada en los mensajes de desconexión dependiendo de como esten
	configurados los Servicios.  Expiración toma el mismo formato como en el
	comando AKILL ADD; Si no es especificado, lo fija por %s.
	
	Auto-desconecciones añadidas con este comando tendrán el formato
	*@Máscara, para cada máscara usada por un cliente en el
	canal.  Si dicha auto-desconexión ya existe para una máscara,
	esta no será modificada; esto puede causar que el número de
	auto-desconecciones añadidas sea menor que el número de usuarios
	afectados.
	
	Limitado a los 04Operadores De Servicios.

OPER_HELP_EXCLUDE
	Sintaxis: 12ELINE ADD máscara
	          12ELINE DEL máscara
	          12ELINE CLEAR ALL
	          12ELINE LIST
	          12ELINE VIEW [máscara]
	          12ELINE COUNT
	 
	Uso: Permite a los Operadores de servicios manipular la lista
	de 12E-LINES del IRCd.
	Cuando una máscara es agregada no podra verse afectada por G-Lines o Throttle
	
	El comando 12ELINE ADD agrega una máscara a la lista de 12ELINES.
	El tiempo de expiración es opcional, si no se especifica se tomara el valor del
	archivo de configuración. 
	 
	Ejemplo:
	      12ELINE ADD +1d *@69.69.69.69 Esta direción es de un IRCop.
	 
	El ejemplo de arriba agregará por 1 día la máscara *@69.69.69.69 a la lista de 
	E-Lines, el último parámetro es el motivo.
	 
	El comando 12ELINE DEL elimina un máscara de la lista de 12ELINES.
	 
	El comando 12ELINE CLEAR ALL elimina todos los registros de la lista de E-Lines.	
	 
	El comando 12ELINE LIST muestra los registros de la lista E-Lines. 
	 
	El comando 12ELINE VIEW [IP] permite ver detalles más especificos de un registro
	si no se especifica la IP mostrara la lista de registros.
	 
	El comando 12ELINE COUNT muestra el número de registros existentes en la lista de
	E-Lines.
	 
	 
	4Nota: Unos tipos de máscaras válidas son las siguientes: 12ident@69.69.69.69, 12*@69.69.69.69 y 1269.69.69.69. 

OPER_HELP_SGLINE
	Sintaxis: 12GLINE ADD expiración máscara razón
	          12GLINE DEL máscara
	
	Uso: Permite a los Operadores de servicios manipular la lista 12SGLINE.
	Una 12GLINE restringe el ingreso a la red a una determinada máscara.
	
	12GLINE ADD agrega la máscara especificada a la lista 12GLINES.
	Si en el parámetro 12máscara se especifica el nick de un usuario conectado
	a la red, se agregará la IP de ese usuario a la lista de 12GLINES.
	
	12GLINE DEL remueve la máscara especificada de la lista 12GLINE
	
	4Nota: El parámetro máscara es el siguiente 12ident@host .
	En 12GLINE ADD.  La fecha de expiración es especificada con un entero 
	seguido por o bien d (días), h (horas), o m (minutos).
	Combinaciones (tales como 1h30m) son también permitidas.

OPER_HELP_SQLINE
	Sintaxis: 12SQLINE ADD [+Expiración] Máscara Razón
	          12SQLINE DEL Máscara
	          12SQLINE CLEAR ALL
	          12SQLINE LIST [+Inicio] [Patrón] [NOEXPIRE]
	          12SQLINE VIEW [+Inicio] [Patrón] [NOEXPIRE]
	          12SQLINE CHECK Máscara
	          12SQLINE COUNT
	
OPER_HELP_SQLINE_KILL
	Permite a los Operadores de Servicios manipular la lista
	12SQLINE. Si un usuario cuyo nick concuerda con una máscara
	12SQLINE trata de conectarse, o si un usuario trata de cambiar
	su nick a uno que concuerda con una máscara 12SQLINE, Los
	Servicios impondrán un 12KILL para dicho usuario y, en los
	tipos de servidores donde esto este disponible, instruirán a
	todos los servidores que agregen un bloqueo (G-line en el
	servidor) para la máscara con la que el usuario concuerda.
OPER_HELP_SQLINE_NOKILL
	Permite a los Operadores de Servicios manipular la lista
	12SQLINE. Si un usuario cuyo nick concuerda con una máscara
	12SQLINE trata de conectarse, o si un usuario trata de cambiar
	su nick a uno que concuerda con una máscara 12SQLINE, Los
	Servicios cambiarán el nick de dicho usuario a un nick
	"guest" (Huésped), y enviará un mensaje al usuario que
	normalmente causará que el programa cliente de IRC del
	usuario pida un nuevo nick.  En tipos de servidores donde
	esté disponible, Los Servicios también instruirán a todos
	los servidores que agregen un bloqueo (Q-line en el
	servidor) para la máscara con la que el usuario concuerda.
OPER_HELP_SQLINE_IGNOREOPERS
	
	Note que los Operadores de IRC no serán afectados por
	máscaras SQLINE.
OPER_HELP_SQLINE_END
	
	Los subcomandos 12ADD, 12DEL, 12CLEAR, 12LIST, y 12VIEW, 12CHECK, y 12COUNT
	funcionan de la misma manera que los subcomandos para el comando
	12SGLINE;  Vea la ayuda para 12SGLINE para más información.
	
	Limitado a los 04Operadores De Servicios.

OPER_HELP_SZLINE
	Sintaxis: 12SZLINE ADD [+Expiración] Máscara Razón
	          12SZLINE DEL Máscara
	          12SZLINE CLEAR ALL
	          12SZLINE LIST [+Inicio] [Patrón] [NOEXPIRE]
	          12SZLINE VIEW [+Inicio] [Patrón] [NOEXPIRE]
	          12SZLINE CHECK Máscara
	          12SZLINE COUNT
	
	Permite a los Operadores de Servicios el manipular la lista 12SZLINE.  Si un usuario
	cuya dirección IP concuerda con una máscara 12SZLINE trata de conectarse, Los servicios
	impondrán un 12KILL para dicho usuario y,en servidores en los que esto este disponible,
	instruirán a todos los servidores que agregen un bloqueo (Z-line en el servidor) para
	la máscara con la que el usuario concuerda.
	
	Los subcomandos 12ADD, 12DEL, 12CLEAR, 12LIST, 12VIEW, 12CHECK, y 12COUNT
	funcionan de la misma forma que los subcomandos para el comando
	12SGLINE; vea la ayuda para 12SGLINE para más información.
	
	Limitado a los 04Operadores De Servicios.

OPER_HELP_EXCEPTION
	Sintaxis: 12CLONES ADD [+Expiración] Dirección-IP Límite Razón
	          12CLONES DEL Dirección-IP
	          12CLONES CLEAR ALL
	          12CLONES LIST
	          12CLONES VIEW [Dirección-IP]
	          12CLONES COUNT
	
	Uso: 
	Permite manipular el limite de conexiones simultaneas para una dirección IP.
	 
	El comando 12CLONES ADD añade una dirección IP a la lista de clones permitidos
	La fecha es opcional si no se especifica el registro expirará en 1 dia. 
	Tener en cuenta que solo se permite añadir direcciones IP (formato: 69.69.69.69). 
	 
	Ejemplo:
	        12CLONES ADD +1h 69.69.69.69 10 CiberCafe HardCore. 
	 
	El ejemplo de arriba agregara la IP 69.69.69.69 a la lista de clones permitidos
	estableciendole un limite de 10 conexiones simultaneas con un tiempo de expiración de 1 hora.
	4Nota: Si la fecha de expiración es especificada con un 12+0 el registro no experará.
	 
	El comando 12CLONES DEL remueve la dirección IP dada.
	También se puede especificar el índice del registro
	para saber el índice de un registro utilice los parámetro 12VIEW o 12LIST.
	 	
	El comando 12CLONES CLEAR ALL elimina (remueve) todos los registros de la lista
	de clones permitidos.
	 	
	El comando 12CLONES LIST muestra los registros de la lista de clones permitidos.
	 
	El comando 12CLONES VIEW [IP] permite ver detalles más especificos de un registro
	si no se especifica la IP mostrara la lista de registros.
	
	El comando 12CLONES COUNT muestra el número de registros existentes en la lista de clones permitidos.
	

OPER_HELP_SESSION
	Sintaxis: 12CONEXIONES LIST Núm-Límite
	          12SESSION VIEW Dirección-IP
	
	Uso: Permite seguir las conexiones de una IP dada de alta en la lista de clones permitidos.	
	 
	El comando 12CLONES LIST lista las direcciones IP con el limite de conexiones especificado
	El límite debe ser un número mayor que 1.
	
	El comando 12CLONES VIEW muestra información detallada sobre una dirección IP.
	
	Vea la ayuda del comando 12CLONES para más información sobre limitado de clones permitidos.

OPER_HELP_SU
	Sintaxis: 12SU Contraseña
	
	Permite acceso a funciones que requieren privilegios de
	super-usuario de los servicios.  La contraseña es la misma
	fijada con el comando 12SET SUPASS; note que la contraseña
	debe ser fijada antes de usar este comando.  Privilegios de
	Super-usuario solamente duran hasta que usted se desconecte
	de IRC.
	
	04¡AVISO!: Si usted ingresa una contraseña incorrecta, Entonces
	los servicios enviarán un mensaje de aviso a todos los IRCops.
	
	Limitado a los 04Administradores De Servicios.

OPER_HELP_SET
	Sintaxis: 12SET Opción Ajuste
	
	Ajusta varias opciones globales de los Servicios.  Algunas
	de las opciones actualmente definidas son:
	    12READONLY   Fija servicios en modo de leer-solamente
	    12DEBUG      Activa/desactiva el modo de detección de errores
	    12SUPASS     Fija contraseña para el comando SU (super-usuario)
	
	Limitado a los 04Administradores De Servicios; la opción 12SUPASS
	solo puede ser fijada por el 04Super-Usuario De Servicios.

OPER_HELP_SET_READONLY
	Sintaxis: 12SET READONLY {ON | OFF}
	
	Activa o desactiva el modo de leer-solamente.  En modo de
	leer-solamente, los usuarios regulares no podrán modificar
	las bases de datos de los servicios, incluyendo las listas
	de acceso de canales y nicks, ect. IRCops con suficientes
	privilegios si podrán modificar la lista 12AKILL asi como
	cancelar o prohibir nicks o canales, pero ninguno de estos
	cambios será grabado al disco a menos que se desactive el modo
	de leer-solamente antes que los servicios sean desactivados o
	re-activados.
	
	Esta opción es equivalente a la opción -readonly en la línea
	de comandos.

OPER_HELP_SET_DEBUG
	Sintaxis: 12SET DEBUG {ON | OFF | Núm}
	
	Activa/Desactiva el modo de detección de errores.  En modo de
	detección de errores, toda la informacion enviada a o desde los
	servicios asi como un número considerable de mensajes de chequeo
	son escritos en un archivo en el disco, Si se especifica Núm,
	el modo de detección de errores es activado con el nivel de
	detección fijado a Núm.
	
	Esta opción es equivalente a la opción -debug en la línea
	de comandos.

OPER_HELP_SET_SUPASS
	Sintaxis: 12SET SUPASS [Contraseña]
	
	Fija la contraseña que se usará para el comando 12SU. La
	contraseña debe ser fijada una vez antes de usar el comando 12SU
	por primera vez.  Si no se establece una contraseña, el comando
	12SU no estará disponible.
	
	Esta opción solo puede ser fijada por el 04Super-Usuario de Servicios.

OPER_HELP_JUPE
	Sintaxis: 12JUPE Servidor [Razón]
	
	Ordena a Servicios que ejecuten el comando jupiter en un servidor
	--eso es, crear un "servidor" falso conectado a los servicios
	que evita que el servidor real con ese nombre se conecte.  Esta
	opción puede ser removida usando un 12/SQUIT estandar.  Si se da
	una razón, esta es colocada en el area de información del servidor;
	de otra manera, el area de información sobre el servidor contendrá
	el texto "Jupitered by <nick>", mostrando el nick de la persona
	que desenganchó (jupitered) al servidor.
	
	Limitado a los 04Administradores De Servicios.

OPER_HELP_RAW
	Sintaxis: 12RAW Texto
	
	Envía una secuencia del texto directamente al servidor al cual
	los Servicios están conectados, sin ejecutar prosesamiento alguno
	de dicho texto. Este comando ha sido creado primordialmente con
	el proposito de hacer pruebas entre los Servicios y ciertos servidores
	de IRC; tiene un muy limitado rango de usos en una red viva, y puede
	causar estragos en la red o causar que los servicios caigan de no ser
	utilizado apropiadamente. ¡04NO USE ESTE COMANDO a menos que usted
	esté completamente seguro de lo que está haciendo!
	
	Limitado al 04Super-Usuario De Servicios.

OPER_HELP_UPDATE
	Sintaxis: 12UPDATE [FORCE]
	
	Causa que los Servicios actualicen las bases de datos tan
	pronto como usted envía el comando.  Si la opción 12FORCE es
	dada, los servicios procurarán abrir (liberar) las bases de
	datos antes de realizar la actualización; esto puede usarse
	para corregir los errores "databases are locked" cuando se
	actualizan las bases de datos.
	
	Limitado a los 04Administradores De Servicios.

OPER_HELP_QUIT
	Sintaxis: 12QUIT
	
	Causa la desactivación de los Servicios; las bases de datos
	no se graban.  Este comando no debe utilizarse a menos que
	se sospeche de un daño en las bases de datos en-memoria y no
	deseen grabarse.  Para desactivación normal de los
	Servicios, utilice el comando 12SHUTDOWN.
	
	Limitado a los 04Administradores De Servicios.

OPER_HELP_SHUTDOWN
	Sintaxis: 12SHUTDOWN
	
	Causa que los Servicios graben todas las bases de datos y despues se desactiven.
	
	Limitado a los 04Administradores De Servicios.

OPER_HELP_RESTART
	Sintaxis: 12RESTART
	
	Causa que los servicios graben todas las bases de datos y
	luego se desactiven. (ejemplo: salir e immediatamente
	re-hacer el ejecutable).
	
	Limitado a los 04Administradores De Servicios.

OPER_HELP_REHASH
	Sintaxis: 12REHASH
	
	Causa que los Servicios re-lean sus ficheros de configuración y que actualicen
	la configuración activa corriente.  Algunos ajustes, tales como RemoteServer
	(la cual establece la dirección de el servidor de IRC al que servicios se
	conectará), no puede ser cambiado con 12REHASH, y solo entrará en efecto cuando
	los Servicios sean re-empezados; en estos casos, un mensaje será escrito en
	en el fichero de archivo de los Servicios , y una notificación será enviada
	poniendolo a usted al corriente de esto.
	
	Si lineas de LoadModule han sido agregadas o removidas de el fichero principal
	de configuración de los servicios (%s), los modulos serán bien cargados o
	descargados según sea necesario.  Los modulos que ya no tengan una linea de
	LoadModule serán descargados (desmontados) en orden reversa a aquellos que se
	cargarán; entonces, despues que los modulos que faltan hayan sido actualizados,
	los modulos nuevos serán cargados (montados) en el orden alistado en el fichero
	configuración.  Si ocurriera un error en cualquiera de los pasos, entonces el
	proceso de actualización será abortado (cancelado).
	
	Note que debido a dependencias de los modules, algunos modulos no pueden ser
	removidos o cambiandos via REHASH; en estos cases, usted deberá re-empenzar
	los servicios para que los cambios entren en efecto.
	
	Limitado a los 04Administradores De Servicios.

OPER_HELP_KILLCLONES
	Sintaxis: 12KILLCLONES nick
	
	Desconecta (Kills) todos los usuarios que tengan la misma
	máscara que nick. un KILL temporario, en la forma *@máscara,
	es agregado para prevenir que los clientes ofensivos se reconecten
	immediatamente. un wallops es también enviado indicando quien usó
	el comando, que máscara fue afectada y cuántos usuarios fueron
	desconectados. Esto es muy útil cuando es necesario remover
	numerosos clones de la red.
	


###########################################################################
#
# AdminServ help messages
#
###########################################################################

ADMIN_HELP
	12%S permite a los administradores de servicios gestionar opciones
	avanzadas de la red.
	Para obtener más información de un comando específico,
	escriba 12/msg HELP %S comando
	 
	Gestion de Staff
	   12OPER   Manipula la lista de operadores de servicios.
	 
	Gestión de Red
	    12SETTIME    Sincroniza la RED a tiempo real.
	    12ELINE      Gestiona las E-Lines de la red.
	    12SERVERMAP    Muestra un mapa de los servidores en la red.
	    12UMODE     Cambia los modos de un usuario.
	    12UPDATE    Fuerza una actualizacion immediata en el disco de las DB's.
	    12RESTART    Graba la base de datos al disco y recomienza los servicios. 
	 
ADMIN_ROOT_HELP
	Comandos disponibles para Root
	    12ADMIN    Manipula la lista de los administradores de servicios.
	    12SHUTDOWN    Cierra los servicios.	 

###########################################################################
#
# PreopServ help messages
#
###########################################################################
PREOP_HELP
	12%S permite a los Preoperadores de servicios realizar
	tareas de mantenimiento del sistema del servidor ,
	asi mismo permite cambiar opciones de statusen los canales de la Red.
	Para obtener más información de un comando específico,
	escriba 12/msg HELP %S comando
	 
	Comandos de uso en canales
	    12OP    Dara op o @ al usuario especificado en el canal especificado.
	    12DEOP  quitara op o @ al usuario especificado en el canal especificado.
	    12INVITE  invitara al usuario especificado en el canal especificado.
	 
	 
PREOP_FOOTER_HELP
	4ATENCION! El mal uso de estos comandos puede ocacionar problemas en la BDD, úsalos con moderación.	 

###########################################################################
#
# DdbServ help messages
#
###########################################################################

DDB_HELP
	12%S permite a los administradores de servicios y root de servicios realizar
	tareas de mantenimiento del sistema de Base de Datos Distribuida del IRCd,
	asi mismo permite cambiar opciones de configuracion de la Red.
	Para obtener mas informacion de un comando específico,
	escriba 12/msg HELP %S comando
	 
	Mantenimiento
	    12COMPACTAR     Compacta las tablas de la BDD para ahorrar CPU y disco.
	    12GENCIFRADO    Regenera manualmente una clave de cifrado para IPs.
	    12DEVEL     asigna manualmente el registro de DEVEL a la ddb del IRCD.
	    12PREOPER     asigna manualmente el registro de PREOPER a la ddb del IRCD.
	    12BOT       asigna manualmente el registro de BOT a la ddb del IRCD.
	    12UNBOT    borra cualquier el registro de la ddb del IRCD de la tabla o y la tabla v.

DDB_ROOT_HELP
	Opciones de Configuración
	    12MAXCLONES    Establece el limite de clones.
	    12QUITCLONES    Establece el mensaje de expulsion de MAXCLONES.
	    12MSGQUIT    Define el mensaje de salida de un servidor especifico.
	    12PSEUDONICK Estable los nicks de los bots virtuales (nickserv, chanserv).
	    12ULINE    Agrega/Borra Ulines de la ddb.
	    12P09      Establece un nodo como servidor P09.
	 

DDB_FOOTER_HELP
	4ATENCION! El mal uso de estos comandos puede ocacionar problemas en la BDD, úsalos con moderación.	 
	

###########################################################################
#
# StatServ help messages
#
###########################################################################

STAT_HELP
	03%S provee información estadística sobre la red de IRC,
	sobre sus servidores y también sus usuarios.  Escriba
	12/msg %S HELP COMMANDOS para ver la lista de comandos de 03%S;  Para
	información sobre un comando, escriba 12/msg %S HELP comando.

STAT_HELP_COMMANDS
	Los siguientes comandoss pueden ser utilizados con 12%S:
	
	    12SERVERS     Estadísticas del servidor
	    12USERS       Estadísticas de los usuarios

STAT_HELP_SERVERS
	Sintaxis: 12SERVERS STATS
	          12SERVERS LIST [Máscara]
	          12SERVERS VIEW [Máscara] [ONLINE | OFFLINE]
	
	Muestra estadísticas relacionadas a los servidores de la red.
	
	12SERVERS STATS muestra un sumário breve de los servidores
	actualmente visibles (en línea) e invisibles (no en línea) a
	los Servicios.
	12SERVERS LIST muestra una lista de servidores en línea y
	estadísticas corrientes sobre cada uno de ellos.
	12SERVERS VIEW muestra una lista de servidores en o fuera de
	línea con estadísticas detalladas sobre cada uno de ellos. las
	opciones 12ONLINE y 12OFFLINE causan, respectivamente, que
	solo los servidores en línea o fuera de línea sean mostrados.
	
	Utilice la opción Máscara para limitar el tipo de estadísticas
	que serán mostradas sobre el servidor.

STAT_HELP_USERS
	Sintaxis: 12USERS STATS
	
	Muestra estadísticas relacionadas a los usuarios de la red.

STAT_OPER_HELP_SERVERS
	Sintaxis: 12SERVERS STATS
	          12SERVERS LIST [Máscara]
	          12SERVERS VIEW [Máscara] [ONLINE | OFFLINE]
	          12SERVERS DELETE Servidor
	          12SERVERS COPY Servidor NuevoNombre
	          12SERVERS RENAME Servidor NuevoNombre
	
	Muestra estadísticas relacionadas a los servidores de la red.
	
	12SERVERS STATS muestra un sumário breve de los servidores
	actualmente visibles (en línea) e invisibles (no en línea) a
	los Servicios.
	12SERVERS LIST muestra una lista de servidores en línea y
	estadísticas corrientes sobre cada uno de ellos.
	12SERVERS VIEW muestra una lista de servidores en o fuera de
	línea con estadísticas detalladas sobre cada uno de ellos. las
	opciones 12ONLINE y 12OFFLINE causan, respectivamente, que
	solo los servidores en línea o fuera de línea sean mostrados.
	
	Utilice la opción Máscara para limitar las estadísticas de
	qué servidor serán mostradas.
	
	12DELETE borra las estadísticas del servidor especificado.
	12COPY duplica un grupo de estadísticas del servidor.
	12RENAME renombra un grupo de estadísticas del servidor.
	Estos tres comandos están limitados al 04Super-Usuario De
	04Servicios.

OPER_HELP_KILL
	Sintaxis: 12KILL nick motivo
	 
	Uso: Expulsa a un usuario del servidor.

OPER_HELP_FJOIN
	Sintaxis: 12FJOIN nick #canal
	 
	Uso: Fuerza a un usuario a ingresar al canal especificado.

OPER_HELP_FPART
	Sintaxis: 12FPART nick #canal
	 
	Uso: Fuerza a un usuario a salir del canal especificado.

OPER_HELP_TGLINE
	Sintaxis: 12BLOCK opción nick
	 
	Uso: Expulsa a un usuario de la red por 1 hora.
	 
	Opciones Disponibles:
	 
	3Spam: Expulsa al usuario especificando en el motivo que no se permite publicidad en la red.
	 
	3Baduser: Expulsa al usuario especificando en el motivo que debe corregir su actitud en la red.
	 
	3Ilegal:  Expulsa al usuario especificando en el motivo que no debe realizar actividades ilegales en la red.

OPER_HELP_HACK
	Sintaxis: 12HACK OP #canal  nick
	              12HACK DEOP #canal nick
	              12HACK KICK #canal nick motivo
	              12HACK MODE #canal modos
	 
	Uso: Simula operaciones hechas por el servidor, de tal forma que cualquiera de los siguientes
	comandos seran efectuados por el servidor de irc.
		
HELP_CABECERA
	3%s - 7%s%s12%s
	 

HELP_FOOTER
	 
	FIN de la AYUDA de 3%s

HELP_COMMAND_FOOTER
	 
	FIN de la AYUDA del comando 12%s
GLOBAL_HELP
	12%S es el servicio de mensajería global
	Para obtener más información de un comando específico,
	escriba 12/msg HELP %S comando
	 
	12GLOBAL    Envía un mensaje global
	12NICK     Envía un mensaje global a través de un nick
	 
GLOBAL_HELP_NICK
	Sintaxis: 12NICK nick mensaje
	 
	Uso: Permite enviar un mensaje a todos los usuarios de la red.
	el parametro 12nick es utilizado como emisor del mensaje.
GLOBAL_NICK_SYNTAX
	12NICK nick mensaje
###########################################################################

# CVS: $Revision: 2.207 $
