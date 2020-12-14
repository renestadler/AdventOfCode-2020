#include "day04.h"
#include <string>
#include <sstream>
#include <iostream>

long Day04::part_one(std::list<std::string> input) {
	int num_correct = 0;
	bool byr = false, iyr = false, eyr = false, hgt = false, hcl = false, ecl = false, pid = false, cid = false;
	for (auto var : input)
	{
		if (var == "") {
			if (byr && iyr && eyr && hgt && hcl && ecl && pid) {
				num_correct++;
			}
			byr = false, iyr = false, eyr = false, hgt = false, hcl = false, ecl = false, pid = false, cid = false;
		}
		else {
			std::stringstream test(var);
			std::string segment;
			while (std::getline(test, segment, ' '))
			{
				int idx = segment.find_first_of(':');
				std::string element = segment.substr(0, idx);
				if (element == "byr")
					byr = true;
				else if (element == "iyr")
					iyr = true;
				else if (element == "eyr")
					eyr = true;
				else if (element == "hgt")
					hgt = true;
				else if (element == "hcl")
					hcl = true;
				else if (element == "ecl")
					ecl = true;
				else if (element == "pid")
					pid = true;
				else if (element == "cid")
					cid = true;
			}
		}
	}
	if (byr && iyr && eyr && hgt && hcl && ecl && pid) {
		num_correct++;
	}
	return num_correct;
}

long Day04::part_two(std::list<std::string> input) {
	int num_correct = 0;
	bool byr = false, iyr = false, eyr = false, hgt = false, hcl = false, ecl = false, pid = false, cid = false;
	for (auto var : input)
	{
		if (var == "") {
			if (byr && iyr && eyr && hgt && hcl && ecl && pid) {
				num_correct++;
			}
			//check validity
			byr = false, iyr = false, eyr = false, hgt = false, hcl = false, ecl = false, pid = false, cid = false;
		}
		else {
			std::stringstream test(var);
			std::string segment;
			while (std::getline(test, segment, ' '))
			{
				int idx = segment.find_first_of(':');
				std::string element = segment.substr(0, idx);
				if (element == "byr") {
					int val = std::stoi(segment.substr(idx + 1, segment.length()));
					if (val >= 1920 && val <= 2002)
						byr = true;
				}
				else if (element == "iyr") {
					int val = std::stoi(segment.substr(idx + 1, segment.length()));
					if (val >= 2010 && val <= 2020)
						iyr = true;
				}
				else if (element == "eyr") {
					int val = std::stoi(segment.substr(idx + 1, segment.length()));
					if (val >= 2020 && val <= 2030)
						eyr = true;
				}
				else if (element == "hgt") {
					int val = std::stoi(segment.substr(idx + 1, segment.length() - 2));
					if (segment.substr(segment.length() - 2, segment.length()) == "in") {
						if (val >= 59 && val <= 76) {
							hgt = true;
						}
					}
					else {
						if (val >= 150 && val <= 193) {
							hgt = true;
						}
					}
				}
				else if (element == "hcl") {
					if (segment[idx + 1] == '#') {
						hcl = true;
						for (int i = idx + 2; i < segment.length(); i++)
						{
							if (!((segment[i] >= '0' && segment[i] <= '9') || (segment[i] >= 'a' && segment[i] <= 'f'))) {
								hcl = false;
							}
						}
					}
				}
				else if (element == "ecl") {
					std::string color = segment.substr(idx + 1, segment.length());
					if (color == "amb")
						ecl = true;
					else if (color == "blu")
						ecl = true;
					else if (color == "brn")
						ecl = true;
					else if (color == "gry")
						ecl = true;
					else if (color == "grn")
						ecl = true;
					else if (color == "hzl")
						ecl = true;
					else if (color == "oth")
						ecl = true;
				}
				else if (element == "pid") {
					if (segment.length() - (idx + 1) == 9) {
						int val = std::stoi(segment.substr(idx + 1, segment.length()));
						pid = true;
					}
				}
				else if (element == "cid")
					cid = true;
			}
		}
	}
	if (byr && iyr && eyr && hgt && hcl && ecl && pid) {
		num_correct++;
	}
	return num_correct;
}