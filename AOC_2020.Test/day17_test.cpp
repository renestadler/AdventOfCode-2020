#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day17.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day17Test)
	{
		Input io;
		Day17 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				".#.",
				"..#",
				"###"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)112, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day17");
			Assert::AreEqual((long)269, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				".#.",
				"..#",
				"###"
			};
			list input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)848, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day17");
			Assert::AreEqual((long)1380, day.part_two(input));
		}
	};
}
