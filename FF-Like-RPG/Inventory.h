#pragma once

#include "Weapon.h"
#include "Armor.h"

class Inventory
{
public:
	Inventory();
	Inventory(const Inventory& obj);
	virtual ~Inventory();

	// Accessors
	inline int size() const { return this->numOfItems; }

	// Operators
	Item& operator[](const unsigned int index);

	// Functions
	void addItem(const Item& item);
	Item* getItem(int index);
	void removeItem(int index);
	inline void debugPrint() const
	{
		for (size_t i = 0; i < this->numOfItems; i++)
		{
			std::cout << this->itemArr[i]->debugPrint() << std::endl;
		}
	}

private:
	unsigned int capacity;
	unsigned int numOfItems;
	Item** itemArr;

	// Functions
	void expand();
	void initialize(const int from = 0);
};

