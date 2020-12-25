#include <string>
#include <vector>
#include "day25.h"

using namespace std;

long Day25::part_one(list<int> input) {
	long subject_nr = 7;
	long value = 1;
	int loop = 0;
	do {
		value *= subject_nr;
		value = value % 20201227;
		loop++;
	} while (value != input.front());
	input.pop_front();
	long long result = 1;
	for (int i = 0; i < loop; i++)
	{
		result *= input.front();
		result = result % 20201227;
	}
	return result;
}

long Day25::part_two(list<int> input) {
	return -1;
}
