#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day21.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day21Test)
	{
		Input io;
		Day21 day;
	public:
		TEST_METHOD(partOneTest)
		{
			string input_arr[] = {
				"mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
				"trh fvjkl sbzzf mxmxvkd(contains dairy)",
				"sqjhc fvjkl(contains soy)",
				"sqjhc mxmxvkd sbzzf(contains fish)"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual(string("5"), day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<string> input = io.read_lines("Day21");
			Assert::AreEqual(string("2595"), day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			string input_arr[] = {
				"mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
				"trh fvjkl sbzzf mxmxvkd(contains dairy)",
				"sqjhc fvjkl(contains soy)",
				"sqjhc mxmxvkd sbzzf(contains fish)"
			};
			list<string> input(begin(input_arr), end(input_arr));
			Assert::AreEqual(string("mxmxvkd,sqjhc,fvjkl"), day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<string> input = io.read_lines("Day21");
			Assert::AreEqual(string("thvm,jmdg,qrsczjv,hlmvqh,zmb,mrfxh,ckqq,zrgzf"), day.part_two(input));
		}
	};
}
