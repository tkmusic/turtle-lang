// main.c
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"
#include "stdio.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <code_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Redirect stdin to read from the file
    freopen(argv[1], "r", stdin);

    AstNode* ast = parse();
    interpret(ast);

    fclose(file);

    return 0;
}
