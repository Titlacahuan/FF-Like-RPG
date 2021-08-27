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
	inline const int& answerSize() const { return this->answers.size(); };

	// Functions
	std::string toString();


private:
	std::string question;
	std::vector<std::string> answers;
	int correctAnswer;

};