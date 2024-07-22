#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;

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
int sum;

pair<int, int> carddist() {

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

//string dealer() {

	//pair<int, int> coords = carddist();
	//int xcord = coords.first;
	//int ycord = coords.second;
	//string card = cards[xcord][ycord];

	//return card;
//}




int main() {
	cout << "press any key to start";
	cin.get();

	vector<int> cardcord1;
	//draw dealer's card
	for (int i = 0; i < 2; i++) {
		pair<int, int> coords = carddist();
		int xcord = coords.first;
		int ycord = coords.second;
		string card1 = cards[xcord][ycord];
		cin.get();

		//put coordinates of cards into "cardcord" vector(array)
		cardcord1.push_back(xcord);
		cardcord1.push_back(ycord);

		cout << "dealer's card ";
		cout << card1 << endl;
	}



	cin.get();




	vector<int> cardcord;
	srand(time(NULL));

	//print random card
	cout << "your card: \n";
	for (int i = 0; i < 2; i++) {
		pair<int, int> coords = carddist();
		int xcord = coords.first;
		int ycord = coords.second;
		string card = cards[xcord][ycord];
		cout << card;
		cin.get();

		//put coordinates of cards into "cardcord" vector(array)
		cardcord.push_back(xcord);
		cardcord.push_back(ycord);
	};

	sum = cardsum(cardcord[0], cardcord[2]);

	cout << "(total:";
	cout << sum;
	cout << ")\n";


	char resp;
	resp = 'h';


	//next options
	while (sum <= 21) {
		cout << "Would you stand or hit?(S or H)";
		cin >> resp;
		resp = tolower(resp);

		if (resp == 'h') {

			pair<int, int> coords = carddist();
			int xcord = coords.first;
			int ycord = coords.second;
			string card = cards[xcord][ycord];
			cout << card;

			sum = sum + xcord + 1;

			cout << "\n(total:";
			cout << sum;
			cout << ")\n";
		}
		else if (resp == 's') {
			dcsum = cardsum(cardocord1[0], cardcord1[2]);

			if (dcsum < sum) {
				cout << dcsum;
				cout << sum;
			}
			else {
				cout << dcsum;
				cout << sum;
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

	"dealer's card";


	return 0;
}


//lol