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
 * strw_concat.c -- wstring concatenation function
 *
 * chng: oct/2004 written [v1ctor]
 *
 */

#include "fb.h"
#include "fb_unicode.h"

/*:::::*/
FBCALL FB_WCHAR *fb_WstrConcat ( const FB_WCHAR *str1, const FB_WCHAR *str2 )
{
	FB_WCHAR *dst, *d;
	int str1_len, str2_len;

	if( str1 != NULL )
		str1_len = fb_wstr_Len( str1 );
	else
		str1_len = 0;

	if( str2 != NULL )
		str2_len = fb_wstr_Len( str2 );
	else
		str2_len = 0;

	/* NULL? */
	if( str1_len + str2_len == 0 )
		return NULL;

	/* alloc temp string */
    dst = fb_wstr_AllocTemp( str1_len + str2_len );

	/* do the concatenation */
    d = fb_wstr_Move( dst, str1, str1_len );
    d = fb_wstr_Move( d, str2, str2_len );
    fb_wstr_SetCharAt( d, 0, L'\0' );

	return dst;
}

