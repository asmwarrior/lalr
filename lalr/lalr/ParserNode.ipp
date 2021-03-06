#ifndef LALR_PARSERNODE_IPP_INCLUDED
#define LALR_PARSERNODE_IPP_INCLUDED

#include "ParserNode.hpp"
#include "assert.hpp"

namespace lalr
{

/**
// Constructor.
//
// @param state
//  The %ParserState at this node.
//
// @param started_productions
//  The productions that were started at this node.
//
// @param symbol
//  The Symbol at this node.
//
// @param user_data
//  The user data that stores application specific data at this node.
*/
template <class UserData, class Char, class Traits, class Allocator>
ParserNode<UserData, Char, Traits, Allocator>::ParserNode( const ParserState* state, const ParserSymbol* symbol, const UserData& user_data )
: state_( state ),
  symbol_( symbol ),
  line_( -1 ),
  lexeme_(),
  user_data_( user_data )
{
    LALR_ASSERT( state );
}

/**
// Constructor.
//
// @param state
//  The state at this node.
//
// @param started_productions
//  The productions that were started at this node.
//
// @param symbol
//  The symbol at this node.
//
// @param lexeme
//  The lexeme at this node.
*/
template <class UserData, class Char, class Traits, class Allocator>
ParserNode<UserData, Char, Traits, Allocator>::ParserNode( const ParserState* state, const ParserSymbol* symbol, const std::basic_string<Char, Traits, Allocator>& lexeme )
: state_( state ),
  symbol_( symbol ),
  line_( -1 ),
  lexeme_( lexeme ),
  user_data_()
{
    LALR_ASSERT( state );
}

/**
// Get the state at this node.
//
// @return
//  The state.
*/
template <class UserData, class Char, class Traits, class Allocator>
const ParserState* ParserNode<UserData, Char, Traits, Allocator>::state() const
{
    return state_;
}

/**
// Get the symbol at this state.
//
// @return
//  The symbol.
*/
template <class UserData, class Char, class Traits, class Allocator>
const ParserSymbol* ParserNode<UserData, Char, Traits, Allocator>::symbol() const
{
    return symbol_;
}

/**
// Get the line that this node was generated from (if any).
//
// @return
//  The line number that this node was generated from or -1 if this node 
//  doesn't relate to a line of source.
*/
template <class UserData, class Char, class Traits, class Allocator>
int ParserNode<UserData, Char, Traits, Allocator>::line() const
{
    return line_;
}

/**
// Get the lexeme at this state.
//
// @return
//  The lexeme.
*/
template <class UserData, class Char, class Traits, class Allocator>
const std::basic_string<Char, Traits, Allocator>& ParserNode<UserData, Char, Traits, Allocator>::lexeme() const
{
    return lexeme_;
}

/**
// Get the user data at this state.
//
// @return
//  The user data.
*/
template <class UserData, class Char, class Traits, class Allocator>
const UserData& ParserNode<UserData, Char, Traits, Allocator>::user_data() const
{
    return user_data_;
}

}

#endif
