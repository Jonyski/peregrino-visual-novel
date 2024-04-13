#include <stdlib.h>
#include "npc.h"

// for autoincrementing ID
int nextNpcID = 0;

struct NPC {
	int id;
	char *name;
	int hp;
	void (*attack)(char *);
};

struct NPC *createNPC(char *name, int hp, void (*attack)(char *)) {
	struct NPC *newNPC = malloc(sizeof(struct NPC));
	if(newNPC == NULL) {
		return NULL; // failed to allocate a new NPC
	}

	newNPC->id = nextNpcID;
	nextNpcID++;
	newNPC->name = name;
	newNPC->hp = hp;
	newNPC->attack = attack;

	return newNPC;
}

void killNPC(struct NPC *npc) {
	free(npc);
}