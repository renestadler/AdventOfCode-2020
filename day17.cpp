#include <regex>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <stack>
#include "day17.h"

using namespace std;

long Day17::part_one(list<string> input) {
	int i = 0, j = 0;
	vector<string> active_pos;
	for (string s : input)
	{
		j = 0;
		for (char c : s) {
			if (c == '#')
				active_pos.push_back(to_string(i) + "," + to_string(j) + ",0");
			j++;
		}
		i++;
	}
	for (int i = 0; i < 6; i++)
	{
		unordered_map<string, int> new_posses;
		for (string pos : active_pos) {
			string cur = pos;
			int x = atoi(cur.substr(0, cur.find(",")).c_str());
			cur = cur.substr(cur.find(",") + 1);
			int y = atoi(cur.substr(0, cur.find(",")).c_str());
			cur = cur.substr(cur.find(",") + 1);
			int z = atoi(cur.c_str());
			for (int j = -1; j < 2; j++)
			{
				for (int k = -1; k < 2; k++)
				{
					for (int l = -1; l < 2; l++)
					{
						if (!(j == 0 && k == 0 && l == 0)) {
							string elem = to_string(x + j) + "," + to_string(y + k) + "," + to_string(z + l);
							if (new_posses.find(elem) == new_posses.end()) {
								new_posses.insert(pair(elem, 1));
							}
							else {
								new_posses.insert_or_assign(elem, new_posses.at(elem) + 1);
							}
						}
					}
				}
			}
		}

		vector<string> new_active_pos;
		for (auto elem : new_posses)
		{
			if (count(active_pos.begin(), active_pos.end(), elem.first)) {
				if (elem.second == 2 || elem.second == 3) {
					new_active_pos.push_back(elem.first);
				}
			}
			else {
				if (elem.second == 3) {
					new_active_pos.push_back(elem.first);
				}
			}
		}
		active_pos.clear();
		active_pos.insert(active_pos.end(), new_active_pos.begin(), new_active_pos.end());
	}

	return active_pos.size();
}

long Day17::part_two(list<string> input) {
	int i = 0, j = 0;
	vector<string> active_pos;
	for (string s : input)
	{
		j = 0;
		for (char c : s) {
			if (c == '#')
				active_pos.push_back(to_string(i) + "," + to_string(j) + ",0,0");
			j++;
		}
		i++;
	}
	for (int i = 0; i < 6; i++)
	{
		unordered_map<string, int> new_posses;
		for (string pos : active_pos) {
			string cur = pos;
			int w = atoi(cur.substr(0, cur.find(",")).c_str());
			cur = cur.substr(cur.find(",") + 1);
			int x = atoi(cur.substr(0, cur.find(",")).c_str());
			cur = cur.substr(cur.find(",") + 1);
			int y = atoi(cur.substr(0, cur.find(",")).c_str());
			cur = cur.substr(cur.find(",") + 1);
			int z = atoi(cur.c_str());
			for (int j = -1; j < 2; j++)
			{
				for (int k = -1; k < 2; k++)
				{
					for (int l = -1; l < 2; l++)
					{
						for (int m = -1; m < 2; m++)
						{
							if (!(j == 0 && k == 0 && l == 0 && m == 0)) {
								string elem = to_string(w + j) + "," + to_string(x + k) + "," + to_string(y + l) + "," + to_string(z + m);
								if (new_posses.find(elem) == new_posses.end()) {
									new_posses.insert(pair(elem, 1));
								}
								else {
									new_posses.insert_or_assign(elem, new_posses.at(elem) + 1);
								}
							}

						}
					}
				}
			}
		}

		vector<string> new_active_pos;
		for (auto elem : new_posses)
		{
			if (count(active_pos.begin(), active_pos.end(), elem.first)) {
				if (elem.second == 2 || elem.second == 3) {
					new_active_pos.push_back(elem.first);
				}
			}
			else {
				if (elem.second == 3) {
					new_active_pos.push_back(elem.first);
				}
			}
		}
		active_pos.clear();
		active_pos.insert(active_pos.end(), new_active_pos.begin(), new_active_pos.end());
	}

	return active_pos.size();
}
