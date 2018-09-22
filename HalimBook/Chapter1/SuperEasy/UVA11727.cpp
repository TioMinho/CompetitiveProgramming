#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T,A,B,C;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> A >> B >> C;
		int SAL[] = {A, B, C};
		
		sort(SAL, SAL+3);
		
		cout << "Case " << i+1 << ": " << SAL[1] << endl;
	}

	return 0;
}