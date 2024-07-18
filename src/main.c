#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>
#include "narrator.h"

int main(int argc, char const *argv[]) {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	#ifdef _WIN32
		char *day1TextPath = ".\\texts\\day1-script.txt";
	#else
		char *day1TextPath = "./texts/day1-script.txt";
	#endif

	struct Narrator narrator = createNarrator(day1TextPath);
	for(int i = 0; i < narrator.amountOfLines - 1; i++) {
		narrate(&narrator, true);
	}
}
