#include "Puzzle.h"

Puzzle::Puzzle(std::string fileName)
{
	std::ifstream inFile(fileName);
	std::string answer = "";
	int numOfAns = 0;

	if (inFile.is_open())
	{
		std::getline(inFile, this->question);
		inFile >> numOfAns;
		inFile.ignore();
		
		for (size_t i = 0; i < numOfAns; i++)
		{
			std::getline(inFile, answer);
			this->answers.push_back(answer);
		}

		inFile >> this->correctAnswer;
		inFile.ignore();

		inFile.close();
	}
}

Puzzle::~Puzzle()
{

}

std::string Puzzle::askQuestion()
{
	std::string str = "";

	str += this->question + "\n";
	for (size_t i = 0; i < answers.size(); i++)
	{
		str += std::to_string(i) + ": " + answers[i] + "\n";
	}

	return str;
}

std::string Puzzle::toString()
{
	std::string str = "";

	str += this->question + "\n";
	for (size_t i = 0; i < answers.size(); i++)
	{
		str += std::to_string(i) + ": " + answers[i] + "\n";
	}

	str += "Correct answer: " + std::to_string(this->correctAnswer) + "\n";

	return str;
}

bool Puzzle::isUserAbleToTry(int& userTry)
{
	bool userIsAbleToTry = true;

	if (userTry > this->maxTries)
	{
		userIsAbleToTry = false;
	}

	return userIsAbleToTry;
}