#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day02.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day02Test)
	{
		Input io;
		Day02 day;
	public:
		TEST_METHOD(partOneTest)
		{
			std::string input_arr[] = { "1 - 3 a: abcde",
										"1 - 3 b: cdefg",
										"2 - 9 c: ccccccccc" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)2, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<std::string> input = io.read_lines("Day02");
			Assert::AreEqual((long)456, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			std::string input_arr[] = { "1 - 3 a: abcde",
										"1 - 3 b: cdefg",
										"2 - 9 c: ccccccccc" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)1, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<std::string> input = io.read_lines("Day02");
			Assert::AreEqual((long)308, day.part_two(input));
		}
	};
}
