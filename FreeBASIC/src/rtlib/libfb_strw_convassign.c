/*
 *  libfb - FreeBASIC's runtime library
 *	Copyright (C) 2004-2005 Andre V. T. Vicentini (av1ctor@yahoo.com.br) and others.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 * strw_convassign.c -- ascii <-> unicode string convertion functions
 *
 * chng: ago/2005 written [v1ctor]
 *
 */

#include "fb.h"
#include "fb_unicode.h"

/*:::::*/
FBCALL FB_WCHAR *fb_WstrAssignFromA ( FB_WCHAR *dst, int dst_chars, void *src, int src_chars )
{
	if( dst != NULL )
		fb_wstr_ConvFromA( dst, dst_chars, FB_STRPTR( src, src_chars ) );

	/* delete temp? */
	if( src_chars == -1 )
		fb_hStrDelTemp( (FBSTRING *)src );

	return dst;
}

/*:::::*/
FBCALL void *fb_WstrAssignToA ( void *dst, int dst_chars, FB_WCHAR *src, int fillrem )
{
	int src_chars;

	if( dst == NULL )
		return dst;

    if( src != NULL )
    	src_chars = fb_wstr_Len( src );
    else
    	src_chars = 0;

	/* is dst var-len? */
	if( dst_chars == -1 )
	{
		/* src NULL? */
		if( src_chars == 0 )
		{
			fb_StrDelete( (FBSTRING *)dst );
		}
		else
		{
        	/* realloc dst if needed and copy src */
			if( FB_STRSIZE( dst ) != src_chars )
				fb_hStrRealloc( (FBSTRING *)dst, src_chars, FB_FALSE );

			fb_wstr_ConvToA( ((FBSTRING *)dst)->data, src_chars, src );
		}
	}
	/* fixed-len or zstring.. */
	else
	{
		/* src NULL? */
		if( src_chars == 0 )
		{
			*(char *)dst = '\0';
		}
		else
		{
			/* byte ptr? as in C, assume dst is large enough */
			if( dst_chars == 0 )
				dst_chars = src_chars;

			fb_wstr_ConvToA( (char *)dst, dst_chars, src );
		}

		/* fill reminder with null's */
		if( fillrem != 0 )
		{
			dst_chars -= src_chars;
			if( dst_chars > 0 )
				memset( &(((char *)dst)[src_chars]), 0, dst_chars );
		}
	}

	return dst;
}

