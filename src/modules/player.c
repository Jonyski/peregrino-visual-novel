#include "player.h"
#include "item.h"
#include <stdlib.h>

#define INVENTORY_SIZE 10
#define INITIAL_HP 20
#define NAME_SIZE_LIMIT 20

struct Player {
  char *name;
  int hp;
  struct Item **items;
};

struct Player *createPlayer() {
  struct Player *player = malloc(sizeof(struct Player));
  if (player == NULL) {
    return NULL; // failed to allocate player
  }

  player->name = calloc(NAME_SIZE_LIMIT, sizeof(char));
  if (player->name == NULL) {
    free(player);
    return NULL; // failed to allocated name
  }
  player->hp = INITIAL_HP;
  player->items = calloc(INVENTORY_SIZE, sizeof(struct Item *));
  if (player->items == NULL) {
    free(player->name);
    free(player);
    return NULL; // failed to allocate items
  }

  return player;
}

void killPlayer(struct Player *p) {
  free(p->name);
  free(p->items);
  free(p);
}
