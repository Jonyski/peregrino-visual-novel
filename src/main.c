#include "gamestate.h"
#include "narrator.h"
#include "places.h"
#include "player.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>
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

  // TODO: make a createContext Function
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
	navigateMap();
}
