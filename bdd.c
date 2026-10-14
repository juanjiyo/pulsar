#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include "services.h"
#include "modules.h"


#ifdef IRC_HISPANO
unsigned int base64toint(const char *);
const char *inttobase64(char *buf, unsigned int v, unsigned int count);
void tea(unsigned int *v, unsigned int *k, unsigned int *x);

const unsigned char base64[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789[]"
};

const unsigned char inv_base64[128] =
{
    255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255,
    52,  53,  54,  55,  56,  57,  58,  59,
    60,  61, 255, 255, 255, 255, 255, 255,
    255,   0,   1,   2,   3,   4,   5,   6,
    7,   8,   9,  10,  11,  12,  13,  14,
    15,  16,  17,  18,  19,  20,  21,  22,
    23,  24,  25,  62, 255,  63, 255, 255,
    255,  26,  27,  28,  29,  30,  31,  32,
    33,  34,  35,  36,  37,  38,  39,  40,
    41,  42,  43,  44,  45,  46,  47,  48,
    49,  50,  51, 255, 255, 255, 255, 255,
};


unsigned int base64toint(const char *s)
{
    unsigned int i = inv_base64[(unsigned char)*s++];
    while (*s)
    {
    	i <<= 6;
    	i += inv_base64[(unsigned char)*s++];
    }
    return i;
}

const char *inttobase64(char *buf, unsigned int v, unsigned int count)
{
    buf[count] = '\0';
    while (count > 0)
    {
    	buf[--count] = base64[(v & 63)];
    	v >>= 6;
    }
    return buf;
}

const char NTL_tolower_tab[] = {
       /* x00-x07 */ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07',
       /* x08-x0f */ '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
       /* x10-x17 */ '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
       /* x18-x1f */ '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f',
       /* ' '-x27 */    ' ',    '!',    '"',    '#',    '$',    '%',    '&', '\x27',
       /* '('-'/' */    '(',    ')',    '*',    '+',    ',',    '-',    '.',    '/',
       /* '0'-'7' */    '0',    '1',    '2',    '3',    '4',    '5',    '6',    '7',
       /* '8'-'?' */    '8',    '9',    ':',    ';',    '<',    '=',    '>',    '?',
       /* '@'-'G' */    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
       /* 'H'-'O' */    'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',
       /* 'P'-'W' */    'p',    'q',    'r',    's',    't',    'u',    'v',    'w',
       /* 'X'-'_' */    'x',    'y',    'z',    '{',    '|',    '}',    '~',    '_',
       /* '`'-'g' */    '`',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
       /* 'h'-'o' */    'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',
       /* 'p'-'w' */    'p',    'q',    'r',    's',    't',    'u',    'v',    'w',
       /* 'x'-x7f */    'x',    'y',    'z',    '{',    '|',    '}',    '~', '\x7f'
};
#define toLower(c) (NTL_tolower_tab[(c)])


void tea(unsigned int *v, unsigned int *k, unsigned int *x)
{
    unsigned int y = v[0] ^ x[0], z = v[1] ^ x[1], sum = 0, delta = 0x9E3779B9;
    unsigned int a = k[0], b = k[1], n = 32;
    unsigned int c = 0, d = 0;

    while (n-- > 0)
    {
    	sum += delta;
    	y += ((z << 4) + a) ^ ((z + sum) ^ ((z >> 5) + b));
    	z += ((y << 4) + c) ^ ((y + sum) ^ ((y >> 5) + d));
    }

    x[0] = y;
    x[1] = z;
}

char *crear_vhost(char *ipreal)
{
    unsigned int v[2], k[2], x[2];
    int ts=0;
    char clave[12 + 1];
    static char virtualhost[22];
    struct hostent *hp;
    struct in_addr addr;

    hp = gethostbyname((char *)ipreal);
    memcpy(&addr,hp->h_addr,hp->h_length);

    strncpy(clave, clave_cifrado, 12);
    clave[12] = '\0';

    /* resultado */
    x[0] = x[1] = 0;

    while (1)
    {
    	char tmp;

    	/* resultado */
    	x[0] = x[1] = 0;

    	/* valor */
    	tmp = clave[6];
    	clave[6] = '\0';
    	k[0] = base64toint(clave);
    	clave[6] = tmp;
    	k[1] = base64toint(clave + 6);

    	v[0] = (k[0] & 0xffff0000) + ts;
    	v[1] = ntohl((unsigned long)addr.s_addr);

    	tea(v, k, x);

    	/* formato direccion virtual: qWeRty.AsDfGh.virtual */
    	inttobase64(virtualhost, x[0], 6);
    	virtualhost[6] = '.';
    	inttobase64(virtualhost + 7, x[1], 6);
    	strcpy(virtualhost + 13, ".virtual");

    	/* el nombre de Host es correcto? */
    	if (!strchr(virtualhost, '[') && !strchr(virtualhost, ']'))
      		break;                    /* nice host name */
    	else
    	{
      		if (++ts == 65536)  {
			/* No deberia ocurrir nunca */
        		strcpy(virtualhost, "Soy pepe");
       			break;
      		}
    	}
    }
    return virtualhost;
}

char *normalizar_nick(char *entrada)
{
    int longitud_nick = strlen(entrada);
    int cont=(longitud_nick < 16) ? 2 : ((longitud_nick + 8) / 8);

    char tempnick[8 * cont + 1];
    char nicks[longitud_nick + 1];                  /* Nick normalizado */
    char *normalizado;

    int i = 0;

    strcpy(nicks, entrada);
    nicks[longitud_nick] = '\0';

    /* Normalizar nick */
    while (nicks[i] != 0)
    {
    	nicks[i] = toLower((int) nicks[i]);
        i++;
    }

    memset(tempnick, 0, sizeof(tempnick));
    strncpy(tempnick, nicks ,sizeof(tempnick) - 1);
    normalizado = nicks;

    return normalizado;
}

void bdd_regnick(char *entrada, const char *valor, ...)
{
        unsigned int v[2], k[2], x[2];
        int longitud_nick = strlen(entrada);
        int cont=(longitud_nick < 16) ? 2 : ((longitud_nick + 8) / 8);

        char tempnick[8 * cont + 1];
        char tmppass[12 + 1];
        unsigned int *p = (unsigned int *)tempnick;     /* int == 32 bits */
        char nicks[longitud_nick + 1];                  /* Nick normalizado */
        char clave[12 + 1];                             /* Clave encriptada */
        int i = 0;

        strcpy(nicks, entrada);
        nicks[longitud_nick] = '\0';

        /* Normalizar nick */
        while (nicks[i] != 0)
        {
                nicks[i] = toLower((int) nicks[i]);
                i++;
        }

        memset(tempnick, 0, sizeof(tempnick));
        strncpy(tempnick, nicks ,sizeof(tempnick) - 1);

        memset(tmppass, 0, sizeof(tmppass));
        strncpy(tmppass, valor, sizeof(tmppass) - 1);

        /* relleno   ->   123456789012 */
        strncat(tmppass, "AAAAAAAAAAAA", sizeof(tmppass) - strlen(tmppass) -1);

        x[0] = x[1] = 0;
        k[1] = base64toint(tmppass + 6);
        tmppass[6] = '\0';
        k[0] = base64toint(tmppass);

        while(cont--)
        {
                v[0] = ntohl(*p++);      /* 32 bits */
                v[1] = ntohl(*p++);      /* 32 bits */
                tea(v, k, x);
        }
        inttobase64(clave, x[0], 6);
        inttobase64(clave + 6, x[1], 6);
        send_cmd(NULL, "DB * %d n %s :%s", tabla_n, nicks, clave);
        tabla_n++;
}

void bdd_dropnick(char *entrada)
{
    send_cmd(NULL, "DB * %d n %s :", tabla_n, normalizar_nick(entrada));
    tabla_n++;
}

void bdd_forbidnick(char *entrada)
{
    send_cmd(NULL, "DB * %d n %s :0*", tabla_n, normalizar_nick(entrada));
    tabla_n++;
}

void bdd_addvhost(char *entrada, char *clave)
{
    send_cmd(NULL, "DB * %d v %s :%s", tabla_v, normalizar_nick(entrada), clave);
    tabla_v++;
}

void bdd_delvhost(char *entrada)
{
    send_cmd(NULL, "DB * %d v %s :", tabla_v, normalizar_nick(entrada));
    tabla_v++;
}

void bdd_addvhostvip(char *entrada, char *clave)
{
    send_cmd(NULL, "DB * %d w %s :%s", tabla_v, normalizar_nick(entrada), clave);
    tabla_w++;
}

void bdd_delvhostvip(char *entrada)
{
    send_cmd(NULL, "DB * %d w %s :", tabla_v, normalizar_nick(entrada));
    tabla_w++;
}

void bdd_privadd(char *entrada, int priv)
{
    if (priv == 2) {
	/* Oper */
    	send_cmd(NULL, "DB * %d o %s :h:1", tabla_o, normalizar_nick(entrada));
    } else if (priv == 4) {
	/* Coder */
        send_cmd(NULL, "DB * %d o %s :c:1", tabla_o, normalizar_nick(entrada));
    } else if (priv == 6) {
	/*Admin */
        send_cmd(NULL, "DB * %d o %s :a:1", tabla_o, normalizar_nick(entrada));
    } else if (priv == 8) {
	/* BOT */
        send_cmd(NULL, "DB * %d o %s :b:1", tabla_o, normalizar_nick(entrada));
    } else {
	/* Pre-Oper */
      send_cmd(NULL, "DB * %d o %s :p:1", tabla_o, normalizar_nick(entrada));
    }
    tabla_o++;
}

void bdd_privrem(char *entrada)
{
    send_cmd(NULL, "DB * %d o %s :", tabla_o, normalizar_nick(entrada));
    tabla_o++;
}

void bdd_regchan(char *clave)
{
    send_cmd(NULL, "DB * %d c %s :+nt-iklps", tabla_c, strlower(clave));
    tabla_c++;
}

void bdd_dropchan(char *clave)
{
    send_cmd(NULL, "DB * %d c %s :", tabla_c, strlower(clave));
    tabla_c++;
}

void bdd_ch_rename(char *clave, char *valor)
{
    send_cmd(NULL, "DB * %d c %s :+nt-ik:%s", tabla_c, strlower(clave), valor);
    tabla_c++;
}

void bdd_ch_mlock(char *clave, char *valor)
{
    send_cmd(NULL, "DB * %d c %s :%s:%s", tabla_c, strlower(clave), valor, clave);
    tabla_c++;
}

void bdd_ch_forbid(char *clave)
{
    send_cmd(NULL, "DB * %d c %s :+ntis-klp", tabla_c, strlower(clave));
    tabla_c++;
}

/* Rutinas para DDbserv. */

void bdd_gen_cifrado(void)
{
    static char cadena[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789[]";
    char cifrado[13];
    int cnt = 0;
    cifrado[12] = '\0';
    for(cnt = 0; cnt < 12; ++cnt)
       cifrado[cnt] = cadena[random() % 64];
    clave_cifrado = cifrado;
    send_cmd(NULL, "DB * %d z clave.de.cifrado.de.ips :%s", tabla_z, cifrado);
    tabla_z++;
}

void bdd_compactar(void)
{
	send_cmd(NULL, "DB * %d n * :", tabla_n);
	send_cmd(NULL, "DB * %d b * :", tabla_b);
	send_cmd(NULL, "DB * %d c * :", tabla_c);
	send_cmd(NULL, "DB * %d e * :", tabla_e);
	send_cmd(NULL, "DB * %d i * :", tabla_i);
	send_cmd(NULL, "DB * %d j * :", tabla_j);
	send_cmd(NULL, "DB * %d o * :", tabla_o);
	send_cmd(NULL, "DB * %d v * :", tabla_v);
	send_cmd(NULL, "DB * %d r * :", tabla_r);
	send_cmd(NULL, "DB * %d w * :", tabla_w);
        send_cmd(NULL, "DB * %d u * :", tabla_u);
	send_cmd(NULL, "DB * %d z * :", tabla_z);
	tabla_n++;
	tabla_b++;
	tabla_c++;
	tabla_e++;
	tabla_i++;
	tabla_j++;
	tabla_o++;
	tabla_v++;
	tabla_r++;
	tabla_w++;
	tabla_z++;
}

void bdd_eline_add(char *username, char *host)
{
    send_cmd(NULL, "DB * %d e %s :%s", tabla_e, host, username);
    tabla_e++;
}

void bdd_eline_del(char *host)
{
    send_cmd(NULL, "DB * %d e %s :", tabla_e, host);
    tabla_e++;
}

void bdd_maxclones(int entrada)
{
	if (entrada)
        	send_cmd(NULL, "DB * %d z numero.maximo.de.clones.por.defecto :%d", tabla_z, entrada);
	else
	send_cmd(NULL, "DB * %d z numero.maximo.de.clones.por.defecto :", tabla_z);
        tabla_z++;
}

void bdd_clones(char *host, int limite)
{
	if (limite)
		send_cmd(NULL, "DB * %d i %s :%d", tabla_i, host, limite);
	else
		send_cmd(NULL, "DB * %d i %s :", tabla_i, host);
	tabla_i++;
}

void bdd_quitclones(char *entrada)
{
        send_cmd(NULL, "DB * %d z mensaje.de.demasiados.clones :%s", tabla_z, entrada);
        tabla_z++;
}

void bdd_serverhide(int entrada)
{
	if (entrada)
        	send_cmd(NULL, "DB * %d z ocultar.servidores :%d", tabla_z, entrada);
	else
		send_cmd(NULL, "DB * %d z ocultar.servidores :", tabla_z);
        tabla_z++;
}

void bdd_autoinv(int entrada)
{
	if (entrada)
        	send_cmd(NULL, "DB * %d z auto.invisible :%d", tabla_z, entrada);
	else
		send_cmd(NULL, "DB * %d z auto.invisible :", tabla_z);
        tabla_z++;
}

void bdd_msgquit(char *entrada, char *valor)
{
        send_cmd(NULL, "DB * %d z quit:%s :%s", tabla_z, entrada, valor);
        tabla_z++;
}

void bdd_pseudonick(char *entrada, char *valor)
{
        send_cmd(NULL, "DB * %d b %s :%s", tabla_b, entrada, valor);
        tabla_b++;
}

void bdd_uline(char *entrada, int valor)
{
        if (valor)
                send_cmd(NULL, "DB * %d u %s :1", tabla_u, entrada);
        else
                send_cmd(NULL, "DB * %d u %s :", tabla_u, entrada);
        tabla_u++;
}

void bdd_set_p09(char *entrada, int valor)
{
        if (valor)
                send_cmd(NULL, "DB * %d z p09:%s :%d", tabla_z, entrada, valor);
        else
                send_cmd(NULL, "DB * %d z p09:%s :", tabla_z, entrada);
        tabla_z++;
}

void bdd_chan_jail(char *entrada, int valor)
{
        if (valor)
                send_cmd(NULL, "DB * %d z debugchan :%s", tabla_z, entrada);
        else
                send_cmd(NULL, "DB * %d z debugchan :", tabla_z);
        tabla_z++;
}

#endif
