#include "Test.h"
#include "Question.h"
#include "Trait.h"
#include <iostream>
#include <vector>

void Test::ask(){
	int answer;
	std::cout << "\n" << ++current_question_num << current_question->text << ": " << std::endl;
	for (size_t i = 0; i < current_question->answers.size(); i++){
		std::cout << "\t" << current_question->answers[i].text << std::endl;
	}
	std::cout << "Input answer: " << std::endl;
	std::cin >> answer;
	for (std::map<trait_numb, int>::iterator it = current_question->answers[answer].points.begin(); it != current_question->answers[answer].points.end(); ++it){
		std::map<trait_numb, int>::iterator itr = r.result.find(it->first);
		if (itr != r.result.end()){
			itr->second += it->second;
		}else{
			r.result[it->first] = it->second;
		}
	}
}

void Test::show_result(){
	std::cout << "\n Results:" << std::endl;
	for (trait_numb i = 0; i < Trait::traits.size(); ++i){
		std::map<trait_numb, int>::iterator it = r.result.find(i);
		if (it != r.result.end()){
			std::cout << i << "; " << Trait::traits[i].name << ": " << it->second << std::endl;
		}
	}
}