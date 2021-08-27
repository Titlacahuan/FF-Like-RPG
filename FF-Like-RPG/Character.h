#pragma once

#include "Inventory.h"
#include "Enemy.h"

class Character
{

public: 
	Character();
	virtual ~Character();

	// Operators


	// Functions
	void initialize(const std::string name);
	std::string toString() const;
	std::string getAsString() const;
	void levelUp();

	// Accessors
	inline const double& getX() const { return this->xPos; }
	inline const double& getY() const { return this->yPos; }

	inline const int& getDistanceTravelled() { return this->distanceTravelled; }

	inline const Weapon& getWeapon() const { return this->weapon; }
	inline const Armor& getHeadArmor() const { return this->armorHead; }
	inline const Armor& getChestArmor() const { return this->armorChest; }
	inline const Armor& getArmsArmor() const { return this->armorArms; }
	inline const Armor& getLegsArmor() const { return this->armorLegs; }
	inline const int& getGold() const { return this->gold; }

	inline const std::string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	
	inline const int& getStrength() const { return this->strength; }
	inline const int& getVitality() const { return this->vitality; }
	inline const int& getDexterity() const { return this->dexterity; }
	inline const int& getIntelligence() const { return this->intelligence; }

	inline const int& getHP() const { return this->hp; }
	inline const int& getHPMax() const { return this->hpMax; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getStaminaMax() const { return this->staminaMax; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefence() const { return this->defence; }
	inline const int& getLuck() const { return this->luck; }

	inline const int& getStatPoints() const { return this->statPoints; }
	inline const int& getSkillPoints() const { return this->skillPoints; }

	// Modifiers
	inline void setDistanceTravelled(const int& distance) { this->distanceTravelled = distance; }
	inline void travel() { this->distanceTravelled++; }

private:
	double xPos;
	double yPos;

	int distanceTravelled;

	Inventory inventory;
	Weapon weapon;
	Armor armorHead;
	Armor armorChest;
	Armor armorArms;
	Armor armorLegs;
	int gold;
	
	std::string name;
	int level;
	int exp;
	int expNext;
	
	int strength;
	int vitality;
	int dexterity;
	int intelligence;

	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	int defence;
	int accuracy;
	int luck;

	int statPoints;
	int skillPoints;
};

