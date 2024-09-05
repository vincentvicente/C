#include <stdio.h>
#include "user.h"
//only greetings
void StandardGreeting(User* user) {
    printf("Hi, I'm %s!\n", user->firstName);
}

void FormalGreeting(User* user) {
    printf("Hello, my name is %s!\n",user->firstName, user->lastName);
}
