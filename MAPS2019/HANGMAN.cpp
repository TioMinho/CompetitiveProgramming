#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	string P1, P2;
	int tries = 0;

	cin >> P1 >> P2;

	for (int i = 0; i < P2.size() && tries < 10; ++i) {
		size_t posP = P1.find_first_of(P2[i], 0);
		if(posP != string::npos)
			P1.erase(remove(P1.begin(), P1.end(), P2[i]), P1.end());
		else
			tries++;

		if (P1.size() == 0) {
			cout << "WIN" << endl;
			return 0;
		}
	}

	if (P1.size() == 0) cout << "WIN" << endl;
	else cout << "LOSE" << endl;

	return 0;
}