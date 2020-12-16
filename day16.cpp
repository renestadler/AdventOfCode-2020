#include <regex>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <stack>
#include "day16.h"

using namespace std;

uint64_t Day16::part_one(list<string> input) {
	vector<pair<int, int>> range;
	for (auto elem : input)
	{
		if (elem == "")
			break;
		else {
			int idx = elem.find(" or ");
			int leftdelim = elem.find(":");
			int middelim = elem.find("-");
			range.push_back(
				pair<int, int>(
					atoi(elem.substr(leftdelim + 2, (middelim - leftdelim)).c_str()),
					atoi(elem.substr(middelim + 1, (idx - middelim)).c_str())
					)
			);

			leftdelim = idx + 4;
			middelim = idx + 4 + elem.substr(idx + 4).find("-");
			range.push_back(
				pair<int, int>(
					atoi(elem.substr(leftdelim, (middelim - leftdelim)).c_str()),
					atoi(elem.substr(middelim + 1).c_str())
					)
			);
		}
	}
	int num = 0;
	int error = 0;
	for (auto elem : input)
	{
		if (elem == "")
			num++;
		if (num >= 2) {
			stringstream ss(elem);
			while (ss.good()) {
				string substr;
				getline(ss, substr, ',');
				int val = atoi(substr.c_str());
				bool one = false;
				for (auto r : range)
					if (val >= r.first && val <= r.second)
						one = true;
				if (!one)
					error += val;
			}
		}
	}
	return error;
}

uint64_t Day16::part_two(list<string> input) {
	vector<pair<int, int>> dep_range;
	vector<pair<int, int>> range;
	for (auto elem : input)
	{
		if (elem == "")
			break;
		else {
			int idx = elem.find(" or ");
			int leftdelim = elem.find(":");
			int middelim = elem.find("-");
			if (elem.rfind("departure", 0) == 0)
				dep_range.push_back(
					pair<int, int>(
						atoi(elem.substr(leftdelim + 2, (middelim - leftdelim)).c_str()),
						atoi(elem.substr(middelim + 1, (idx - middelim)).c_str())
						)
				);
			else
				range.push_back(
					pair<int, int>(
						atoi(elem.substr(leftdelim + 2, (middelim - leftdelim)).c_str()),
						atoi(elem.substr(middelim + 1, (idx - middelim)).c_str())
						)
				);

			leftdelim = idx + 4;
			middelim = idx + 4 + elem.substr(idx + 4).find("-");
			if (elem.rfind("departure", 0) == 0)
				dep_range.push_back(
					pair<int, int>(
						atoi(elem.substr(leftdelim, (middelim - leftdelim)).c_str()),
						atoi(elem.substr(middelim + 1).c_str())
						)
				);
			else
				range.push_back(
					pair<int, int>(
						atoi(elem.substr(leftdelim, (middelim - leftdelim)).c_str()),
						atoi(elem.substr(middelim + 1).c_str())
						)
				);
		}
	}
	int num = 0;
	vector<vector<int>> valid;
	for (auto elem : input)
	{
		if (elem == "") {
			num++;
		}
		else if (num == 1) {
			vector<int> v;
			stringstream ss(elem);
			while (ss.good()) {
				string substr;
				getline(ss, substr, ',');
				int val = atoi(substr.c_str());
				v.push_back(val);
			}
			if (v.size() > 1)
				valid.push_back(v);
		}
		else if (num >= 2) {
			bool all = true;
			stringstream ss(elem);
			vector<int> v;
			while (ss.good() && all) {
				string substr;
				getline(ss, substr, ',');
				int val = atoi(substr.c_str());
				v.push_back(val);
				bool one = false;
				for (auto r : range)
					if (val >= r.first && val <= r.second)
						one = true;
				for (auto r : dep_range)
					if (val >= r.first && val <= r.second)
						one = true;
				if (!one)
					all = false;
			}
			if (all && v.size() > 1) {
				valid.push_back(v);
			}
		}
	}

	vector<vector<int>> allDepPairs;
	if (dep_range.size() != 0) {
		for (int k = 0; k < dep_range.size() - 1; k += 2)
		{
			vector<int> valid_dep_pairs;
			for (int j = 0; j < valid[0].size(); j++) {
				bool all_valid = true;
				for (int i = 0; i < valid.size(); i++) {
					if (!((valid[i][j] >= dep_range[k].first && valid[i][j] <= dep_range[k].second)
						|| (valid[i][j] >= dep_range[k + 1].first && valid[i][j] <= dep_range[k + 1].second)))
						all_valid = false;

				}
				if (all_valid) {
					valid_dep_pairs.push_back(j);
				}
			}
			if (valid_dep_pairs.size() > 0) {
				allDepPairs.push_back(valid_dep_pairs);
			}
		}
	}

	vector<vector<int>> allPairs;
	if (range.size() != 0) {
		for (int k = 0; k < range.size() - 1; k += 2)
		{
			vector<int> valid_pairs;
			for (int j = 0; j < valid[0].size(); j++) {
				bool all_valid = true;
				for (int i = 0; i < valid.size(); i++) {
					if (!((valid[i][j] >= range[k].first && valid[i][j] <= range[k].second)
						|| (valid[i][j] >= range[k + 1].first && valid[i][j] <= range[k + 1].second)))
						all_valid = false;

				}
				if (all_valid) {
					valid_pairs.push_back(j);
				}
			}
			if (valid_pairs.size() > 0) {
				allPairs.push_back(valid_pairs);
			}
		}
	}

	uint64_t mult = 1;
	while (allPairs.size() > 0 || allDepPairs.size() > 0) {
		sort(allPairs.begin(), allPairs.end(), [](const vector<int>& a, const vector<int>& b) { return a.size() < b.size(); });
		sort(allDepPairs.begin(), allDepPairs.end(), [](const vector<int>& a, const vector<int>& b) { return a.size() < b.size(); });
		int val;
		if (allDepPairs.size() != 0 && allDepPairs[0].size() == 1) {
			val = allDepPairs[0][0];
			mult *= valid[0][allDepPairs[0][0]];
			allDepPairs.erase(allDepPairs.begin());
		}
		else if (allPairs.size() != 0) {
			val = allPairs[0][0];
			allPairs.erase(allPairs.begin());
		}

		for (int i = 0; i < allPairs.size(); i++)
		{
			for (int j = 0; j < allPairs[i].size(); j++)
			{
				if (allPairs[i][j] == val) {
					allPairs[i].erase(allPairs[i].begin() + j);
					j--;
				}
			}
			if (allPairs[i].size() == 0)
				allPairs.erase(allPairs.begin() + i);
		}

		for (int i = 0; i < allDepPairs.size(); i++)
		{
			for (int j = 0; j < allDepPairs[i].size(); j++)
			{
				if (allDepPairs[i][j] == val) {
					allDepPairs[i].erase(allDepPairs[i].begin() + j);
					j--;
				}
			}
			if (allDepPairs[i].size() == 0)
				allDepPairs.erase(allDepPairs.begin() + i);
		}
	}
	return mult;
}
