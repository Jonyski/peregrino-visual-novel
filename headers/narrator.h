#ifndef NARRATOR_H
#define NARRATOR_H

#include <stdbool.h>
#include "userinput.h"

// a struct that stores what is necessary for the narration system
struct Narrator {
	int nextLine;      // index of the next unread line
	int amountOfLines; // length of the script in number of lines
	char **script;     // array of strings, each one representing a line to be narrated
};

struct Narrator createNarrator(char *filePath); // instanciates a narrator
void narrate(struct Narrator *, bool);  // narrates 1 line (the one indexed be narrator->nextLine)
char *getUserInput(InputERR);      // reads the user input and comunicates any error
InputERR processFreeFormInput(char *, int); // does with the input what is adequate according to the context
char *preProcessLine();                 // 
void slowPrint(char *str);              // prints strings in a clean way
void *checkInterrupt(void *arg);        // checks for interruptions that will fast-forward slowPrint()
int getNumberOfLines(char *);           // finds the number of lines in a file


#endif