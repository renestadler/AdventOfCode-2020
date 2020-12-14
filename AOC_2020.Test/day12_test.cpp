#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day12.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day12Test)
	{
		Input io;
		Day12 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				"F10",
				"N3",
				"F7",
				"R90",
				"F11"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)25, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day12");
			Assert::AreEqual((long)759, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				"F10",
				"N3",
				"F7",
				"R90",
				"F11"
			};
			list input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)286, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day12");
			Assert::AreEqual((long)45763, day.part_two(input));
		}
	};
}
