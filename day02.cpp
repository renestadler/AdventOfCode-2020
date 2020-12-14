#include <sstream>
#include "day02.h"

long Day02::part_one(std::list<std::string> input) {
	int total_sum = 0;
	for (auto var : input)
	{
		int string_start = var.find_first_of(":");
		int first_num_end = var.find_first_of("-");
		int second_num_end = string_start - 2;
		const char* value = var.c_str();

		std::string s;
		std::stringstream ss;
		for (int i = 0; i < first_num_end; i++)
		{

			s += value[i];
		}
		int min = 0, max = 0;

		ss << s;
		ss >> min;
		s = "";
		for (int i = first_num_end + 1; i < second_num_end; i++)
		{
			s += value[i];
		}
		ss.clear();
		ss << s;
		ss >> max;
		char type = value[second_num_end + 1];
		int num_occurs = 0;
		for (int i = string_start + 2; i < var.length(); i++)
		{
			if (value[i] == type) {
				num_occurs++;
			}
		}
		if (num_occurs >= min && num_occurs <= max) {
			total_sum++;
		}
	}
	return total_sum;
}

long Day02::part_two(std::list<std::string> input) {
	int total_sum = 0;
	for (auto var : input)
	{
		int string_start = var.find_first_of(":");
		int first_num_end = var.find_first_of("-");
		int second_num_end = string_start - 2;
		const char* value = var.c_str();

		std::string s;
		std::stringstream ss;
		for (int i = 0; i < first_num_end; i++)
		{

			s += value[i];
		}
		int first = 0, second = 0;

		ss << s;
		ss >> first;
		s = "";
		for (int i = first_num_end + 1; i < second_num_end; i++)
		{
			s += value[i];
		}
		ss.clear();
		ss << s;
		ss >> second;
		char type = value[second_num_end + 1];
		int i = string_start + 1;
		if ((value[i + first] == type && value[i + second] != type) || (value[i + first] != type && value[i + second] == type)) {
			total_sum++;
		}
	}
	return total_sum;
}