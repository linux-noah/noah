/*--------------------------------------------------------------------------
  ----- File:        t1libx.h
  ----- Author:      Rainer Menzner (Rainer.Menzner@web.de)
  ----- Date:        2003-01-02
  ----- Description: This file is part of the t1-library. It must be
                     included by the user of the t1lib. It contains
		     function declarations for the X11 wrapper.
  ----- Copyright:   t1lib is copyrighted (c) Rainer Menzner, 1996-2003.
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


#ifndef T1LIBX_H_INCLUDED

#define T1LIBX_H_INCLUDED


#ifndef _XLIB_H_
#include <X11/Xlib.h>
#endif


#define T1LIB_X11_SUPPORT

/* For paint mode of X-rastering functions */
#define T1_OPAQUE              0x1
#define T1_TRANSPARENT         0x0


/* type definitions, needed by the user: */

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif


/* from t1x11.c */
extern int T1_SetX11Params( Display *display,
			    Visual *visual,
			    unsigned int depth,
			    Colormap colormap);
extern GLYPH *T1_SetCharX( Drawable d, GC gc, int mode, int x, int y,
			   int FontID, char charcode,
			   float size, T1_TMATRIX *transform);
extern GLYPH *T1_SetStringX( Drawable d, GC gc, int mode, int x, int y,
			     int FontID, char *string, int len,
			     long spaceoff, int modflag,
			     float size, T1_TMATRIX *transform);
extern GLYPH *T1_SetRectX( Drawable d, GC gc, int mode, int x_dest, int y_dest,
			   int FontID, float size,
			   float width, float height,
			   T1_TMATRIX *transform);
extern GLYPH *T1_AASetCharX( Drawable d, GC gc, int mode, int x, int y,
			     int FontID, char charcode,
			     float size, T1_TMATRIX *transform);
extern GLYPH *T1_AASetStringX( Drawable d, GC gc, int mode, int x, int y,
			       int FontID, char *string, int len,
			       long spaceoff, int modflag,
			       float size, T1_TMATRIX *transform);
extern GLYPH *T1_AASetRectX( Drawable d, GC gc, int mode, int x_dest, int y_dest,
			     int FontID, float size,
			     float width, float height,
			     T1_TMATRIX *transform);
extern int T1_ComputeAAColorsX( unsigned long fg,
				unsigned long bg,
				int nolevels);
extern int T1_GetDepthOfDrawable( Drawable drawable);
extern void T1_LogicalPositionX( int pos_switch);
extern XImage *T1_XImageFromGlyph( GLYPH *pglyph);

  
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif /* T1LIBX_H_INCLUDED */
