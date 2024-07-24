#ifndef PLACES_H
#define PLACES_H

int navigateMap();            // loops the navigation cycle
int printMap();               // exibits the map
void showNavigationOptions(); // shows the each-general navigation options

// functions that print what happens when you first enter each place
// and calls its respective loop
void biblioteca();
void queijo();
void auditorios();
void titanic();
void grama();
int cb();
int elefantebranco();
int ginasio();

// each place has a loop that asks what the player wants to do in that place
void biblioLoop(char *);
void titanicLoop(char *);
void queijoLoop(char *);
void auditoriosLoop(char *);
void gramaLoop(char *);


#endif