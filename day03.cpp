#include <sstream>
#include <vector>
#include "day03.h"

long Day03::part_one(std::list<std::string> input) {
	std::vector<std::string> vector;
	for (auto var : input)
	{
		vector.push_back(var);
	}
	int num_trees = 0, cur_x = 0, cur_y = 0;
	while (cur_y < vector.size()) {
		if (vector[cur_y][cur_x] == '#') {
			num_trees++;
		}
		cur_x = (cur_x + 3) % vector[0].length();
		cur_y++;
	}
	return num_trees;
}

long Day03::part_two(std::list<std::string> input) {
	std::vector<std::string> vector;
	for (auto var : input)
	{
		vector.push_back(var);
	}
	int cur_x = 0, cur_y = 0;
	long num_trees = 0;
	while (cur_y < vector.size()) {
		if (vector[cur_y][cur_x] == '#') {
			num_trees++;
		}
		cur_x = (cur_x + 1) % vector[0].length();
		cur_y += 2;
	}
	long total_product = num_trees;
	for (int i = 1; i <= 7; i += 2) {
		cur_x = 0, cur_y = 0;
		num_trees = 0;
		while (cur_y < vector.size()) {
			if (vector[cur_y][cur_x] == '#') {
				num_trees++;
			}
			cur_x = (cur_x + i) % vector[0].length();
			cur_y++;
		}
		total_product *= num_trees;
	}
	return total_product;
}