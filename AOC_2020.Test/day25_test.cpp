#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <list>
#include "../day.h"
#include "../day25.h"
#include "../input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AOC2020Test
{
	TEST_CLASS(Day25Test)
	{
		Input io;
		Day25 day;
	public:
		TEST_METHOD(partOneTest)
		{
			int input_arr[] = {
				5764801,
				17807724
			};
			list<int> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)14897079, day.part_one(input));
		}

		TEST_METHOD(partOne)
		{
			list<int> input = io.read_numbers("Day25");
			Assert::AreEqual((long)17032383, day.part_one(input));
		}

		TEST_METHOD(partTwoTest)
		{
			int input_arr[] = {
				5764801,
				17897724
			};
			list<int> input(begin(input_arr), end(input_arr));
			Assert::AreEqual((long)-1, day.part_two(input));
		}

		TEST_METHOD(partTwo)
		{
			list<int> input = io.read_numbers("Day25");
			Assert::AreEqual((long)-1, day.part_two(input));
		}
	};
}
