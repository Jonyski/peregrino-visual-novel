#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <string.h>

void readCommand();            // gets the user command and calls processComand
int processCommand(char *cmd); // run the corresponding function to the command recieved (returns 0 if there wasn't a command)

void help();            // tells the user what are the available commands and what they do
void options();         // allows the user to change the options
void save();            // saves the game
void exibitInventory(); // shows the user their inventory
void jupiterWeb();      // shows the user the course's cronogram
void quit();            // quits the game (auto-saves?)

#endif