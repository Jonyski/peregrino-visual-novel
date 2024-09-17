#include <stdio.h>
#include <string.h>
#include "tests.h"
#include "gamestate.h"
#include "minigame.h"
#include "narrator.h"
#include "navigation.h"
#include "utils.h"

void testFeature(const char *flag) {
	if(!strcmp(flag, "-nrt")) {
		testNarration();
	} else if(!strcmp(flag, "-nav")) {
		testNavigation();
	} else if(!strcmp(flag, "-min")) {
		testMinigames();
	} else if(!strcmp(flag, "-btl")) {
		testBattles();
	}
}

void testNarration() {
	player = createPlayer();
	#ifdef _WIN32
	  strcpy(currContext.textPath, ".\\texts\\day1-script.txt");
	#else
	  strcpy(currContext.textPath, "./texts/day1-script.txt");
	#endif
	currContext.currDay = 1;
	currContext.numOfInputs = 2;
	currContext.inputsRead = 0;
	currContext.currActivity = CLASS;
	currContext.miniGameId = 0;
	currContext.miniGameQuestionId = 0;

	struct Narrator narrator = createNarrator(currContext.textPath);
	for(int i = 0; i < narrator.amountOfLines; i++) {
	  narrate(&narrator, true);
	}
}

void testNavigation() {
	//currContext.currActivity = NAVIGATION;
	navigatetest(each);
}

void testMinigames() {
	currContext.miniGameId = 0;
	currContext.miniGameQuestionId = 0;
	minigameManager();
}

void testBattles() {
	printf("ESTE FEATURE AINDA  NÃO EXISTE :<");
	pause_til_newline;
}
