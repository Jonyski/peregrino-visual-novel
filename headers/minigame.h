#ifndef MINIGAME_H
#define MINIGAME_H

#include "userinput.h"

void minigameManager();

InputERR processCalcGame(char *input, short int question_num);

InputERR processIpGame(char *input, short int question_num);

#endif // MINIGAME_H
