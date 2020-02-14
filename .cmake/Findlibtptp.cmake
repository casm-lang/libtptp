#
#   Copyright (C) 2017-2020 CASM Organization <https://casm-lang.org>
#   All rights reserved.
#
#   Developed by: Philipp Paulweber
#                 Jakob Moosbrugger
#                 <https://github.com/casm-lang/libtptp>
#
#   This file is part of libtptp.
#
#   libtptp is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   libtptp is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with libtptp. If not, see <http://www.gnu.org/licenses/>.
#
#   Additional permission under GNU GPL version 3 section 7
#
#   libtptp is distributed under the terms of the GNU General Public License
#   with the following clarification and special exception: Linking libtptp
#   statically or dynamically with other modules is making a combined work
#   based on libtptp. Thus, the terms and conditions of the GNU General
#   Public License cover the whole combination. As a special exception,
#   the copyright holders of libtptp give you permission to link libtptp
#   with independent modules to produce an executable, regardless of the
#   license terms of these independent modules, and to copy and distribute
#   the resulting executable under terms of your choice, provided that you
#   also meet, for each linked independent module, the terms and conditions
#   of the license of that module. An independent module is a module which
#   is not derived from or based on libtptp. If you modify libtptp, you
#   may extend this exception to your version of the library, but you are
#   not obliged to do so. If you do not wish to do so, delete this exception
#   statement from your version.
#

# LIBTPTP_FOUND        - system has found the package
# LIBTPTP_INCLUDE_DIR  - the package include directory
# LIBTPTP_LIBRARY      - the package library

include( LibPackage )

libfind_pkg_check_modules( LIBTPTP_PKGCONF libtptp )

find_path( LIBTPTP_INCLUDE_DIR
  NAMES libtptp/libtptp.h
  PATHS ${LIBTPTP_PKGCONF_INCLUDE_DIRS}
  )

find_library( LIBTPTP_LIBRARY
  NAMES libtptp.so libtptp.dylib libtptp.dll
  PATHS ${LIBTPTP_PKGCONF_LIBRARY_DIRS}
  )

find_library( LIBTPTP_ARCHIVE
  NAMES libtptp.a
  PATHS ${LIBTPTP_PKGCONF_LIBRARY_DIRS}
  )

set( LIBTPTP_PROCESS_INCLUDES LIBTPTP_INCLUDE_DIR )
set( LIBTPTP_PROCESS_LIBS     LIBTPTP_LIBRARY LIBTPTP_ARCHIVE )

libfind_process( LIBTPTP )

if( EXISTS "${LIBTPTP_LIBRARY}" AND ${LIBTPTP_LIBRARY} AND
    EXISTS "${LIBTPTP_ARCHIVE}" AND ${LIBTPTP_ARCHIVE} )
  set( LIBTPTP_FOUND TRUE PARENT_SCOPE )
else()
  set( LIBTPTP_FOUND FALSE PARENT_SCOPE )
endif()
