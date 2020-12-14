#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "input.h"

std::list<int> Input::read_numbers(std::string day) {
	std::list<int> values;

	std::ifstream inFile;

	inFile.open("./" + day + ".in");
	std::string line;
	std::getline(inFile, line);
	int x;
	while (std::getline(inFile, line))
	{
		std::stringstream ss;
		ss << line;
		ss >> x;
		values.push_back(x);
	}
	inFile.close();
	return values;
}

std::list<std::string> Input::read_lines(std::string day) {
	std::list<std::string> values;

	std::ifstream inFile;

	inFile.open("./" + day + ".in");
	std::string line;
	std::getline(inFile, line);
	int x;
	while (std::getline(inFile, line))
	{
		values.push_back(line);
	}
	inFile.close();
	return values;
}