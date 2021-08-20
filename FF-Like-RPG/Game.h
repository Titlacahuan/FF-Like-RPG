#pragma once

#include <ctime>
#include <vector>
#include <fstream>
#include "Character.h"

class Game
{

public:
	Game();
	virtual ~Game();

	// Operators

	// Functions
	void mainMenu();
	void initGame();
	void createNewCharacter();
	void saveCharacters();
	void loadCharacter();
	void travel();

	// Accessors
	inline bool getPlaying() const { return this->playing; }

	// Modifiers

private:
	int choice;
	bool playing;

	// Character
	int activeChar;
	std::vector<Character> characters;
	std::string fileName;
};

