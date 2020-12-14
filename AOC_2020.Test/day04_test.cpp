#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day04.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AOC2020Test
{
	TEST_CLASS(Day04Test)
	{
		Input io;
		Day04 day;
	public:
		TEST_METHOD(partOneTest)
		{
			std::string input_arr[] = { "ecl:gry pid:860033327 eyr:2020 hcl:#fffffd",
										"byr:1937 iyr:2017 cid:147 hgt:183cm",
										"",
										"iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884",
										"hcl:#cfa07d byr:1929",
										"",
										"hcl:#ae17e1 iyr:2013",
										"eyr:2024",
										"ecl:brn pid:760753108 byr:1931",
										"hgt:179cm",
										"",
										"hcl:#cfa07d eyr:2025 pid:166559648",
										"iyr:2011 ecl:brn hgt:59in" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)2, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			std::list<std::string> input = io.read_lines("Day04");
			Assert::AreEqual((long)208, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			std::string input_arr[] = { "ecl:gry pid:860033327 eyr:2020 hcl:#fffffd",
										"byr:1937 iyr:2017 cid:147 hgt:183cm",
										"",
										"iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884",
										"hcl:#cfa07d byr:1929",
										"",
										"hcl:#ae17e1 iyr:2013",
										"eyr:2024",
										"ecl:brn pid:760753108 byr:1931",
										"hgt:179cm",
										"",
										"hcl:#cfa07d eyr:2025 pid:166559648",
										"iyr:2011 ecl:brn hgt:59in" };
			std::list input(std::begin(input_arr), std::end(input_arr));
			Assert::AreEqual((long)2, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			std::list<std::string> input = io.read_lines("Day04");
			Assert::AreEqual((long)167, day.part_two(input));
		}
	};
}
