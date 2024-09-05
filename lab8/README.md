# Lab 8
### Course: CS5008
### Instructor: Drew Jelani 
### Name: Qiyuan Zhu
### Date: 04/02/2024

## Reports
### variation1
```
==603552== Memcheck, a memory error detector
==603552== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==603552== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==603552== Command: ./variation1
==603552== 

Size     | Time (s)     | Time (micros)        | Partition Calls      | Quicksort Calls      | Comparisons         
------------------------------------------------------------------------------------------
16       | 0            | 3504                 | 16                   | 33                   | 56                  
64       | 0            | 90                   | 63                   | 127                  | 466                 
128      | 0            | 239                  | 127                  | 255                  | 1056                
512      | 0            | 995                  | 511                  | 1023                 | 5996                
1024     | 0            | 1958                 | 1023                 | 2047                 | 15471               
2048     | 0            | 48099                | 2047                 | 4095                 | 42789               
==603552== 
==603552== HEAP SUMMARY:
==603552==     in use at exit: 0 bytes in 0 blocks
==603552==   total heap usage: 7 allocs, 7 frees, 16,192 bytes allocated
==603552== 
==603552== All heap blocks were freed -- no leaks are possible
==603552== 
==603552== For lists of detected and suppressed errors, rerun with: -s
==603552== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### variation2
```
==605520== Memcheck, a memory error detector
==605520== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==605520== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==605520== Command: ./variation2
==605520== 
Size     | Time (s)     | Time (micros)        | Partition Calls      | Quicksort Calls      | Comparisons         
------------------------------------------------------------------------------------------
16       | 0            | 4057                 | 15                   | 31                   | 57                  
64       | 0            | 553                  | 63                   | 127                  | 421                 
128      | 0            | 299                  | 127                  | 255                  | 952                 
512      | 0            | 1068                 | 511                  | 1023                 | 5892                
1024     | 0            | 2084                 | 1023                 | 2047                 | 14688               
2048     | 0            | 8792                 | 2047                 | 4095                 | 39520               
==605520== 
==605520== HEAP SUMMARY:
==605520==     in use at exit: 0 bytes in 0 blocks
==605520==   total heap usage: 7 allocs, 7 frees, 16,192 bytes allocated
==605520== 
==605520== All heap blocks were freed -- no leaks are possible
==605520== 
==605520== For lists of detected and suppressed errors, rerun with: -s
==605520== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### variation3
```
==605820== Memcheck, a memory error detector
==605820== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==605820== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==605820== Command: ./variation3
==605820== 
Size     | Time (s)     | Time (micros)     | Partition Calls | Quicksort Calls | Comparisons
---------------------------------------------------------------------------------------------
16       | 0            | 1692                 | 0               | 1               | 66        
64       | 0            | 61                   | 0               | 1               | 921       
128      | 0            | 243                  | 0               | 1               | 4055      
512      | 0            | 2860                 | 7               | 15              | 11072     
1024     | 0            | 2034                 | 14              | 29              | 25311     
2048     | 0            | 8198                 | 33              | 67              | 46661     
==605820== 
==605820== HEAP SUMMARY:
==605820==     in use at exit: 0 bytes in 0 blocks
==605820==   total heap usage: 7 allocs, 7 frees, 16,192 bytes allocated
==605820== 
==605820== All heap blocks were freed -- no leaks are possible
==605820== 
==605820== For lists of detected and suppressed errors, rerun with: -s
==605820== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Who did I work with?
### Only myself
## What external resources did you use?
### Canvas modules, Youtube tutorial
## How long did it take you to finish?
### About 4 hours



