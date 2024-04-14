#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include "narrator.h"

#define pause do { while (getchar() != '\n'); } while (0)

int main(int argc, char const *argv[]) {
	setlocale(LC_ALL, "");

	struct Narrator *narrator = createNarrator();
	for(int i = 0; i < narrator->amountOfLines; i++) {
		narrate(narrator, true);
		pause;
	}
	killNarrator(narrator);
}
