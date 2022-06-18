#ifndef SHOP_H
#define SHOP_H

#include "Inventory.h"

class Shop
{
private:
	Inventory* inventory;
	string title;

public:
	Shop(string title, Inventory* inventory) {
		this->title = title;
		this->inventory = inventory;
	}

	~Shop() {
		delete inventory;
	}

	Inventory* getInventory() {
		return inventory;
	}

	string getTitle() {
		return title;
	}
};
#endif // 

