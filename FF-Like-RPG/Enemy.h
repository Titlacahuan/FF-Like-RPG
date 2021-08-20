#pragma once

#include <string>
#include <stdlib.h>

class Enemy
{
public:
	Enemy(int level = 0);
	virtual ~Enemy();

	// Functions
	inline bool isAlive() { return this->hp > 0; }
	inline void takeDamage(int damage) { this->hp -= damage; }
	inline int getDamage() const { return rand() % this->damageMax - this->damageMin; }
	inline int getExp() const { return this->level * 100; }
	std::string getAsString() const; 

private:
	int level;
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	int defence;
	int accuracy;
	float dropChance;
	std::string name;
};

