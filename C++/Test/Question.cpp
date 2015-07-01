#include <string>
#include <fstream>
#include <sstream>
#include "Question.h"

std::vector<Question> Question::questions;


void Question::init(std::string fileName)
{
	std::string buffer, temp;
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
		throw std::exception("Error: file(Question.csv) is not opened!\n");
	int counter = 0, number;
	while (!file.eof())
	{
		std::getline(file, buffer);
		std::stringstream ss(buffer);
		ss >> number; // next character after number

		if (counter == number)
		{
			// now buffer contains  smth. like "00;Question"
			auto position = buffer.find(';');
			auto last_pos = buffer.size() - position - 1;
			temp = buffer.substr(position + 1, last_pos);
			Question q(temp);
			questions.push_back(q);
			counter++;
		}
		else
			throw std::exception("Error: file(Question.csv) content!\n");

	}
	file.close();
}

// 'tghuihiu';7;'nbhj'
std::vector<std::string> ParsCSVString(std::string &str)
{
	std::vector<std::string> result;
	auto size = str.size() - 1;
	auto position = str.find(';');
	while (position != size)
	{
		size = str.size() - 1;
		position = str.find(';');
		str = str.substr(position + 1, size - position);
		size = str.size() - 1;
		position = str.find(';');
		result.push_back(str.substr(0, position));
		if (position != size)
			str = str.substr(position + 1, size - position);
	}
	return result;
}