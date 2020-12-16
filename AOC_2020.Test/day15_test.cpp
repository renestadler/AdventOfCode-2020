#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include <vector>
#include "../day.h"
#include "../day15.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day15Test)
	{
		Input io;
		Day15 day;
	public:
		TEST_METHOD(partOneTest)
		{
			int input_arr[] = { 0,3,6 };
			vector<int> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)436, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<int> input = io.read_numbers("Day15");
			vector<int> input_v(begin(input), end(input));
			Assert::AreEqual((long)1085, day.part_one(input_v));
		}

		TEST_METHOD(partTwoTest)
		{
			int input_arr[] = { 0,3,6 };
			vector<int> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)175594, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<int> input = io.read_numbers("Day15");
			vector<int> input_v(begin(input), end(input));
			Assert::AreEqual((long)10652, day.part_two(input_v));
		}
	};
}
