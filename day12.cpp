#include <regex>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include "day12.h"

using namespace std;

long Day12::part_one(list<string> input) {
	int x = 0;
	int y = 0;
	int rotation = 0;
	for (auto line : input) {
		switch (line[0]) {
		case 'N': y += atoi(line.substr(1).c_str()); break;
		case 'S': y -= atoi(line.substr(1).c_str()); break;
		case 'E': x += atoi(line.substr(1).c_str()); break;
		case 'W': x -= atoi(line.substr(1).c_str()); break;
		case 'L': rotation -= (atoi(line.substr(1).c_str()) / 90);
			if (rotation < 0)
				rotation = 4 + rotation;
			break;
		case 'R': rotation = (rotation + (atoi(line.substr(1).c_str()) / 90)) % 4; break;
		case 'F':
			if (rotation == 0)
				x += atoi(line.substr(1).c_str());
			else if (rotation == 1)
				y -= atoi(line.substr(1).c_str());
			else if (rotation == 2)
				x -= atoi(line.substr(1).c_str());
			else if (rotation == 3)
				y += atoi(line.substr(1).c_str());
			break;
		}
	}
	return abs(x) + abs(y);
}

long Day12::part_two(list<string> input) {
	int x = 10;
	int y = 1;
	int shipx = 0;
	int shipy = 0;
	int temp, change;
	for (auto line : input) {
		switch (line[0]) {
		case 'N': y += atoi(line.substr(1).c_str()); break;
		case 'S': y -= atoi(line.substr(1).c_str()); break;
		case 'E': x += atoi(line.substr(1).c_str()); break;
		case 'W': x -= atoi(line.substr(1).c_str()); break;
		case 'L':
			change = (atoi(line.substr(1).c_str()) / 90);
			for (int i = 0; i < change; i++)
			{
				temp = y;
				y = x;
				x = -temp;
			}
			break;
		case 'R':
			change = (atoi(line.substr(1).c_str()) / 90);
			for (int i = 0; i < change; i++)
			{
				temp = y;
				y = -x;
				x = temp;

			}
			break;
		case 'F':
			shipx += x * atoi(line.substr(1).c_str());
			shipy += y * atoi(line.substr(1).c_str());
		}
	}
	return abs(shipx) + abs(shipy);
}
