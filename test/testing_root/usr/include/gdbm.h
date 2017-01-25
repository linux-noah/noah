/* gdbm.h  -  The include file for dbm users.  -*- c -*- */

/*  This file is part of GDBM, the GNU data base manager, by Philip A. Nelson.
    Copyright (C) 1990, 1991, 1993, 2011 Free Software Foundation, Inc.

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

/* Protection for multiple includes. */
#ifndef _GDBM_H_
# define _GDBM_H_

# include <stdio.h>

/* GDBM C++ support */
# if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
# endif

/* Parameters to gdbm_open for READERS, WRITERS, and WRITERS who
   can create the database. */
# define GDBM_READER	0	/* A reader. */
# define GDBM_WRITER	1	/* A writer. */
# define GDBM_WRCREAT	2	/* A writer.  Create the db if needed. */
# define GDBM_NEWDB	3	/* A writer.  Always create a new db. */
# define GDBM_OPENMASK	7	/* Mask for the above. */

# define GDBM_FAST	0x010	/* Write fast! => No fsyncs.  OBSOLETE. */
# define GDBM_SYNC	0x020	/* Sync operations to the disk. */
# define GDBM_NOLOCK	0x040	/* Don't do file locking operations. */
# define GDBM_NOMMAP	0x080	/* Don't use mmap(). */
# define GDBM_CLOEXEC   0x100   /* Close the underlying fd on exec(3) */
  
/* Parameters to gdbm_store for simple insertion or replacement in the
   case that the key is already in the database. */
# define GDBM_INSERT	0	/* Never replace old data with new. */
# define GDBM_REPLACE	1	/* Always replace old data with new. */

/* Parameters to gdbm_setopt, specifing the type of operation to perform. */
# define GDBM_SETCACHESIZE    1  /* Set the cache size. */
# define GDBM_FASTMODE	      2	/* Toggle fast mode.  OBSOLETE. */
# define GDBM_SETSYNCMODE     3  /* Turn on or off sync operations. */
# define GDBM_SETCENTFREE     4  /* Keep all free blocks in the header. */
# define GDBM_SETCOALESCEBLKS 5  /* Attempt to coalesce free blocks. */
# define GDBM_SETMAXMAPSIZE   6  /* Set maximum mapped memory size */
# define GDBM_SETMMAP         7  /* Toggle mmap mode */

/* Compatibility defines: */
# define GDBM_CACHESIZE	     GDBM_SETCACHESIZE
# define GDBM_SYNCMODE	     GDBM_SETSYNCMODE
# define GDBM_CENTFREE       GDBM_SETCENTFREE
# define GDBM_COALESCEBLKS   GDBM_SETCOALESCEBLKS

# define GDBM_GETFLAGS        8  /* Get gdbm_open flags */
# define GDBM_GETMMAP         9  /* Get mmap status */
# define GDBM_GETCACHESIZE    10 /* Get current cache side */
# define GDBM_GETSYNCMODE     11 /* Get synch mode */
# define GDBM_GETCENTFREE     12 /* Get "centfree" status */
# define GDBM_GETCOALESCEBLKS 13 /* Get free block coalesce status */
# define GDBM_GETMAXMAPSIZE   14 /* Get maximum mapped memory size */
# define GDBM_GETDBNAME       15 /* Return database file name */

typedef unsigned long long int gdbm_count_t;
  
/* The data and key structure. */
typedef struct {
	char *dptr;
	int   dsize;
      } datum;


/* A pointer to the GDBM file. */
typedef struct gdbm_file_info *GDBM_FILE;

/* External variable, the gdbm build release string. */
extern const char *gdbm_version;	

# define GDBM_VERSION_MAJOR 1
# define GDBM_VERSION_MINOR 12
# define GDBM_VERSION_PATCH 0

extern int const gdbm_version_number[3];

/* GDBM external functions. */

extern GDBM_FILE gdbm_open (const char *, int, int, int,
			    void (*)(const char *));
extern void gdbm_close (GDBM_FILE);
extern int gdbm_store (GDBM_FILE, datum, datum, int);
extern datum gdbm_fetch (GDBM_FILE, datum);
extern int gdbm_delete (GDBM_FILE, datum);
extern datum gdbm_firstkey (GDBM_FILE);
extern datum gdbm_nextkey (GDBM_FILE, datum);
extern int gdbm_reorganize (GDBM_FILE);
extern void gdbm_sync (GDBM_FILE);
extern int gdbm_exists (GDBM_FILE, datum);
extern int gdbm_setopt (GDBM_FILE, int, void *, int);
extern int gdbm_fdesc (GDBM_FILE);
  
extern int gdbm_export (GDBM_FILE, const char *, int, int);
extern int gdbm_export_to_file (GDBM_FILE dbf, FILE *fp);
  
extern int gdbm_import (GDBM_FILE, const char *, int);
extern int gdbm_import_from_file (GDBM_FILE dbf, FILE *fp, int flag);

extern int gdbm_count (GDBM_FILE dbf, gdbm_count_t *pcount);
  
#define GDBM_DUMP_FMT_BINARY 0
#define GDBM_DUMP_FMT_ASCII  1

#define GDBM_META_MASK_MODE    0x01
#define GDBM_META_MASK_OWNER   0x02
  
extern int gdbm_dump (GDBM_FILE, const char *, int fmt, int open_flags,
		      int mode);
extern int gdbm_dump_to_file (GDBM_FILE, FILE *, int fmt);

extern int gdbm_load (GDBM_FILE *, const char *, int replace,
		      int meta_flags,
		      unsigned long *line);
extern int gdbm_load_from_file (GDBM_FILE *, FILE *, int replace,
				int meta_flags,
				unsigned long *line);

# define GDBM_NO_ERROR		0
# define GDBM_MALLOC_ERROR	1
# define GDBM_BLOCK_SIZE_ERROR	2
# define GDBM_FILE_OPEN_ERROR	3
# define GDBM_FILE_WRITE_ERROR	4
# define GDBM_FILE_SEEK_ERROR	5
# define GDBM_FILE_READ_ERROR	6
# define GDBM_BAD_MAGIC_NUMBER	7
# define GDBM_EMPTY_DATABASE	8
# define GDBM_CANT_BE_READER	9
# define GDBM_CANT_BE_WRITER	10
# define GDBM_READER_CANT_DELETE	11
# define GDBM_READER_CANT_STORE	12
# define GDBM_READER_CANT_REORGANIZE	13
# define GDBM_UNKNOWN_UPDATE	14
# define GDBM_ITEM_NOT_FOUND	15
# define GDBM_REORGANIZE_FAILED	16
# define GDBM_CANNOT_REPLACE	17
# define GDBM_ILLEGAL_DATA	18
# define GDBM_OPT_ALREADY_SET	19
# define GDBM_OPT_ILLEGAL	20
# define GDBM_BYTE_SWAPPED	21
# define GDBM_BAD_FILE_OFFSET	22
# define GDBM_BAD_OPEN_FLAGS	23
# define GDBM_FILE_STAT_ERROR   24
# define GDBM_FILE_EOF          25
# define GDBM_NO_DBNAME         26
# define GDBM_ERR_FILE_OWNER    27
# define GDBM_ERR_FILE_MODE     28
  
# define _GDBM_MIN_ERRNO		0
# define _GDBM_MAX_ERRNO		GDBM_ERR_FILE_MODE
typedef int gdbm_error;		/* For compatibilities sake. */
extern gdbm_error gdbm_errno;
extern const char * const gdbm_errlist[];

/* extra prototypes */

extern const char *gdbm_strerror (gdbm_error);
extern int gdbm_version_cmp (int const a[], int const b[]);

# if defined(__cplusplus) || defined(c_plusplus)
}
# endif

#endif
