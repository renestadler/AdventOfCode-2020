#include <regex>
#include <unordered_map>
#include <stack>
#include "day09.h"

using namespace std;

long Day09::part_one(list<int> input) {
	std::vector<int> v{ std::begin(input), std::end(input) };
	int preamble = v.size() >= 25 ? 25 : 5;
	for (int i = preamble; i < v.size(); i++)
	{
		bool found = false;
		for (int j = i - preamble; j < i; j++)
		{
			for (int k = i - preamble; k < i; k++)
			{
				if (v[i] == v[j] + v[k])
					found = true;
			}
		}
		if (!found)
			return v[i];
	}
	return -1;
}

long Day09::part_two(list<int> input) {
	int num = part_one(input);
	std::vector<int> v{ std::begin(input), std::end(input) };
	int preamble = v.size() >= 25 ? 25 : 5;
	int sum = 0;
	int start = 0;
	for (int i = start; i < v.size(); i++)
	{
		sum += v[i];
		if (sum == num) {
			int min = INT_MAX;
			int max = INT_MIN;
			for (int j = start; j < i; j++)
			{
				if (v[j] > max)
					max = v[j];
				if (v[j] < min)
					min = v[j];
			}
			return min + max;
		}
		else if (sum > num) {
			i = start;
			start++;
			sum = 0;
		}
	}
	return -1;
}