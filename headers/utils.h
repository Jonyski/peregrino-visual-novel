#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "userinput.h"

// waits for a newline input in the terminal
#define pause do { while (getchar() != '\n'); } while (0)
// generates a random float between 0 and 1
#define randomFloat (float)rand()/(float)RAND_MAX
// removes whitespace from te beggining and ending of a str
void trimWhitespace(char *str);
// reads stdin input avoiding buffer overflows and trimming white space
void cleanScan(char *dest);

#endif