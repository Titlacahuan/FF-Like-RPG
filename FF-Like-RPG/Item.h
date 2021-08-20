#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Item
{

public:
	Item(std::string name = "NONE", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~Item();
		
	// Functions
	inline std::string debugPrint() const
	{
		//std::cout << std::setw(10) << std::setfill('=' * 10) << std::endl;
		//std::cout << "Item Name: " << this->name << std::endl;
		//std::cout << "Buy Value: " << this->buyValue << std::endl;
		//std::cout << "Sell Value: " << this->sellValue << std::endl;
		//std::cout << std::setw(10) << std::setfill('=' * 10) << std::endl;

		return this->name;
	};
	virtual Item* clone() const = 0;

	// Accessors
	inline const std::string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getBuyValue() const { return this->buyValue; }
	inline const int& getSellValue() const { return this->sellValue; }
	inline const int& getRarity() const { return this->rarity; }

	// Modifiers


private:
	std::string name;
	int buyValue;
	int sellValue;
	int level;
	int rarity;
};

