#
#   Copyright (C) 2017-2018 CASM Organization <https://casm-lang.org>
#   All rights reserved.
#
#   Developed by: Philipp Paulweber
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

include_directories(
  ${PROJECT_BINARY_DIR}/src
  ${LIBSTDHL_INCLUDE_DIR}
  ${LIBPASS_INCLUDE_DIR}
  )


add_library( ${PROJECT}-cpp OBJECT
  Atom.cpp
  Logic.cpp
  Formula.cpp
  Node.cpp
  Record.cpp
  Specification.cpp
  Term.cpp
  Token.cpp
  Trace.cpp
  Visitor.cpp
  analyze/DumpDebugPass.cpp
  transform/DumpSourcePass.cpp
  transform/SourceToAstPass.cpp
  )


configure_file(
  Version.in.h
  ${PROJECT}/Version.h
  )
configure_file(
  Version.in
  ${PROJECT}/Version
  )
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}/Version.h
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}/Version
  DESTINATION
    "include/${PROJECT}"
  )


ecm_generate_headers( ${PROJECT}_HEADERS_CPP
  ORIGINAL
    CAMELCASE
  HEADER_NAMES
    Atom
    Logic
    Formula
    Node
    Record
    Role
    Specification
    TPTP
    Term
    Token
    Trace
    Visitor
    libtptp
  PREFIX
    ${PROJECT}
  REQUIRED_HEADERS
    ${PROJECT}_HEADERS
  )
install(
  FILES
    ${${PROJECT}_HEADERS}
    ${${PROJECT}_HEADERS_CPP}
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}/Version
  DESTINATION
    "include/${PROJECT}"
  )


ecm_generate_headers( ${PROJECT}_ANALYZE_HEADERS_CPP
  ORIGINAL
    CAMELCASE
  HEADER_NAMES
    DumpDebugPass
  PREFIX
    ${PROJECT}/analyze
  RELATIVE
    analyze
  REQUIRED_HEADERS
    ${PROJECT}_ANALYZE_HEADERS
)
install(
  FILES
    ${${PROJECT}_ANALYZE_HEADERS}
    ${${PROJECT}_ANALYZE_HEADERS_CPP}
  DESTINATION
    "include/${PROJECT}/analyze"
)


ecm_generate_headers( ${PROJECT}_TRANSFORM_HEADERS_CPP
  ORIGINAL
    CAMELCASE
  HEADER_NAMES
    DumpSourcePass
    SourceToAstPass
  PREFIX
    ${PROJECT}/transform
  RELATIVE
    transform
  REQUIRED_HEADERS
    ${PROJECT}_TRANSFORM_HEADERS
)
install(
  FILES
    ${${PROJECT}_TRANSFORM_HEADERS}
    ${${PROJECT}_TRANSFORM_HEADERS_CPP}
  DESTINATION
    "include/${PROJECT}/transform"
)
