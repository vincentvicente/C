# Name Formatting Library
This library provides utility functions for formatting personal names in various styles. It includes two main functions: FormatName and FillName. Below is a detailed explanation of how to use these functions.

## Functions
```
void FormatName(Name *name, char format)
```
Prints a given name in the format specified by the format character.

## Parameters:

name: A pointer to a Name structure containing the first, middle, and last names.
format: A character indicating the desired format. Supported format characters are:
'B': Big format (first middle last)
'L': Last format (last, first)
'R': Regular format (first last)
'M': Middle format (first middle_initial. last)
'S': Small format (first)
### Example Usage:
```
Name exampleName = {"John", "Michael", "Doe"};
FormatName(&exampleName, 'B'); // Output: John Michael Doe
void FillName(Name *name, char format, char *dest)
```
Formats a given name according to the specified format and stores it in the destination array without printing anything on the screen.

### Parameters:

name: A pointer to a Name structure.
format: A character indicating the desired format (same as in FormatName).
dest: A character array where the formatted name will be stored.
Example Usage:
```
char formattedName[50];
FillName(&exampleName, 'L', formattedName);
printf("%s\n", formattedName); // Output: Doe, John
```
Structure Definition
The Name structure should be defined as follows:
```
typedef struct {
    char *first;
    char *middle;
    char *last;
} Name;
```

>## Common Questions
### Can I create helper functions? Do I include the function prototype in the .h file? Do I have to test the helper functions I create?
    Yes, you can create helper functions. You can include the function prototype in the .h file, but it's not mandatory; you can also place it at the top of the .c file. While testing helper functions is not required, you are responsible for ensuring their correctness.

### Why does my program work differently depending on how I initialize the strings?
    Working with strings in C can be tricky. Whether strings are mutable or immutable depends on how they are initialized. Refer to class notes for guidance on initializing strings.
