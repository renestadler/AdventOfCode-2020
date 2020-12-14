#pragma once
#include <string>

template<class input, class output> class Day {
	virtual output part_one(input input) = 0;
	virtual output part_two(input input) = 0;
};
