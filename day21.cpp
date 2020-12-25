#include <string>
#include <vector>
#include <set>
#include <regex>
#include <map>
#include "day21.h"

using namespace std;

string Day21::part_one(list<string> input) {
	map<string, set<string>> allergens;
	map<string, int> ingredients;

	regex word_match("[a-z]{1,}");

	for (string item : input) {
		if (item.empty()) {
			break;
		}
		int separator = item.find('(');
		sregex_iterator regex_it(item.begin(), item.begin() + separator, word_match);
		set<string> cur_ingredients;
		for (auto it = regex_it; it != std::sregex_iterator(); it++) {
			ingredients[(*it).str()]++;
			cur_ingredients.insert((*it).str());
		}
		regex_it = sregex_iterator(item.begin() + separator + 9, item.end(), word_match);
		for (auto it = regex_it; it != std::sregex_iterator(); it++) {
			string allergen = (*it).str();
			if (allergens.find(allergen) == allergens.end()) {
				allergens[allergen] = cur_ingredients;
			}
			else {
				set<string> to_erase;
				for (auto& ingredient : allergens[allergen]) {
					if (cur_ingredients.find(ingredient) == cur_ingredients.end())
					{
						to_erase.insert(ingredient);
					}
				}
				for (auto& ingredient : to_erase) {
					allergens[allergen].erase(ingredient);
				}
			}
		}
	}
	int result = 0;
	for (auto ingredient : ingredients) {
		if (find_if(allergens.begin(), allergens.end(), [&ingredient](auto allergen)
			{
				return allergen.second.find(ingredient.first) != allergen.second.end();
			}) == allergens.end()) {
			result += ingredient.second;
		}
	}
	return to_string(result);
}

string Day21::part_two(list<string> input) {
	map<string, set<string>> allergens;
	map<string, int> ingredients;

	regex word_match("[a-z]{1,}");

	for (string item : input) {
		if (item.empty()) {
			break;
		}
		int separator = item.find('(');
		sregex_iterator regex_it(item.begin(), item.begin() + separator, word_match);
		set<string> cur_ingredients;
		for (auto it = regex_it; it != std::sregex_iterator(); it++) {
			ingredients[(*it).str()]++;
			cur_ingredients.insert((*it).str());
		}
		regex_it = sregex_iterator(item.begin() + separator + 9, item.end(), word_match);
		for (auto it = regex_it; it != std::sregex_iterator(); it++) {
			string allergen = (*it).str();
			if (allergens.find(allergen) == allergens.end()) {
				allergens[allergen] = cur_ingredients;
			}
			else {
				set<string> to_erase;
				for (auto& ingredient : allergens[allergen]) {
					if (cur_ingredients.find(ingredient) == cur_ingredients.end())
					{
						to_erase.insert(ingredient);
					}
				}
				for (auto& ingredient : to_erase) {
					allergens[allergen].erase(ingredient);
				}
			}
		}
	}

	while (find_if(allergens.begin(), allergens.end(), [](auto allergen) {return allergen.second.size() > 1; }) != allergens.end()) {
		for (auto it = allergens.begin(); it != allergens.end(); it++) {
			if (it->second.size() == 1) {
				auto ingredient = *it->second.begin();
				for (auto it1 = allergens.begin(); it1 != allergens.end(); it1++) {
					if (it->first != it1->first) {
						it1->second.erase(ingredient);
					}
				}
			}
		}
	}

	string result;
	for (auto allergen : allergens) {
		result.append(*allergen.second.begin() + ",");
	}
	result = result.substr(0, result.length() - 1);
	return result;
}
