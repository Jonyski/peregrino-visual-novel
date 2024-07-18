#ifndef NARRATOR_H
#define NARRATOR_H

#include <stdbool.h>

// a struct that stores what is necessary for the narration system
struct Narrator {
	int nextLine;      // index of the next unread line
	int amountOfLines; // length of the script in number of lines
	char **script;     // array of strings, each one representing a line to be narrated
};
// useful when prompting the user for a new input
enum InputErr {
	SHOULD_BE_STR,
	SHOULD_BE_INT,
	TOO_LONG,
	TOO_SHORT,
	NULL_INPUT,
	NO_ERR
};
struct Narrator createNarrator(char *filePath); // instanciates a narrator
void narrate(struct Narrator *, bool);  // narrates 1 line (the one indexed be narrator->nextLine)
char *getUserInput(enum InputERR);      // reads the user input and comunicates any error
enum InputERR processFreeFormInput(char *input, char *context); // 
char *preProcessLine();
void slowPrint(char *str);              // prints strings in a clean way
void *checkInterrupt(void *arg);        // checks for interruptions that will fast-forward slowPrint()
int getNumberOfLines(char *);           // finds the number of lines in a file


#endif