#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "IO.h"
#include "utils.h"
#include "gamestate.h"
#include "minigame.h"
#include "inputhandlers.h"

volatile bool shouldSkip = false;
volatile bool ignoreSkip = false;

void readInput() {
  currContext.inputsRead++;
  InputERR currError = NO_ERR;
  printf("> ");
  // ask for it until it is formated correctly
  do {
    char userInput[USR_INPUT_MAX_SIZE];
    treatInputError(currError);
    cleanScan(userInput);
    currError = processFreeFormInput(userInput);
  } while (currError != NO_ERR);
}

void treatInputError(InputERR err) {
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

int cleanScan(char *dest) {
  if (fgets(dest, USR_INPUT_MAX_SIZE, stdin) != NULL) {
    size_t len = strlen(dest);
    if (len > 0 && dest[len - 1] == '\n') {
      dest[len - 1] = '\0';
    } else {
      // Clear the input buffer if input exceeds USR_INPUT_MAX_SIZE
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF);
    }
    trimWhitespace(dest);
  }
  return strlen(dest);
}

void slowPrint(char *str) {
  // changing terminal configurations to read input discreetly
  struct termios old_conf, new_conf;
  tcgetattr(STDIN_FILENO, &old_conf);
  new_conf = old_conf;
  new_conf.c_lflag &= ~(ICANON | ECHO); // turns off canon mode and input echo
  tcsetattr(STDIN_FILENO, TCSANOW, &new_conf);

  // creating a thread that may fast-forward the slow printing;
  // this thread accesses the volatile variable defined in the beggining of this
  // file
  pthread_t checkInterruption;
  pthread_create(&checkInterruption, NULL, checkInterrupt, NULL);

  // reseting on every call of slowPrint
  shouldSkip = false;

  while (*str) {
    // if the user presss a key we fast-forward the printing process
    if (shouldSkip) {
      printf("%s", str);
      break;
    }
    putchar(*str++);
    fflush(stdout);
    // sleep a little longer on dots, this gives more dinamicity to the output
    if (*(str - 1) == '.') {
      usleep(300000);
    }
    // between each character output sleep for 20~35 miliseconds
    usleep((randomFloat * 15 + 20) * 1000);
  }

  if (shouldSkip == false) {
    pthread_cancel(checkInterruption);
  } else {
    shouldSkip = false;
    pthread_join(checkInterruption, NULL);
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &old_conf);
}

void *checkInterrupt(void *arg) {
  // activates the shouldSkip flag when a key is pressed
  while (!shouldSkip) {
    if (getchar()) {
      shouldSkip = true;
    }
  }
}

void printCentered(char *text) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int width = w.ws_col;

  int textLength = strlen(text);
  int padding = (width - textLength) / 2;

  // Print leading spaces
  for (int i = 0; i < padding; i++) {
    printf(" ");
  }

  // Print the actual text
  printf("%s\n", text);
}

void slowPrintCentered(char *text) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int width = w.ws_col;

  int textLength = strlen(text);
  int padding = (width - textLength) / 2;

  // Print leading spaces
  for (int i = 0; i < padding; i++) {
    printf(" ");
  }

  // Print the actual text
  slowPrint(text);
}