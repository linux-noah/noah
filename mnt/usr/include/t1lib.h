/*--------------------------------------------------------------------------
  ----- File:        t1lib.h
  ----- Author:      Rainer Menzner (Rainer.Menzner@web.de)
  ----- Date:        2004-12-19
  ----- Description: This file is part of the t1-library. It must be
                     included by the user of the t1lib. It contains
		     function declarations and some basic data types, the
		     user must deal with.
  ----- Copyright:   t1lib is copyrighted (c) Rainer Menzner, 1996-2004.
                     As of version 0.5, t1lib is distributed under the
		     GNU General Public Library Lincense. The
		     conditions can be found in the files LICENSE and
		     LGPL, which should reside in the toplevel
		     directory of the distribution.  Please note that 
		     there are parts of t1lib that are subject to
		     other licenses:
		     The parseAFM-package is copyrighted by Adobe Systems
		     Inc.
		     The type1 rasterizer is copyrighted by IBM and the
		     X11-consortium.
  ----- Warranties:  Of course, there's NO WARRANTY OF ANY KIND :-)
  ----- Credits:     I want to thank IBM and the X11-consortium for making
                     their rasterizer freely available.
		     Also thanks to Piet Tutelaers for his ps2pk, from
		     which I took the rasterizer sources in a format
		     independent from X11.
                     Thanks to all people who make free software living!
--------------------------------------------------------------------------*/


#ifndef T1LIB_H_INCLUDED

#define T1LIB_H_INCLUDED

/* type definitions, needed by the user: */

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

/* Version information filled in by configure */
#define T1LIB_VERSION            5
#define T1LIB_REVISION           1
#define T1LIB_PATCHLEVEL         2
#define T1LIB_VERSIONSTRING      "5.1.2"

/* Data Type information filled in by configure. */
typedef short T1_int16;
typedef int T1_int32;

/* the data structure which contains the character bitmap description */
typedef struct
{
  char *bits;           /* A pointer to the characters local bitmap */
  struct                /* A struct containing diverse metric information */
  {
    int ascent;
    int descent;
    int leftSideBearing;
    int rightSideBearing;
    int advanceX;
    int advanceY;
  } metrics;
  void *pFontCacheInfo;
  unsigned long bpp;
} GLYPH;


/* A structure representing a matrix */
typedef struct
{
  double cxx;
  double cyx;
  double cxy;
  double cyy;
} T1_TMATRIX;


/* the bounding box data structure: */
typedef struct
{ 
   int llx;	/* lower left x-position  */
   int lly;	/* lower left y-position  */
   int urx;	/* upper right x-position */
   int ury;	/* upper right y-position */
} BBox;


/* A data that makes most important information available to user. */
typedef struct
{
  int      width;       /* The glyph's width */
  BBox     bbox;        /* The glyph's bounding box */
  int      numchars;    /* The number of characters in the glyph (string) */
  int      *charpos;    /* A pointer to an integer array were the horizontal
			   positions in (afm units) of the individual
			   characters in the string are stored */
} METRICSINFO;


#define  PAD(bits, pad)  (((bits)+(pad)-1)&-(pad))


/* def's for T1_InitLib() */
#define NO_LOGFILE          0x0
#define LOGFILE             0x1
#define IGNORE_FONTDATABASE 0x2  /* Default is to read database */
#define IGNORE_CONFIGFILE   0x4  /* Default is to read config file */
#define T1_AA_CACHING       0x8  /* Cache aa-bytes */
#define T1_NO_AFM           0x10 /* Do not load or generate AFM data */



/* common 'yes'/'no' */
#define T1_YES              0x1
#define T1_NO               0x0


/* logfile levels: */
#define T1LOG_ERROR     1
#define T1LOG_WARNING   2
#define T1LOG_STATISTIC 3
#define T1LOG_DEBUG     4


/* #define's for manipulating searchpaths */
#define T1_PFAB_PATH        0x01
#define T1_AFM_PATH         0x02
#define T1_ENC_PATH         0x04
#define T1_FDB_PATH         0x08
#define T1_APPEND_PATH      0x00
#define T1_PREPEND_PATH     0x01


/* #define's for character/string properties (not all implemented) */
#define T1_DEFAULT             0x0000
#define T1_UNDERLINE           0x0001
#define T1_OVERLINE            0x0002
#define T1_OVERSTRIKE          0x0004
#define T1_DOUBLEOVERSTRIKE    0x0008
#define T1_RIGHT_TO_LEFT       0x0010
#define T1_SUBSCRIPT           0x0100
#define T1_SUPERSCRIPT         0x0200
#define T1_STROKED             0x1000
#define T1_KERNING             0x2000


/* Setting the subsampling value */
#define T1_AA_NONE  1
#define T1_AA_LOW   2
#define T1_AA_HIGH  4


/* Error handling: */
extern int T1_errno;

/* These are from scanning a font file */
#define T1ERR_SCAN_FONT_FORMAT       -5
#define T1ERR_SCAN_FILE_OPEN_ERR     -4
#define T1ERR_SCAN_OUT_OF_MEMORY     -3
#define T1ERR_SCAN_ERROR             -2
#define T1ERR_SCAN_FILE_EOF          -1
/* These are from generating paths */
#define T1ERR_PATH_ERROR              1
#define T1ERR_PARSE_ERROR             2
#define T1ERR_TYPE1_ABORT             3
/* These are from t1lib */
#define T1ERR_INVALID_FONTID          10
#define T1ERR_INVALID_PARAMETER       11
#define T1ERR_OP_NOT_PERMITTED        12
#define T1ERR_ALLOC_MEM               13
#define T1ERR_FILE_OPEN_ERR           14
#define T1ERR_UNSPECIFIED             15
#define T1ERR_NO_AFM_DATA             16
#define T1ERR_X11                     17
#define T1ERR_COMPOSITE_CHAR          18
#define T1ERR_SCAN_ENCODING           19


/* Flags to control the rasterizer */
#define T1_IGNORE_FORCEBOLD           0x0001
#define T1_IGNORE_FAMILYALIGNMENT     0x0002
#define T1_IGNORE_HINTING             0x0004

#define T1_DEBUG_LINE                 0x0100
#define T1_DEBUG_REGION               0x0200
#define T1_DEBUG_PATH                 0x0400
#define T1_DEBUG_FONT                 0x0800
#define T1_DEBUG_HINT                 0x1000


/* definitions for outline handling */
#define   FRACTBITS     16   /* number of fractional bits in 'fractpel'      */
/* From/to conversion of pels/fractpels */
#define   T1_TOPATHPOINT(p)      (((T1_int32)p)<<FRACTBITS)
#define   PPHALF                 (1<<(FRACTBITS-1))
#define   T1_NEARESTPOINT(fp)    (((fp)+PPHALF)>>FRACTBITS)

/* A fractional point */
typedef struct {
  T1_int32 x;
  T1_int32 y;
} T1_PATHPOINT;


/* A straight outline segment, stroked or not stroked */
typedef struct pathsegment {  
  char type;                /* type of segment (line or move) */
  unsigned char flag;       /* type1 rasterizer internal stuff */
  short references;         /* type1 rasterizer internal stuff */
  unsigned char size;       /* size of the structure */
  unsigned char context;    /* index to device context */
  struct pathsegment *link; /* pointer to next structure in linked list */
  struct pathsegment *last; /* pointer to last structure in list */
  T1_PATHPOINT    dest;     /* relative ending location of path segment */
} T1_PATHSEGMENT;

/* A third order bezier segment */
typedef struct bezierpathsegment {
  char type;                /* type of segment (bezier) */
  unsigned char flag;     /* type1 rasterizer internal stuff */
  short references;       /* type1 rasterizer internal stuff */
  unsigned char size;     /* as with any 'segment' type */
  unsigned char context;  /* as with any 'segment' type */
  T1_PATHSEGMENT *link;   /* as with any 'segment' type */
  T1_PATHSEGMENT *last;   /* as with any 'segment' type */
  T1_PATHPOINT    dest;   /* ending point (D) */
  T1_PATHPOINT    B;      /* control point B */
  T1_PATHPOINT    C;      /* control point C */
} T1_BEZIERSEGMENT;

typedef T1_PATHSEGMENT  T1_OUTLINE;

#define   T1_PATHTYPE_LINE           0x10
#define   T1_PATHTYPE_BEZIER         0x12
#define   T1_PATHTYPE_MOVE           0x15


/* Definitions for font subsetting */
#define T1_SUBSET_DEFAULT            0x00
#define T1_SUBSET_FORCE_REENCODE     0x01
#define T1_SUBSET_SKIP_REENCODE      0x02
#define T1_SUBSET_ENCRYPT_BINARY     0x04
/* This is only for debugging, it does not produce valid font-files!
   This flag is not in the documented API!. */
#define T1_SUBSET_ENCRYPT_NONE       0x08


/* Two structures for handling composite character data */
/* One structure for each symbol of the composite character */
typedef struct
{
  int piece;               /* the index of the current symbol */
  int deltax;              /* horizontal displacement of current symbol in CS */ 
  int deltay;              /* vertical displacement of current symbol in CS */ 
} T1_COMP_PIECE;

/* This one defines the composite character, the number of pieces and how to
   access their data. */
typedef struct 
{
  int compchar;             /* the base character in the current encoding */
  int numPieces;            /* the number of defined pieces including the base char */
  T1_COMP_PIECE *pieces;   /* a pointer to the pieces' information */
} T1_COMP_CHAR_INFO;



/* function declarations: */

/* from t1base.c */
extern void *T1_InitLib( int log);
extern int T1_CloseLib( void);
extern int T1_AddFont( char *fontfilename);
extern void T1_PrintLog( char *func_ident, char *msg_txt, int level, ...);
extern void T1_SetLogLevel( int level);
extern int T1_CheckForInit(void);
extern int T1_CheckForFontID( int FontID);
extern char *T1_GetFontFileName( int FontID);
extern int  T1_GetNoFonts(void);
extern int T1_SetDeviceResolutions( float x_res, float y_res);
extern int T1_CopyFont( int FontID);
extern int T1_QueryX11Support( void);
extern int T1_CheckEndian(void);
extern int T1_SetBitmapPad( int pad);
extern int T1_GetBitmapPad( void);
extern char *T1_GetLibIdent( void);
extern void T1_SetRasterFlags( int flags);
extern char *T1_GetAfmFileName( int FontID);
extern int T1_SetAfmFileName( int FontId, char *afm_name);
extern char *T1_GetFontFilePath( int FontID);
extern char *T1_GetAfmFilePath( int FontID);
extern const char *T1_StrError( int t1err);

/* from t1delete.c */
extern int T1_DeleteSize( int FontID, float size);
extern int T1_DeleteAllSizes( int FontID);
extern int T1_FreeGlyph( GLYPH *glyph);
extern int T1_FreeCompCharData( T1_COMP_CHAR_INFO *cci);
extern int T1_DeleteFont( int FontID);

/* from t1enc.c */
extern char **T1_LoadEncoding( char *FileName);
extern int T1_DeleteEncoding( char **encoding);
extern int T1_ReencodeFont( int FontID, char **Encoding);
extern int T1_SetDefaultEncoding( char **encoding);
extern char *T1_GetEncodingScheme( int FontID);

/* from t1env.c */
extern int T1_SetFileSearchPath( int type, char *pathname);
extern int T1_AddToFileSearchPath( int pathtype, int mode, char *pathname);
extern char *T1_GetFileSearchPath( int type);
extern int T1_SetFontDataBase( char *filename);
extern int T1_AddFontDataBase( int mode, char *filename);

/* from t1finfo.c */
extern int T1_GetKerning( int FontID, char char1,
			  char char2);
extern int T1_GetCharWidth( int FontID, char char1);
extern BBox T1_GetCharBBox( int FontID, char char1);
extern float T1_GetUnderlinePosition( int FontID);
extern float T1_GetUnderlineThickness( int FontID);
extern float T1_GetItalicAngle( int FontID);
extern int T1_GetIsFixedPitch( int FontID);
extern char *T1_GetFontName( int FontID);
extern char *T1_GetFullName( int FontID);
extern char *T1_GetFamilyName( int FontID);
extern char *T1_GetWeight( int FontID);
extern char *T1_GetVersion( int FontID);
extern char *T1_GetNotice( int FontID);
extern char *T1_GetCharName( int FontID, char char1);
extern int T1_QueryLigs( int FontID,
			 char char1,
			 char **successors,
			 char **ligatures);
extern int T1_GetEncodingIndex( int FontID, char *char1);
extern int *T1_GetEncodingIndices( int FontID, char *char1);
extern int T1_GetStringWidth( int FontID, char *string,
			      int len,  long spaceoff, int kerning);
extern BBox T1_GetStringBBox( int FontID, char *string,
			      int len,  long spaceoff, int kerning);
extern METRICSINFO T1_GetMetricsInfo( int FontID, char *string,
				      int len,  long spaceoff, int kerning);
extern BBox T1_GetFontBBox( int FontID);
extern char **T1_GetAllCharNames( int FontID);
extern int T1_GetNoKernPairs( int FontID);
extern int T1_GetNoCompositeChars( int FontID);
extern int T1_QueryCompositeChar( int FontID, char char1);
extern T1_COMP_CHAR_INFO *T1_GetCompCharData( int FontID, char char1);
extern T1_COMP_CHAR_INFO *T1_GetCompCharDataByIndex( int FontID, int index);
extern int T1_IsInternalChar( int FontID, char char1);

/* from t1load.c */
extern int T1_LoadFont( int FontID);
extern void *T1_QueryFontSize( int FontID, float size, int aa);

/* from t1set.c */
extern GLYPH *T1_SetChar( int FontID, char charcode, 
			  float size, T1_TMATRIX *transform);
extern GLYPH *T1_SetString( int FontID, char *string, int len,
			    long spaceoff, int modflag,
			    float size, T1_TMATRIX *transform);
extern GLYPH* T1_SetRect( int FontID, float size,
			  float width, float height,
			  T1_TMATRIX *transform);
extern GLYPH *T1_CopyGlyph(GLYPH *glyph);
extern void T1_DumpGlyph( GLYPH *glyph);
extern GLYPH *T1_ConcatGlyphs( GLYPH *glyph1, GLYPH *glyph2,
			       int x_off, int y_off, int modflag);
extern void T1_DumpPixmap( GLYPH *glyph);
extern GLYPH *T1_FillOutline( T1_OUTLINE *path, int modflag);

/* from t1trans.c */
extern int T1_ExtendFont( int FontID, double extend);
extern int T1_SlantFont( int FontID, double slant);
extern int T1_TransformFont( int FontID, T1_TMATRIX *matrix);
extern double T1_GetExtend( int FontID);
extern double T1_GetSlant( int FontID);
extern T1_TMATRIX T1_GetTransform( int FontID);
extern int T1_SetLinePosition( int FontID, int linetype, float value);
extern int T1_SetLineThickness( int FontID, int linetype, float value);
extern float T1_GetLinePosition( int FontID, int linetype);
extern float T1_GetLineThickness( int FontID, int linetype);
extern T1_TMATRIX *T1_RotateMatrix( T1_TMATRIX *matrix, double angle);
extern T1_TMATRIX *T1_MirrorHMatrix( T1_TMATRIX *matrix);
extern T1_TMATRIX *T1_MirrorVMatrix( T1_TMATRIX *matrix);
extern T1_TMATRIX *T1_ShearHMatrix( T1_TMATRIX *matrix, double shear);
extern T1_TMATRIX *T1_ShearVMatrix( T1_TMATRIX *matrix, double shear);
extern T1_TMATRIX *T1_ExtendHMatrix( T1_TMATRIX *matrix, double extent);
extern T1_TMATRIX *T1_ExtendVMatrix( T1_TMATRIX *matrix, double extent);
extern T1_TMATRIX *T1_TransformMatrix( T1_TMATRIX *matrix,
				       double cxx, double cyx,
				       double cxy, double cyy);
extern int T1_StrokeFont( int FontID, int dostroke);
extern int T1_SetStrokeFlag( int FontID);
extern int T1_ClearStrokeFlag( int FontID);
extern int T1_GetStrokeMode( int FontID);
extern int T1_SetStrokeWidth( int FontID, float strokewidth);
extern float T1_GetStrokeWidth( int FontID);


/* from t1aaset.c */
extern GLYPH *T1_AASetChar( int FontID, char charcode, 
			    float size, T1_TMATRIX *transform);
extern GLYPH *T1_AASetString( int FontID, char *string, int len,
			      long spaceoff, int modflag,
			      float size, T1_TMATRIX *transform);
extern GLYPH* T1_AASetRect( int FontID, float size,
			    float width, float height,
			    T1_TMATRIX *transform);
extern int T1_AASetGrayValues(unsigned long white,
			      unsigned long gray75,
			      unsigned long gray50,
			      unsigned long gray25,
			      unsigned long black);
extern int T1_AAHSetGrayValues( unsigned long *grayvals);
extern int T1_AANSetGrayValues( unsigned long bg, unsigned long fg);
extern int T1_AAGetGrayValues( long *pgrayvals);
extern int T1_AAHGetGrayValues( long *pgrayvals);
extern int T1_AANGetGrayValues( long *pgrayvals);
extern int T1_AASetBitsPerPixel( int bpp);
extern int T1_AAGetBitsPerPixel( void);
extern int T1_AASetLevel( int level);
extern int T1_AAGetLevel( void);
extern GLYPH *T1_AAFillOutline( T1_OUTLINE *path, int modflag);
extern int T1_AASetSmartLimits( float limit1, float limit2);
extern int T1_AASetSmartMode( int smart);


/* from t1afmtool.c */
extern int      T1_WriteAFMFallbackFile( int FontID);

/* from t1outline.c */
extern T1_OUTLINE *T1_GetCharOutline( int FontID, char charcode,
				      float size, T1_TMATRIX *transform);
extern T1_OUTLINE *T1_GetStringOutline( int FontID, char *string, int len, 
					long spaceoff, int modflag,
					float size, T1_TMATRIX *transform);
extern T1_OUTLINE *T1_ConcatOutlines( T1_OUTLINE *path1,
				      T1_OUTLINE *path2);
extern T1_OUTLINE *T1_ScaleOutline( T1_OUTLINE *path, float scale);
extern T1_OUTLINE *T1_GetMoveOutline( int FontID, int deltax, int deltay, int modflag,
				      float size, T1_TMATRIX *transform);
extern void T1_DumpPath( T1_OUTLINE *path);
extern void T1_AbsolutePath( T1_OUTLINE *rpath);
extern void T1_RelativePath( T1_OUTLINE *apath);
extern void T1_ManipulatePath( T1_OUTLINE *path,
			       void (*manipulate)(long *x,long *y,int type));
extern T1_OUTLINE *T1_CopyOutline( T1_OUTLINE *path);
extern void T1_FreeOutline( T1_OUTLINE *path);


/* from t1subset.c */
extern char *T1_SubsetFont( int FontID,
			    char *mask,
			    unsigned int flags,
			    int linewidth,
			    unsigned long maxblocksize,
			    unsigned long *bufsize);
extern char *T1_GetCharString( int FontID, char *charname, int *len);
extern int T1_GetlenIV( int FontID);


#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif /* T1LIB_H_INCLUDED */
