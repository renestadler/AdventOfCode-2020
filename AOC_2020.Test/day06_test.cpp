#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day06.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day06Test)
	{
		Input io;
		Day06 day;
	public:
		TEST_METHOD(partOneTest)
		{
			std::string input_arr[] = { "abc","","a","b","c","","ab","ac","","a","a","a","a","","b" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)11, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<std::string> input = io.read_lines("Day06");
			Assert::AreEqual((long)6335, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			std::string input_arr[] = { "abc","","a","b","c","","ab","ac","","a","a","a","a","","b" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)6, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<std::string> input = io.read_lines("Day06");
			Assert::AreEqual((long)3392, day.part_two(input));
		}
	};
}
