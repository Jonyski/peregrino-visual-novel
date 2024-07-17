#include "narrator.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void narrate(struct Narrator *narrator, bool shouldClear) {
	if(shouldClear) {
		#ifdef _WIN32
			char *clearTerminal = "cls";
		#else 
			char *clearTerminal = "clear";
		#endif
		system(clearTerminal);
	}
	printf("%s\n", narrator->script[narrator->nextLine]);
	narrator->nextLine++;
}

int getNumberOfLines(char *filePath) {
	FILE *file = fopen(filePath, "r");
	char buffer[1024];
	int numOfLines = 0;
	while(fgets(buffer, 1024, file)) {
		numOfLines++;
	}
	fclose(file);
	return numOfLines;
}

struct Narrator *createNarrator() {
	struct Narrator *narrator = malloc(sizeof(struct Narrator));
	if(narrator == NULL) {
		return NULL; // failed to allocate the narrator
	}

	#ifdef _WIN32
		char *textPath = ".\\texts\\narratorscript.txt";
	#else
		char *textPath = "./texts/narratorscript.txt";
	#endif

	int numOfLines = getNumberOfLines(textPath);
	FILE *scriptFile = fopen(textPath, "r");

	if(scriptFile == NULL) {
		return NULL; // failed to access script file
	}

	char **script = malloc(numOfLines * sizeof(char *));
	char buffer[1024];
	int currLine = 0;
	while(fgets(buffer, sizeof(buffer), scriptFile) && currLine < numOfLines) {
		script[currLine] = malloc(strlen(buffer) + 1);
		if(script[currLine] == NULL) {
			return NULL; // failed to allocate the script
		}

		strcpy(script[currLine], buffer);
		script[currLine][strlen(buffer)] = '\0';
		currLine++;
	}
	fclose(scriptFile);

	narrator->nextLine = 0;
	narrator->amountOfLines = numOfLines;
	narrator->script = script;

	return narrator;
}

void killNarrator(struct Narrator *narrator) {
  for (int i = 0; i < narrator->amountOfLines; i++) {
    free(narrator->script[i]);
  }
  free(narrator->script);
  free(narrator);
}
