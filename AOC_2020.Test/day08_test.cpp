#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day08.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day08Test)
	{
		Input io;
		Day08 day;
	public:
		TEST_METHOD(partOneTest)
		{
			std::string input_arr[] = { "nop +0",
										"acc + 1",
										"jmp + 4",
										"acc + 3",
										"jmp - 3",
										"acc - 99",
										"acc + 1",
										"jmp - 4",
										"acc + 6" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)5, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<std::string> input = io.read_lines("Day08");
			Assert::AreEqual((long)1675, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			std::string input_arr[] = { "nop +0",
										"acc + 1",
										"jmp + 4",
										"acc + 3",
										"jmp - 3",
										"acc - 99",
										"acc + 1",
										"jmp - 4",
										"acc + 6" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)8, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<std::string> input = io.read_lines("Day08");
			Assert::AreEqual((long)1532, day.part_two(input));
		}
	};
}
