/*
 * This program is copyright Alec Muffett 1993, portions copyright other authors.
 * The authors disclaim all responsibility or liability with respect to it's usage
 * or its effect upon hardware or computer systems.
 */

#ifndef CRACKLIB_PACKER_H
#define CRACKLIB_PACKER_H

/* Moved here cause needed by mod_php */
#define STRINGSIZE	1024
#define TRUNCSTRINGSIZE	(STRINGSIZE/4)

#ifndef NUMWORDS
#define NUMWORDS 	16
#endif
#define MAXWORDLEN	32
#define MAXBLOCKLEN 	(MAXWORDLEN * NUMWORDS)

#ifdef IN_CRACKLIB

#include <stdio.h>
#include <ctype.h>
#include <crack.h>

#if defined(ENABLE_NLS)
#include <libintl.h>
#define _(String) dgettext("cracklib", String)
#else
#define _(String) (String)
#endif

#if defined(HAVE_INTTYPES_H)
#include <inttypes.h>
#else
#if defined(HAVE_STDINT_H)
#include <stdint.h>
#else
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
#endif
#endif


struct pi_header
{
    uint32_t pih_magic;
    uint32_t pih_numwords;
    uint16_t pih_blocklen;
    uint16_t pih_pad;
};

typedef struct
{
    /* Might be FILE* or gzFile */
    void *ifp;
    void *dfp;
    void *wfp;

    uint32_t flags;
#define PFOR_WRITE	0x0001
#define PFOR_FLUSH	0x0002
#define PFOR_USEHWMS	0x0004
#define PFOR_USEZLIB	0x0008

    uint32_t hwms[256];

    struct pi_header header;

    int count;
    char data_put[NUMWORDS][MAXWORDLEN];
    char data_get[NUMWORDS][MAXWORDLEN];
} PWDICT;

#define PW_WORDS(x) ((x)->header.pih_numwords)
#define PIH_MAGIC 0x70775631

/* Internal routines */
extern char *GetPW(PWDICT *pwp, uint32_t number);

#else

/* Dummy structure, this is an internal only opaque data type */
typedef struct {
	int dummy;
} PWDICT;

#endif

extern PWDICT *PWOpen(const char *prefix, char *mode);
extern int PWClose(PWDICT *pwp);
extern unsigned int FindPW(PWDICT *pwp, char *string);
extern int PutPW(PWDICT *pwp, char *string);
extern int PMatch(char *control, char *string);
extern char *Mangle(char *input, char *control);
extern char Chop(char *string);
extern char *Trim(char *string);
extern char *FascistLook(PWDICT *pwp, char *instring);
extern char *FascistLookUser(PWDICT *pwp, char *instring, const char *user, const char *gecos);
extern char *FascistGecos(char *password, int uid);
extern char *FascistGecosUser(char *password, const char *user, const char *gecos);
extern const char *FascistCheck(const char *password, const char *path);

#endif
