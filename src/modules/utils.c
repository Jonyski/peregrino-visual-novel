#include "utils.h"

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

void cleanScan(char *dest) {
	if (fgets(dest, USR_INPUT_MAX_SIZE, stdin) != NULL) {
        size_t len = strlen(dest);
        if (len > 0 && dest[len - 1] == '\n') {
            dest[len - 1] = '\0';
        }
        trimWhitespace(dest);
    }
}