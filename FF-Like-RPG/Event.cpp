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
	int i = rand() % this->numOfEvents;

	switch (i)
	{
	case 0:
		// Enemy encounter
		break;
	case 1:
		// Puzzle
		break;
	case 2:
		break;
	default:
		break;
	}
}

void Event::enemyEncounter(Character& character)
{

}

void Event::puzzleEncounter(Character& character)
{
	
}