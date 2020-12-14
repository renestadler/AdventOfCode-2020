#include <regex>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include "day10.h"

using namespace std;

int64_t Day10::part_one(list<int> input) {
	vector<int> v{ begin(input), end(input) };
	sort(v.begin(), v.end());
	int num1 = v[0] == 1 ? 1 : 0, num3 = v[0] == 3 ? 2 : 1;
	for (int i = 0; i < v.size() - 1; i++)
	{
		if ((v[i + 1] - v[i]) == 1)
			num1++;
		if ((v[i + 1] - v[i]) == 3)
			num3++;
	}
	return num1 * num3;
}

int64_t Day10::part_two(list<int> input) {
	input.push_front(0);
	vector<int> v{ begin(input), end(input) };
	sort(v.begin(), v.end());
	long sum = 1;
	vector<int64_t>paths;
	paths.resize(v.size());
	paths[v.size() - 1] = 1;
	for (int i = v.size() - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < v.size() && (v[j] - v[i]) < 4; j++) {
			paths[i] += paths[j];
		}
	}
	return paths[0];
}