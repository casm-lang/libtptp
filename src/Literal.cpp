#include "Literal.h"

using namespace libtptp;

Literal::Literal( const Node::ID id )
: Node( id )
{
}

IntegerLiteral::IntegerLiteral( const std::string& integer )
: Literal( Node::ID::INTEGER_LITERAL )
{
    m_value = std::stol( integer );
}

void IntegerLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const long& IntegerLiteral::value( void ) const
{
    return m_value;
}

StringLiteral::StringLiteral( const std::string& string )
: Literal( Node::ID::STRING_LITERAL )
, m_value( string )
{
    switch( string[ 0 ] )
    {
        case '"':
        {
            m_type = StringType::DOUBLE_QUOTED;
            break;
        }
        case '\'':
        {
            m_type = StringType::SINGLE_QUOTED;
            break;
        }
        default:
        {
            m_type = StringType::NOT_QUOTED;
            break;
        }
    }
}

void StringLiteral::accept( Visitor& visitor )
{
    visitor.visit( *this );
}

const std::string& StringLiteral::value( void ) const
{
    return m_value;
}
