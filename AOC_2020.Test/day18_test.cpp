#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day18.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day18Test)
	{
		Input io;
		Day18 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				"1 + 2 * 3 + 4 * 5 + 6",
				"1 + (2 * 3) + (4 * (5 + 6))",
				"2 * 3 + (4 * 5)",
				"5 + (8 * 3 + 9 + 3 * 4 * 3)",
				"5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))",
				"((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual(to_string(71 + 51 + 26 + 437 + 12240 + 13632), day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day18");
			Assert::AreEqual(string("18213007238947"), day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				"1 + 2 * 3 + 4 * 5 + 6",
				"1 + (2 * 3) + (4 * (5 + 6))",
				"2 * 3 + (4 * 5)",
				"5 + (8 * 3 + 9 + 3 * 4 * 3)",
				"5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))",
				"((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2"
			};
			list input(begin(input_arr), end(input_arr));
			Assert::AreEqual(to_string(231 + 51 + 46 + 1445 + 669060 + 23340), day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day18");
			Assert::AreEqual(string("388966573054664"), day.part_two(input));
		}
	};
}
