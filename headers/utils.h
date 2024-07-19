#ifndef  UTILS_H
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
void trimWhitespace(char *str) {
    char *start = str;
    // trim leading whitespace
    while(isspace((unsigned char)*start)) start++;

    // Move the trimmed string to the beginning
    memmove(str, start, strlen(start) + 1);

    // Trim trailing whitespace
    char *end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}
// reads stdin input avoiding buffer overflows and trimming white space
void cleanScan(char *dest) {
	if (fgets(dest, USR_INPUT_MAX_SIZE, stdin) != NULL) {
        size_t len = strlen(dest);
        if (len > 0 && dest[len - 1] == '\n') {
            dest[len - 1] = '\0';
        }

        trimWhitespace(dest);
    }
}
#endif