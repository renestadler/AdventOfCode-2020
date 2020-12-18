#pragma once
#include <list>
#include <string>
#include "day.h"

class Day18 :Day<std::list<std::string>, std::string> {
public:
	std::string part_one(std::list<std::string> input);
	std::string part_two(std::list<std::string> length);
};
