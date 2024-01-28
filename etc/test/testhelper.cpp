//
//  Copyright (C) 2017-2024 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber et al.
//  <https://github.com/casm-lang/libtptp/graphs/contributors>
//
//  This file is part of libtptp.
//
//  libtptp is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  libtptp is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with libtptp. If not, see <http://www.gnu.org/licenses/>.
//
//  Additional permission under GNU GPL version 3 section 7
//
//  libtptp is distributed under the terms of the GNU General Public License
//  with the following clarification and special exception: Linking libtptp
//  statically or dynamically with other modules is making a combined work
//  based on libtptp. Thus, the terms and conditions of the GNU General
//  Public License cover the whole combination. As a special exception,
//  the copyright holders of libtptp give you permission to link libtptp
//  with independent modules to produce an executable, regardless of the
//  license terms of these independent modules, and to copy and distribute
//  the resulting executable under terms of your choice, provided that you
//  also meet, for each linked independent module, the terms and conditions
//  of the license of that module. An independent module is a module which
//  is not derived from or based on libtptp. If you modify libtptp, you
//  may extend this exception to your version of the library, but you are
//  not obliged to do so. If you do not wish to do so, delete this exception
//  statement from your version.
//

#include "testhelper.h"

#include <cctype>

using namespace libtptp;

size_t nextChar( const std::string& str, size_t offset )
{
    bool inComment = false;
    for( int i = offset; i < str.size(); ++i )
    {
        char c = str[ i ];
        if( c == '%' )
        {
            inComment = true;
        }
        if( c == '\n' )
        {
            inComment = false;
        }
        if( inComment || std::isspace( c ) )
        {
            continue;
        }
        return i;
    }
    return str.size();
}

bool TestHelper::compareTPTPFiles( const std::string& expected, const std::string& actual )
{
    size_t expected_offset = nextChar( expected, 0 );
    size_t actual_offset = nextChar( actual, 0 );

    while( expected_offset < expected.size() && actual_offset < actual.size() )
    {
        expected_offset = nextChar( expected, expected_offset + 1 );
        actual_offset = nextChar( actual, actual_offset + 1 );
        if( expected_offset < expected.size() && actual_offset < actual.size() )
        {
            if( expected[ expected_offset ] != actual[ actual_offset ] )
            {
                return false;
            }
        }
        else
        {
            if( expected_offset < expected.size() || actual_offset < actual.size() )
            {
                return false;
            }
        }
    }
    return true;
}
