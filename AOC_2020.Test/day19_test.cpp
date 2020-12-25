#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day19.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day19Test)
	{
		Input io;
		Day19 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				"0: 4 1 5",
				"1: 2 3 | 3 2",
				"2 : 4 4 | 5 5",
				"3 : 4 5 | 5 4",
				"4 : \"a\"",
				"5 : \"b\"",
				"",
				"ababbb",
				"bababa",
				"abbbab",
				"aaabbb",
				"aaaabbb"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)2, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day19");
			Assert::AreEqual((long)184, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				"42: 9 14 | 10 1",
				"9: 14 27 | 1 26",
				"10: 23 14 | 28 1",
				"1: \"a\"",
				"11: 42 31",
				"5: 1 14 | 15 1",
				"19: 14 1 | 14 14",
				"12: 24 14 | 19 1",
				"16: 15 1 | 14 14",
				"31: 14 17 | 1 13",
				"6: 14 14 | 1 14",
				"2: 1 24 | 14 4",
				"0: 8 11",
				"13: 14 3 | 1 12",
				"15: 1 | 14",
				"17: 14 2 | 1 7",
				"23: 25 1 | 22 14",
				"28: 16 1",
				"4: 1 1",
				"20: 14 14 | 1 15",
				"3: 5 14 | 16 1",
				"27: 1 6 | 14 18",
				"14: \"b\"",
				"21: 14 1 | 1 14",
				"25: 1 1 | 1 14",
				"22: 14 14",
				"8: 42",
				"26: 14 22 | 1 20",
				"18: 15 15",
				"7: 14 5 | 1 21",
				"24: 14 1",
				"",
				"abbbbbabbbaaaababbaabbbbabababbbabbbbbbabaaaa",
				"bbabbbbaabaabba",
				"babbbbaabbbbbabbbbbbaabaaabaaa",
				"aaabbbbbbaaaabaababaabababbabaaabbababababaaa",
				"bbbbbbbaaaabbbbaaabbabaaa",
				"bbbababbbbaaaaaaaabbababaaababaabab",
				"ababaaaaaabaaab",
				"ababaaaaabbbaba",
				"baabbaaaabbaaaababbaababb",
				"abbbbabbbbaaaababbbbbbaaaababb",
				"aaaaabbaabaaaaababaa",
				"aaaabbaaaabbaaa",
				"aaaabbaabbaaaaaaabbbabbbaaabbaabaaa",
				"babaaabbbaaabaababbaabababaaab",
				"aabbbbbaabbbaaaaaabbbbbababaaaaabbaaabba"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)12, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day19");
			Assert::AreEqual((long)389, day.part_two(input));
		}
	};
}
