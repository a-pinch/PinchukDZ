#include "Test.h"
#include <vector>
#include <fstream>
#include <string>
#include "Question.h"
#include <sstream>
#include "ParseCSVString.h"
#include "Profession.h"
#include "Trait.h"
#include <iostream>
#include <map>
#include "Answer.h"


// ????????????????????????????
std::vector<Question> Test::questions;


// ????????????????????????????

void Test::LoadQuestions()
{
    // check
    if (questions.size())
        return;

	std::string buffer, number;
	std::ifstream file;
	file.open("../Data/Questions.csv");
	if (!file.is_open())
		throw std::exception("Error: file(Question.csv) is not opened!\n");
	int counter = 0, question_num;

	while (!file.eof())
	{
		std::getline(file, buffer);
		std::vector<std::string> data = ParseCSVString(buffer);
        if (!data.size())
            break;
	
		number = data[0];
		std::stringstream ss(number);
		ss >> question_num;
		if (counter == question_num)
		{
			Question q(data[1]);
			questions.push_back(q);
			counter++;
		}
		else
		{
			file.close();
			throw std::exception("Error: file(Question.csv) content!\n");
		}
	}
	file.close();

}






void Test::LoadAnswers()
{
	std::string buffer, number;
	std::ifstream file;

	file.open("../Data/Answers.csv");
	if (!file.is_open())
		throw std::exception("Error: file(Question.csv) is not opened!\n");

	int question_num;
	while (!file.eof())
	{
		std::getline(file, buffer);
		std::vector<std::string> data = ParseCSVString(buffer);
		if (!data.size())
			break;

		number = data[0];
		std::stringstream ss(number);
		ss >> question_num;

		Answer answer(data[1]);
		for (auto it = data.begin() + 2; it != data.end(); it++)
		{
			// read trait number
			int trait_, score_;
			number = *it;
			std::stringstream ss1(number);
			ss1 >> trait_;

			//read score
			it++;

			number = *it;
			std::stringstream ss2(number);
			ss2 >> score_;
			answer.AddPoint(trait_, score_);
		}
		questions[question_num].answers.push_back(answer);
	}
	file.close();
}





void Test::AskQuestion()
{
    // ASK QUESTION

    std::cout << questions[current_question].question << std::endl;
    // output annswer options for this question
    int answer_num = 1;
    for (auto it = questions[current_question].answers.begin();
		it != questions[current_question].answers.end(); it++, answer_num++)
        std::cout << answer_num << it->answer << std::endl;
    // processing answer
    std::string ratee_response;
	bool flag;
	do{
		flag = false;
		std::getline(std::cin, ratee_response);
		for (int i = 0; i < ratee_response.length(); ++i){
			if (ratee_response[i] <= '0' || ratee_response[i] - '0' > answer_num - 1){
				std::cout << "You enter invalid number! Try again!" << std::endl;
				flag = true;
				break;
			}else{
				// PROCESSING RESULT

				auto points = ((questions[current_question]).answers)[ratee_response[i] - '0' - 1].points;

				for (auto it = points.begin(); it != points.end(); it++)
					human.result[it->first] += it->second;
			}
		}
	} while (flag);
    current_question++;
}

void Test::ShowResult()
{
    int prof_number = 0;
    for (auto &pr: Profession::professions)
    {
        // ????????????????????????????????????????
        human.final_result[prof_number] = 0;
        for (auto &tr: pr.traits)
            human.final_result[prof_number] += human.result[tr];
		prof_number++;
    }
    
	std::multimap<int, trait_numb> reverseResult = human.reverseResult();
	std::cout << "Your traits:" << std::endl;	
	
	for (auto it = reverseResult.rbegin(); it != reverseResult.rend(); ++it){
		std::cout << Trait::traits[it->second].name << ": " << it->first << std::endl;
	}

	
	std::cout << "\nYour Professions:" << std::endl;
	std::multimap<int, trait_numb> reverseFinalResult = human.reverseFinalResult();
    size_t profession_number;
    for (auto it = reverseFinalResult.rbegin(); it != reverseFinalResult.rend(); it++)
    {
        profession_number = it->second;
        std::cout << Profession::professions[profession_number].name << ": " << it->first << std::endl;
    }
	
}