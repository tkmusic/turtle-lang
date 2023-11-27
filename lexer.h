// lexer.h
#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_EQUAL,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_PRINT,
} TokenType;

typedef struct {
    TokenType type;
    char* value;
} Token;

Token getNextToken();

#endif
