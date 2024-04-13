#include <stdlib.h>
#include "item.h"

struct Item {
	char *name;
	char *effectDescription;
	int amount;
	void (*use)(struct Item *);
	void (*applyEffect)(struct Item *);
};

struct Item *createItem(char *name, char *effectDescription, int amount, void (*effect)(struct Item *)) {
	struct Item *newItem = malloc(sizeof(struct Item));
	if(newItem == NULL) {
		return NULL; // failed to allocate a new item
	}

	newItem->name = name;
	newItem->effectDescription = effectDescription;
	newItem->amount = amount;
	newItem->applyEffect = effect;
	return newItem;
}

void useItem(struct Item *item, int amount) {
	if(item->amount > 0){
		item->applyEffect(item);
	}
	item->amount -= amount;
}

void deleteItem(struct Item *item) {
	free(item);
}