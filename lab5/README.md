# Lab 5: Style and cLint
## Author Qiyuan Zhu
## Date 2024-02-11

In this lab, we begin to utilize a tool to help us ensure good, 
programming style. 

## Files: 

* clint.py
* grades1.c 
* stuff.c
* Stuff.h
* Makefile

## Who did you work with?
Myself

## How long did this take you?
About 1.5 hours

## Write a sentence or two about what file you chose to clean up, and note something about what the most common or annoying issue you had to fix.
I chose to clean up LinkedList.c in a4. I found tab and extra spaces issues really annoying.

## Outputs before cleaning
```
LinkedList.c:37:  Else clause should never be on same line as else (use 2 lines)  [whitespace/newline] [4]
LinkedList.c:39:  Else clause should never be on same line as else (use 2 lines)  [whitespace/newline] [4]
LinkedList.c:106:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
LinkedList.c:115:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
LinkedList.c:116:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
LinkedList.c:149:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
LinkedList.c:158:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
LinkedList.c:190:  Else clause should never be on same line as else (use 2 lines)  [whitespace/newline] [4]
LinkedList.c:192:  Else clause should never be on same line as else (use 2 lines)  [whitespace/newline] [4]
LinkedList.c:194:  Else clause should never be on same line as else (use 2 lines)  [whitespace/newline] [4]
LinkedList.c:200:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
LinkedList.c:205:  At least two spaces is best between code and comments  [whitespace/comments] [2]
LinkedList.c:206:  At least two spaces is best between code and comments  [whitespace/comments] [2]
LinkedList.c:208:  At least two spaces is best between code and comments  [whitespace/comments] [2]
LinkedList.c:217:  Else clause should never be on same line as else (use 2 lines)  [whitespace/newline] [4]
LinkedList.c:0:  One or more unexpected \r (^M) found;better to use only a \n  [whitespace/newline] [1]
Done processing LinkedList.c
Total errors found: 16
```
## Outputs after cleaning
```
Done processing LinkedList_clean.c
Total errors found: 0
```
