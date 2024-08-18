#include "narrator.h"
#include "commands.h"
#include "gamestate.h"
#include "minigame.h"
#include "inputhandlers.h"
#include "utils.h"
#include "IO.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Narrator createNarrator(char *textFilePath) {
  struct Narrator narrator;

  int numOfLines = getNumberOfLines(textFilePath);
  FILE *scriptFile = fopen(textFilePath, "r");

  if (scriptFile == NULL) {
    exit(1); // failed to access script file
  }

  char **script = malloc(numOfLines * sizeof(char *));
  if (script == NULL) {
    exit(1);
  }

  char buffer[2048];
  int currLine = 0;
  while (fgets(buffer, sizeof(buffer), scriptFile) && currLine < numOfLines) {
    script[currLine] = malloc(strlen(buffer) + 1);
    if (script[currLine] == NULL) {
      exit(1);
    }

    strcpy(script[currLine], buffer);
    script[currLine][strlen(buffer)] = '\0';
    currLine++;
  }
  fclose(scriptFile);

  narrator.nextLine = 0;
  narrator.amountOfLines = numOfLines;
  narrator.script = script;

  return narrator;
}

void narrate(struct Narrator *narrator, bool shouldClear) {
  if (shouldClear) {
    system("clear");
  }

  // saving a copy of the raw narration line
  char nextLine[strlen(narrator->script[narrator->nextLine] + 1)];
  strcpy(nextLine, narrator->script[narrator->nextLine]);

  bool isInput = strncmp(nextLine, "<input>", 7) ? false : true;
  bool isMinigame = strncmp(nextLine, "<minigame>", 10) ? false : true;

  // altering the original line to clean it up and format it
  free(narrator->script[narrator->nextLine]);
  narrator->script[narrator->nextLine] = processLine(nextLine);

  slowPrint(narrator->script[narrator->nextLine]);
  if (narrator->nextLine == narrator->amountOfLines - 1) {
    printf("\n"); // so that the last line of the script don't make thing weird
  }

  if (isInput) {
    // geting and processing user input
    readInput();
  } else if (isMinigame) {
    minigameManager();
    currContext.miniGameId++; // Increment minigame count
  } else {
    // getting and processing user command
    readCommand();
  }

  free(narrator->script[narrator->nextLine]);
  if (narrator->nextLine < narrator->amountOfLines) {
    narrator->nextLine++;
  }
}

char *processLine(char *line) {
  char *outputLine;  // the line that will recieve all processing changes
  char *temp = line; // variable to hold lines that will be free'd (since
                     // strReplace returns a new manually allocated str)

  // tags to be substituted
  char *inputTag = "<input>";
  char *minigameTag = "<minigame>";
  char *playerNameTag = "<P-name>";
  char *playerSpeechTag = "<P>";
  char *playerThoughtTag = "<P-T>";

  // strings to replace the tags with
  char playerSpeech[42];
  strcpy(playerSpeech, player.name);
  strcat(playerSpeech, ": ");
  char playerThought[42];
  strcpy(playerThought, player.name);
  strcat(playerThought, ": ");

  // removing "<input>" from the beggining of input lines
  outputLine = strReplace(temp, inputTag, NULL);
  temp = outputLine;
  outputLine = strReplace(temp, playerNameTag, player.name);
  free(temp);
  temp = outputLine;
  outputLine = strReplace(temp, playerSpeechTag, playerSpeech);
  free(temp);
  temp = outputLine;
  outputLine = strReplace(temp, playerThoughtTag, playerThought);
  free(temp);
  temp = outputLine;
  outputLine = strReplace(temp, minigameTag, NULL);
  free(temp);

  return outputLine;
}

int getNumberOfLines(char *filePath) {
  FILE *file = fopen(filePath, "r");
  char buffer[1024];
  int numOfLines = 0;
  while (fgets(buffer, 1024, file)) {
    numOfLines++;
  }
  fclose(file);
  return numOfLines;
}