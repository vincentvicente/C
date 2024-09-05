# Assignment 5: Robust Data Structures
### Course: CS5008
### Instructor: Drew Jelani 
### Name: Qiyuan Zhu
### Date: 02/20/2024


## Who did I work with?
### Only myself


## What external resources did you use?
### Canvas modules, in class notes


## How long did it take you to finish?
### About 2.5 hours


##Test results
```
[==========] Running 15 tests from 8 test cases.
[----------] Global test environment set-up.
[----------] 1 test from contains
[ RUN      ] contains.givenEmptyListThenReturnsFalse
[       OK ] contains.givenEmptyListThenReturnsFalse (0 ms)
[----------] 1 test from contains (0 ms total)

[----------] 2 tests from CreateLinkedList
[ RUN      ] CreateLinkedList.givenNoInputWhenCreatingListThenSizeIsZero
[       OK ] CreateLinkedList.givenNoInputWhenCreatingListThenSizeIsZero (0 ms)
[ RUN      ] CreateLinkedList.givenNoInputWhenCreatingListThenHeadAndTailAreNull
[       OK ] CreateLinkedList.givenNoInputWhenCreatingListThenHeadAndTailAreNull (0 ms)
[----------] 2 tests from CreateLinkedList (0 ms total)

[----------] 2 tests from InsertLinkedList
[ RUN      ] InsertLinkedList.givenNonNullStringWhenInsertedThenStringIsInList
[       OK ] InsertLinkedList.givenNonNullStringWhenInsertedThenStringIsInList (0 ms)
[ RUN      ] InsertLinkedList.givenNonNullStringWhenInsertedThenStringHead
[       OK ] InsertLinkedList.givenNonNullStringWhenInsertedThenStringHead (0 ms)
[----------] 2 tests from InsertLinkedList (0 ms total)

[----------] 1 test from RemoveLLElem
[ RUN      ] RemoveLLElem.givenNonNullStringWhenRemovedThenStringIsNotInList
[       OK ] RemoveLLElem.givenNonNullStringWhenRemovedThenStringIsNotInList (0 ms)
[----------] 1 test from RemoveLLElem (0 ms total)

[----------] 1 test from EmptyListHasNullHeadAndTell
[ RUN      ] EmptyListHasNullHeadAndTell.givenEmptyListWhenInsertAndRemoveThenHeadAndTailAreNull
[       OK ] EmptyListHasNullHeadAndTell.givenEmptyListWhenInsertAndRemoveThenHeadAndTailAreNull (0 ms)
[----------] 1 test from EmptyListHasNullHeadAndTell (0 ms total)

[----------] 3 tests from NumElementsInLinkedList
[ RUN      ] NumElementsInLinkedList.givenEmptyListThenNumElementsIsZero
[       OK ] NumElementsInLinkedList.givenEmptyListThenNumElementsIsZero (0 ms)
[ RUN      ] NumElementsInLinkedList.givenListWithSingleNodeThenNumElementsIsOne
[       OK ] NumElementsInLinkedList.givenListWithSingleNodeThenNumElementsIsOne (0 ms)
[ RUN      ] NumElementsInLinkedList.givenListWith_N_NodeThenNumElementsIsN
[       OK ] NumElementsInLinkedList.givenListWith_N_NodeThenNumElementsIsN (0 ms)
[----------] 3 tests from NumElementsInLinkedList (0 ms total)

[----------] 2 tests from PopLinkedList
[ RUN      ] PopLinkedList.givenEmptyListWhenPoppedThenReturnsTheInputDataPtr
[       OK ] PopLinkedList.givenEmptyListWhenPoppedThenReturnsTheInputDataPtr (0 ms)
[ RUN      ] PopLinkedList.givenNonEmptyListWhenPoppedThenDoesNotReturnTheInputDataPtr
test_linkedlist.cc:158: Failure
      Expected: 0
To be equal to: strcmp(node->payload, *buffer)
      Which is: -116

```


I haven't figured it out the error that occured above, sorry about that!




