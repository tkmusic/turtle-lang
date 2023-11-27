// lexer.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

#define MAX_IDENTIFIER_LENGTH 100

char currentChar;
char currentIdentifier[MAX_IDENTIFIER_LENGTH];
int currentNumber;

void getNextChar() {
    currentChar = getchar();
}

Token createToken(TokenType type, char* value) {
    Token token;
    token.type = type;
    token.value = value;
    return token;
}

Token getNextToken() {
    while (isspace(currentChar)) {
        getNextChar();
    }

    if (isalpha(currentChar)) {
        int i = 0;
        while (isalnum(currentChar) && i < MAX_IDENTIFIER_LENGTH - 1) {
            currentIdentifier[i++] = currentChar;
            getNextChar();
        }
        currentIdentifier[i] = '\0';

        if (strcmp(currentIdentifier, "print") == 0) {
            return createToken(TOKEN_PRINT, NULL);
        } else {
            return createToken(TOKEN_IDENTIFIER, currentIdentifier);
        }
    } else if (isdigit(currentChar)) {
        currentNumber = 0;
        while (isdigit(currentChar)) {
            currentNumber = currentNumber * 10 + (currentChar - '0');
            getNextChar();
        }
        return createToken(TOKEN_NUMBER, NULL);
    } else if (currentChar == '=') {
        getNextChar();
        return createToken(TOKEN_EQUAL, NULL);
    } else if (currentChar == '+') {
        getNextChar();
        return createToken(TOKEN_PLUS, NULL);
    } else if (currentChar == '-') {
        getNextChar();
        return createToken(TOKEN_MINUS, NULL);
    } else if (currentChar == '*') {
        getNextChar();
        return createToken(TOKEN_STAR, NULL);
    } else if (currentChar == '/') {
        getNextChar();
        return createToken(TOKEN_SLASH, NULL);
    } else if (currentChar == EOF) {
        return createToken(TOKEN_EOF, NULL);
    } else {
        // Handle unexpected characters or errors
        exit(EXIT_FAILURE);
    }
}
