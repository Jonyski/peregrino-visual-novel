#include "inputhandlers.h"
#include "gamestate.h"
#include "minigame.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

//----------------------------------//
// DAILY ACTIVITIES INPUT HANDLERS  //
//----------------------------------//

InputERR processDay1ClassInput(char *input, int inputNum) {
  if (strlen(input) == 0)
    return NULL_INPUT;

  if (inputNum == 1) {
    // player name handling
    if (strlen(input) > NAME_SIZE_LIMIT)
      return TOO_LONG;
    strcpy(player.name, input);
  } else if (inputNum == 2) {
    // Calculus classroom number handling
    if (strcmp(input, "219"))
      return WRONG_ANSWER;
  }
  return NO_ERR;
}

//--------------------------//
// MINIGAME INPUT HANDLERS  //
//--------------------------//

InputERR processCalcGameQ1(char *input);
InputERR processCalcGameQ2(char *input);
InputERR processCalcGameQ3(char *input);

InputERR processCalcGame(char *input, short int question_num) {
  switch (question_num) {
  case 0:
    return processCalcGameQ1(input);
    break;
  case 1:
    return processCalcGameQ2(input);
    break;
  default:
    return NO_ERR;
    break;
  }
}

InputERR processCalcGameQ1(char *input) {
  if (!strlen(input)) {
    return NULL_INPUT;
  } else if (strlen(input) > 1) {
    return TOO_LONG;
  }

  int input_as_num = atoi(input);
  if (input_as_num == 0) {
    return SHOULD_BE_INT;
  } else if (input_as_num != 2) {
    return WRONG_ANSWER;
  } else {
    return NO_ERR;
  }
}

// TODO: Unimplemented
InputERR processCalcGameQ2(char *input) { return NO_ERR; }

// TODO: Unimplemented
InputERR processCalcGameQ3(char *input) { return NO_ERR; }

// TODO: Unimplemented
InputERR processIpGame(char *input, short int question_num) { return NO_ERR; }
