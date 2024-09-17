#ifndef NAVIGATION_H
#define NAVIGATION_H
#include "navigation.h"
#include <stddef.h>

typedef struct place{
	const char* name;
	struct place* subPlaces[10];
	char *filePath;
	int numSubPlaces;
	struct place* father;
} place_t;

		extern place_t banheirofb;
		extern place_t banheiromb;
		extern place_t estantes;
	extern place_t biblioteca;
		extern place_t ru;
		extern place_t salaaula;
		extern place_t spawn;
		extern place_t papelao;
		extern place_t banheiroft;
		extern place_t banheiromt;
		extern place_t telhado;
	extern place_t titanic;
		extern place_t anfiteatrocb;
		extern place_t lab;
		extern place_t cantinacb;
		extern place_t banheiromcb;
		extern place_t banheirofcb;
		extern place_t rp;
	extern place_t cb;
		extern place_t quadra;
		extern place_t aluguel;
		extern place_t labirinto;
		extern place_t academia;
		extern place_t escalada;
		extern place_t pingpong;
	extern place_t ginasio;
	extern place_t grama;
	extern place_t queijo;
	extern place_t auditorio;
extern place_t each;


void initializePlaces();
int navigate(place_t place);
int navigateMap();            // loops the navigation cycle
int printMap();               // exibits the map
void showNavigationOptions(); // shows the each-general navigation options
#endif