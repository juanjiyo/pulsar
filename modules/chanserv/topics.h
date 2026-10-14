/* News data structures and constants.
 *
 * IRC Services is copyright (c) 1996-2009 Andrew Church.
 *     E-mail: <achurch@achurch.org>
 * Parts written by Andrew Kempe and others.
 * This program is free but copyrighted software; see the file GPL.txt for
 * details.
 */

#ifndef TOPICOS_H
#define TOPICOS_H

/*************************************************************************/

typedef struct topicositem_ TopicosItem;
struct topicositem_ {
    TopicosItem *next, *prev;

    int16 type;
    int32 num;          /* Numbering is separate for login and oper news */
    char *text;
    char who[NICKMAX];
    time_t time;
};

#define MAX_TOPICOS        32767

/* Maximum number of news items to display */
#define TOPICOS_DISPCOUNT  3

/*************************************************************************/

/* Constants for news types. */

#define TOPICOS_INVALID    -1      /* Used as placeholder */
#define TOPICOS_LOGON      0
#define TOPICOS_OPER       1

/*************************************************************************/

/* Database functions: */

E TopicosItem *add_topicos(NewsItem *topicos);
E void del_topicos(TopicosItem *topicos);
E TopicosItem *get_topicos(int16 type, int32 num);
E TopicosItem *put_topicos(TopicosItem *topicos);
E TopicosItem *first_topicos(void);
E TopicosItem *next_topicos(void);
E int topicos_count(void);

/*************************************************************************/

#endif  /* TOPICOS_H */

/*
 * Local variables:
 *   c-file-style: "stroustrup"
 *   c-file-offsets: ((case-label . *) (statement-case-intro . *))
 *   indent-tabs-mode: nil
 * End:
 *
 * vim: expandtab shiftwidth=4:
 */
