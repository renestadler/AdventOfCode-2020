#pragma once
#include <list>
#include <string>
#include "day.h"

class Day10 :Day<std::list<int>, int64_t> {
public:
	int64_t part_one(std::list<int> input);
	int64_t part_two(std::list<int> length);
};