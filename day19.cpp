#include <regex>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <boost/regex.hpp>
#include "day19.h"

using namespace std;

string create_regex(const unordered_map<int, string>& rules, int cur = 0, bool second = false) {
	if (second)
	{
		switch (cur)
		{
		case 8:
		{
			return '(' + create_regex(rules, 42, second) + "+)";
		}
		case 11:
		{
			string cur_line;
			cur_line += '(';
			for (int i = 2; i < 10; ++i)
			{
				cur_line +=
					create_regex(rules, 42, second) + '{' + to_string(i) + '}'
					+ create_regex(rules, 31, second) + '{' + to_string(i) + '}' + '|';
			}
			cur_line += create_regex(rules, 42, second) + create_regex(rules, 31, second) + ')';
			return cur_line;
		}
		}
	}
	stringstream rule_to_parse(rules.at(cur));
	string result;
	string cur_string;
	while (rule_to_parse >> cur_string)
	{
		if (isdigit(cur_string[0]))
		{
			result += create_regex(rules, stoi(cur_string), second);
		}
		else result += cur_string;
	}
	return '(' + result + ')';
}

long Day19::part_one(list<string> input) {
	bool first = true;
	int a = 0;
	int b = 0;
	unordered_map<int, string> formatted_input;
	vector<string> elems;
	for (auto line : input) {
		if (line == "")
			first = false;
		if (first) {
			int idx = atoi(line.substr(0, line.find(":")).c_str());
			string cur = line.substr(line.find(":") + 2);
			cur.erase(remove(cur.begin(), cur.end(), '\"'), cur.end());
			formatted_input.insert(pair(idx, cur));
		}
		else {
			elems.push_back(line);
		}
	}
	const boost::regex r(create_regex(formatted_input, 0, false));
	long result = 0;
	for (string s: elems)
	{
		result += boost::regex_match(s, r);
	}
	return result;
}

long Day19::part_two(list<string> input) {
	bool first = true;
	int a = 0;
	int b = 0;
	unordered_map<int, string> formatted_input;
	vector<string> elems;
	for (auto line : input) {
		if (line == "")
			first = false;
		if (first) {
			int idx = atoi(line.substr(0, line.find(":")).c_str());
			string cur = line.substr(line.find(":") + 2);
			cur.erase(remove(cur.begin(), cur.end(), '\"'), cur.end());
			formatted_input.insert(pair(idx, cur));
		}
		else {
			elems.push_back(line);
		}
	}
	const boost::regex r(create_regex(formatted_input, 0, true));
	long result = 0;
	for (string s : elems)
	{
		result += boost::regex_match(s, r);
	}
	return result;
}
