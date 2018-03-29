#ifndef SWEET_LALR_GRAMMARCOMPILER_HPP_INCLUDED
#define SWEET_LALR_GRAMMARCOMPILER_HPP_INCLUDED

#include <deque>
#include <string>
#include <memory>

namespace sweet
{

namespace lalr
{

class ErrorPolicy;
class Grammar;
class GrammarGenerator;
class ParserAction;
class ParserSymbol;
class ParserTransition;
class ParserState;
class ParserStateMachine;
class LexerAllocations;

class GrammarCompiler
{    
    std::deque<std::string> strings_;
    std::unique_ptr<ParserAction[]> actions_; ///< The parser actions for this ParserStateMachine.
    std::unique_ptr<ParserSymbol[]> symbols_; ///< The symbols in the grammar for this ParserStateMachine.
    std::unique_ptr<ParserTransition[]> transitions_; ///< The transitions in the state machine for this ParserStateMachine.
    std::unique_ptr<ParserState[]> states_; ///< The states in the state machine for this ParserStateMachine.
    std::unique_ptr<LexerAllocations> lexer_allocations_; ///< Allocated lexer state machine.
    std::unique_ptr<LexerAllocations> whitespace_lexer_allocations_; ///< Allocated whitespace lexer state machine.
    std::unique_ptr<ParserStateMachine> parser_state_machine_; ///< Allocated parser state machine.

public:
    GrammarCompiler();
    ~GrammarCompiler();
    const LexerAllocations* lexer_allocations() const;
    const LexerAllocations* whitespace_lexer_allocations() const;
    const ParserStateMachine* parser_state_machine() const;
    void compile( const char* begin, const char* end, ErrorPolicy* error_policy = nullptr );

private:
    const char* add_string( const std::string& string );
    void set_actions( std::unique_ptr<ParserAction[]>& actions, int actions_size );
    void set_symbols( std::unique_ptr<ParserSymbol[]>& symbols, int symbols_size );
    void set_transitions( std::unique_ptr<ParserTransition[]>& transitions, int transitions_size );
    void set_states( std::unique_ptr<ParserState[]>& states, int states_size, const ParserState* start_state );
    void set_lexer_allocations( std::unique_ptr<LexerAllocations>& lexer_allocations );
    void set_whitespace_lexer_allocations( std::unique_ptr<LexerAllocations>& whitespace_lexer_allocations );
    void populate_parser_state_machine( const Grammar& grammar, const GrammarGenerator& generator );
    void populate_lexer_state_machine( const GrammarGenerator& generator, ErrorPolicy* error_policy );
    void populate_whitespace_lexer_state_machine( const Grammar& grammar, ErrorPolicy* error_policy );
};

}

}

#endif