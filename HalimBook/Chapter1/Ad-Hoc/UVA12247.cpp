#include <iostream>
#include <algorithm>
#include <vector>

#define all(c) c.begin(),c.end()

using namespace std;

bool cards[53];

int main() {
	int resp;

	while(1) {
		resp = 0;
		vector<int> ps(3,0), pr(2,0);

		cin >> ps[0] >> ps[1] >> ps[2] >> pr[0] >> pr[1];
		
		if(ps[0] * ps[1] * ps[2] * pr[0] * pr[1] == 0) break;

		cards[ps[0]] = 1; cards[ps[1]] = 1; cards[ps[2]] = 1; cards[pr[0]] = 1; cards[pr[1]] = 1;
		sort(all(ps)); sort(all(pr));
		
		bool oneLose = false;
		for (int i = 0; i < 3; ++i)	{
			if(ps[i] > pr[0]) {
				oneLose = true;
				ps.erase(ps.begin()+i);
				break;
			}
		}

		if(!oneLose) {
			while(cards[++resp]);
			cout << resp << endl;
		} else {

			if(ps[1] > pr[1]) cout << "-1" << endl;
			else {
				resp = ps[1];
				while(cards[++resp]);
				if(resp < 53) cout << resp << endl;
				else		  cout << "-1" << endl;
			}
		}

		for(int i = 0; i < 53; i++) cards[i] = 0;
	}

	return 0;
}