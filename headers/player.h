#ifndef PLAYER_H
#define PLAYER_H

struct Player;
struct Player *createPlayer(char name[16]);
void killPlayer(struct Player *p);

#endif