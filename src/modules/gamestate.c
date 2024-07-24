#include "gamestate.h"
#include "npc.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct GameState *createGameState() {
  struct GameState *newState = malloc(sizeof(struct GameState));
  if (newState == NULL) {
    return NULL; // failed to allocate newState
  }

  newState->isaPoints = 0;

  newState->bossesDefeated = malloc(NUM_OF_BOSSES * sizeof(struct NPC *));
  if (newState->bossesDefeated == NULL) {
    free(newState);
    return NULL; // failed to allocate bossesDefeated
  }
  // remove the garbage setting initial values to NULL
  for (int i = 0; i < NUM_OF_BOSSES; i++) {
    newState->bossesDefeated[i] = NULL;
  }

  newState->panelasUnlocked = false;
  return newState;
}

void deleteGameState(struct GameState *gs) {
  free(gs->bossesDefeated);
  free(gs);
}
