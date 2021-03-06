#pragma once
#include <list>
#include <string>
#include "day.h"

class Day04 :Day<std::list<std::string>, long> {
public:
	long part_one(std::list<std::string> input);
	long part_two(std::list<std::string> length);
};