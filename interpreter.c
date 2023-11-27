// interpreter.c
#include <stdio.h>
#include "interpreter.h"
#include <stdlib.h>

void executePrintStatement(AstNode* node);
void executeAssignmentStatement(AstNode* node);
int evaluateExpression(AstNode* node);

void interpret(AstNode* ast) {
    if (ast->type == TOKEN_PRINT) {
        executePrintStatement(ast);
    } else if (ast->type == TOKEN_EQUAL) {
        executeAssignmentStatement(ast);
    }
}

void executePrintStatement(AstNode* node) {
    printf("%s: %d\n", node->identifier, evaluateExpression(node));
}

void executeAssignmentStatement(AstNode* node) {
    // Implement assignment logic if needed
}

int evaluateExpression(AstNode* node) {
    if (node->type == TOKEN_NUMBER) {
        return node->number;
    } else if (node->type == TOKEN_PLUS) {
        return evaluateExpression(node->left) + evaluateExpression(node->right);
    } else if (node->type == TOKEN_MINUS) {
        return evaluateExpression(node->left) - evaluateExpression(node->right);
    } else if (node->type == TOKEN_STAR) {
        return evaluateExpression(node->left) * evaluateExpression(node->right);
    } else if (node->type == TOKEN_SLASH) {
        return evaluateExpression(node->left) / evaluateExpression(node->right);
    } else {
        // Handle unexpected node types
        exit(EXIT_FAILURE);
    }
}
