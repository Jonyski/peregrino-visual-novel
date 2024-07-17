#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "narrator.h"

#define pause while (getchar() != '\n'); 

int main(int argc, char const *argv[]) {
	setlocale(LC_ALL, "");

	struct Narrator *narrator = createNarrator();
	for(int i = 0; i < narrator->amountOfLines; i++) {
		narrate(narrator, true);
		pause;
	}
	killNarrator(narrator);
}
