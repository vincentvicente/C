# Assignment 4: Robust Data Structures
### Course: CS5008
### Instructor: Drew Jelani 
### Name: Qiyuan Zhu
### Date: 02/11/2024


## Who did I work with?
### Only myself


## What external resources did you use?
### Canvas modules, in class notes


## How long did it take you to finish?
### About 2 hours



## Test results
```
[==========] Running 2 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from Test
[ RUN      ] Test.Test
[       OK ] Test.Test (0 ms)
[----------] 1 test from Test (0 ms total)

[----------] 1 test from LinkedList
[ RUN      ] LinkedList.Create
[       OK ] LinkedList.Create (0 ms)
[----------] 1 test from LinkedList (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 2 tests.
```



## Memory leaks test using Valgrind
```
==1427843== Memcheck, a memory error detector
==1427843== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==1427843== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==1427843== Command: ./main
==1427843== 
hi
==1427843== 
==1427843== HEAP SUMMARY:
==1427843==     in use at exit: 0 bytes in 0 blocks
==1427843==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==1427843== 
==1427843== All heap blocks were freed -- no leaks are possible
==1427843== 
==1427843== For lists of detected and suppressed errors, rerun with: -s
==1427843== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

