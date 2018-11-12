#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int T, r, c, res;
	char cp;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> cp >> r >> c;

		if(cp == 'Q') {
			res = min(r, c);
		}
		else if(cp == 'K') {
			res = ceil(r*1.0/2) * ceil(c*1.0/2);
		}
		else if(cp == 'k') {
			res = ceil((r*c)*1.0 / 2);
		}
		else if(cp == 'r') {
			res = min(r, c);
		}

		cout << res << endl;
	}

	return 0;
}