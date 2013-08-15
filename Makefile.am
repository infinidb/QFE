#/* Copyright (C) 2013 Calpont Corp.
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; version 2 of the License.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License along
#   with this program; if not, write to the Free Software Foundation, Inc.,
#   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */
#

AM_YFLAGS = -d -p qfe
AM_LFLAGS = -i -Pqfe -olex.yy.c
bin_PROGRAMS = QFE
QFE_SOURCES = \
	cseputils.cpp \
	ddlstmts.cpp \
	parsequery.cpp \
	returnedrows.cpp \
	sendcsep.cpp \
	server.cpp \
	socketio.cpp \
	qfelexer.lpp \
	qfeparser.ypp
BUILT_SOURCES = qfeparser.cpp qfelexer.cpp qfeparser.h
QFE_CPPFLAGS = -I$(HOME)/genii/export/include -I/usr/include/libxml2

