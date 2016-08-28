/** \file popt/popt.h
 * \ingroup popt
 */

/* (C) 1998-2000 Red Hat, Inc. -- Licensing details are in the COPYING
   file accompanying popt source distributions, available from 
   ftp://ftp.rpm.org/pub/rpm/dist. */

#ifndef H_POPT
#define H_POPT

#include <stdio.h>			/* for FILE * */

#define POPT_OPTION_DEPTH	10

/** \ingroup popt
 * \name Arg type identifiers
 */
/*@{*/
#define POPT_ARG_NONE		 0U	/*!< no arg */
#define POPT_ARG_STRING		 1U	/*!< arg will be saved as string */
#define POPT_ARG_INT		 2U	/*!< arg ==> int */
#define POPT_ARG_LONG		 3U	/*!< arg ==> long */
#define POPT_ARG_INCLUDE_TABLE	 4U	/*!< arg points to table */
#define POPT_ARG_CALLBACK	 5U	/*!< table-wide callback... must be
					   set first in table; arg points 
					   to callback, descrip points to 
					   callback data to pass */
#define POPT_ARG_INTL_DOMAIN     6U	/*!< set the translation domain
					   for this table and any
					   included tables; arg points
					   to the domain string */
#define POPT_ARG_VAL		 7U	/*!< arg should take value val */
#define	POPT_ARG_FLOAT		 8U	/*!< arg ==> float */
#define	POPT_ARG_DOUBLE		 9U	/*!< arg ==> double */
#define	POPT_ARG_LONGLONG	 10U	/*!< arg ==> long long */

#define POPT_ARG_MAINCALL	16U+11U	/*!< EXPERIMENTAL: return (*arg) (argc, argv) */
#define	POPT_ARG_ARGV		12U	/*!< dupe'd arg appended to realloc'd argv array. */
#define	POPT_ARG_SHORT		13U	/*!< arg ==> short */
#define	POPT_ARG_BITSET		16U+14U	/*!< arg ==> bit set */

#define POPT_ARG_MASK		0x000000FFU
#define POPT_GROUP_MASK		0x0000FF00U

/*@}*/

/** \ingroup popt
 * \name Arg modifiers
 */
/*@{*/
#define POPT_ARGFLAG_ONEDASH	0x80000000U  /*!< allow -longoption */
#define POPT_ARGFLAG_DOC_HIDDEN 0x40000000U  /*!< don't show in help/usage */
#define POPT_ARGFLAG_STRIP	0x20000000U  /*!< strip this arg from argv(only applies to long args) */
#define	POPT_ARGFLAG_OPTIONAL	0x10000000U  /*!< arg may be missing */

#define	POPT_ARGFLAG_OR		0x08000000U  /*!< arg will be or'ed */
#define	POPT_ARGFLAG_NOR	0x09000000U  /*!< arg will be nor'ed */
#define	POPT_ARGFLAG_AND	0x04000000U  /*!< arg will be and'ed */
#define	POPT_ARGFLAG_NAND	0x05000000U  /*!< arg will be nand'ed */
#define	POPT_ARGFLAG_XOR	0x02000000U  /*!< arg will be xor'ed */
#define	POPT_ARGFLAG_NOT	0x01000000U  /*!< arg will be negated */
#define POPT_ARGFLAG_LOGICALOPS \
        (POPT_ARGFLAG_OR|POPT_ARGFLAG_AND|POPT_ARGFLAG_XOR)

#define	POPT_BIT_SET	(POPT_ARG_VAL|POPT_ARGFLAG_OR)
					/*!< set arg bit(s) */
#define	POPT_BIT_CLR	(POPT_ARG_VAL|POPT_ARGFLAG_NAND)
					/*!< clear arg bit(s) */

#define	POPT_ARGFLAG_SHOW_DEFAULT 0x00800000U /*!< show default value in --help */
#define	POPT_ARGFLAG_RANDOM	0x00400000U  /*!< random value in [1,arg] */
#define	POPT_ARGFLAG_TOGGLE	0x00200000U  /*!< permit --[no]opt prefix toggle */

/*@}*/

/** \ingroup popt
 * \name Callback modifiers
 */
/*@{*/
#define POPT_CBFLAG_PRE		0x80000000U  /*!< call the callback before parse */
#define POPT_CBFLAG_POST	0x40000000U  /*!< call the callback after parse */
#define POPT_CBFLAG_INC_DATA	0x20000000U  /*!< use data from the include line,
					       not the subtable */
#define POPT_CBFLAG_SKIPOPTION	0x10000000U  /*!< don't callback with option */
#define POPT_CBFLAG_CONTINUE	0x08000000U  /*!< continue callbacks with option */
/*@}*/

/** \ingroup popt
 * \name Error return values
 */
/*@{*/
#define POPT_ERROR_NOARG	-10	/*!< missing argument */
#define POPT_ERROR_BADOPT	-11	/*!< unknown option */
#define POPT_ERROR_OPTSTOODEEP	-13	/*!< aliases nested too deeply */
#define POPT_ERROR_BADQUOTE	-15	/*!< error in paramter quoting */
#define POPT_ERROR_ERRNO	-16	/*!< errno set, use strerror(errno) */
#define POPT_ERROR_BADNUMBER	-17	/*!< invalid numeric value */
#define POPT_ERROR_OVERFLOW	-18	/*!< number too large or too small */
#define	POPT_ERROR_BADOPERATION	-19	/*!< mutually exclusive logical operations requested */
#define	POPT_ERROR_NULLARG	-20	/*!< opt->arg should not be NULL */
#define	POPT_ERROR_MALLOC	-21	/*!< memory allocation failed */
#define	POPT_ERROR_BADCONFIG	-22	/*!< config file failed sanity test */
/*@}*/

/** \ingroup popt
 * \name poptBadOption() flags
 */
/*@{*/
#define POPT_BADOPTION_NOALIAS  (1U << 0)  /*!< don't go into an alias */
/*@}*/

/** \ingroup popt
 * \name poptGetContext() flags
 */
/*@{*/
#define POPT_CONTEXT_NO_EXEC	(1U << 0)  /*!< ignore exec expansions */
#define POPT_CONTEXT_KEEP_FIRST	(1U << 1)  /*!< pay attention to argv[0] */
#define POPT_CONTEXT_POSIXMEHARDER (1U << 2) /*!< options can't follow args */
#define POPT_CONTEXT_ARG_OPTS	(1U << 4) /*!< return args as options with value 0 */
/*@}*/

/** \ingroup popt
 */
struct poptOption {
/*@observer@*/ /*@null@*/
    const char * longName;	/*!< may be NULL */
    char shortName;		/*!< may be NUL */
    unsigned int argInfo;
/*@shared@*/ /*@null@*/
    void * arg;			/*!< depends on argInfo */
    int val;			/*!< 0 means don't return, just update flag */
/*@observer@*/ /*@null@*/
    const char * descrip;	/*!< description for autohelp -- may be NULL */
/*@observer@*/ /*@null@*/
    const char * argDescrip;	/*!< argument description for autohelp */
};

/** \ingroup popt
 * A popt alias argument for poptAddAlias().
 */
struct poptAlias {
/*@owned@*/ /*@null@*/
    const char * longName;	/*!< may be NULL */
    char shortName;		/*!< may be NUL */
    int argc;
/*@owned@*/
    const char ** argv;		/*!< must be free()able */
};

/** \ingroup popt
 * A popt alias or exec argument for poptAddItem().
 */
/*@-exporttype@*/
typedef struct poptItem_s {
    struct poptOption option;	/*!< alias/exec name(s) and description. */
    int argc;			/*!< (alias) no. of args. */
/*@owned@*/
    const char ** argv;		/*!< (alias) args, must be free()able. */
} * poptItem;
/*@=exporttype@*/

/** \ingroup popt
 * \name Auto-generated help/usage
 */
/*@{*/

/**
 * Empty table marker to enable displaying popt alias/exec options.
 */
/*@-exportvar@*/
/*@unchecked@*/ /*@observer@*/
extern struct poptOption poptAliasOptions[];
/*@=exportvar@*/
#define POPT_AUTOALIAS { NULL, '\0', POPT_ARG_INCLUDE_TABLE, poptAliasOptions, \
			0, "Options implemented via popt alias/exec:", NULL },

/**
 * Auto help table options.
 */
/*@-exportvar@*/
/*@unchecked@*/ /*@observer@*/
extern struct poptOption poptHelpOptions[];
/*@=exportvar@*/

/*@-exportvar@*/
/*@unchecked@*/ /*@observer@*/
extern struct poptOption * poptHelpOptionsI18N;
/*@=exportvar@*/

#define POPT_AUTOHELP { NULL, '\0', POPT_ARG_INCLUDE_TABLE, poptHelpOptions, \
			0, "Help options:", NULL },

#define POPT_TABLEEND { NULL, '\0', 0, NULL, 0, NULL, NULL }
/*@}*/

/** \ingroup popt
 */
/*@-exporttype@*/
typedef /*@abstract@*/ struct poptContext_s * poptContext;
/*@=exporttype@*/

/** \ingroup popt
 */
#ifndef __cplusplus
/*@-exporttype -typeuse@*/
typedef struct poptOption * poptOption;
/*@=exporttype =typeuse@*/
#endif

/** \ingroup popt
 */
/*@-exportconst@*/
enum poptCallbackReason {
    POPT_CALLBACK_REASON_PRE	= 0, 
    POPT_CALLBACK_REASON_POST	= 1,
    POPT_CALLBACK_REASON_OPTION = 2
};
/*@=exportconst@*/

#ifdef __cplusplus
extern "C" {
#endif
/*@-type@*/

/** \ingroup popt
 * Table callback prototype.
 * @param con		context
 * @param reason	reason for callback
 * @param opt		option that triggered callback
 * @param arg		@todo Document.
 * @param data		@todo Document.
 */
typedef void (*poptCallbackType) (poptContext con, 
		enum poptCallbackReason reason,
		/*@null@*/ const struct poptOption * opt,
		/*@null@*/ const char * arg,
		/*@null@*/ const void * data)
	/*@globals internalState @*/
	/*@modifies internalState @*/;

/** \ingroup popt
 * Destroy context.
 * @param con		context
 * @return		NULL always
 */
/*@null@*/
poptContext poptFreeContext( /*@only@*/ /*@null@*/ poptContext con)
	/*@modifies con @*/;

/** \ingroup popt
 * Initialize popt context.
 * @param name		context name (usually argv[0] program name)
 * @param argc		no. of arguments
 * @param argv		argument array
 * @param options	address of popt option table
 * @param flags		or'd POPT_CONTEXT_* bits
 * @return		initialized popt context
 */
/*@only@*/ /*@null@*/
poptContext poptGetContext(
		/*@dependent@*/ /*@keep@*/ const char * name,
		int argc, /*@dependent@*/ /*@keep@*/ const char ** argv,
		/*@dependent@*/ /*@keep@*/ const struct poptOption * options,
		unsigned int flags)
	/*@globals internalState @*/
	/*@modifies internalState @*/;

/** \ingroup popt
 * Destroy context (alternative implementation).
 * @param con		context
 * @return		NULL always
 */
/*@null@*/
poptContext poptFini( /*@only@*/ /*@null@*/ poptContext con)
	/*@modifies con @*/;

/** \ingroup popt
 * Initialize popt context (alternative implementation).
 * This routine does poptGetContext() and then poptReadConfigFiles().
 * @param argc		no. of arguments
 * @param argv		argument array
 * @param options	address of popt option table
 * @param configPaths	colon separated file path(s) to read.
 * @return		initialized popt context (NULL on error).
 */
/*@only@*/ /*@null@*/ /*@unused@*/
poptContext poptInit(int argc, /*@dependent@*/ /*@keep@*/ const char ** argv,
		/*@dependent@*/ /*@keep@*/ const struct poptOption * options,
		/*@null@*/ const char * configPaths)
	/*@globals fileSystem, internalState @*/
	/*@modifies fileSystem, internalState @*/;

/** \ingroup popt
 * Reinitialize popt context.
 * @param con		context
 */
/*@unused@*/
void poptResetContext(/*@null@*/poptContext con)
	/*@modifies con @*/;

/** \ingroup popt
 * Return value of next option found.
 * @param con		context
 * @return		next option val, -1 on last item, POPT_ERROR_* on error
 */
int poptGetNextOpt(/*@null@*/poptContext con)
	/*@globals fileSystem, internalState @*/
	/*@modifies con, fileSystem, internalState @*/;

/** \ingroup popt
 * Return next option argument (if any).
 * @param con		context
 * @return		option argument, NULL if no argument is available
 */
/*@observer@*/ /*@null@*/ /*@unused@*/
char * poptGetOptArg(/*@null@*/poptContext con)
	/*@modifies con @*/;

/** \ingroup popt
 * Return next argument.
 * @param con		context
 * @return		next argument, NULL if no argument is available
 */
/*@observer@*/ /*@null@*/ /*@unused@*/
const char * poptGetArg(/*@null@*/poptContext con)
	/*@modifies con @*/;

/** \ingroup popt
 * Peek at current argument.
 * @param con		context
 * @return		current argument, NULL if no argument is available
 */
/*@observer@*/ /*@null@*/ /*@unused@*/
const char * poptPeekArg(/*@null@*/poptContext con)
	/*@*/;

/** \ingroup popt
 * Return remaining arguments.
 * @param con		context
 * @return		argument array, NULL terminated
 */
/*@observer@*/ /*@null@*/
const char ** poptGetArgs(/*@null@*/poptContext con)
	/*@modifies con @*/;

/** \ingroup popt
 * Return the option which caused the most recent error.
 * @param con		context
 * @param flags
 * @return		offending option
 */
/*@observer@*/
const char * poptBadOption(/*@null@*/poptContext con, unsigned int flags)
	/*@*/;

/** \ingroup popt
 * Add arguments to context.
 * @param con		context
 * @param argv		argument array, NULL terminated
 * @return		0 on success, POPT_ERROR_OPTSTOODEEP on failure
 */
/*@unused@*/
int poptStuffArgs(poptContext con, /*@keep@*/ const char ** argv)
	/*@modifies con @*/;

/** \ingroup popt
 * Add alias to context.
 * @todo Pass alias by reference, not value.
 * @deprecated Use poptAddItem instead.
 * @param con		context
 * @param alias		alias to add
 * @param flags		(unused)
 * @return		0 on success
 */
/*@unused@*/
int poptAddAlias(poptContext con, struct poptAlias alias, int flags)
	/*@modifies con @*/;

/** \ingroup popt
 * Add alias/exec item to context.
 * @param con		context
 * @param newItem	alias/exec item to add
 * @param flags		0 for alias, 1 for exec
 * @return		0 on success
 */
int poptAddItem(poptContext con, poptItem newItem, int flags)
	/*@modifies con @*/;

/** \ingroup popt
 * Perform sanity checks on a file path.
 * @param fn		file name
 * @return		0 on OK, 1 on NOTOK.
 */
int poptSaneFile(const char * fn)
	/*@globals errno, internalState @*/
	/*@modifies errno, internalState @*/;

/**
 * Read a file into a buffer.
 * @param fn		file name
 * @retval *bp		buffer (malloc'd) (or NULL)
 * @retval *nbp		no. of bytes in buffer (including final NUL) (or NULL)
 * @param flags		1 to trim escaped newlines
 * return		0 on success
 */
int poptReadFile(const char * fn, /*@null@*/ /*@out@*/ char ** bp,
		/*@null@*/ /*@out@*/ size_t * nbp, int flags)
	/*@globals errno, fileSystem, internalState @*/
	/*@modifies *bp, *nbp, errno, fileSystem, internalState @*/;
#define	POPT_READFILE_TRIMNEWLINES	1

/** \ingroup popt
 * Read configuration file.
 * @param con		context
 * @param fn		file name to read
 * @return		0 on success, POPT_ERROR_ERRNO on failure
 */
int poptReadConfigFile(poptContext con, const char * fn)
	/*@globals errno, fileSystem, internalState @*/
	/*@modifies con->execs, con->numExecs,
		errno, fileSystem, internalState @*/;

/** \ingroup popt
 * Read configuration file(s).
 * Colon separated files to read, looping over poptReadConfigFile().
 * Note that an '@' character preceeding a path in the list will
 * also perform additional sanity checks on the file before reading.
 * @param con		context
 * @param paths		colon separated file name(s) to read
 * @return		0 on success, POPT_ERROR_BADCONFIG on failure
 */
int poptReadConfigFiles(poptContext con, /*@null@*/ const char * paths)
	/*@globals errno, fileSystem, internalState @*/
	/*@modifies con->execs, con->numExecs,
		errno, fileSystem, internalState @*/;

/** \ingroup popt
 * Read default configuration from /etc/popt and $HOME/.popt.
 * @param con		context
 * @param useEnv	(unused)
 * @return		0 on success, POPT_ERROR_ERRNO on failure
 */
/*@unused@*/
int poptReadDefaultConfig(poptContext con, /*@unused@*/ int useEnv)
	/*@globals fileSystem, internalState @*/
	/*@modifies con->execs, con->numExecs,
		fileSystem, internalState @*/;

/** \ingroup popt
 * Duplicate an argument array.
 * @note: The argument array is malloc'd as a single area, so only argv must
 * be free'd.
 *
 * @param argc		no. of arguments
 * @param argv		argument array
 * @retval argcPtr	address of returned no. of arguments
 * @retval argvPtr	address of returned argument array
 * @return		0 on success, POPT_ERROR_NOARG on failure
 */
int poptDupArgv(int argc, /*@null@*/ const char **argv,
		/*@null@*/ /*@out@*/ int * argcPtr,
		/*@null@*/ /*@out@*/ const char *** argvPtr)
	/*@modifies *argcPtr, *argvPtr @*/;

/** \ingroup popt
 * Parse a string into an argument array.
 * The parse allows ', ", and \ quoting, but ' is treated the same as " and
 * both may include \ quotes.
 * @note: The argument array is malloc'd as a single area, so only argv must
 * be free'd.
 *
 * @param s		string to parse
 * @retval argcPtr	address of returned no. of arguments
 * @retval argvPtr	address of returned argument array
 */
int poptParseArgvString(const char * s,
		/*@out@*/ int * argcPtr, /*@out@*/ const char *** argvPtr)
	/*@modifies *argcPtr, *argvPtr @*/;

/** \ingroup popt
 * Parses an input configuration file and returns an string that is a 
 * command line.  For use with popt.  You must free the return value when done.
 *
 * Given the file:
\verbatim
# this line is ignored
    #   this one too
aaa
  bbb
    ccc   
bla=bla

this_is   =   fdsafdas
     bad_line=        
  reall bad line  
  reall bad line  = again
5555=   55555   
  test = with lots of spaces
\endverbatim
*
* The result is:
\verbatim
--aaa --bbb --ccc --bla="bla" --this_is="fdsafdas" --5555="55555" --test="with lots of spaces"
\endverbatim
*
* Passing this to poptParseArgvString() yields an argv of:
\verbatim
'--aaa'
'--bbb' 
'--ccc' 
'--bla=bla' 
'--this_is=fdsafdas' 
'--5555=55555' 
'--test=with lots of spaces' 
\endverbatim
 *
 * @bug NULL is returned if file line is too long.
 * @bug Silently ignores invalid lines.
 *
 * @param fp		file handle to read
 * @param *argstrp	return string of options (malloc'd)
 * @param flags		unused
 * @return		0 on success
 * @see			poptParseArgvString
 */
/*@-fcnuse@*/
int poptConfigFileToString(FILE *fp, /*@out@*/ char ** argstrp, int flags)
	/*@globals fileSystem @*/
	/*@modifies *fp, *argstrp, fileSystem @*/;
/*@=fcnuse@*/

/** \ingroup popt
 * Return formatted error string for popt failure.
 * @param error		popt error
 * @return		error string
 */
/*@observer@*/
const char * poptStrerror(const int error)
	/*@*/;

/** \ingroup popt
 * Limit search for executables.
 * @param con		context
 * @param path		single path to search for executables
 * @param allowAbsolute	absolute paths only?
 */
/*@unused@*/
void poptSetExecPath(poptContext con, const char * path, int allowAbsolute)
	/*@modifies con @*/;

/** \ingroup popt
 * Print detailed description of options.
 * @param con		context
 * @param fp		ouput file handle
 * @param flags		(unused)
 */
void poptPrintHelp(poptContext con, FILE * fp, /*@unused@*/ int flags)
	/*@globals fileSystem @*/
	/*@modifies fp, fileSystem @*/;

/** \ingroup popt
 * Print terse description of options.
 * @param con		context
 * @param fp		ouput file handle
 * @param flags		(unused)
 */
void poptPrintUsage(poptContext con, FILE * fp, /*@unused@*/ int flags)
	/*@globals fileSystem @*/
	/*@modifies fp, fileSystem @*/;

/** \ingroup popt
 * Provide text to replace default "[OPTION...]" in help/usage output.
 * @param con		context
 * @param text		replacement text
 */
/*@-fcnuse@*/
void poptSetOtherOptionHelp(poptContext con, const char * text)
	/*@modifies con @*/;
/*@=fcnuse@*/

/** \ingroup popt
 * Return argv[0] from context.
 * @param con		context
 * @return		argv[0]
 */
/*@-fcnuse@*/
/*@observer@*/
const char * poptGetInvocationName(poptContext con)
	/*@*/;
/*@=fcnuse@*/

/** \ingroup popt
 * Shuffle argv pointers to remove stripped args, returns new argc.
 * @param con		context
 * @param argc		no. of args
 * @param argv		arg vector
 * @return		new argc
 */
/*@-fcnuse@*/
int poptStrippedArgv(poptContext con, int argc, char ** argv)
	/*@modifies *argv @*/;
/*@=fcnuse@*/

/**
 * Add a string to an argv array.
 * @retval *argvp	argv array
 * @param argInfo	(unused)
 * @param val		string arg to add (using strdup)
 * @return		0 on success, POPT_ERROR_NULLARG/POPT_ERROR_BADOPERATION
 */
/*@unused@*/
int poptSaveString(/*@null@*/ const char *** argvp, unsigned int argInfo,
		/*@null@*/const char * val)
	/*@modifies *argvp @*/;

/**
 * Save a long long, performing logical operation with value.
 * @warning Alignment check may be too strict on certain platorms.
 * @param arg		integer pointer, aligned on int boundary.
 * @param argInfo	logical operation (see POPT_ARGFLAG_*)
 * @param aLongLong	value to use
 * @return		0 on success, POPT_ERROR_NULLARG/POPT_ERROR_BADOPERATION
 */
/*@-incondefs@*/
/*@unused@*/
int poptSaveLongLong(/*@null@*/ long long * arg, unsigned int argInfo,
		long long aLongLong)
	/*@globals internalState @*/
	/*@modifies *arg, internalState @*/
	/*@requires maxSet(arg) >= 0 /\ maxRead(arg) == 0 @*/;
/*@=incondefs@*/

/**
 * Save a long, performing logical operation with value.
 * @warning Alignment check may be too strict on certain platorms.
 * @param arg		integer pointer, aligned on int boundary.
 * @param argInfo	logical operation (see POPT_ARGFLAG_*)
 * @param aLong		value to use
 * @return		0 on success, POPT_ERROR_NULLARG/POPT_ERROR_BADOPERATION
 */
/*@-incondefs@*/
/*@unused@*/
int poptSaveLong(/*@null@*/ long * arg, unsigned int argInfo, long aLong)
	/*@globals internalState @*/
	/*@modifies *arg, internalState @*/
	/*@requires maxSet(arg) >= 0 /\ maxRead(arg) == 0 @*/;
/*@=incondefs@*/

/**
 * Save a short integer, performing logical operation with value.
 * @warning Alignment check may be too strict on certain platorms.
 * @param arg		short pointer, aligned on short boundary.
 * @param argInfo	logical operation (see POPT_ARGFLAG_*)
 * @param aLong		value to use
 * @return		0 on success, POPT_ERROR_NULLARG/POPT_ERROR_BADOPERATION
 */
/*@-incondefs@*/
/*@unused@*/
int poptSaveShort(/*@null@*/ short * arg, unsigned int argInfo, long aLong)
	/*@globals internalState @*/
	/*@modifies *arg, internalState @*/
	/*@requires maxSet(arg) >= 0 /\ maxRead(arg) == 0 @*/;
/*@=incondefs@*/

/**
 * Save an integer, performing logical operation with value.
 * @warning Alignment check may be too strict on certain platorms.
 * @param arg		integer pointer, aligned on int boundary.
 * @param argInfo	logical operation (see POPT_ARGFLAG_*)
 * @param aLong		value to use
 * @return		0 on success, POPT_ERROR_NULLARG/POPT_ERROR_BADOPERATION
 */
/*@-incondefs@*/
/*@unused@*/
int poptSaveInt(/*@null@*/ int * arg, unsigned int argInfo, long aLong)
	/*@globals internalState @*/
	/*@modifies *arg, internalState @*/
	/*@requires maxSet(arg) >= 0 /\ maxRead(arg) == 0 @*/;
/*@=incondefs@*/

/* The bit set typedef. */
/*@-exporttype@*/
typedef struct poptBits_s {
    unsigned int bits[1];
} * poptBits;
/*@=exporttype@*/

#define _POPT_BITS_N    1024U    /* estimated population */
#define _POPT_BITS_M    ((3U * _POPT_BITS_N) / 2U)
#define _POPT_BITS_K    16U      /* no. of linear hash combinations */

/*@-exportlocal -exportvar -globuse @*/
/*@unchecked@*/
extern unsigned int _poptBitsN;
/*@unchecked@*/
extern  unsigned int _poptBitsM;
/*@unchecked@*/
extern  unsigned int _poptBitsK;
/*@=exportlocal =exportvar =globuse @*/

/*@-exportlocal@*/
int poptBitsAdd(/*@null@*/poptBits bits, /*@null@*/const char * s)
	/*@modifies bits @*/;
/*@=exportlocal@*/
int poptBitsChk(/*@null@*/poptBits bits, /*@null@*/const char * s)
	/*@*/;
int poptBitsClr(/*@null@*/poptBits bits)
	/*@modifies bits @*/;
/*@-exportlocal@*/
int poptBitsDel(/*@null@*/poptBits bits, /*@null@*/const char * s)
	/*@modifies bits @*/;
/*@-fcnuse@*/
int poptBitsIntersect(/*@null@*/ poptBits * ap, /*@null@*/ const poptBits b)
	/*@modifies *ap @*/;
int poptBitsUnion(/*@null@*/ poptBits * ap, /*@null@*/ const poptBits b)
	/*@modifies *ap @*/;
int poptBitsArgs(/*@null@*/ poptContext con, /*@null@*/ poptBits * ap)
	/*@modifies con, *ap @*/;
/*@=fcnuse@*/
/*@=exportlocal@*/

/**
 * Save a string into a bit set (experimental).
 * @retval *bits	bit set (lazily malloc'd if NULL)
 * @param argInfo	logical operation (see POPT_ARGFLAG_*)
 * @param s		string to add to bit set
 * @return		0 on success, POPT_ERROR_NULLARG/POPT_ERROR_BADOPERATION
 */
/*@-incondefs@*/
/*@unused@*/
int poptSaveBits(/*@null@*/ poptBits * bitsp, unsigned int argInfo,
		/*@null@*/ const char * s)
	/*@globals _poptBitsN, _poptBitsM, _poptBitsK, internalState @*/
	/*@modifies *bitsp, _poptBitsN, _poptBitsM, _poptBitsK, internalState @*/;
/*@=incondefs@*/

/*@=type@*/

#ifdef  __cplusplus
}
#endif

#endif
