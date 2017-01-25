#ifdef __cplusplus
extern "C" {
#endif

#ifndef GD_IO_H
#define GD_IO_H 1

#include <stdio.h>

#ifdef VMS
#	define Putchar gdPutchar
#endif

/*
  Group: Types

  typedef: gdIOCtx

  gdIOCtx structures hold function pointers for doing image IO.
  
  Most of the gd functions that read and write files, such as
  <gdImagePng> also have variants that accept a <gdIOCtx> structure;
  see <gdImagePngCtx> and <gdImageCreateFromJpegCtx>.

  Those who wish to provide their own custom routines to read and
  write images can populate a gdIOCtx structure with functions of
  their own devising to to read and write data. For image reading, the
  only mandatory functions are getC and getBuf, which must return the
  number of characters actually read, or a negative value on error or
  EOF. These functions must read the number of characters requested
  unless at the end of the file.

  For image writing, the only mandatory functions are putC and putBuf,
  which return the number of characters written; these functions must
  write the number of characters requested except in the event of an
  error. The seek and tell functions are only required in conjunction
  with the gd2 file format, which supports quick loading of partial
  images. The gd_free function will not be invoked when calling the
  standard Ctx functions; it is an implementation convenience when
  adding new data types to gd. For examples, see gd_png.c, gd_gd2.c,
  gd_jpeg.c, etc., all of which rely on gdIOCtx to implement the
  standard image read and write functions.

  > typedef struct gdIOCtx
  > {
  >   int (*getC) (struct gdIOCtx *);
  >   int (*getBuf) (struct gdIOCtx *, void *, int wanted);
  > 
  >   void (*putC) (struct gdIOCtx *, int);
  >   int (*putBuf) (struct gdIOCtx *, const void *, int wanted);
  > 
  >   // seek must return 1 on SUCCESS, 0 on FAILURE. Unlike fseek! 
  >   int (*seek) (struct gdIOCtx *, const int);
  >   long (*tell) (struct gdIOCtx *);
  > 
  >   void (*gd_free) (struct gdIOCtx *);
  > } gdIOCtx;




 */
typedef struct gdIOCtx {
    int (*getC)(struct gdIOCtx *);
    int (*getBuf)(struct gdIOCtx *, void *, int);
    void (*putC)(struct gdIOCtx *, int);
    int (*putBuf)(struct gdIOCtx *, const void *, int);
    /* seek must return 1 on SUCCESS, 0 on FAILURE. Unlike fseek! */
    int (*seek)(struct gdIOCtx *, const int);
    long (*tell)(struct gdIOCtx *);
    void (*gd_free)(struct gdIOCtx *);
    void *data;
} gdIOCtx;

typedef struct gdIOCtx *gdIOCtxPtr;

void Putword(int w, gdIOCtx *ctx);
void Putchar(int c, gdIOCtx *ctx);

void gdPutC(const unsigned char c, gdIOCtx *ctx);
int gdPutBuf(const void *, int, gdIOCtx *);
void gdPutWord(int w, gdIOCtx *ctx);
void gdPutInt(int w, gdIOCtx *ctx);

int gdGetC(gdIOCtx *ctx);
int gdGetBuf(void *, int, gdIOCtx *);
int gdGetByte(int *result, gdIOCtx *ctx);
int gdGetWord(int *result, gdIOCtx *ctx);
int gdGetWordLSB(signed short int *result, gdIOCtx *ctx);
int gdGetInt(int *result, gdIOCtx *ctx);
int gdGetIntLSB(signed int *result, gdIOCtx *ctx);

int gdSeek(gdIOCtx *ctx, const int offset);
long gdTell(gdIOCtx *ctx);

#endif

#ifdef __cplusplus
}
#endif
