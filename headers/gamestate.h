#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <stdbool.h>
#include "player.h"


// enum representing what the player is doing in a determined context
typedef enum {
	CLASS,
	NAVIGATION,
	BOSS_FIGHT,
	MISSION,
	MINIGAME,
	PAUSED
} Activity;

// useful for input reading, control flow and others
struct Context {
	char textPath[64];     // the current file being read by the narrator
	short int numOfInputs; // total number of inputs asked in the current file
	short int currDay;     // the number of the day being played 
	Activity currActivity; // true if the player is in a boss fight
};

// global variables
extern struct Player player; // the player object
extern struct Context currContext; // path to the current file being read, serves as a context identifier

// game-long important values for a save-system
struct GameState {
	int isaPoints;
	struct NPC **bossesDefeated;
	bool panelasUnlocked;
};

struct GameState *createGameState();
void deleteGameState(struct GameState *gs);

#endif