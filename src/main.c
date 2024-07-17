#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>
#include "narrator.h"

int main(int argc, char const *argv[]) {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	struct Narrator narrator = createNarrator();
	for(int i = 0; i < narrator.amountOfLines; i++) {
		narrate(&narrator, true);
	}
}
