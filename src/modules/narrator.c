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

struct Narrator createNarrator(char *textFilePath) {
	struct Narrator narrator;

	int numOfLines = getNumberOfLines(textFilePath);
	FILE *scriptFile = fopen(textFilePath, "r");

	if(scriptFile == NULL) {
		exit(1); // failed to access script file
	}

	char *script[numOfLines];
	char buffer[2048];
	int currLine = 0;
	while(fgets(buffer, sizeof(buffer), scriptFile) && currLine < numOfLines) {
		script[currLine] = malloc(strlen(buffer));
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
	//narrator->script[narrator->nextLine] = preProcessLine(narrator->script[narrator->nextLine]);
	slowPrint(narrator->script[narrator->nextLine]);
	if(!shouldSkip) {
		pause;
	}
	if(narrator->nextLine < narrator->amountOfLines){
		narrator->nextLine++;
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

	// reseting on every call of slowPrint
	shouldSkip = false;

	while(*str) {
		// if the user presss a key we fast-forward the printing process
		if(shouldSkip) {
			printf("%s", str);
			break;
		}
		putchar(*str++);
		fflush(stdout);
		// sleep a little longer on dots, this gives more dinamicity to the output
		if(*(str - 1) == '.') {
			usleep(300000);
		}
		// between each character output sleep for 20~35 miliseconds
		usleep((randomFloat * 15 + 20) * 1000);
	}
	shouldSkip = false;
	pthread_join(checkInterruption, NULL);
	tcsetattr(STDIN_FILENO, TCSANOW, &old_conf);
}

void *checkInterrupt(void *arg) {
	// activates the shouldSkip flag when a key is pressed
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