#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day22.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day22Test)
	{
		Input io;
		Day22 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				"Player 1:",
				"9",
				"2",
				"6",
				"3",
				"1",
				"",
				"Player 2:",
				"5",
				"8",
				"4",
				"7",
				"10"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)306, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day22");
			Assert::AreEqual((long)32162, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				"Player 1:",
				"9",
				"2",
				"6",
				"3",
				"1",
				"",
				"Player 2:",
				"5",
				"8",
				"4",
				"7",
				"10"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)291, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day22");
			Assert::AreEqual((long)32534, day.part_two(input));
		}
	};
}
