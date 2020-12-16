#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day16.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day16Test)
	{
		Input io;
		Day16 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				"class: 1-3 or 5-7",
				"row: 6 - 11 or 33 - 44",
				"seat : 13 - 40 or 45 - 50",
				"",
				"your ticket :",
				"7,1,14",
				"",
				"nearby tickets :",
				"7,3,47",
				"40,4,50",
				"55,2,20",
				"38,6,12"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((uint64_t)71, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day16");
			Assert::AreEqual((uint64_t)19093, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				"departure location: 0-1 or 4-19",
				"departure station: 0 - 5 or 8 - 19",
				"departure platform: 0 - 13 or 16 - 19",
				"",
				"your ticket :",
				"11,12,13",
				"",
				"nearby tickets :",
				"3,9,18",
				"15,1,5",
				"5,14,19"
			};
			list input(begin(input_arr), end(input_arr));
			Assert::AreEqual((uint64_t)11 * 12 * 13, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day16");
			Assert::AreEqual((uint64_t)5311123569883, day.part_two(input));
		}
	};
}
