#include <regex>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include "day13.h"

using namespace std;

uint64_t Day13::part_one(list<string> input) {
	long val = atol(input.front().c_str());
	string cur = input.back();
	long min_diff = LONG_MAX;
	long min_id;
	while (cur.find(',') != -1) {
		if (cur.substr(0, cur.find(',')) != "x") {
			long cur_val = atol(cur.substr(0, cur.find(',')).c_str());
			if (cur_val - (val % cur_val) < min_diff) {
				min_diff = cur_val - (val % cur_val);
				min_id = cur_val;
			}
		}
		cur = cur.substr(cur.find(',') + 1);
	}
	long cur_val = atol(cur.substr(0).c_str());
	if (val % cur_val < min_diff) {
		min_diff = val % cur_val;
		min_id = cur_val;
	}
	return min_diff * min_id;
}

uint64_t Day13::part_two(list<string> input) {
	long val = atol(input.front().c_str());
	string cur = input.back();
	vector<int> ids;
	while (cur.find(',') != -1) {
		if (cur.substr(0, cur.find(',')) != "x") {
			ids.push_back(atol(cur.substr(0, cur.find(',')).c_str()));
		}
		else {
			ids.push_back(1);
		}
		cur = cur.substr(cur.find(',') + 1);
	}
	if (cur.substr(0, cur.find(',')) != "x") {
		ids.push_back(atol(cur.substr(0, cur.find(',')).c_str()));
	}
	else {
		ids.push_back(1);
	}
	uint64_t result = 0;
	uint64_t incr = 1;
	for (int j = 0; j < ids.size(); j++) {
		while ((result + j) % ids[j] != 0) {
			result += incr;
		}
		incr *= ids[j];
	}
	return result;
}