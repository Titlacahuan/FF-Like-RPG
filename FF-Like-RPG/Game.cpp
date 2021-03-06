#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "characters.txt";
}

Game::~Game()
{
}

void Game::mainMenu()
{
	std::cout << "MAIN MENU" << std::endl << std::endl;

	std::cout << "0: Quit" << std::endl;
	std::cout << "1: Travel" << std::endl;
	std::cout << "2: Shop" << std::endl;
	std::cout << "3: Level Up" << std::endl;
	std::cout << "4: Rest" << std::endl;
	std::cout << "5. Character Sheet" << std::endl;
	std::cout << "6. New Character" << std::endl;
	std::cout << "7. Save Characters" << std::endl;
	std::cout << "8. Load Characters" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "Choice: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice)
	{
	case 0: // Quit
		playing = false;
		break;

	case 1: // Travel
		travel();
		break;

	case 2: // Shop
		std::cout << "Not implemented yet" << std::endl;
		break;

	case 3: // Level Up
		characters[activeCharacter].levelUp();
		break;

	case 4: // Rest
		std::cout << "Not implemented yet" << std::endl;
		break;

	case 5: // Character Sheet
		std::cout << "Character Sheet" << std::endl;
		std::cout << characters[activeCharacter].toString();
		break;

	case 6: // New Character
		std::cin.ignore();
		createNewCharacter();
		saveCharacters();
		break;

	case 7: // Save Characters
		saveCharacters();
		break;

	case 8: // Load Characters
		std::cout << "Not implemented yet" << std::endl;
		break;

	default:
		std::cout << "Invalid choice. Please only select options available from the menu." << std::endl;
		break;
	}
}

void Game::initGame()
{
	createNewCharacter();
}

void Game::createNewCharacter()
{
	std::string name;
	std::cout << "Enter name for character: " << std::endl;
	getline(std::cin, name);

	this->characters.push_back(Character());
	this->activeCharacter = this->characters.size() - 1;
	this->characters[this->activeCharacter].initialize(name);
}

void Game::saveCharacters()
{
	std::ofstream outFile(this->fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < this->characters.size(); i++)
		{
			outFile << this->characters[i].getAsString() << std::endl;
		}

		outFile.close();
	}
}

void Game::loadCharacter()
{
}

void Game::travel()
{
	this->characters[activeCharacter].travel();

	Event ev;

	ev.generateEvent(this->characters[activeCharacter]);
}
