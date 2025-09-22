/// @defgroup cli cli
/// @ingroup lib
/// @{

#pragma once

#include "os.hpp"
#include "vm.hpp"

#include <string>
#include <map>
#include <vector>

/// @defgroup lexer lexer
/// @ingroup cli
/// @{
extern int yylex();   ///< lexer (`flex`)
extern int yylineno;  ///< current line
extern char *yyfile;  ///< current file name
extern FILE *yyin;    ///< current file handler
extern char *yytext;  ///< token lexeme value

/// @name number parsers
extern float num(char *val);  ///< @returns float
extern int dec(char *val);    ///< @returns decimal
extern int hex(char *val);    ///< @returns hexadecimal
extern int oct(char *val);    ///< @returns octal
extern int bin(char *val);    ///< @returns binary

/// @}

/// @defgroup parser parser
/// @ingroup cli
/// @{
extern int yyparse();                  ///< parser (`bison`)
extern void yyerror(const char *msg);  ///< syntax error callback

#include "cli.yacc.hpp"

/// @}

/// @defgroup compiler compiler
/// @brief @ref bytecode compiler
/// @{

extern std::map<std::string, addr> label;  ///< known labels

extern addr compile(byte b);
extern addr compile(Op op);
extern addr compile(addr a);
extern addr compile(cell n);
extern addr compile(fcell f);

/// @}

/// @brief process script file
/// @param[in] filename
extern void cli(char *filename);

/// @}
