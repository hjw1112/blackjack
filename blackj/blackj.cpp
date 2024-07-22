#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;
srand(time(NULL));

//card lists
vector<vector<string>> cards = {
	{"♠A", "♥A", "♦A", "♣A"},
	{"♠2", "♥2", "♦2", "♣2"},
	{"♠3", "♥3", "♦3", "♣3"},
	{"♠4", "♥4", "♦4", "♣4"},
	{"♠5", "♥5", "♦5", "♣5"},
	{"♠6", "♥6", "♦6", "♣6"},
	{"♠7", "♥7", "♦7", "♣7"},
	{"♠8", "♥8", "♦8", "♣8"},
	{"♠9", "♥9", "♦9", "♣9"},
	{"♠10", "♥10", "♦10", "♣10"},
	{"♠J", "♥J", "♦J", "♣J"},
	{"♠Q", "♥Q", "♦Q", "♣Q"},
	{"♠K", "♥K", "♦K", "♣K"}
};
vector<int> cardcord_player;
vector<int> cardcord_dealer;
int player_sum;
int dealer_sum;

pair<int, int> cardgen() {

	//generate random coordinates for selecting card.
	int Randindex = rand() % 52;
	int xcord = Randindex / 4;
	int ycord = Randindex % 4;
	return make_pair(xcord, ycord);
}


int cardsum(int val1, int val2) {
	//add up the valuers of card.
	if (val1 > 9)
		val1 = 9;
	if (val2 > 9)
		val2 = 9;
	return val1 + val2 + 2;
};

string draw_card(string who) {

	//draw dealer's card(twice)
	for (int i = 0; i < 2; i++) {
		pair<int, int> coords = cardgen();
		int xcord = coords.first;
		int ycord = coords.second;
		string card1 = cards[xcord][ycord];
		cin.get();

		//put coordinates of cards into "cardcord1" vector(array)
		cardcord_[who].push_back(xcord);
		cardcord_[who].push_back(ycord);


		return card1;
	};
};


int main() {
	cout << "press any key to start";
	cin.get();
	cout << "dealer's card: " << draw_card("dealer") << endl;
	dealer_sum = cardsum(cardcord_dealer[0], cardcord_dealer[2]);

	if (dealer_sum < 17) {
		draw_card("dealer")
			dealer_sum = dealer_sum + *(cardcord_dealer.end() - 2) + 1;
		
	}
	cout << dealer_sum << endl;

	cin.get()

		cout << "your card" << draw_card("player") << endl;
	player_sum = cardsum(cardcord_player[0], cardcord_player[2]);
	cout << "(total:" << player_sum ")\n";

	char SorH;

	while (sum <= 21) {
		cout << "Would you stand or hit?(S or H)";
		cin >> SorH;
		SorH = tolower(SorH);

		if (SorH == 'h') {

			cout << draw_card("player") << endl

				player_sum = player_sum + *(cardcord_player.end() - 2) + 1;

			cout << "\n(total:";
			cout << sum;
			cout << ")\n";
		}

		else if (SorH == 's') {

			if (dealer_sum < player_sum) {
				cout << "dealer sum" << dealer_sum;
				cout << "your sum" << player_sum;
				cout << "you won";
			}
			else {
				cout << "dealer sum" << dealer_sum << "\n";
				cout << "your sum" << player_sum << "\n";
				cout << "dealer won";
			}

			break;
		}
		else {
			cout << "wrong input\n";
		}

	}

	if (sum > 21) {
		cout << "bust(over 21)\n";
	}



	return 0;
}