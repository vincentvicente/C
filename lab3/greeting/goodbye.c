#include <stdio.h>
#include "user.h"

void InformalGoodbye(User* user) {
	printf("See you, %s!\n", user->firstName);
}

void FormalGoodbye(User* user) {
	printf("Goodbye, %s!\n", user->lastName);
}
