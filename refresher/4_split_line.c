#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 64

size_t split_line(char *line, char *tokens[], size_t tokens_size);

int main(int ac, char **av) {
    if (ac != 2) {
        fprintf(stderr, "Error: Usage: %s <input_string>\n", av[0]);
        return 1;
    }

    char *input_string = av[1];
    char *tokens[MAX_TOKENS];

    size_t token_count = split_line(input_string, tokens, MAX_TOKENS);

    printf("Number of tokens: %zu\n", token_count);
    printf("Tokens:\n");

    for (size_t i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}

size_t split_line(char *line, char *tokens[], size_t tokens_size) {
    size_t token_count = 0;
    char *token = strtok(line, " \t\n");

    while (token != NULL && token_count < tokens_size - 1) {
        tokens[token_count++] = token;
        token = strtok(NULL, " \t\n");
    }

    tokens[token_count] = NULL;

    return token_count;
}