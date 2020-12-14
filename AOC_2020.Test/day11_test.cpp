#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day11.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day11Test)
	{
		Input io;
		Day11 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				"L.LL.LL.LL",
				"LLLLLLL.LL",
				"L.L.L..L..",
				"LLLL.LL.LL",
				"L.LL.LL.LL",
				"L.LLLLL.LL",
				"..L.L.....",
				"LLLLLLLLLL",
				"L.LLLLLL.L",
				"L.LLLLL.LL"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)37, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day11");
			Assert::AreEqual((long)2126, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				"L.LL.LL.LL",
				"LLLLLLL.LL",
				"L.L.L..L..",
				"LLLL.LL.LL",
				"L.LL.LL.LL",
				"L.LLLLL.LL",
				"..L.L.....",
				"LLLLLLLLLL",
				"L.LLLLLL.L",
				"L.LLLLL.LL"
			};
			list input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)26, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day11");
			Assert::AreEqual((long)1914, day.part_two(input));
		}
	};
}
