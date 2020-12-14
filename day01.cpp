#include "day01.h"

long Day01::part_one(std::list<int> input) {
	for (auto first = input.begin(); first != input.end(); ++first)
	{
		for (auto second = input.begin(); second != input.end(); ++second)
		{
			if (first != second && (*first) + (*second) == 2020) {
				return (*first) * (*second);
			}
		}
	}
	return -1;
}

long Day01::part_two(std::list<int> input) {
	for (auto first = input.begin(); first != input.end(); ++first)
	{
		for (auto second = input.begin(); second != input.end(); ++second)
		{
			for (auto third = input.begin(); third != input.end(); ++third)
			{
				if (first != second && second != third && (*first) + (*second) + (*third) == 2020) {
					return (*first) * (*second) * (*third);
				}
			}
		}
	}
	return -1;
}