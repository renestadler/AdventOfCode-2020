#pragma once
#include <list>
#include <string>
#include "day.h"

class Day25 :Day<std::list<int>, long> {
public:
	long part_one(std::list<int> input);
	long part_two(std::list<int> input);
};
