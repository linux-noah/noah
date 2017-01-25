/* ndbm.h  -  The include file for ndbm users.  */

/*  This file is part of GDBM, the GNU data base manager, by Philip A. Nelson.
    Copyright (C) 1990-2011  Free Software Foundation, Inc.

    GDBM is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2, or (at your option)
    any later version.

    GDBM is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GDBM. If not, see <http://www.gnu.org/licenses/>.

    You may contact the author by:
       e-mail:  phil@cs.wwu.edu
      us-mail:  Philip A. Nelson
                Computer Science Department
                Western Washington University
                Bellingham, WA 98226
       
*************************************************************************/

#include <gdbm.h>

/* Parameters to dbm_store for simple insertion or replacement. */
#define DBM_INSERT  GDBM_INSERT
#define DBM_REPLACE GDBM_REPLACE

/* The file information header.  */
typedef struct
{
  GDBM_FILE file;         /* Actual gdbm file (held in the .pag file */
  int dirfd;              /* Descriptor of the .dir file */
  datum _dbm_memory;      /* Keeps the last returned key */
  char *_dbm_fetch_val;   /* Keeps the dptr of the last fetched datum */
  gdbm_error _dbm_errno;  /* Error code from the last failed call */
} DBM;

/* Used internally by the library */
#define __gdbm_error_to_ndbm(dbm)				\
  do								\
    {								\
      if (gdbm_errno && gdbm_errno != GDBM_ITEM_NOT_FOUND)	\
	(dbm)->_dbm_errno = gdbm_errno;				\
    }								\
  while (0)

/* These are the routines */

extern DBM 	*dbm_open (char *file, int flags, int mode);
extern void	 dbm_close (DBM *dbf);
extern datum	 dbm_fetch (DBM *dbf, datum key);
extern int	 dbm_store (DBM *dbf, datum key, datum content, int flags);
extern int	 dbm_delete (DBM *dbf, datum key);
extern datum	 dbm_firstkey (DBM *dbf);
extern datum	 dbm_nextkey (DBM *dbf);
extern int       dbm_error (DBM *dbf);
extern void      dbm_clearerr (DBM *dbf);
extern int	 dbm_dirfno (DBM *dbf);
extern int	 dbm_pagfno (DBM *dbf);
extern int	 dbm_rdonly (DBM *dbf);
