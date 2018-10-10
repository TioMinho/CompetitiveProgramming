#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main () {
	deque<string> C;
	string aux;
	vector<string> H;
	int T;

	cin >> T;
	for(int j = 0; j < T; j++) {
		C.clear(); H.clear();

		for(int i = 0; i < 52; i++) { cin >> aux; C.push_back(aux); }

		int Y = 0, X; 

		H.insert(H.begin(), C.begin()+27, C.end());
		C.erase(C.begin()+27, C.end());

		for(int i = 0; i < 3; i++) {
			if(C.back()[0] == 'A' || C.back()[0] == 'K' || C.back()[0] == 'Q' || C.back()[0] == 'J' || C.back()[0] == 'T')
				X = 10;
			else
				X = (int) C.back()[0] - '0';

			Y += X;

			C.erase(C.begin()+C.size()-(11-X), C.end());
		}


		C.insert(C.end(), H.begin(), H.end());

		cout << "Case " << j+1 << ": " << C[Y-1] << endl;
	}

	return 0;
}