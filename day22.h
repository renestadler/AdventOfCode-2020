#pragma once
#include <list>
#include <string>
#include "day.h"

class Day22 :Day<std::list<std::string>, long> {
public:
	long part_one(std::list<std::string> input);
	long part_two(std::list<std::string> input);
};
