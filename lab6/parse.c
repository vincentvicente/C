/**
 * Author: Qiyuan Zhu
 * Date: 03/16/2024
 * Version: 1.0
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse(char *buffer) {
    char* token;
    char* rest = buffer;

    // Tokenize the input string using space, newline, and quote as delimiters
    token = strtok_r(rest, " \n\"", &rest);

    // Process each token
    while (token != NULL) {
        printf("%s\n", token); // Print each token on a new line
        token = strtok_r(NULL, " \n\"", &rest); // Get the next token
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./parse \"command to parse\"\n");
        return 1;
    }

    // Since the entire command is passed as a single string in argv[1], we parse this argument
    parse(argv[1]);

    return 0;
}

