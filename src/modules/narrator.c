#include "narrator.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "narrator.h"
#include "utils.h"

struct Narrator createNarrator() {
	struct Narrator narrator;

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
			exit(1); // failed to allocate the script
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
	if(shouldClear) {
		system("clear");
	}
	slowPrint(narrator->script[narrator->nextLine]);
	narrator->nextLine++;
	pause;
}

void slowPrint(char *str) {
	while(*str) {
		putchar(*str++);
		fflush(stdout);
		usleep((randomFloat * 15 + 20) * 1000);
	}
}

int getNumberOfLines(char *filePath) {
	FILE *file = fopen(filePath, "r");
	char buffer[256];
	int numOfLines = 0;
	while(fgets(buffer, 256, file)) {
		numOfLines++;
	}
	fclose(file);
	return numOfLines;
}
