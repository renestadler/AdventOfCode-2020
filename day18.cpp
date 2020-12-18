#include <regex>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <stack>
#include "day18.h"

using namespace std;

pair<uint64_t, int> eval_expr(string s) {
	uint64_t sum = 0;
	char op = '\0';
	string num = "";
	bool first = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ') {
			if (num != "") {
				if (first) {
					sum = atoi(num.c_str());
					first = false;
				}
				if (op == '*')
					sum *= atoi(num.c_str());
				else if (op == '+')
					sum += atoi(num.c_str());
				num = "";
			}
		}
		else if (s[i] == '(') {
			auto result = eval_expr(s.substr(i + 1));
			if (first) {
				sum = result.first;
				first = false;
			}
			if (op == '*')
				sum *= result.first;
			else if (op == '+')
				sum += result.first;
			i += result.second + 1;
		}
		else if (s[i] == ')') {
			if (num != "") {
				if (first)
					sum = atoi(num.c_str());
				if (op == '*')
					sum *= atoi(num.c_str());
				else if (op == '+')
					sum += atoi(num.c_str());
			}
			return pair(sum, i);

		}
		else if (s[i] == '*') {
			op = '*';
		}
		else if (s[i] == '+') {
			op = '+';
		}
		else {
			num += s[i];
		}
	}
	if (num != "") {
		if (first)
			sum = atoi(num.c_str());
		if (op == '*')
			sum *= atoi(num.c_str());
		else if (op == '+')
			sum += atoi(num.c_str());
	}
	return pair(sum, 0);
}

string Day18::part_one(list<string> input) {
	uint64_t sum = 0;
	for (string s : input) {
		sum += eval_expr(s).first;
	}
	return to_string(sum);
}

pair<uint64_t, int> eval_expr_complex(string s) {
	uint64_t sum = 0;
	char op = '\0';
	string num = "";
	vector<uint64_t> elems;
	vector<char> ops;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ') {
			if (num != "") {
				elems.push_back(atoi(num.c_str()));
				num = "";
			}
		}
		else if (s[i] == '(') {
			auto result = eval_expr_complex(s.substr(i + 1));
			elems.push_back(result.first);
			i += result.second + 1;
		}
		else if (s[i] == ')') {
			if (num != "") {
				elems.push_back(atoi(num.c_str()));
				num = "";
			}
			int idx = 0;
			for (int j = 0; j < ops.size(); j++) {
				if (ops[j] == '+') {
					elems[idx] = elems[idx] + elems[idx + 1];
					elems.erase(elems.begin() + idx + 1);
				}
				else
					idx++;

			}
			for (int j = 0; j < ops.size(); j++) {
				if (ops[j] == '*') {
					elems[0] = elems[0] * elems[1];
					elems.erase(elems.begin() + 1);
				}
			}
			sum = elems[0];
			return pair(sum, i);

		}
		else if (s[i] == '*') {
			ops.push_back('*');
		}
		else if (s[i] == '+') {
			ops.push_back('+');
		}
		else {
			num += s[i];
		}
	}
	if (num != "") {
		elems.push_back(atoi(num.c_str()));
		num = "";
	}
	int idx = 0;
	for (int j = 0; j < ops.size(); j++) {
		if (ops[j] == '+') {
			elems[idx] = elems[idx] + elems[idx + 1];
			elems.erase(elems.begin() + idx + 1);
		}
		else
			idx++;

	}
	for (int j = 0; j < ops.size(); j++) {
		if (ops[j] == '*') {
			elems[0] = elems[0] * elems[1];
			elems.erase(elems.begin() + 1);
		}
	}
	sum = elems[0];
	return pair(sum, 0);
}

string sum_up(string str1, string str2)
{
	if (str1.length() > str2.length())
		swap(str1, str2);

	string str = "";
	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < n1; i++)
	{
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	for (int i = n1; i < n2; i++)
	{
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry)
		str.push_back(carry + '0');

	reverse(str.begin(), str.end());

	return str;
}

string Day18::part_two(list<string> input) {
	string sum;
	for (string s : input) {
		string cur=to_string(eval_expr_complex(s).first);
		sum = sum_up(sum, cur);
	}
	return sum;
}
