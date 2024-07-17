#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include "narrator.h"
#include "utils.h"

volatile int shouldSkip = false; // for allowing the slow printing to be fast-forwarded

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
		exit(1); // failed to access script file
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
	if(!shouldSkip) {
		pause;
	}
}

void slowPrint(char *str) {
	// changing terminal configurations to read input discreetly
	struct termios old_conf, new_conf;
	tcgetattr(STDIN_FILENO, &old_conf);
	new_conf = old_conf;
	new_conf.c_lflag &= ~(ICANON | ECHO); // turns off canon mode and input echo
	tcsetattr(STDIN_FILENO, TCSANOW, &new_conf);

	// creating a thread that may fast-forward the slow printing;
	// this thread accesses the volatile variable defined in the beggining of this file
	pthread_t checkInterruption;
	pthread_create(&checkInterruption, NULL, checkInterrupt, NULL);
	shouldSkip = false;

	while(*str) {
		if(shouldSkip) {
			printf("%s", str);
			break;
		}
		putchar(*str++);


		fflush(stdout);
		if(*(str - 1) == '.') {
			usleep(300000);
		}
		usleep((randomFloat * 15 + 20) * 1000);
	}
	shouldSkip = false;
	pthread_join(checkInterruption, NULL);
	tcsetattr(STDIN_FILENO, TCSANOW, &old_conf);
}

void *checkInterrupt(void *arg) {
	// prints the rest of the narration line if a key is pressed
	while(!shouldSkip) {
		if(getchar()) {
			shouldSkip = true;
		}
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