#include <stdlib.h>
#include "player.h"
#include "item.h"

#define INVENTORY_SIZE 10
#define INITIAL_HP 20
#define NAME_SIZE_LIMIT 16

struct Player {
	char *name;
	int hp;
	struct Item **items;
};

struct Player *createPlayer() {
	struct Player *player = malloc(sizeof(struct Player));
	if(player == NULL) {
		return NULL; // failed to allocate player
	}

	player->name = malloc(NAME_SIZE_LIMIT * sizeof(char));
	player->hp = INITIAL_HP;
	player->items = malloc(INVENTORY_SIZE * sizeof(struct Item *));
	if(player->items == NULL) {
		free(player);
		return NULL; // failed to allocate items
	}
	for(int i = 0; i < INVENTORY_SIZE; i++){
		player->items[i] = NULL;
	}

	return player;
}

void killPlayer(struct Player *p) {
	free(p->name);
	free(p->items);
	free(p);
}