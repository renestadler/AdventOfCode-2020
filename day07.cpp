#include <regex>
#include <unordered_map>
#include <stack>
#include "day07.h"

long Day07::part_one(std::list<std::string> input) {
	std::regex bags_regex("\\d+ \\w+ \\w+ bags?[,. ]{1,2}");
	std::unordered_map<std::string, std::unordered_map<std::string, int>> bag_groups;
	for (auto elem : input) {
		int idx = elem.find(" bags contain ");
		std::string bag_name = elem.substr(0, idx);
		bag_groups[bag_name] = {};
		std::string bags = elem.substr(idx + 14);
		for (std::sregex_iterator jt(bags.begin(), bags.end(), bags_regex), jt_end; jt != jt_end; ++jt) {
			std::string element = (*jt)[0];
			auto numberpos = element.find(' ', 1);
			int number = std::stoi(element.substr(0, numberpos));
			std::string name = element.substr(numberpos + 1, element.find(" bag") - 2);
			bag_groups[bag_name][name] = number;
		}
	}

	int sum = 0;
	for (auto&& [luggage, bags] : bag_groups) {
		std::stack<std::string> bagsStack;
		bagsStack.push(luggage);
		auto isRunning = true;
		while (!bagsStack.empty() && isRunning) {
			auto bags = bag_groups[bagsStack.top()];
			bagsStack.pop();

			for (auto&& [bag, _] : bags) {
				if (bag == "shiny gold") {
					++sum;
					isRunning = false;
					break;
				}
				else {
					bagsStack.push(bag);
				}
			}
		}
	}

	return sum;
}

long Day07::part_two(std::list<std::string> input) {
	std::regex bags_regex("\\d+ \\w+ \\w+ bags?[,. ]{1,2}");
	std::unordered_map<std::string, std::unordered_map<std::string, int>> bag_groups;
	for (auto elem : input) {
		int idx = elem.find(" bags contain ");
		std::string bag_name = elem.substr(0, idx);
		bag_groups[bag_name] = {};
		std::string bags = elem.substr(idx + 14);
		for (std::sregex_iterator jt(bags.begin(), bags.end(), bags_regex), jt_end; jt != jt_end; ++jt) {
			std::string element = (*jt)[0];
			auto numberpos = element.find(' ', 1);
			int number = std::stoi(element.substr(0, numberpos));
			std::string name = element.substr(numberpos + 1, element.find(" bag") - 2);
			bag_groups[bag_name][name] = number;
		}
	}

	std::stack<std::pair<std::string, int>> bagsStack;
	bagsStack.push({ "shiny gold", 1 });
	int sum = 0;
	while (!bagsStack.empty()) {
		auto bags = bag_groups[bagsStack.top().first];
		auto mult = bagsStack.top().second;
		bagsStack.pop();

		for (auto&& [bag, count] : bags) {
			bagsStack.push({ bag,count * mult });
			sum += mult * count;
		}
	}

	return sum;
}