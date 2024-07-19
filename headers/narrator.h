#ifndef NARRATOR_H
#define NARRATOR_H

#include <stdbool.h>

// A struct that stores what is necessary for the narration system
struct Narrator {
	int nextLine;      // index of the next unread line
	int amountOfLines; // length of the script in number of lines
	char **script;     // array of strings, each one representing a line to be narrated
};
struct Narrator createNarrator(char *);      // instanciates a narrator
void narrate(struct Narrator *, bool); // narrates 1 line (the one indexed be narrator->nextLine)
int getNumberOfLines(char *);          // finds the number of lines in a file
void slowPrint(char *str);             // prints strings in a clean way
void *checkInterrupt(void *arg);       // checks for interruptions that will fast-forward slowPrint()
void printCenteredText(char *text); //print text in a centralized way
void slowCenteredText(char *text); //slowly, print text in a centralized way
#endif