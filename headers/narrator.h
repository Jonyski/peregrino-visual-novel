#ifndef NARRATOR_H
#define NARRATOR_H

#include <stdbool.h>

struct Narrator {
	int nextLine;
	int amountOfLines;
	char **script;
};
void narrate(struct Narrator *, bool);
int getNumberOfLines(char *);
void slowPrint(char *str);
struct Narrator createNarrator();

#endif