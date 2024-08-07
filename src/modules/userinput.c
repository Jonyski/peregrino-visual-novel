#include "userinput.h"
#include "gamestate.h"
#include "minigame.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

void readInput() {
  currContext.inputsRead++;
  InputERR currError = NO_ERR;
  printf("> ");
  // ask for it until it is formated correctly
  do {
    char userInput[USR_INPUT_MAX_SIZE];
    getUserInput(userInput, currError);
    currError = processFreeFormInput(userInput);
  } while (currError != NO_ERR);
}

void getUserInput(char *userInput, InputERR err) {
  switch (err) {
  case SHOULD_BE_STR:
    printf("\npor favor, escreva apenas caracteres alfanuméricos:\n> ");
    break;
  case SHOULD_BE_INT:
    printf("\nnão não não, isso não me parece um número, mim dê um número:\n> ");
    break;
  case TOO_LONG:
    printf("\npassou de duas linhas eu nem leio, me dê algo mais curto:\n> ");
    break;
  case TOO_SHORT:
    printf("\nisso é muito curto (foi o que ela disse), tente de novo:\n> ");
    break;
  case NULL_INPUT:
    printf("\nei, seu input não pode ser vazio:\n> ");
    break;
  case WRONG_ANSWER:
    printf("\nnão, isso está errado, tente de novo:\n> ");
    break;
  case NO_ERR:
    break;
  }
  cleanScan(userInput);
}

InputERR processFreeFormInput(char *input) {
  if (currContext.currActivity == CLASS) {
    if (currContext.currDay == 1) {
      return processDay1ClassInput(input, currContext.inputsRead);
    }
  } else if (currContext.currActivity == MINIGAME) {
    switch (currContext.miniGameId) {
    case 0:
      return processCalcGame(input, currContext.miniGameQuestionId);
      break;
    case 1:
      return processIpGame(input, currContext.miniGameQuestionId);
      break;
    }
  }

  return NO_ERR;
}

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
