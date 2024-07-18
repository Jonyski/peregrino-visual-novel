#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "item.h"

struct Player createPlayer() {
  struct Player player;
  strcpy(player.name, "Peregrino"); // default name
  player.hp = INITIAL_HP;
  for(int i = 0; i < INVENTORY_SIZE; i++) {
    player.inventory[i] = NULL;
  }
  return player;
}

