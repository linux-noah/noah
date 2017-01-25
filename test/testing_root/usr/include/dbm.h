/* dbm.h  -  The include file for dbm users.  */

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

/* These are the routines in dbm. */

extern int	dbminit (char *file);
extern datum	fetch (datum key);
extern int	store (datum key, datum content);
extern int	delete (datum key);
extern datum	firstkey (void);
extern datum	nextkey (datum key);
extern int	dbmclose (void);
