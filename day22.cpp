#include <string>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include "day22.h"

using namespace std;

long Day22::part_one(list<string> input) {
	queue<int> player1;
	queue<int> player2;
	bool second = false;
	for (string line : input) {
		if (line == "")
			second = true;
		else if (!line._Starts_with("Player")) {
			if (second)
				player2.push(stoi(line));
			else
				player1.push(stoi(line));
		}
	}
	while (player1.size() > 0 && player2.size() > 0) {
		int p1 = player1.front();
		int p2 = player2.front();
		player1.pop();
		player2.pop();
		if (p1 > p2) {
			player1.push(p1);
			player1.push(p2);
		}
		else {
			player2.push(p2);
			player2.push(p1);
		}
	}
	long result = 0;
	if (player1.empty()) {
		while (!player2.empty()) {
			result += player2.front() * player2.size();
			player2.pop();
		}
	}
	else {
		while (!player1.empty()) {
			result += player1.front() * player1.size();
			player1.pop();
		}
	}
	return result;
}

using game_state = pair<deque<int>, deque<int>>;

struct player
{
	void push(int n) {
		deck.push_back(n);
	}

	int pop() {
		int n = deck.front();
		deck.pop_front();
		return n;
	}

	size_t size() {
		return deck.size();
	}

	bool empty() {
		return deck.empty();
	}

	long score() {
		long result = 0;
		size_t count = deck.size();
		for (int card : deck) {
			result += count * card;
			count--;
		}
		return result;
	}

	std::deque<int> deck;
};

struct game
{
	enum class winner
	{
		p1won,
		p2won
	};

	void deal_p1(int n) {
		player1.push(n);
	}

	void deal_p2(int n) {
		player2.push(n);
	}

	bool check_loop() {
		game_state state = make_pair(player1.deck, player2.deck);
		if (prev_games.find(state) != prev_games.end()) {
			return true;
		}
		else {
			prev_games.insert(state);
		}
		return false;
	}

	winner recursion()
	{
		while (!(player1.empty() || player2.empty())) {
			if (check_loop()) {
				return winner::p1won;
			}
			int card1 = player1.pop();
			int card2 = player2.pop();
			if (player1.size() >= card1 && player2.size() >= card2) {
				game recursive_combat;
				for (int i = 0; i < card1; i++) {
					recursive_combat.deal_p1(player1.deck[i]);
				}
				for (int i = 0; i < card2; i++) {
					recursive_combat.deal_p2(player2.deck[i]);
				}

				winner sub_winner = recursive_combat.recursion();
				if (sub_winner == winner::p1won) {
					player1.push(card1);
					player1.push(card2);
				}
				else {
					player2.push(card2);
					player2.push(card1);
				}
			}
			else if (card1 > card2) {
				player1.push(card1);
				player1.push(card2);
			}
			else {
				player2.push(card2);
				player2.push(card1);
			}
		}
		winner winner = player1.empty() ? winner::p2won : winner::p1won;
		return winner;
	}

	int play_game() {
		winner winner = recursion();
		if (winner == winner::p1won) {
			return player1.score();
		}
		else {
			return player2.score();
		}
	}

	player player1;
	player player2;
	set<game_state> prev_games;
};

long Day22::part_two(list<string> input) {
	game g;
	bool second = false;
	for (string line : input) {
		if (line == "")
			second = true;
		else if (!line._Starts_with("Player")) {
			if (second)
				g.deal_p2(stoi(line));
			else
				g.deal_p1(stoi(line));
		}
	}
	return g.play_game();
}
