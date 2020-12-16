#pragma once
#include <list>
#include <string>
#include "day.h"

class Day14 :Day<std::list<std::string>, int64_t> {
public:
	int64_t part_one(std::list<std::string> input);
	int64_t part_two(std::list<std::string> length);
};