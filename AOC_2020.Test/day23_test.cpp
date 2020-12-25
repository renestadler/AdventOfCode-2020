#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day23.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day23Test)
	{
		Input io;
		Day23 day;
	public:
		TEST_METHOD(partOneTest)
		{
			int input_arr[] = {
				389125467
			};
			Assert::AreEqual((uint64_t)67384529, day.part_one(input_arr[0]));
		}

		TEST_METHOD(partOne)
		{
			list<int> input = io.read_numbers("Day23");
			Assert::AreEqual((uint64_t)69425837, day.part_one(input.front()));
		}

		TEST_METHOD(partTwoTest)
		{
			int input_arr[] = {
				389125467
			};
			Assert::AreEqual((uint64_t)149245887792, day.part_two(input_arr[0]));
		}

		TEST_METHOD(partTwo)
		{
			list<int> input = io.read_numbers("Day23");
			Assert::AreEqual((uint64_t)218882971435, day.part_two(input.front()));
		}
	};
}
