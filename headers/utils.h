#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

#define pause_til_newline do { while (getchar() != '\n'); } while (0)
// generates a random float between 0 and 1
#define randomFloat (float)rand()/(float)RAND_MAX
// removes whitespace from te beggining and ending of a str
void trimWhitespace(char *str);
// replaces all occurences of rep in orig with with
char *strReplace(char *orig, char *rep, char *with);
#endif
