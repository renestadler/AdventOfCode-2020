#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include "day20.h"

using namespace std;

struct image_border {
	string data;
	int neighbor = -1;
};

struct image_part {
	vector<string> data;
	array<image_border, 4> borders;
};

bool corner(const image_part& part) {
	int border_tile = 0;
	for (const auto& border : part.borders) {
		if (border.neighbor < 0) {
			border_tile++;
		}
	}
	return border_tile > 1;
}

uint64_t Day20::part_one(list<string> input) {
	vector items(input.begin(), input.end());
	map<int, image_part> parts;
	uint64_t result = 1;

	for (int i = 0; i < items.size(); i++) {
		if (items[i].empty()) {
			break;
		}
		image_part cur;
		string id = regex_replace(items[i], regex("[^0-9]*([0-9]+).*"), string("$1"));
		for (int j = 0; j < 10; j++) {
			i++;
			cur.data.push_back(items[i]);
		}
		for (int j = 0; j < 10; j++) {
			cur.borders[0].data.push_back(cur.data[0][j]);
			cur.borders[1].data.push_back(cur.data[j][9]);
			cur.borders[2].data.push_back(cur.data[9][9 - j]);
			cur.borders[3].data.push_back(cur.data[9 - j][0]);
		}
		parts[stoi(id)] = cur;
		i++;
	}

	for (auto it1 = parts.begin(); it1 != parts.end(); it1++) {
		for (int i = 0; i < 4; i++) {
			for (auto it2 = next(it1); it2 != parts.end(); it2++) {
				if (it1->second.borders[i].neighbor < 0) {
					const string border1 = it1->second.borders[i].data;
					for (int j = 0; j < 4; ++j) {
						const string border2 = it2->second.borders[j].data;
						const string reversed2(border2.rbegin(), border2.rend());
						if (border1 == border2 || border1 == reversed2) {
							it2->second.borders[j].neighbor = it1->first;
							it1->second.borders[i].neighbor = it2->first;
						}
					}
				}
				else {
					break;
				}
			}
		}
	}

	for (const auto& part : parts)
	{
		if (corner(part.second))
		{
			result *= part.first;
		}
	}
	return result;
}

void flip_image(vector<string>& data) {
	vector<string> copy = data;
	for (int j = 0; j < data.size(); j++)
	{
		for (int i = 0; i < data[j].size(); i++)
		{
			data[j][i] = copy[j][data[j].size() - 1 - i];
		}
	}
}

void rotate_image(vector<string>& data) {
	vector<string> copy = data;
	for (int j = 0; j < data.size(); j++)
	{
		for (int i = 0; i < data[j].size(); i++)
		{
			data[j][i] = copy[i][data[i].size() - 1 - j];
		}
	}
}

void flip_image_part(image_part& part) {
	flip_image(part.data);
	std::reverse(part.borders[0].data.begin(), part.borders[0].data.end());
	std::reverse(part.borders[1].data.begin(), part.borders[1].data.end());
	std::reverse(part.borders[2].data.begin(), part.borders[2].data.end());
	std::reverse(part.borders[3].data.begin(), part.borders[3].data.end());
	std::swap(part.borders[1], part.borders[3]);
}

void rotate_image_part(image_part& part) {
	rotate_image(part.data);
	image_border temp = part.borders[0];
	part.borders[0] = part.borders[1];
	part.borders[1] = part.borders[2];
	part.borders[2] = part.borders[3];
	part.borders[3] = temp;
}

const vector<function<void(image_part&)>> image_part_transformations{
	rotate_image_part, rotate_image_part, rotate_image_part, flip_image_part, rotate_image_part, rotate_image_part, rotate_image_part };

const vector<function<void(vector<string>&)>> image_transformations{
	rotate_image, rotate_image, rotate_image, flip_image, rotate_image , rotate_image, rotate_image };

void match_part(map<int, image_part>& parts, image_border b, int b_idx) {
	auto tile_id = b.neighbor;
	reverse(b.data.begin(), b.data.end());
	for (const auto& transformation : image_part_transformations) {
		if (b.data == parts[tile_id].borders[b_idx].data) {
			break;
		}
		else {
			transformation(parts[tile_id]);
		}
	}
}

void expand_image(vector<string>& image, map<int, image_part>& parts, int pid, int row, int col) {
	if (pid < 0 || image[row].size() > col) {
		return;
	}
	for (size_t i = 0; i < 8; i++) {
		image[row + i].append(parts[pid].data[i + 1].substr(1, 8));
	}
	if (parts[pid].borders[2].neighbor > 0) {
		match_part(parts, parts[pid].borders[2], 0);
		expand_image(image, parts, parts[pid].borders[2].neighbor, row + 8, col);
	}
	if (parts[pid].borders[1].neighbor > 0) {
		match_part(parts, parts[pid].borders[1], 3);
		expand_image(image, parts, parts[pid].borders[1].neighbor, row, col + 8);
	}
}

uint64_t Day20::part_two(list<string> input) {
	vector items(input.begin(), input.end());
	map<int, image_part> parts;

	for (int i = 0; i < items.size(); i++) {
		if (items[i].empty()) {
			break;
		}
		image_part cur;
		string id = regex_replace(items[i], regex("[^0-9]*([0-9]+).*"), string("$1"));
		for (int j = 0; j < 10; j++) {
			i++;
			cur.data.push_back(items[i]);
		}
		for (int j = 0; j < 10; j++) {
			cur.borders[0].data.push_back(cur.data[0][j]);
			cur.borders[1].data.push_back(cur.data[j][9]);
			cur.borders[2].data.push_back(cur.data[9][9 - j]);
			cur.borders[3].data.push_back(cur.data[9 - j][0]);
		}
		parts[stoi(id)] = cur;
		i++;
	}

	for (auto it1 = parts.begin(); it1 != parts.end(); it1++) {
		for (int i = 0; i < 4; i++) {
			for (auto it2 = next(it1); it2 != parts.end(); it2++) {
				if (it1->second.borders[i].neighbor < 0) {
					const string border1 = it1->second.borders[i].data;
					for (int j = 0; j < 4; ++j) {
						const string border2 = it2->second.borders[j].data;
						const string reversed2(border2.rbegin(), border2.rend());
						if (border1 == border2 || border1 == reversed2) {
							it2->second.borders[j].neighbor = it1->first;
							it1->second.borders[i].neighbor = it2->first;
						}
					}
				}
				else {
					break;
				}
			}
		}
	}

	int start;
	for (const auto& part : parts) {
		if (corner(part.second)) {
			start = part.first;
		}
	}

	const size_t size = ceil(sqrt(parts.size())) * 8;

	vector<string> image(size, "");

	for (const auto& transformation : image_part_transformations) {
		if (parts[start].borders[0].neighbor == parts[start].borders[3].neighbor) {
			break;
		}
		else {
			transformation(parts[start]);
		}
	}

	expand_image(image, parts, start, 0, 0);

	int monster_count = 0;
	int wave_count = 0;
	for (const auto& row : image)
	{
		wave_count += count(row.begin(), row.end(), '#');
	}
	for (const auto& transform : image_transformations)
	{
		regex body_regex("#.{4}##.{4}##.{4}###");
		regex feet_regex("#..#..#..#..#..#");
		smatch body_match;
		for (size_t i = 1; i < image.size() - 1; i++)
		{
			string row = image[i];
			size_t pos = 0;
			while (regex_search(row, body_match, body_regex))
			{
				pos += body_match.position();
				if ((image[i - 1][pos + 18] == '#') && (regex_match(image[i + 1].substr(pos + 1, 16), feet_regex))) {
					monster_count++;
				}
				row = image[i].substr(pos + 1);
				pos++;
			}
		}
		if (monster_count > 0)
		{
			break;
		}
		transform(image);
	}

	return wave_count - monster_count * 15;
}
