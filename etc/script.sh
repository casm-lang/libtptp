#!/bin/bash
#
#   Copyright (C) 2017-2019 CASM Organization <https://casm-lang.org>
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

APP=`basename $0`

function usage
{
    echo "usage: $APP <generate-token-header|generate-token-body|generate-lexer|generate-parser>"
    exit -1
}

function print_token_definition
{
    tokens=$1

    local mode=name
    declare -i uid=1

	echo "            /*  0 */ UNRESOLVED,"
    for element in $tokens; do
        #printf "%2i -> %s\n" $uid $element
	if [ "$mode" = "name" ]; then
	    printf "            /* %2i */ $element,\n" $uid
	    mode=token
	else
	    # mode token
	    mode=name
        uid+=1
	fi
    done
}

function print_builder_definition
{
    tokens=$1
    local mode=name
    #echo "        static const Token::Ptr& unresolved( void );"
    echo "        static const Token::Ptr& UNRESOLVED( void );"
    for element in $tokens; do
        #printf "%2i -> %s\n" $uid $element
	if [ "$mode" = "name" ]; then
        #echo "        static const Token::Ptr& ${element,,}( void );"
        echo "        static const Token::Ptr& ${element}( void );"
	    mode=token
	else
	    # mode token
	    mode=name
	fi
    done
}

function generate_token_h
{
    local src=$1
    local dst=$2
    local grammartoken=$3

    local tokens=`cat $grammartoken | grep '.*\"'`

    local token_definitions=$(print_token_definition "$tokens")

    token_definitions="${token_definitions//\\/\\\\}"
    token_definitions="${token_definitions//\//\\/}"
    token_definitions="${token_definitions//&/\\&}"
    token_definitions="${token_definitions//$'\n'/\\n}"

    local builder_definitions=$(print_builder_definition "$tokens")

    builder_definitions="${builder_definitions//\\/\\\\}"
    builder_definitions="${builder_definitions//\//\\/}"
    builder_definitions="${builder_definitions//&/\\&}"
    builder_definitions="${builder_definitions//$'\n'/\\n}"

    sed -e "s%^[ \t]*/\*<<token_definitions>>\*/%$token_definitions%" -e "s%^[ \t]*/\*<<token_builder_definitions>>\*/%$builder_definitions%" $src > $dst
    exit 0
}

function print_token_as_string
{
    tokens=$1
    echo "                case /*  0 */ Token::UNRESOLVED:"
	echo "                {"
	echo "                    return \"\$unresolved\$\";"
	echo "                }"

    mode=name
    declare -i uid=1
    for element in $tokens; do
	if [ "$mode" = "name" ]; then
	    printf "                case /* %2i */ Token::$element:\n" $uid
	    mode=token
	else
	    # mode token
	    echo "                {"
	    printf "                    return %s;\n" $element
	    echo "                }"
	    mode=name
        uid+=1
	fi
    done
}

function print_builder_implementation
{
    tokens=$1
    echo "const Token::Ptr& TokenBuilder::UNRESOLVED( void )"
    echo "{"
    echo "    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::UNRESOLVED );"
    echo "    return instance;"
    echo "}"
    echo ""

    mode=name
    for element in $tokens; do
	if [ "$mode" = "name" ]; then
	    mode=token
        #local lowerVar=${element,,}
        local lowerVar=${element}

        echo "const Token::Ptr& TokenBuilder::$lowerVar( void )"
        echo "{"
        echo "    static const Token::Ptr instance = std::make_shared< Token >( Grammar::Token::$element );"
        echo "    return instance;"
        echo "}"
        echo ""
    else
	    # mode token
        mode=name
	fi
    done
}

function generate_token_cpp
{
    local src=$1
    local dst=$2
    local grammartoken=$3

    local tokens=`cat $grammartoken | grep '.*\"'`
    to_string=$(print_token_as_string "$tokens")
    to_string="${to_string//\\/\\\\}"
    to_string="${to_string//\//\\/}"
    to_string="${to_string//&/\\&}"
    to_string="${to_string//$'\n'/\\n}"

    local implementations=$(print_builder_implementation "$tokens")
    implementations="${implementations//\\/\\\\}"
    implementations="${implementations//\//\\/}"
    implementations="${implementations//&/\\&}"
    implementations="${implementations//$'\n'/\\n}"

    sed -e "s%^[ \t]*/\*<<builder_implementation>>\*/%$implementations%" -e "s%^[ \t]*/\*<<token_as_string>>\*/%$to_string%" $src > $dst

    exit 0
}

function generate_lexer
{
    local src=$1
    local dst=$2
    local grammartoken=$3

    mkdir -p `dirname $src`
	head -n +`grep -n "{{grammartoken}}" $src | grep -o "[0-9]*"` $src | cat  > $dst

    local tokens=`cat $grammartoken | grep '.*\"'`
    local mode=name
    local name=""
    declare -i uid=1
    for element in $tokens; do
        #printf "%2i -> %s\n" $uid $element
	    if [ "$mode" = "name" ]; then
	        mode=token
            name=$element
	    else
	        # mode token
	        mode=name
            uid+=1
	        printf "%-20s { YY_TOKEN_ACTION( %s ) }\n" $element $name >> $dst
	    fi
    done

    tail -n +`grep -n "{{grammartoken}}" $src | grep -o "[0-9]*"` $src | cat >> $dst
	sed -i "/^{{grammartoken}}/d" $dst

    exit 0
}

function generate_parser
{
    local src=$1
    local dst=$2
    local grammartoken=$3

    mkdir -p `dirname $src`
	head -n +`grep -n "{{grammartoken}}" $src | grep -o "[0-9]*"` $src | cat  > $dst

    local tokens=`cat $grammartoken | grep '.*\"'`
    local mode=name
    declare -i uid=1
    for element in $tokens; do
        #printf "%2i -> %s\n" $uid $element
	    if [ "$mode" = "name" ]; then
	        printf "%-20s " $element >> $dst
	        mode=token
	    else
	        # mode token
	        mode=name
            uid+=1
	        printf "%s\n" $element >> $dst
	    fi
    done

    mode=name
    uid=1
    for element in $tokens; do
        #printf "%2i -> %s\n" $uid $element
	    if [ "$mode" = "name" ]; then
	        echo "%type <Token::Ptr> $element" >> $dst
	        mode=token
	    else
	        # mode token
	        mode=name
            uid+=1
	    fi
    done

	tail -n +`grep -n "{{grammartoken}}" $src | grep -o "[0-9]*"` $src | cat >> $dst
	sed -i "/^{{grammartoken}}/d" $dst

    exit 0
}

if [ -z "$1" ]; then
    usage
    exit -1
fi

if [ "$1" = "generate-token-header" ]; then
    generate_token_h $2 $3 $4
elif [ "$1" = "generate-token-body" ]; then
    generate_token_cpp $2 $3 $4
elif [ "$1" = "generate-lexer" ]; then
    generate_lexer $2 $3 $4
elif [ "$1" = "generate-parser" ]; then
    generate_parser $2 $3 $4
else
    usage
fi
