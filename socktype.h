/* Copyright (C) 2013 Calpont Corp.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#ifndef QFE_SOCKTYPE_H__
#define QFE_SOCKTYPE_H__

#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif

#ifdef _MSC_VER
typedef SOCKET SockType;
#define SockReadFcn qfe::socketio::reads
#define SockWriteFcn qfe::socketio::writes
#else
typedef int SockType;
#define SockReadFcn qfe::socketio::readn
#define SockWriteFcn qfe::socketio::writen
#endif

#endif

