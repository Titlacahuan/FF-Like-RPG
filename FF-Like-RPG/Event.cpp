#include "Event.h"

Event::Event() 
{
	this->numOfEvents = 2;
}

Event::~Event()
{

}

void Event::generateEvent(Character& character)
{
	//int i = rand() % this->numOfEvents;
	int i = 1;

	switch (i)
	{
	case 0:
		// Enemy encounter
		break;
	case 1:
		// Puzzle
		this->puzzleEncounter(character);
		break;
	case 2:
		break;
	default:
		break;
	}
}

void Event::enemyEncounter(Character& character)
{
	// while()
}

void Event::puzzleEncounter(Character& character)
{
	bool completed = false;
	int userAns = 0;
	int userTry = 1;
	Puzzle puzzle("Puzzles\\1.txt");

	while (!completed && puzzle.isUserAbleToTry(userTry))
	{
		std::cout << puzzle.askQuestion();

		std::cout << "\nCurrent try: " << std::to_string(userTry) << " / " << std::to_string(puzzle.getMaxTries()) << std::endl;
		std::cout << "Your answer: ";
		std::cin >> userAns;
		std::cout << std::endl;

		if (puzzle.getCorrectAns() == userAns)
		{
			completed = true;
		}

		userTry++;
	}

	if (completed)
	{
		std::cout << "\nYou got the right answer!" << std::endl;
		// Give user exp, etc and continue
	}
	else
	{
		std::cout << "\nYou failed the puzzle!" << std::endl;
	}
}