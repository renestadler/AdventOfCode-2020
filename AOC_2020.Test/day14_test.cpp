#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day14.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day14Test)
	{
		Input io;
		Day14 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				"mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X","mem[8] = 11","mem[7] = 101","mem[8] = 0"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((int64_t)165, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day14");
			Assert::AreEqual((int64_t)11926135976176, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				"mask = 000000000000000000000000000000X1001X","mem[42] = 100","mask = 00000000000000000000000000000000X0XX","mem[26] = 1"
			};
			list input(begin(input_arr), end(input_arr));
			Assert::AreEqual((int64_t)208, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day14");
			Assert::AreEqual((int64_t)4330547254348, day.part_two(input));
		}
	};
}
