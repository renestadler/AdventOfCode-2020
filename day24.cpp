#include <string>
#include <vector>
#include <set>
#include <map>
#include "day24.h"

using namespace std;

long Day24::part_one(list<string> input) {
	set<string> s;
	for (string item : input) {
		int curx = 0;
		int cury = 0;
		for (int i = 0; i < item.size(); i++) {
			switch (item[i]) {
			case 'w':
				curx -= 2;
				break;
			case 'e':
				curx += 2;
				break;
			case 's':
				i++;
				if (item[i] == 'w')
					curx -= 1;
				if (item[i] == 'e')
					curx += 1;
				cury--;
				break;
			case 'n':
				i++;
				if (item[i] == 'w')
					curx -= 1;
				if (item[i] == 'e')
					curx += 1;
				cury++;
				break;
			}
		}
		string new_string = to_string(curx) + "," + to_string(cury);
		auto it = s.find(new_string);
		if (it == s.end()) {
			s.insert(new_string);
		}
		else {
			s.erase(new_string);
		}
	}
	return s.size();
}

long Day24::part_two(list<string> input) {
	set<string> s;
	for (string item : input) {
		int curx = 0;
		int cury = 0;
		for (int i = 0; i < item.size(); i++) {
			switch (item[i]) {
			case 'w':
				curx -= 2;
				break;
			case 'e':
				curx += 2;
				break;
			case 's':
				i++;
				if (item[i] == 'w')
					curx -= 1;
				if (item[i] == 'e')
					curx += 1;
				cury--;
				break;
			case 'n':
				i++;
				if (item[i] == 'w')
					curx -= 1;
				if (item[i] == 'e')
					curx += 1;
				cury++;
				break;
			}
		}
		string new_string = to_string(curx) + "," + to_string(cury);
		auto it = s.find(new_string);
		if (it == s.end()) {
			s.insert(new_string);
		}
		else {
			s.erase(new_string);
		}
	}

	for (int i = 0; i < 100; i++) {
		set<string> cur;
		map<pair<int, int>, int>elems;
		for (string item : s) {
			auto it = item.find(",");
			int first = stoi(item.substr(0, it));
			int second = stoi(item.substr(it + 1));
			pair p(first - 2, second);
			if (elems.find(p) != elems.end()) {
				elems.insert_or_assign(p, elems.at(p) + 1);
			}
			else {
				elems.insert_or_assign(p, 1);
			}
			p = pair(first + 2, second);
			if (elems.find(p) != elems.end()) {
				elems.insert_or_assign(p, elems.at(p) + 1);
			}
			else {
				elems.insert_or_assign(p, 1);
			}
			p = pair(first - 1, second - 1);
			if (elems.find(p) != elems.end()) {
				elems.insert_or_assign(p, elems.at(p) + 1);
			}
			else {
				elems.insert_or_assign(p, 1);
			}
			p = pair(first - 1, second + 1);
			if (elems.find(p) != elems.end()) {
				elems.insert_or_assign(p, elems.at(p) + 1);
			}
			else {
				elems.insert_or_assign(p, 1);
			}
			p = pair(first + 1, second - 1);
			if (elems.find(p) != elems.end()) {
				elems.insert_or_assign(p, elems.at(p) + 1);
			}
			else {
				elems.insert_or_assign(p, 1);
			}
			p = pair(first + 1, second + 1);
			if (elems.find(p) != elems.end()) {
				elems.insert_or_assign(p, elems.at(p) + 1);
			}
			else {
				elems.insert_or_assign(p, 1);
			}
		}
		for (auto elem : elems) {
			string id = to_string(elem.first.first) + "," + to_string(elem.first.second);
			if (s.find(id) != s.end()) {
				if (elem.second > 0 && elem.second <= 2)
					cur.insert(id);
			}
			else {
				if (elem.second == 2)
					cur.insert(id);
			}
		}
		s.clear();
		s.insert(cur.begin(), cur.end());
	}
	return s.size();
}
