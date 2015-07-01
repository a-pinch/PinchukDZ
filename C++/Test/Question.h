#pragma once
#include <string>
#include <vector>
#include "Answer.h"
class Question
{
private:	
	static std::vector<Question> Question::questions;
public:
	std::string text;
	std::vector<Answer> answers;
	static void init(std::string fileName);
	Question(std::string &text_) : text(text_) {}
	static std::vector<Question>::iterator begin() { return questions.begin(); }
	static std::vector<Question>::iterator end() { return questions.end(); }
};

