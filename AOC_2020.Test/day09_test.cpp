#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day09.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day09Test)
	{
		Input io;
		Day09 day;
	public:
		TEST_METHOD(partOneTest)
		{
			int input_arr[] = { 35, 20, 15, 25, 47, 40, 62,	55,	65,	95, 102, 117, 150, 182, 127, 219, 299, 277, 309, 576 };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)127, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<int> input = io.read_numbers("Day09");
			Assert::AreEqual((long)507622668, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			int input_arr[] = { 35, 20, 15, 25, 47, 40, 62,	55,	65,	95, 102, 117, 150, 182, 127, 219, 299, 277, 309, 576 };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)62, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<int> input = io.read_numbers("Day09");
			Assert::AreEqual((long)76688505, day.part_two(input));
		}
	};
}
