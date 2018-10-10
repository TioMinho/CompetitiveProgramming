#include <iostream>
#include <map>

using namespace std;

char suitRel[4] = {'S', 'H', 'D', 'C'};
short suit(char c) {
	if(c == 'S') return 0;
	if(c == 'H') return 1;
	if(c == 'D') return 2;
	if(c == 'C') return 3;
}

int main() {
	string card[13];

	while(cin >> card[0]) {
		int P = 0;
		int nS[4] = {0, 0, 0, 0};
		bool stops[4] = {0, 0, 0, 0};

		nS[suit(card[0][1])]++;
		for(int i = 1; i < 13; i++) { 
			cin >> card[i];

			nS[suit(card[i][1])]++;
		}

		for(int i = 0; i < 13; i++) {
			if(card[i][0] == 'A') {
				P += 4;

				stops[suit(card[i][1])] = 1;
			} else if(card[i][0] == 'K') {
				P += 3;

				if(nS[suit(card[i][1])] > 1) stops[suit(card[i][1])] = 1;
				if(nS[suit(card[i][1])] == 1) P--;

			} else if(card[i][0] == 'Q') {
				P += 2;
				
				if(nS[suit(card[i][1])] > 2) stops[suit(card[i][1])] = 1;
				if(nS[suit(card[i][1])] <= 2) P--;

			} else if(card[i][0] == 'J') {
				P += 1;
				
				if(nS[suit(card[i][1])] <= 3) P--;

			}
		}

		if(P >= 16 && stops[0]+stops[1]+stops[2]+stops[3] == 4) {
			cout << "BID NO-TRUMP" << endl;
			continue;
		}

		char M; int maior = 0;
		for(int i = 0; i < 4; i++) {
			if(nS[i] > maior) { maior = nS[i]; M = suitRel[i]; } 

			if(nS[i] == 2) P++;
			if(nS[i] == 1) P+=2;
			if(nS[i] == 0) P+=2;
		}

		if(P >= 14)
			cout << "BID " << M << endl;
		else
			cout << "PASS" << endl;
	}
	
	return 0;
}