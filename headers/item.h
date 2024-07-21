#ifndef ITEM_H
#define ITEM_H

struct Item {
	char *name;
	char *effectDescription;
	int amount;
	void (*use)(struct Item *);
	void (*applyEffect)(struct Item *);
} Item;
struct Item *createItem(char *name, char *effectDescription, int amount, void (*effect)(struct Item *));
void useItem(struct Item *item, int amount);
void deleteItem(struct Item *item);

#endif