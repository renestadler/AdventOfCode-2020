#pragma once
#include <list>
#include <string>

class Input {
public:
	std::list<int> read_numbers(std::string day);
	std::list<std::string> read_lines(std::string day);
};