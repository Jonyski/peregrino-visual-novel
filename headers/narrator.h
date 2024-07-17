#ifndef NARRATOR_H
#define NARRATOR_H

#define pause do { while (getchar() != '\n'); } while (0)

struct Narrator {
	int nextLine;
	int amountOfLines;
	char **script;
};
void narrate(struct Narrator *, bool);
int getNumberOfLines(char *);
void killNarrator(struct Narrator *);
void slowPrint(char *str);
struct Narrator createNarrator();

#endif