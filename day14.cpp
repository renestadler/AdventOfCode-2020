#include <regex>
#include <map>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <stack>
#include "day14.h"

using namespace std;


int64_t Day14::part_one(list<string> input) {
	map<int64_t, int64_t> m;
	string mask = "";
	int64_t value;
	for (auto entry : input) {
		if (entry.rfind("mask", 0) == 0) {
			mask = entry.substr(entry.find("=") + 2);
		}
		else {
			int64_t key = atoll(entry.substr(entry.find("[", 0) + 1, entry.find("]", 0)).c_str());
			bitset<64> b(atoll(entry.substr(entry.find("=") + 2).c_str()));
			for (int i = 0; i < mask.size(); i++)
			{
				if (mask[mask.size() - 1 - i] == '1')
					b[i] = 1;
				if (mask[mask.size() - 1 - i] == '0')
					b[i] = 0;
			}
			m.insert_or_assign(key, b.to_ullong());
		}
	}
	int64_t sum = 0;
	for (auto entry : m)
	{
		sum += entry.second;
	}
	return sum;
}

int64_t Day14::part_two(list<string> input) {
	map<int64_t, int64_t> m;
	string mask = "";
	int64_t value;
	for (auto entry : input) {
		if (entry.rfind("mask", 0) == 0) {
			mask = entry.substr(entry.find("=") + 2);
		}
		else {
			int64_t key = atoll(entry.substr(entry.find("[", 0) + 1, entry.find("]", 0)).c_str());
			int value = atoll(entry.substr(entry.find("=") + 2).c_str());
			bitset<64> b(key);
			vector<bitset<64>> addresses;
			addresses.push_back(b);
			for (int i = 0; i < mask.size(); i++)
			{
				if (mask[mask.size() - 1 - i] == '1')
					std::transform(addresses.begin(), addresses.end(), addresses.begin(), [i](bitset<64> b) { b[i] = 1; return b; });
				if (mask[mask.size() - 1 - i] == 'X') {
					vector<bitset<64>> new_addresses;
					for (auto address : addresses) {
						bitset<64> first = address;
						first[i] = 0;
						bitset<64> second(address);
						second[i] = 1;
						new_addresses.push_back(first);
						new_addresses.push_back(second);
					}
					addresses.clear();
					addresses.insert(addresses.end(), new_addresses.begin(), new_addresses.end());
				}
			}
			for (auto address : addresses) {
				m.insert_or_assign(address.to_ullong(), value);
			}
		}
	}
	int64_t sum = 0;
	for (auto entry : m)
	{
		sum += entry.second;
	}
	return sum;
}