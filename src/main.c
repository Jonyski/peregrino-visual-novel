#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "narrator.h"
#include "player.h"
#include "gamestate.h"
#include "navigation.h"
#include "utils.h"
#include "IO.h"
#include "tests.h"

struct Player player;
struct Context currContext;

void gameMenu();
void startGame();

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "");
  srand(time(NULL));

  if(argc > 1) {
    testFeature(argv[1]);
  } else {
    gameMenu();
    startGame();
  }
}

void gameMenu() {
  wchar_t *titleImg[7] = {
  L"░▒▓███████▓▒░░▒▓████████▓▒░▒▓███████▓▒░░▒▓████████▓▒░▒▓██████▓▒░░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░  \n",
  L"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n",
  L"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n",
  L"░▒▓███████▓▒░░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓██████▓▒░░▒▓█▓▒▒▓███▓▒░▒▓███████▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n",
  L"░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n",
  L"░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n",
  L"░▒▓█▓▒░      ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  \n"
  };

  system("clear");
  usleep(700000);
  // gradually printing the title (falling effect)
  for(int i = 6; i >= 0; i--) {
    system("clear");
    printf("\n\n");
    for(int j = i; j <= 6; j++) {
      printf("%ls", titleImg[j]);
    }
    // simulting acceleration
    usleep(25000 + (3000 * ((i * i) / 2)));
  }
  printf("\n\n");

  wchar_t *compressedTitleImg = L"\n\n░▒▓███████▓▒░░▒▓████████▓▒░▒▓███████▓▒░░▒▓████████▓▒░▒▓██████▓▒░░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░  \n░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n░▒▓███████▓▒░░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓██████▓▒░░▒▓█▓▒▒▓███▓▒░▒▓███████▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n░▒▓█▓▒░      ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  \n\n";

  wchar_t *subtitleImg[6] = {
  L"  _   _ _                 _   _   _                _ \n",
  L" | | | (_)               | | | \\ | |              | |\n",
  L" | | | |_ ___ _   _  __ _| | |  \\| | _____   _____| |\n",
  L" | | | | / __| | | |/ _` | | | . ` |/ _ \\ \\ / / _ \\ |\n",
  L" \\ \\_/ / \\__ \\ |_| | (_| | | | |\\  | (_) \\ V /  __/ |\n",
  L"  \\___/|_|___/\\__,_|\\__,_|_| \\_| \\_/\\___/ \\_/ \\___|_|\n",
  };

  usleep(1000000);
  int subtitleLen = wcslen(subtitleImg[0]);
  // gradually printing the subtitle (sliding effect)
  for(int i = 0; i < subtitleLen; i++) {
    system("clear");
    printf("%ls", compressedTitleImg);
    for(int j = 0; j < 6; j++) {
      printf("%ls", &(subtitleImg[j][subtitleLen - i]));
    }
    usleep(15000);
  }

  usleep(600000);
  slowPrint("\n Por Jonyski, Orimoto, Montoya e Yukina!\n\n\n\n");
  usleep(600000);

  printf(" Aperte ENTER para começar...\n");
  char trash[USR_INPUT_MAX_SIZE];
  cleanScan(trash);
}

void startGame() {
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