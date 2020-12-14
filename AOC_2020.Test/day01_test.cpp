#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day01.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day01Test)
	{
		Input io;
		Day01 day;
	public:
		TEST_METHOD(partOneTest)
		{
			int input_arr[] = { 1721,979,366,299,675,1456 };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)514579, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<int> input = io.read_numbers("Day01");
			Assert::AreEqual((long)100419, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			int input_arr[] = { 1721,979,366,299,675,1456 };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)241861950, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<int> input = io.read_numbers("Day01");
			Assert::AreEqual((long)265253940, day.part_two(input));
		}
	};
}
