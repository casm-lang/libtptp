//
//  Copyright (C) 2017-2019 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                Jakob Moosbrugger
//                <https://github.com/casm-lang/libtptp>
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

#include "Role.h"

namespace libtptp
{
    static Role::Ptr axiomVariable;
    static Role::Ptr hypothesisVariable;
    static Role::Ptr definitionVariable;
    static Role::Ptr assumptionVariable;
    static Role::Ptr lemmaVariable;
    static Role::Ptr theoremVariable;
    static Role::Ptr corollaryVariable;
    static Role::Ptr conjectureVariable;
    static Role::Ptr negated_conjectureVariable;
    static Role::Ptr plainVariable;
    static Role::Ptr typeVariable;
    static Role::Ptr fi_domainVariable;
    static Role::Ptr fi_functorsVariable;
    static Role::Ptr fi_predicatesVariable;
    static Role::Ptr unknownVariable;

    Role::Role( const Identifier::Ptr& word )
    : Role( word, parseKind( word ) )
    {
    }

    Role::Role( const Identifier::Ptr& word, Kind kind )
    : Node( Node::ID::FORMULA_ROLE )
    , m_word( word )
    , m_kind( kind )
    {
    }

    const Identifier::Ptr& Role::word( void ) const
    {
        return m_word;
    }

    Role::Kind Role::kind( void ) const
    {
        return m_kind;
    }

    const Role::Ptr& Role::axiom( void )
    {
        if( !axiomVariable )
        {
            axiomVariable =
                std::make_shared< Role >( std::make_shared< Identifier >( "axiom" ), Kind::AXIOM );
        }
        return axiomVariable;
    }

    const Role::Ptr& Role::hypothesis( void )
    {
        if( !hypothesisVariable )
        {
            hypothesisVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "hypothesis" ), Kind::HYPOTHESIS );
        }
        return hypothesisVariable;
    }

    const Role::Ptr& Role::definition( void )
    {
        if( !definitionVariable )
        {
            definitionVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "definition" ), Kind::DEFINITION );
        }
        return definitionVariable;
    }

    const Role::Ptr& Role::assumption( void )
    {
        if( !assumptionVariable )
        {
            assumptionVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "assumption" ), Kind::ASSUMPTION );
        }
        return assumptionVariable;
    }

    const Role::Ptr& Role::lemma( void )
    {
        if( !lemmaVariable )
        {
            lemmaVariable =
                std::make_shared< Role >( std::make_shared< Identifier >( "lemma" ), Kind::LEMMA );
        }
        return lemmaVariable;
    }

    const Role::Ptr& Role::theorem( void )
    {
        if( !theoremVariable )
        {
            theoremVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "theorem" ), Kind::THEOREM );
        }
        return theoremVariable;
    }

    const Role::Ptr& Role::corollary( void )
    {
        if( !corollaryVariable )
        {
            corollaryVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "corollary" ), Kind::COROLLARY );
        }
        return corollaryVariable;
    }

    const Role::Ptr& Role::conjecture( void )
    {
        if( !conjectureVariable )
        {
            conjectureVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "conjecture" ), Kind::CONJECTURE );
        }
        return conjectureVariable;
    }

    const Role::Ptr& Role::negated_conjecture( void )
    {
        if( !negated_conjectureVariable )
        {
            negated_conjectureVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "negated_conjecture" ), Kind::NEGATED_CONJECTURE );
        }
        return negated_conjectureVariable;
    }

    const Role::Ptr& Role::plain( void )
    {
        if( !plainVariable )
        {
            plainVariable =
                std::make_shared< Role >( std::make_shared< Identifier >( "plain" ), Kind::PLAIN );
        }
        return plainVariable;
    }

    const Role::Ptr& Role::type( void )
    {
        if( !typeVariable )
        {
            typeVariable =
                std::make_shared< Role >( std::make_shared< Identifier >( "type" ), Kind::TYPE );
        }
        return typeVariable;
    }

    const Role::Ptr& Role::fi_domain( void )
    {
        if( !fi_domainVariable )
        {
            fi_domainVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "fi_domain" ), Kind::FI_DOMAIN );
        }
        return fi_domainVariable;
    }
    const Role::Ptr& Role::fi_functors( void )
    {
        if( !fi_functorsVariable )
        {
            fi_functorsVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "fi_functors" ), Kind::FI_FUNCTORS );
        }
        return fi_functorsVariable;
    }
    const Role::Ptr& Role::fi_predicates( void )
    {
        if( !fi_predicatesVariable )
        {
            fi_predicatesVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "fi_predicates" ), Kind::FI_PREDICATES );
        }
        return fi_predicatesVariable;
    }
    const Role::Ptr& Role::unknown( void )
    {
        if( !unknownVariable )
        {
            unknownVariable = std::make_shared< Role >(
                std::make_shared< Identifier >( "unknown" ), Kind::UNKNOWN );
        }
        return unknownVariable;
    }

    void Role::accept( Visitor& visitor )
    {
        visitor.visit( *this );
    }

    Role::Kind Role::parseKind( const Identifier::Ptr& word )
    {
        auto string = word->name();
        if( string == "axiom" )
        {
            return Kind::AXIOM;
        }
        if( string == "hypothesis" )
        {
            return Kind::HYPOTHESIS;
        }
        if( string == "definition" )
        {
            return Kind::DEFINITION;
        }
        if( string == "assumption" )
        {
            return Kind::ASSUMPTION;
        }
        if( string == "lemma" )
        {
            return Kind::LEMMA;
        }
        if( string == "theorem" )
        {
            return Kind::THEOREM;
        }
        if( string == "corollary" )
        {
            return Kind::COROLLARY;
        }
        if( string == "conjecture" )
        {
            return Kind::CONJECTURE;
        }
        if( string == "negated_conjecture" )
        {
            return Kind::NEGATED_CONJECTURE;
        }
        if( string == "plain" )
        {
            return Kind::PLAIN;
        }
        if( string == "type" )
        {
            return Kind::TYPE;
        }
        if( string == "fi_domain" )
        {
            return Kind::FI_DOMAIN;
        }
        if( string == "fi_functors" )
        {
            return Kind::FI_FUNCTORS;
        }
        if( string == "fi_predicates" )
        {
            return Kind::FI_PREDICATES;
        }
        return Kind::UNKNOWN;
    }

}

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
