#pragma once

#include <stdlib.h>
#include "Character.h"
#include "Puzzle.h"

class Event
{

public:
	Event();
	virtual ~Event();

	void generateEvent(Character& character);
	void enemyEncounter(Character& character);
	void puzzleEncounter(Character& character);

private:
	int numOfEvents;

};