#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day13.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day13Test)
	{
		Input io;
		Day13 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				"939","7,13,x,x,59,x,31,19"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((uint64_t)295, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day13");
			Assert::AreEqual((uint64_t)2298, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				"939","7,13,x,x,59,x,31,19"
			};
			list input(begin(input_arr), end(input_arr));
			Assert::AreEqual((uint64_t)1068781, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day13");
			Assert::AreEqual((uint64_t)783685719679632, day.part_two(input));
		}
	};
}
