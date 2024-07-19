#include <string.h>
#include "userinput.h"
#include "gamestate.h"

InputERR processDay1ClassInput(char *input, int inputNum) {
	if(strlen(input) == 0) return NULL_INPUT;

	if(inputNum == 1) {
		// player name handling
		if(strlen(input) > NAME_SIZE_LIMIT) return TOO_LONG;
		strcpy(player.name, input);
		return NO_ERR;
	} else if(inputNum == 2) {
		// Calculus classroom number handling
		if(strcmp(input, "219")) return WRONG_ANSWER;
		return NO_ERR;
	}
}