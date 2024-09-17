#ifndef NARRATOR_H
#define NARRATOR_H

#include <stdbool.h>
#include "IO.h"

// a struct that stores what is necessary for the narration system
struct Narrator {
	int nextLine;      // index of the next unread line
	int amountOfLines; // length of the script in number of lines
	char **script;     // array of strings, each one representing a line to be narrated
};

struct Narrator createNarrator(char *filePath); // instanciates a narrator
void narrate(struct Narrator *, bool);  // narrates 1 line (the one indexed be narrator->nextLine)
char *processLine(char *);              // cleans the line and makes necessary substitutions before it is printed
int getNumberOfLines(char *);           // finds the number of lines in a file

#endif