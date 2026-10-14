/* CregServ-related structures.
 *
 * IRC Services is copyright (c) 1996-2009 Andrew Church.
 * E-mail: <achurch@achurch.org>
 * Parts written by Andrew Kempe and others.
 * This program is free but copyrighted software; see the file GPL.txt for
 * details.
 */

#ifndef CREGSERV_H
#define CREGSERV_H

#ifndef ENCRYPT_H
# include "../../encrypt.h"
#endif
#ifndef NICKSERV_H
# include "../nickserv/nickserv.h"
#endif

struct creginfo_ {
    CregInfo *next, *prev;
    int usecount;

    char name[CHANMAX];
    char foundernick[NICKMAX];

    uint32 founder;

    Password founderpass;
    char *descr;

    time_t time_registered;
    time_t time_aprobado;

    int32 flags;

    char nickoper[NICKMAX];

    char denegado_nick[NICKMAX];
    char *denegado_motivo;
    time_t denegado_time;
};

#define CR_DENEGADO    0x00000001
#define CR_PROCESOREG  0x00000002
#define CR_REGISTRADO  0x00000004

E CregInfo *add_creginfo(CregInfo *ci);
E void del_creginfo(CregInfo *ci);
E CregInfo *get_creginfo(const char *chan);
E CregInfo *put_creginfo(CregInfo *cr);
E CregInfo *first_creginfo(void);
E CregInfo *next_creginfo(void);

static void free_creginfo(CregInfo *ci);
#endif
