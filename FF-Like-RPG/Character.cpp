#include "Character.h"

Character::Character()
{
	this->xPos = 0.0;
	this->yPos = 0.0;
	
	this->distanceTravelled = 0;

	this->gold = 0;
	
	this->name = "NONE";
	this->level = 1;
	this->exp = 0;
	this->expNext = 0;
	
	this->strength;
	this->vitality;
	this->dexterity;
	this->intelligence;
	
	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;

	this->statPoints = 0;
	this->skillPoints = 0;
}

Character::~Character()
{

}

void Character::initialize(const std::string name)
{
	this->distanceTravelled = 0;
	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>((50/3) * ((pow(level, 3) - 6 * pow(level, 2)) + (17 * level - 12)) + 100);
	
	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	this->hpMax = (this->vitality * 2) + (this->strength/2);
	this->hp = hpMax;
	this->staminaMax = this->vitality + (this->strength/2) + (this->dexterity/2);
	this->stamina = staminaMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->defence = this->dexterity + (this->intelligence/2);
	this->accuracy = (this->dexterity / 2);
	this->luck = this->intelligence;
	
	this->statPoints = 0;
	this->skillPoints = 0;
}

std::string Character::toString() const
{
	std::string characterInformation = "";
	std::string sectionSeperator = "";

	for (int i = 0; i < 30; i++)
	{
		sectionSeperator.append("-");
	}
	sectionSeperator.append("\n");

	characterInformation.append(sectionSeperator);
	characterInformation.append(this->name);
	characterInformation.append("\n");
	characterInformation.append(sectionSeperator);
	
	characterInformation.append("Current Position: ( " + std::to_string(this->xPos) + " , " + std::to_string(this->yPos) + " )");
	characterInformation.append("\n");
	characterInformation.append(sectionSeperator);

	characterInformation.append("Level: " + std::to_string(this->level));
	characterInformation.append("\n");
	characterInformation.append("Current Experience: " + std::to_string(this->exp));
	characterInformation.append("\n");
	characterInformation.append("Experience Needed to Level: " + std::to_string(this->expNext));
	characterInformation.append("\n");
	characterInformation.append(sectionSeperator);

	characterInformation.append("Strength: " + std::to_string(this->strength));
	characterInformation.append("\n");
	characterInformation.append("Vitality: " + std::to_string(this->vitality));
	characterInformation.append("\n");
	characterInformation.append("Dexterity: " + std::to_string(this->dexterity));
	characterInformation.append("\n");
	characterInformation.append("Intelligence: " + std::to_string(this->intelligence));
	characterInformation.append("\n");
	characterInformation.append(sectionSeperator);

	characterInformation.append("Health Points (HP): " + std::to_string(this->hp) + '/' + std::to_string(this->hpMax));
	characterInformation.append("\n");
	characterInformation.append("Stamina: " + std::to_string(this->stamina) + '/' + std::to_string(this->staminaMax));
	characterInformation.append("\n");
	characterInformation.append("Damage: " + std::to_string(this->damageMin) + '-' + std::to_string(this->damageMax));
	characterInformation.append("\n");
	characterInformation.append("Defence: " + std::to_string(this->defence));
	characterInformation.append("\n");
	characterInformation.append("Accuracy: " + std::to_string(this->accuracy));
	characterInformation.append("\n");
	characterInformation.append(sectionSeperator);

	return characterInformation;
}

std::string Character::getAsString() const
{
	return std::to_string(this->xPos) + " "
		+ std::to_string(this->yPos) + " "
		+ this->name + " "
		+ std::to_string(this->level) + " "
		+ std::to_string(this->exp) + " "
		+ std::to_string(this->strength) + " "
		+ std::to_string(this->vitality) + " "
		+ std::to_string(this->dexterity) + " "
		+ std::to_string(this->intelligence) + " "
		+ std::to_string(this->hp) + " "
		+ std::to_string(this->stamina) + " "
		+ std::to_string(this->statPoints) + " "
		+ std::to_string(this->skillPoints);
}

void Character::levelUp()
{
	while (this->exp >= this->expNext)
	{
		this->exp -= this->expNext;
		this->level++;
		this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2)) + (17 * level - 12)));

		this->statPoints++;
		this->skillPoints++;
	}
}
