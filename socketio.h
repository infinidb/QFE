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

#ifndef QFE_SOCKETIO_H__
#define QFE_SOCKETIO_H__

#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#else
#include <stdint.h>
#endif
#include <unistd.h>
#include <string>

#include "socktype.h"

namespace qfe
{
namespace socketio
{

#ifndef _MSC_VER
void readn(int fd, void* buf, const size_t wanted);
size_t writen(int fd, const void* data, const size_t nbytes);
#else
void reads(SOCKET fd, void* buf, const size_t wanted);
size_t writes(SOCKET fd, const void* buf, const size_t len);
#endif
uint32_t readNumber32(SockType);
std::string readString(SockType);
void writeString(SockType, const std::string&);

} //namespace qfe::socketio
} //namespace qfe

#endif

