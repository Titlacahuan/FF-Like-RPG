#include "Inventory.h"

Inventory::Inventory()
{
	this->capacity = 5;
	this->numOfItems = 0;
	this->itemArr = new Item*[this->capacity];
	this->initialize();
}

Inventory::Inventory(const Inventory& obj)
{
	this->capacity = obj.capacity;
	this->numOfItems = obj.numOfItems;
	this->itemArr = new Item * [this->capacity];
	
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	this->initialize(this->numOfItems);
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		delete this->itemArr[i];
	}

	delete[] itemArr;
}

Item& Inventory::operator[](const unsigned int index) 
{
	if(index < 0 || index >= this->numOfItems)
	{
		throw("BAD INDEX!");
	}

	return *this->itemArr[index];
}

void Inventory::expand()
{
	this->capacity *= 2;

	Item** tempArr = new Item * [this->capacity];

	for (size_t i = 0; i < this->numOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}

	delete[] this->itemArr;

	this->itemArr = tempArr;
	this->initialize(this->numOfItems);
}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < this->capacity; i++)
	{
		this->itemArr[i] = nullptr;
	}
}

void Inventory::addItem(const Item& item)
{
	if (this->numOfItems >= this->capacity)
	{
		expand();
	}

	this->itemArr[this->numOfItems++] = item.clone();
}

Item* Inventory::getItem(int index)
{
	return this->itemArr[index];
}

void Inventory::removeItem(int index)
{
	if (index >= 0)
	{
		delete this->itemArr[index];
	}
}
