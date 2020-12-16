#pragma once
#include <vector>
#include <string>
#include "day.h"

class Day15 :Day<std::vector<int>, long> {
public:
	long part_one(std::vector<int> input);
	long part_two(std::vector<int> length);
};