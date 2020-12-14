#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day07.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day07Test)
	{
		Input io;
		Day07 day;
	public:
		TEST_METHOD(partOneTest)
		{
			std::string input_arr[] = { "light red bags contain 1 bright white bag, 2 muted yellow bags.",
										"dark orange bags contain 3 bright white bags, 4 muted yellow bags.",
										"bright white bags contain 1 shiny gold bag.",
										"muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.",
										"shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.",
										"dark olive bags contain 3 faded blue bags, 4 dotted black bags.",
										"vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.",
										"faded blue bags contain no other bags.",
										"dotted black bags contain no other bags." };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)4, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<std::string> input = io.read_lines("Day07");
			Assert::AreEqual((long)161, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			std::string input_arr[] = { "light red bags contain 1 bright white bag, 2 muted yellow bags.",
										"dark orange bags contain 3 bright white bags, 4 muted yellow bags.",
										"bright white bags contain 1 shiny gold bag.",
										"muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.",
										"shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.",
										"dark olive bags contain 3 faded blue bags, 4 dotted black bags.",
										"vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.",
										"faded blue bags contain no other bags.",
										"dotted black bags contain no other bags." };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)32, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<std::string> input = io.read_lines("Day07");
			Assert::AreEqual((long)30899, day.part_two(input));
		}
	};
}
