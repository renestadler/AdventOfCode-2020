#include <regex>
#include <unordered_map>
#include <stack>
#include "day08.h"

using namespace std;

enum instruction_type {
	NOP,
	ACC,
	JMP
};


class instruction {
public:
	bool visited = false;
	instruction_type type;
	int change;
};


long Day08::part_one(list<string> input) {
	vector <instruction>instructions;
	for (auto input_line : input) {
		int split_point = input_line.find(" ");
		string command = input_line.substr(0, split_point);
		int change = atoi(input_line.substr(split_point + 2).c_str());
		if (input_line[split_point + 1] == '-')
			change *= -1;
		instruction i;
		i.change = change;
		if (command == "nop") {
			i.type = NOP;
		}
		else if (command == "acc") {
			i.type = ACC;
		}
		else if (command == "jmp") {
			i.type = JMP;
		}
		instructions.push_back(i);
	}
	int pos = 0;
	int acc = 0;
	while (!instructions[pos].visited) {
		instructions[pos].visited = true;
		switch (instructions[pos].type) {
		case NOP: pos++; break;
		case JMP: pos += instructions[pos].change; break;
		case ACC: acc += instructions[pos].change; pos++; break;
		}
	}
	return acc;
}

long Day08::part_two(list<string> input) {
	vector <instruction>instructions;
	for (auto input_line : input) {
		int split_point = input_line.find(" ");
		string command = input_line.substr(0, split_point);
		int change = atoi(input_line.substr(split_point + 2).c_str());
		if (input_line[split_point + 1] == '-')
			change *= -1;
		instruction i;
		i.change = change;
		if (command == "nop") {
			i.type = NOP;
		}
		else if (command == "acc") {
			i.type = ACC;
		}
		else if (command == "jmp") {
			i.type = JMP;
		}
		instructions.push_back(i);
	}
	for (int i = 0; i < instructions.size(); i++) {
		if (instructions[i].type == NOP)
			instructions[i].type = JMP;
		else if (instructions[i].type == JMP)
			instructions[i].type = NOP;
		int pos = 0;
		int acc = 0;
		while (pos < instructions.size() && !instructions[pos].visited) {
			instructions[pos].visited = true;
			switch (instructions[pos].type) {
			case NOP: pos++; break;
			case JMP: pos += instructions[pos].change; break;
			case ACC: acc += instructions[pos].change; pos++; break;
			}
		}
		for (int j = 0; j < instructions.size(); j++)
			instructions[j].visited = false;
		if (pos >= instructions.size())
			return acc;
		if (instructions[i].type == NOP)
			instructions[i].type = JMP;
		else if (instructions[i].type == JMP)
			instructions[i].type = NOP;
	}
	return -1;
}