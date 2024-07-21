#ifndef USERINPUT_H
#define USERINPUT_H

#define USR_INPUT_MAX_SIZE 128

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

// compilation of functions that process each daily classes inputs
InputERR processDay1ClassInput(char *, int); // day 1 has 2 inputs: player name and Calculus classroom n°
InputERR processDay2ClassInput(char *, int); //
InputERR processDay3ClassInput(char *, int); //
InputERR processDay4ClassInput(char *, int); //
InputERR processDay5ClassInput(char *, int); //
InputERR processDay6ClassInput(char *, int); //
InputERR processDay7ClassInput(char *, int); //

#endif