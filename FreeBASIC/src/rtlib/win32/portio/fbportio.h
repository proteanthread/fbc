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
 * fbportio.h -- Driver control header
 *
 * chng: aug/2005 written [lillo]
 *
 */

#ifndef __FBPORTIO_H__
#define __FBPORTIO_H__

#define FBPORTIO_NAME			"fbportio"
#define FBPORTIO_VERSION		0x0100

#define FBPORTIO				32768

#define IOCTL_GRANT_IOPM		CTL_CODE(FBPORTIO, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_GET_VERSION		CTL_CODE(FBPORTIO, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)

#endif
