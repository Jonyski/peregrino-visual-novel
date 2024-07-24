#include "utils.h"
#include "userinput.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trimWhitespace(char *str) {
  char *start = str;
  // trim leading whitespace
  while (isspace((unsigned char)*start))
    start++;

  // Move the trimmed string to the beginning
  memmove(str, start, strlen(start) + 1);

  // Trim trailing whitespace
  char *end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char)*end))
    end--;

  *(end + 1) = '\0';
}

int cleanScan(char *dest) {
  if (fgets(dest, USR_INPUT_MAX_SIZE, stdin) != NULL) {
    size_t len = strlen(dest);
    if (len > 0 && dest[len - 1] == '\n') {
      dest[len - 1] = '\0';
    }
    trimWhitespace(dest);
  }
  return strlen(dest);
}


// copy-pasted from stackoverflow:
// https://stackoverflow.com/questions/779875/what-function-is-to-replace-a-substring-from-a-string-in-c
char *strReplace(char *orig, char *rep, char *with) {
  char *result;  // the return string
  char *ins;     // the next insert point
  char *tmp;     // varies
  int len_rep;   // length of rep (the string to remove)
  int len_with;  // length of with (the string to replace rep with)
  int len_front; // distance between rep and end of last rep
  int count;     // number of replacements

  // sanity checks and initialization
  if (!orig || !rep)
    return NULL;
  len_rep = strlen(rep);
  if (len_rep == 0)
    return NULL; // empty rep causes infinite loop during count
  if (!with)
    with = "";
  len_with = strlen(with);

  // count the number of replacements needed
  ins = orig;
  for (count = 0; (tmp = strstr(ins, rep)); ++count) {
    ins = tmp + len_rep;
  }

  tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

  if (!result)
    return NULL;

  // first time through the loop, all the variable are set correctly
  // from here on,
  //    tmp points to the end of the result string
  //    ins points to the next occurrence of rep in orig
  //    orig points to the remainder of orig after "end of rep"
  while (count--) {
    ins = strstr(orig, rep);
    len_front = ins - orig;
    tmp = strncpy(tmp, orig, len_front) + len_front;
    tmp = strcpy(tmp, with) + len_with;
    orig += len_front + len_rep; // move to next "end of rep"
  }
  strcpy(tmp, orig);
  return result;
}
