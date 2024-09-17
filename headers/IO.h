#ifndef IO_H
#define IO_H

#include <stdbool.h>

#define USR_INPUT_MAX_SIZE 128

extern volatile bool shouldSkip; // for allowing the slow printing to be fast-forwarded
extern volatile bool ignoreSkip; // so that skip tentatives are ignored during input reading

// useful when prompting the user for a new input
typedef enum {
	SHOULD_BE_STR,
	SHOULD_BE_INT,
	TOO_LONG,
	TOO_SHORT,
	NULL_INPUT,
	WRONG_ANSWER,
	NO_ERR
} InputERR;

// INPUT RELATED FUNCTIONS
void readInput();                      // gets the user input and then process it
void treatInputError(InputERR);   // reads the user input and comunicates any error
InputERR processFreeFormInput(char *); // does with the input what is adequate according to the context
int cleanScan(char *dest);             // reads stdin input avoiding buffer overflows and trimming white space

// OUTPUT RELATED FUNCTIONS
void slowPrint(char *str);          // prints strings in a clean way
void *checkInterrupt(void *arg);        // checks for interruptions that will fast-forward slowPrint()
void printCentered(char *text);     //print text in a centralized way
void slowPrintCentered(char *text); //slowly, print text in a centralized way

#endif