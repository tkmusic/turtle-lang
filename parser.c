// parser.c
#include <stdlib.h>
#include "parser.h"

AstNode* parsePrintStatement();
AstNode* parseAssignmentStatement();
AstNode* parseExpression();
AstNode* parseTerm();

Token currentToken;

void match(TokenType expectedType) {
    if (currentToken.type == expectedType) {
        currentToken = getNextToken();
    } else {
        // Handle syntax errors
        exit(EXIT_FAILURE);
    }
}

AstNode* createAstNode(TokenType type) {
    AstNode* node = (AstNode*)malloc(sizeof(AstNode));
    node->type = type;
    node->identifier = NULL;
    node->number = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

AstNode* parse() {
    currentToken = getNextToken();
    return parsePrintStatement();
}

AstNode* parsePrintStatement() {
    match(TOKEN_PRINT);
    AstNode* node = createAstNode(TOKEN_PRINT);
    node->left = parseExpression();
    return node;
}

AstNode* parseAssignmentStatement() {
    AstNode* node = createAstNode(TOKEN_EQUAL);
    node->identifier = currentToken.value;
    match(TOKEN_IDENTIFIER);
    match(TOKEN_EQUAL);
    node->right = parseExpression();
    return node;
}

AstNode* parseExpression() {
    AstNode* left = parseTerm();
    while (currentToken.type == TOKEN_PLUS || currentToken.type == TOKEN_MINUS) {
        TokenType operatorType = currentToken.type;
        match(operatorType);
        AstNode* right = parseTerm();
        AstNode* node = createAstNode(operatorType);
        node->left = left;
        node->right = right;
        left = node;
    }
    return left;
}

AstNode* parseTerm() {
    AstNode* left = createAstNode(TOKEN_NUMBER);
    left->number = currentToken.type == TOKEN_NUMBER ? currentToken.value : 0;
    match(TOKEN_NUMBER);
    while (currentToken.type == TOKEN_STAR || currentToken.type == TOKEN_SLASH) {
        TokenType operatorType = currentToken.type;
        match(operatorType);
        AstNode* right = createAstNode(TOKEN_NUMBER);
        right->number = currentToken.type == TOKEN_NUMBER ? currentToken.value : 0;
        match(TOKEN_NUMBER);
        AstNode* node = createAstNode(operatorType);
        node->left = left;
        node->right = right;
        left = node;
    }
    return left;
}
