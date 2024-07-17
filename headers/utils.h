#ifndef  UTILS_H
#define UTILS_H

// waits for a newline input in the terminal
#define pause do { while (getchar() != '\n'); } while (0)
// generates a random float between 0 and 1
#define randomFloat (float)rand()/(float)RAND_MAX

#endif