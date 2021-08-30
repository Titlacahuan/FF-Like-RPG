#pragma once

#include <string>
#include <vector>
#include <fstream>

class Puzzle
{

public:
	Puzzle(std::string fileName);
	virtual ~Puzzle();

	// Accessors
	inline const int& answerSize() const { return this->answers.size(); }
	inline const int& getCorrectAns() const { return this->correctAnswer; }
	inline const int& getMaxTries() const { return this->maxTries; }

	// Functions
	std::string askQuestion();
	std::string toString();
	bool isUserAbleToTry(int& userTry);


private:
	std::string question;
	std::vector<std::string> answers;
	int correctAnswer;
	const int maxTries = 3;
};