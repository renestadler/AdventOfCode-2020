#include <string>
#include <array>
#include <vector>
#include "day23.h"

using namespace std;

struct node {
	long value;
	node* next = nullptr;
};

uint64_t Day23::part_one(int input) {
	vector<int> vals;
	while (input != 0) {
		vals.insert(vals.begin(), input % 10);
		input /= 10;
	}
	int cur = 0;
	int size = vals.size();
	for (int i = 0; i < 100; i++)
	{
		int first = vals[(cur + 1) % size];
		int second = vals[(cur + 2) % size];
		int third = vals[(cur + 3) % size];
		int temp;
		if (cur + 1 == size) {
			vals.erase(vals.begin());
			vals.erase(vals.begin());
			vals.erase(vals.begin());
			cur -= 3;
			temp = vals[cur];
		}
		else if (cur + 2 == size) {
			vals.erase(vals.end() - 1);
			vals.erase(vals.begin());
			vals.erase(vals.begin());
			cur -= 2;
			temp = vals[cur];
		}
		else if (cur + 3 == size) {
			vals.erase(vals.end() - 1);
			vals.erase(vals.end() - 1);
			vals.erase(vals.begin());
			cur -= 1;
			temp = vals[cur];
		}
		else {
			auto it = vals.begin();
			advance(it, cur + 1);
			vals.erase(it, it + 3);
			temp = vals[cur];
		}
		vector<int>::iterator it_idx;
		do {
			temp--;
			if (temp < 1)
				temp = 9;
			it_idx = find(vals.begin(), vals.end(), temp);
		} while (it_idx == vals.end());
		int pos = it_idx - vals.begin();
		if (pos <= cur)
			cur += 3;
		vals.insert(it_idx + 1, third);
		vals.insert(it_idx + 1, second);
		vals.insert(it_idx + 1, first);
		cur = (cur + 1) % size;
	}

	int sum = 0;
	for (int i = 0; i < vals.size(); i++)
	{
		if (vals[i] == 1) {
			for (int j = 0; j < vals.size() - 1; j++)
			{
				sum += vals[(i + j + 1) % vals.size()];
				sum *= 10;
			}
		}
	}

	return sum / 10;
}

uint64_t Day23::part_two(int input) {

	vector<int> vals;
	while (input != 0) {
		vals.insert(vals.begin(), input % 10);
		input /= 10;
	}
	vector<node*> index(1'000'000 + 1);
	vector<node> nodes(1'000'000);
	for (int i = 0; i < vals.size(); i++)
	{
		nodes[i] = { vals[i], nullptr };
		index[nodes[i].value] = &nodes[i];
		if (i > 0) {
			nodes[i - 1].next = &nodes[i];
		}
	}
	for (int i = vals.size(); i < 1'000'000; i++)
	{
		nodes[i] = { i + 1,nullptr };
		index[nodes[i].value] = &nodes[i];
		if (i > 0) {
			nodes[i - 1].next = &nodes[i];
		}
	}
	nodes.back().next = &nodes[0];

	int low = 1;
	int high = 1'000'000;

	int num_rounds = 10'000'000;

	array<int64_t, 3> picked;

	node* p = &nodes[0], * q = nullptr, * r = nullptr;
	for (int i = 0; i < num_rounds; i++)
	{
		q = p->next;
		picked[0] = q->value;
		q = q->next;
		picked[1] = q->value;
		q = q->next;
		picked[2] = q->value;

		int d = p->value - 1;
		if (d < low)
			d = high;
		while (find(picked.begin(), picked.end(), d) != picked.end()) {
			if (--d < low) d = high;
		}
		r = index[d];

		node* tmp = q->next;
		q->next = r->next;
		r->next = p->next;
		p->next = tmp;
		p = p->next;
	}

	node* elem1 = index[1];
	return static_cast<uint64_t>(elem1->next->value) * elem1->next->next->value;
}
