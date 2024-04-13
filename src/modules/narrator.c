#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "narrator.h"

struct Narrator {
	char *nextLine;
	void (*narrate)(void);
};

void narrate(char *nextLine, bool shouldClear) {
	if(shouldClear) {
		system("clear");
	}
	printf("%s\n", nextLine);
}