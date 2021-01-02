#
#   Copyright (C) 2017-2021 CASM Organization <https://casm-lang.org>
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

TARGET = libtptp

FORMAT  = src
FORMAT += src/analyze
FORMAT += src/transform
FORMAT += etc
FORMAT += etc/*
FORMAT += etc/*/*

CONFIG  = ../stdhl
ifeq ($(wildcard $(CONFIG)/.cmake/.*),)
  CONFIG = lib/stdhl
  ifeq ($(wildcard $(CONFIG)/.cmake/.*),)
    $(shell git submodule update --init $(CONFIG) && git -C $(CONFIG) checkout master)
  endif
endif

INCLUDE = $(CONFIG)/.cmake/config.mk
include $(INCLUDE)


LX  = flex
YC  = bison
YF  = -Wall -v -g -x

GRAMMAR  = $(OBJ)/src/various/GrammarParser.cpp
GRAMMAR += $(OBJ)/src/various/GrammarLexer.cpp
GRAMMAR += $(OBJ)/src/various/Token.h
GRAMMAR += $(OBJ)/src/various/Token.cpp
# GRAMMAR += src/various/Grammar.txt

grammar: $(GRAMMAR)
.PHONY: grammar
# src/various/Grammar.txt


%/src/various/GrammarLexer.cpp: src/various/GrammarLexer.cpp
	mkdir -p "`dirname $@`"
	cp -f $< $@

src/various/GrammarLexer.cpp: src/GrammarLexer.l src/GrammarToken.hpp
	etc/script.sh generate-lexer "`pwd`/$<" "`pwd`/obj/$< $(filter %.hpp,$^)"
	$(LX) $(LFLAGS) -o $@ obj/$<
	sed -i "s/#include <FlexLexer\.h>//g" $@


%/src/various/GrammarParser.cpp: src/various/GrammarParser.cpp
	mkdir -p "`dirname $@`"
	cp -f $< $@

src/various/GrammarParser.cpp: src/GrammarParser.yy src/GrammarToken.hpp
	etc/script.sh generate-parser "`pwd`/$<" "`pwd`/obj/$< $(filter %.hpp,$^)"
	cd src/various && $(YC) $(YF) -b src/various/ --output GrammarParser.cpp --defines=GrammarParser.tab.h ../../obj/$<


%/src/various/Token.h: src/various/Token.h
	mkdir -p "`dirname $@`"
	cp -f "$<" "$@"

src/various/Token.h: src/Token.h src/GrammarToken.hpp
	etc/script.sh generate-token-header "`pwd`/$<" "`pwd`/$@ $(filter %.hpp,$^)"

%/src/various/Token.cpp: src/various/Token.cpp
	mkdir -p "`dirname $@`"
	cp -f "$<" "$@"

src/various/Token.cpp: src/Token.cpp src/GrammarToken.hpp
	etc/script.sh generate-token-body "`pwd`/$<" "`pwd`/$@ $(filter %.hpp,$^)"

src/various/GrammarParser.output: src/various/GrammarParser.cpp
src/various/GrammarParser.dot:    src/various/GrammarParser.cpp
src/various/GrammarParser.xml:    src/various/GrammarParser.cpp

# src/various/Grammar.txt: src/various/GrammarParser.xml src/GrammarLexer.l
# 	@xsltproc ../stdhl/src/xsl/bison/xml2dw.xsl $< > $@
# 	@sed -i "/ error/d" $@
# 	@sed -i "s/\"binary\"/\"`grep BINARY src/GrammarLexer.l -B 1 | head -n 1 | sed 's/ {//g' | sed 's/\n//g' | sed 's/\r//g'`\"/g" $@
# 	@sed -i "s/\"hexadecimal\"/\"`grep HEXADECIMAL src/GrammarLexer.l -B 1 | head -n 1 | sed 's/ {//g' | sed 's/\n//g' | sed 's/\r//g'`\"/g" $@
# 	@sed -i "s/\"integer\"/\"`grep INTEGER src/GrammarLexer.l -B 1 | head -n 1 | sed 's/ {//g' | sed 's/\n//g' | sed 's/\r//g'`\"/g" $@
# 	@sed -i "s/\"rational\"/\"`grep RATIONAL src/GrammarLexer.l -B 1 | head -n 1 | sed 's/ {//g' | sed 's/\n//g' | sed 's/\r//g'`\"/g" $@
# 	@sed -i "s/\"decimal\"/\"`grep DECIMAL src/GrammarLexer.l -B 1 | head -n 1 | sed 's/ {//g' | sed 's/\n//g' | sed 's/\r//g'`\"/g" $@
# 	@sed -i "s/\"identifier\"/\"`grep IDENTIFIER src/GrammarLexer.l -B 1 | head -n 1 | sed 's/ {//g' | sed 's/\n//g' | sed 's/\r//g'`\"/g" $@
# 	@sed -i "s/\"string\"/'\"'.*'\"'/g" $@
