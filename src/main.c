#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "narrator.h"
#include "player.h"
#include "gamestate.h"
#include "navigation.h"

struct Player player;
struct Context currContext;

int main(int argc, char const *argv[]) {
	setlocale(LC_ALL, "");
	srand(time(NULL));

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

	struct Narrator narrator = createNarrator(currContext.textPath);
	for(int i = 0; i < narrator.amountOfLines; i++) {
		narrate(&narrator, true);
	}
	navigateMap();
}
