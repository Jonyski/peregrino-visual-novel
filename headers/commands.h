#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <string.h>

void help();            // tells the user what are the available commands and what they do
void options();         // allows the user to change the options
void save();            // saves the game
void exibitInventory(); // shows the user their inventory
void jupiterWeb();      // shows the user the course's cronogram
void quit();            // quits the game (auto-saves?)

#endif