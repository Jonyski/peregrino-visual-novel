#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"

#define INVENTORY_SIZE 10
#define INITIAL_HP 20
#define NAME_SIZE_LIMIT 20

// the simple struct representing the player
// there should probably be one instance of this struct, but idk
struct Player{
  char name[NAME_SIZE_LIMIT];             // name defined by player input
  int hp;                                 // maximum Health Points
  struct Item *inventory[INVENTORY_SIZE]; // list of items
};
struct Player createPlayer(); // creates a player with default properties

#endif