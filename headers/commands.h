#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <string.h>

void readCommand();         // gets the user command and calls processComand
int processCommand(char *); // run the corresponding function to the command recieved (returns 0 if there wasn't a command)

void help();            // tells the user what are the available commands and what they do
void options();         // allows the user to change the options
void exibitInventory(); // shows the user their inventory
void jupiterWeb();      // shows the user the course's cronogram
void map();             // prints the EACH map
void clear();           // clears the screen
void save();            // saves the game
void quit();            // quits the game (auto-saves?)
int classifiesAsCommand(char *); // returns 1 if the input has an equivalent command

#endif