# Assignment 7: K-SEA Shell (ksesh)
### Course: CS5008
### Instructor: Drew Jelani 
### Name: Qiyuan Zhu
### Date: 03/25/2024

### Summary
This assignment involves the development of a simple command-line shell implemented in C. The shell supports several built-in commands including cd, help, game, and exit. 
Each command is associated with specific functionality designed to demonstrate fundamental concepts of operating systems, such as process creation, execution, and inter-process communication.

### Build and Test
To compile the program, use the following command in your terminal:
```
gcc shell.c -o shell
```

After compilation, start the shell by running:
```
./shell
```

### Functions
cd (Change Directory):
Synopsis: cd <directory>
Changes the current working directory to the specified <directory>. Utilizes the chdir() system call. 
If successful, the shell changes to the specified directory without any message; if an error occurs, it prints the error reason.

help
Synopsis: help
Displays a list of available built-in commands and their brief descriptions, assisting users in understanding the functionalities provided by the shell.

game
Synopsis: game
Launchies a simple guessing game where the user attempts to guess a randomly generated number between 1 and 100. 
Feedback is provided for each guess, indicating whether the guess is too high, too low, or correct. 
Upon correctly guessing the number, the game displays a congratulatory message along with the number of attempts.

exit
Synopsis: exit
Exits the shell with a status code of 0, indicating successful termination.

### Test sample & Valgrind report
```
[vincentvicenteqy@login-students a7]$ valgrind shell
==1209888== Memcheck, a memory error detector
==1209888== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==1209888== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==1209888== Command: shell
==1209888== 
> help
Built-in commands:
cd <directory>: Changes the current working directory.
help: Displays this help message.
game: Starts a number guessing game.
exit: Exits the shell.
> cd ..
> cd a7
> ls
README.md  run_ls.c  shell  shell.c
> game
Welcome to the Number Guessing Game!
Try to guess the number between 1 and 100.
Enter your guess: 50
Too large! Try again.
Enter your guess: 25
Too large! Try again.
Enter your guess: 13
Too large! Try again.
Enter your guess: 7
Too large! Try again.
Enter your guess: 3
Congratulations! You guessed the number 3 in 5 attempts.
> > exit
==1209888== 
==1209888== HEAP SUMMARY:
==1209888==     in use at exit: 0 bytes in 0 blocks
==1209888==   total heap usage: 2 allocs, 2 frees, 2,048 bytes allocated
==1209888== 
==1209888== All heap blocks were freed -- no leaks are possible
==1209888== 
==1209888== For lists of detected and suppressed errors, rerun with: -s
==1209888== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Who did I work with?
### Only myself
## What external resources did you use?
### Canvas modules, Tutorial
## How long did it take you to finish?
### About two days



