# Assignment 8: Finding Anagrams with Hashtables
### Course: CS5008
### Instructor: Drew Jelani 
### Name: Qiyuan Zhu
### Date: 04/12/2024

## Example outputs
```
[vincentvicenteqy@login-students a8]$ make
gcc -c -Wall -g Hashtable.c -o Hashtable.o
gcc -g Hashtable.c LinkedList.c Main.c -o main
[vincentvicenteqy@login-students a8]$ ./main
============== Anagrams Hash Table Results ==============
| Anagram Group        | Words                                              |
|----------------------|----------------------------------------------------|
| act                  | act, cat,                                          |
| aelno                | alone, anole,                                      |
| abdel                | blade, baled,                                      |
| abekr                | brake, baker,                                      |
| acep                 | cape, pace,                                        |
| acr                  | car, arc,                                          |
| aclor                | carol, coral,                                      |
| ceinr                | ciner, nicer,                                      |
| aceimn               | cinema, iceman,                                    |
| dstu                 | dust, stud,                                        |
| dstuy                | dusty, study,                                      |
| aet                  | eat, tea,                                          |
| aehrt                | earth, heart,                                      |
| eilv                 | evil, veil, vile, live,                            |
| aefkl                | flake, fakle,                                      |
| dgo                  | god, dog,                                          |
| ahst                 | hats, stah,                                        |
| aeels                | lease, easel,                                      |
| abelst               | stable, tables,                                    |
| epst                 | step, pets,                                        |
| apt                  | tap, pat,                                          |
| aeprt                | taper, prate,                                      |
| deirt                | tired, tried,                                      |
| eert                 | tree, teer,                                        |
| deeelst              | steeled, deletes,                                  |
| aabglor              | aalborg,                                           |
| aabert               | abater,                                            |
| agllop               | gallop,                                            |
| abgr                 | garb,                                              |
==========================================================
```

## Valgrind report
```
==1209888== 
==1209888== HEAP SUMMARY:
==1209888==     in use at exit: 0 bytes in 0 blocks
==1209888==   total heap usage: 525 allocs, 525 frees, 119,078 bytes allocated
==1209888== 
==1209888== All heap blocks were freed -- no leaks are possible
==1209888== 
==1209888== For lists of detected and suppressed errors, rerun with: -s
==1209888== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
## Who did I work with?
### I work myself
## What external resources did you use?
### Canvas modules, Tutorial, Youtube tutorial
## How long did it take you to finish?
### About one day and half


Provided files: 

* ```words.txt```: The word file you need to read in to find anagrams with. 
* ```Hashtable_easy.h```: A starting point to structuring your hashtable that 
stores strings (```char*```s). **IF** you want to use it. 
* ```Hashtable.h```: **IF** you want, you can use this to start structuring 
and building your hashtable. 
* ```Hashtable.c```: Stub file for your hashtable code, contains FNV Hash function. 
* ```LinkedList.c```: Placeholder file. Please replace with your version of LinkedList.c
* ```LinkedList_easy.h```: Contains API for a LinkedList that holds strings. It's an easier 
implementation than the other LinkedList. Feel free to replace with your own version if the signatures do not align.
* ```LinkedList.h```: Contains API for a generic LinkedList implementation that you can 
use for your Hashtable implementation, if you'd like.
* ```Makefile```: Generic starting Makefile
* ```test_hashtable.cc```: A starting test file for you to use to test your hashtable implementation. 


# Resources: 

* https://medium.com/basecs/hashing-out-hash-functions-ea5dd8beb4dd (Hash Functions)
* https://medium.com/basecs/taking-hash-tables-off-the-shelf-139cbf4752f0?source=---------17----------------------- (Hash Tables, generally)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#hashTables (Hashtables in C)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#File_IO  (Reading a file in C)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#functionPointers (Function Pointers, for more challenge)
