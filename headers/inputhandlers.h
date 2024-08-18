#ifndef USERINPUT_H
#define USERINPUT_H

#include "IO.h"

// compilation of functions that process each daily classes inputs
InputERR processDay1ClassInput(char *, int); // day 1 has 2 inputs: player name and Calculus classroom n°
InputERR processDay2ClassInput(char *, int); // unimplemented
InputERR processDay3ClassInput(char *, int); // unimplemented
InputERR processDay4ClassInput(char *, int); // unimplemented
InputERR processDay5ClassInput(char *, int); // unimplemented
InputERR processDay6ClassInput(char *, int); // unimplemented
InputERR processDay7ClassInput(char *, int); // unimplemented

// functions that process each minigame's inputs
InputERR processCalcGame(char *input, short int question_num);
InputERR processIpGame(char *input, short int question_num); // unimplemented
InputERR processCalcGameQ1(char *input);
InputERR processCalcGameQ2(char *input); // unimplemented
InputERR processCalcGameQ3(char *input); // unimplemented

#endif
