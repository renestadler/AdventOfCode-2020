#include <regex>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <map>
#include "day15.h"

using namespace std;

long Day15::part_one(vector<int> input) {
	map<int, int> elems;
	int lastNum = 0;
	for (int i = 0; i < 2020; i++)
	{
		if (i < input.size()) {
			if (i != 0)
				elems[lastNum] = i;
			lastNum = input[i];
		}
		else {
			if (elems.count(lastNum) == 0) {
				elems[lastNum] = i;
				lastNum = 0;
			}
			else {
				auto elem = elems.find(lastNum);
				int temp = (i)-elem->second;
				elems[lastNum] = i;
				lastNum = temp;
			}
		}
	}
	return lastNum;
}

long Day15::part_two(vector<int> input) {
	unordered_map<int, int> elems;
	int lastNum = 0;
	for (int i = 0; i < input.size(); i++) {

		if (i != 0)
			elems[lastNum] = i;
		lastNum = input[i];
	}
	for (int i = input.size(); i < 30000000; i++)
	{
		if (elems.find(lastNum) == elems.end()) {
			elems[lastNum] = i;
			lastNum = 0;
		}
		else {
			auto elem = elems.find(lastNum);
			int temp = (i)-elem->second;
			elems[lastNum] = i;
			lastNum = temp;
		}
	}
	return lastNum;
}