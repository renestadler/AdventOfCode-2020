#include "day05.h"
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

long Day05::part_one(std::list<std::string> input) {
	int highest_seed = 0;
	for (auto elem : input) {
		int num = 0;
		for (int i = 0; i < 10; i++)
		{
			num *= 2;
			if (elem[i] == 'B') {
				num += 1;
			}
			if (elem[i] == 'R') {
				num += 1;
			}
		}
		if (num > highest_seed)
			highest_seed = num;
	}
	return highest_seed;
}

long Day05::part_two(std::list<std::string> input) {
	int min = 100000;
	int max = 0;
	int total = 0;
	for (auto elem : input) {
		int num = 0;
		for (int i = 0; i < 10; i++)
		{
			num *= 2;
			if (elem[i] == 'B') {
				num += 1;
			}
			if (elem[i] == 'R') {
				num += 1;
			}
		}
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		total += num;
	}
	int sum = (max - min + 1) * (min + max) / 2;
	return sum - total;
}