#pragma once
#include <list>
#include <string>
#include "day.h"

class Day20 :Day<std::list<std::string>, uint64_t> {
public:
	uint64_t part_one(std::list<std::string> input);
	uint64_t part_two(std::list<std::string> length);
};
