// parser.h
#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct AstNode {
    TokenType type;
    char* identifier;
    int number;
    struct AstNode* left;
    struct AstNode* right;
} AstNode;

AstNode* parse();

#endif
