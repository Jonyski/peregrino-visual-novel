#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "narrator.h"
#include "player.h"
#include "gamestate.h"

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
	currContext.currActivity = CLASS;

	struct Narrator narrator = createNarrator(currContext.textPath);
	for(int i = 0; i < narrator.amountOfLines - 1; i++) {
		narrate(&narrator, true);
	}
}
