/* SPDX-License-Identifier: GPL-2.0-or-later */
#include "utils.h"

/* 6bone referto: extension */
#define REFERTO_FORMAT	"%% referto: whois -h %255s -p %15s %1021[^\n\r]"

#define HIDE_TO_THE_END  -3
#define HIDE_DISABLED    -2
#define HIDE_NOT_STARTED -1

/* prototypes */
char *guess_server(const char *);
const char *match_config_file(const char *);
const char *whereas(const unsigned long);
const char *whereas32(const unsigned long);
char *queryformat(const char *, const char *, const char *);
int hide_line(int *hiding, const char *const line);
char *do_query(const int, const char *, char **, size_t);
char *query_crsnic(const int, const char *);
char *query_afilias(const int, const char *);
char *query_iana(const int, const char *);
int openconn(const char *, const char *);
int connect_with_timeout(int, const struct sockaddr *, socklen_t, int);
void NORETURN usage(int error);
void NORETURN alarm_handler(int);
void NORETURN sighandler(int);
int japanese_locale(void);
unsigned long myinet_aton(const char *);
unsigned long asn32_to_long(const char *);
int isasciidigit(const char);
int endstrcaseeq(const char *, const char *);
int in_domain(const char *, const char *);
const char *is_new_gtld(const char *);
int domfind(const char *, const char *[]);
char *normalize_domain(const char *);
char *convert_6to4(const char *);
char *convert_teredo(const char *);
char *convert_inaddr(const char *);
char *convert_in6arpa(const char *);
char *handle_query(const char *server, const char *port,
		   const char *qstring, const char *fstring);
void split_server_port(const char *const input, char **server, char **port);
char *query_whois(const char* query);


/* flags for RIPE-like servers */
const char *ripeflags="abBcdFGKlLmMrRx";
const char *ripeflagsp="gisTtvq";

