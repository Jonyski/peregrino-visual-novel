#include <stdio.h>
#include <stdlib.h>
#include "places.h"
#include "narrator.h"

int mapa(){
	char choice[1];
	printMap();
	slowPrint("Você está no portão 3 da EACH.\n");
	showNavigationOptions();
}