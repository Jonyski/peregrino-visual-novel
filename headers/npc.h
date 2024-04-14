#ifndef NPC_H
#define NPC_H

#ifndef NUM_OF_BOSSES
#define NUM_OF_BOSSES 8
#endif

struct NPC;
struct NPC *createNPC(char *name, int hp, void (*attack)(char *));
void killNPC(struct NPC *npc);

#endif