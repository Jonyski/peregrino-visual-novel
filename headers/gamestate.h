#ifndef GAMESTATE_H
#define GAMESTATE_H

struct GameState;
struct GameState *createGameState();
void deleteGameState(struct GameState *gs);

#endif