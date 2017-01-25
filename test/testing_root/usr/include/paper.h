
/*
 * Copyright (C) Yves Arrouye <Yves.Arrouye@marin.fdn.fr>, 1996.
 *
 * Use under the GPL version 2. You are not allowed to remove this
 * copyright notice.
 *
 */

#ifndef PAPER_H
#define PAPER_H

/*
 * systempapername() returns the preferred paper size got from either the
 *   PAPER environment variable or the /etc/papersize file. If 0 is
 *   returned, one should use the value of defaultpapername().
 *
 * paperinfo() looks from the given paper name in a table of known sizes
 *   and returns 0 if it found it; if this is the case, the width and
 *   height arguments have been set to the correct values in points (one
 *   inch contains 72 points). The case of paper size is not significant.
 *
 */

#if !defined(__STDC__)

#define __PAPER_CONST
#define __PAPER_PROTO(p)	()

#else

#define __PAPER_CONST		const
#define __PAPER_PROTO(p)	p

#endif

#ifdef __cplusplus
extern "C" {
#endif

struct paper;

extern int paperinit __PAPER_PROTO((void));
extern int paperdone __PAPER_PROTO((void));

extern __PAPER_CONST char* papername __PAPER_PROTO((const struct paper*));
extern double paperpswidth __PAPER_PROTO((const struct paper*));
extern double paperpsheight __PAPER_PROTO((const struct paper*));

extern __PAPER_CONST char* defaultpapersizefile __PAPER_PROTO((void));
extern __PAPER_CONST char* systempapersizefile __PAPER_PROTO((void));
extern __PAPER_CONST char* defaultpapername __PAPER_PROTO((void));
extern char* systempapername __PAPER_PROTO((void));
extern __PAPER_CONST struct paper* paperinfo __PAPER_PROTO((const char*));
extern __PAPER_CONST struct paper* paperwithsize __PAPER_PROTO((
    double pswidth, double psheight));

extern __PAPER_CONST struct paper* paperfirst __PAPER_PROTO((void));
extern __PAPER_CONST struct paper* paperlast __PAPER_PROTO((void));
extern __PAPER_CONST struct paper* papernext __PAPER_PROTO((
    const struct paper*));
extern __PAPER_CONST struct paper* paperprev __PAPER_PROTO((
    const struct paper*));

#undef __PAPER_CONST
#undef __PAPER_PROTO

#ifdef __cplusplus
}
#endif

#endif

