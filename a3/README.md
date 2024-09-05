# Assignment 3: implementation of linked list and deque
### Course: CS5008
### Instructor: Drew Jelani 
### Name: Qiyuan Zhu
### Date: 02/02/2024

## Output
deque
```
Initial Deque (empty):
Deque: Error: current is NULL

After pushing 1 left and 2 right:
Deque: 1 2 
After pushing 3 left and 4 right:
Deque: 3 1 2 4 
Peek Left: 3
Peek Right: 4
Pop Left: 3
After popping from left:
Deque: 1 2 4 
Pop Right: 4
After popping from right:
Deque: 1 2 
Deque has value 2.
```
doublylinkedlist
```
Initial List: 0 -> 1 -> 2 -> 3 -> NULL
After inserting 99 at index 2: 0 -> 1 -> 99 -> 2 -> 3 -> NULL
After removing node at index 3: 0 -> 1 -> 99 -> 3 -> NULL
List contains the value 99
```

## What did you learn from the assignment and what you found challenging?
Not only did I learn about the implementation of deque and doubly linked list, but also the encapsulation of managing data type.

I also found Valgrind very useful for identifying memory management errors and threading bugs in my program.

I found the implementation of doubly linked list quite challenging, as for the clarification of nodes. 

I also found member naming consistency quite tricky as I debugged compilation errors for sometime.


