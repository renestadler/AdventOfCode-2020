#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day03.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day03Test)
	{
		Input io;
		Day03 day;
	public:
		TEST_METHOD(partOneTest)
		{
			std::string input_arr[] = { "..##.......",
										"#...#...#..",
										".#....#..#.",
										"..#.#...#.#",
										".#...##..#.",
										"..#.##.....",
										".#.#.#....#",
										".#........#",
										"#.##...#...",
										"#...##....#",
										".#..#...#.#" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)7, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<std::string> input = io.read_lines("Day03");
			Assert::AreEqual((long)280, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			std::string input_arr[] = { "..##.......",
										"#...#...#..",
										".#....#..#.",
										"..#.#...#.#",
										".#...##..#.",
										"..#.##.....",
										".#.#.#....#",
										".#........#",
										"#.##...#...",
										"#...##....#",
										".#..#...#.#" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)336, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<std::string> input = io.read_lines("Day03");
			Assert::AreEqual((long)4355551200, day.part_two(input));
		}
	};
}
