#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day05.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day05Test)
	{
		Input io;
		Day05 day;
	public:
		TEST_METHOD(partOneTest)
		{
			std::string input_arr[] = { "FBFBBFFRLR",
										"BFFFBBFRRR",
										"FFFBBBFRRR",
										"BBFFBBFRLL" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)820, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<std::string> input = io.read_lines("Day05");
			Assert::AreEqual((long)922, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			std::string input_arr[] = { "FBFBBFFRLR",
										"BFFFBBFRRR",
										"FFFBBBFRRR",
										"BBFFBBFRLL" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)327726, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<std::string> input = io.read_lines("Day05");
			Assert::AreEqual((long)747, day.part_two(input));
		}
	};
}
