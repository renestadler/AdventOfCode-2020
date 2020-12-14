#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day10.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day10Test)
	{
		Input io;
		Day10 day;
	public:
		TEST_METHOD(partOneTest)
		{
			int input_arr[] = { 28,33,18,42,31,14,46,20,48,47,24,23,49,45,19,38,39,11,1,32,25,35,8,17,7,9,4,2,34,10,3 };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((int64_t)22 * 10, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<int> input = io.read_numbers("Day10");
			Assert::AreEqual((int64_t)2574, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			int input_arr[] = { 28,33,18,42,31,14,46,20,48,47,24,23,49,45,19,38,39,11,1,32,25,35,8,17,7,9,4,2,34,10,3 };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((int64_t)19208, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<int> input = io.read_numbers("Day10");
			Assert::AreEqual((int64_t)2644613988352, day.part_two(input));
		}
	};
}
