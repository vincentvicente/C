/**
 *  CS 5008: Spr 2024
 *  Northeastern University, Seattle
 *  A7
 *
 *  Author: Qiyuan Zhu(03/25/2024)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#include <sys/wait.h>

#define MAXARGS 4
#define MAXLINE 8192

// Command names
char* commands[MAXARGS] = {"cd", "help", "game", "exit"};

// Function declarations for command handlers
void* cd(void* input);
void* help(void* input);
void* game(void* input);
void* exit_command(void* input); // Renamed for clarity

// Function pointers for command implementations
void* (*command_functions[])(void*) = {cd, help, game, exit_command};

// Change directory command
void* cd(void* input) {
    char* directory = (char*)input;
    if (chdir(directory) != 0) {
        fprintf(stderr, "Error changing directory: %s\n", strerror(errno));
    }
    return NULL;
}

// Display help information
void* help(void* input) {
    printf("Built-in commands:\n");
    printf("cd <directory>: Changes the current working directory.\n");
    printf("help: Displays this help message.\n");
    printf("game: Starts a number guessing game.\n");
    printf("exit: Exits the shell.\n");
    return NULL;
}

// Number guessing game
void* game(void* input) {
    printf("Welcome to the Number Guessing Game!\n");
    printf("Try to guess the number between 1 and 100.\n");

    srand(time(NULL));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < secretNumber) {
            printf("Too small! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too large! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", secretNumber, attempts);
            break;
        }
    } while (1);

    return NULL;
}

// Exit the shell
void* exit_command(void* input) {
    exit(0);
}

// Wrapper for fork to handle errors
pid_t Fork(void) {
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return pid;
}

// Safe fgets wrapper
char* Fgets(char *ptr, int n, FILE *stream) {
    if (!fgets(ptr, n, stream) && ferror(stream)) {
        fprintf(stderr, "fgets error\n");
        exit(1);
    }
    return ptr;
}

// Check for built-in commands and execute them
int builtin_command(char** argv) {
    for (int i = 0; i < MAXARGS; i++) {
        if (strcmp(commands[i], argv[0]) == 0) {
            // Execute the matching command function
            command_functions[i](argv[1]);  // Passes argument if any
            return 1;  // Indicates a built-in command was found and executed
        }
    }
    return 0;  // No built-in command matched
}

// Parse input line into arguments
void parse_input(char *input, char *argv[]) {
    const char delimiters[] = " \t\n";
    char *token = strtok(input, delimiters);
    int i = 0;
    while (token != NULL && i < MAXARGS - 1) {
        argv[i++] = token;
        token = strtok(NULL, delimiters);
    }
    argv[i] = NULL;  // Null-terminate the argument list
}

// Evaluate and execute command
void eval(char *cmdline) {
    char *argv[MAXARGS];
    char buf[MAXLINE];
    pid_t pid;

    strcpy(buf, cmdline);
    parse_input(buf, argv);

    if (argv[0] == NULL) return; // Ignore empty lines

    if (!builtin_command(argv)) {
        pid = Fork();
        if (pid == 0) {  // Child process
            if (execvp(argv[0], argv) < 0) {
                fprintf(stderr, "%s: Command not found.\n", argv[0]);
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0); // Wait for the child process to finish
        }
    }
}

int main() {
    char cmdline[MAXLINE]; // Command line input buffer

    // Infinite loop to keep the shell running
    while (1) {
        printf("> "); // Display a prompt
        Fgets(cmdline, MAXLINE, stdin); // Read a line from stdin

        if (feof(stdin)) { // Check for end of file (Ctrl+D)
            exit(0); // Exit the shell
        }

        // Evaluate and execute the command
        eval(cmdline);
    }

    return 0; // Return statement to make the compiler happy, never reached
}

