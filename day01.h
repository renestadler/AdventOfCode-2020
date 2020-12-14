#pragma once
#include <list>
#include "day.h"

class Day01 :Day<std::list<int>, long> {
public:
	long part_one(std::list<int> input);
	long part_two(std::list<int> length);
};