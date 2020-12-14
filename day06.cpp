#include "day06.h"

long Day06::part_one(std::list<std::string> input) {
	bool elements[26];
	int newGroup = false;
	int count = 0;
	for (auto i : input)
	{
		if (i == "") {
			newGroup = true;
		}

		if (newGroup) {
			for (int j = 0; j < 26; j++)
			{
				if (!elements[j])
					count++;
			}
			for (int j = 0; j < 26; j++)
			{
				elements[j] = true;
			}
			newGroup = false;
		}
		else {
			for (int k = 0; k < i.size(); k++)
			{
				elements[i[k] - 'a'] = false;
			}
		}
	}
	for (int j = 0; j < 26; j++)
	{
		if (!elements[j])
			count++;
	}
	return count;
}

long Day06::part_two(std::list<std::string> input) {
	int elements[26];
	int count = 0;
	for (int j = 0; j < 26; j++)
	{
		elements[j] = 0;
	}
	int newGroup = false;
	int numElems = 0;
	for (auto i : input)
	{
		if (i == "") {
			newGroup = true;
		}
		else {
			numElems++;
		}

		if (newGroup) {
			for (int j = 0; j < 26; j++)
			{
				if (elements[j] == numElems)
					count++;
			}
			for (int j = 0; j < 26; j++)
			{
				elements[j] = 0;
			}
			newGroup = false;
			numElems = 0;
		}
		else {
			for (int k = 0; k < i.size(); k++)
			{
				elements[i[k] - 'a']++;
			}
		}
	}
	for (int j = 0; j < 26; j++)
	{
		if (elements[j] == numElems)
			count++;
	}
	return count;
}