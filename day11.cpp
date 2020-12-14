#include <regex>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include "day11.h"

using namespace std;

long Day11::part_one(list<string> input) {
	vector<string> v{ begin(input), end(input) };
	string last;
	while (true) {
		vector<string> new_vector;
		for (int i = 0; i < v.size(); i++) {
			new_vector.push_back(string(v[i]));
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].length(); j++) {
				if (v[i][j] == '.')
					continue;
				int num = 0;
				if (i > 0 && j > 0 && v[i - 1][j - 1] == '#') {
					num++;
				}
				if (i > 0 && v[i - 1][j] == '#') {
					num++;
				}
				if (j > 0 && v[i][j - 1] == '#') {
					num++;
				}
				if (i < (v.size() - 1) && j < (v[i].length() - 1) && v[i + 1][j + 1] == '#') {
					num++;
				}
				if (i < (v.size() - 1) && v[i + 1][j] == '#') {
					num++;
				}
				if (j < (v[i].length() - 1) && v[i][j + 1] == '#') {
					num++;
				}
				if (i < (v.size() - 1) && j > 0 && v[i + 1][j - 1] == '#') {
					num++;
				}
				if (i > 0 && j < (v[i].length() - 1) && v[i - 1][j + 1] == '#') {
					num++;
				}
				if (num >= 4) {
					new_vector[i][j] = 'L';
				}
				else if (num == 0) {
					new_vector[i][j] = '#';
				}
			}
		}
		string new_string;
		if (new_vector == v) {
			int num_elem = 0;
			for (int i = 0; i < v.size(); i++)
				for (int j = 0; j < v[0].length(); j++)
					if (v[i][j] == '#')
						num_elem++;
			return num_elem;
		}
		v = new_vector;
	}
	return -1;
}

long Day11::part_two(list<string> input) {
	vector<string> v{ begin(input), end(input) };
	string last;
	while (true) {
		vector<string> new_vector;
		for (int i = 0; i < v.size(); i++) {
			new_vector.push_back(string(v[i]));
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].length(); j++) {
				if (v[i][j] == '.')
					continue;
				int num = 0;
				int offseti = 1, offsetj = 1;
				while (i - offseti >= 0 && j - offsetj >= 0) {
					if (v[i - offseti][j - offsetj] == '.')
						offseti++, offsetj++;
					else if (v[i - offseti][j - offsetj] == '#') {
						num++;
						break;
					}
					else {
						break;
					}
				}
				offseti = 1;
				while (i - offseti >= 0) {
					if (v[i - offseti][j] == '.')
						offseti++;
					else if (v[i - offseti][j] == '#') {
						num++;
						break;
					}
					else {
						break;
					}
				}
				offsetj = 1;
				while (j - offsetj >= 0) {
					if (v[i][j - offsetj] == '.')
						offsetj++;
					else if (v[i][j - offsetj] == '#') {
						num++;
						break;
					}
					else {
						break;
					}
				}
				offseti = 1, offsetj = 1;
				while (i + offseti < v.size() && j + offsetj < v[i].length()) {
					if (v[i + offseti][j + offsetj] == '.')
						offseti++, offsetj++;
					else if (v[i + offseti][j + offsetj] == '#') {
						num++;
						break;
					}
					else {
						break;
					}
				}
				offseti = 1;
				while (i + offseti < v.size()) {
					if (v[i + offseti][j] == '.')
						offseti++;
					else if (v[i + offseti][j] == '#') {
						num++;
						break;
					}
					else {
						break;
					}
				}
				offsetj = 1;
				while (j + offsetj < v[i].length()) {
					if (v[i][j + offsetj] == '.')
						offsetj++;
					else if (v[i][j + offsetj] == '#') {
						num++;
						break;
					}
					else {
						break;
					}
				}
				offseti = 1, offsetj = 1;
				while (i + offseti < v.size() && j - offsetj >= 0) {
					if (v[i + offseti][j - offsetj] == '.')
						offseti++, offsetj++;
					else if (v[i + offseti][j - offsetj] == '#') {
						num++;
						break;
					}
					else {
						break;
					}
				}
				offseti = 1, offsetj = 1;
				while (i - offseti >= 0 && j + offsetj < v[i].length()) {
					if (v[i - offseti][j + offsetj] == '.')
						offseti++, offsetj++;
					else if (v[i - offseti][j + offsetj] == '#') {
						num++;
						break;
					}
					else {
						break;
					}
				}
				if (num >= 5) {
					new_vector[i][j] = 'L';
				}
				else if (num == 0) {
					new_vector[i][j] = '#';
				}
			}
		}
		string new_string;
		if (new_vector == v) {
			int num_elem = 0;
			for (int i = 0; i < v.size(); i++)
				for (int j = 0; j < v[0].length(); j++)
					if (v[i][j] == '#')
						num_elem++;
			return num_elem;
		}
		v = new_vector;
	}
	return -1;
}
