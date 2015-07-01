#pragma once
#include "Ratee.h"
#include "Question.h"
#include <vector>

// тест, проходимый конкретным испытуемым
class Test
{
public:
	// объект-испытуемый
	Ratee r;
	// итератор на текущий вопрос, который будет задан
	std::vector<Question>::iterator current_question;
	int current_question_num;
	// если все вопросы отвечены, то показать результат теста
	void show_result();
	// задать очередной вопрос
	void ask();
	bool isFinished() {
		return current_question == Question::end();
	}

	Test(std::string& name_) : r(name_), current_question(Question::begin()), current_question_num(0) {}
};
