#include <iostream>

using namespace std;

int main() {
	int t;
	long long int A, B;
	cin >> t;
	for(int i = 0 ; i < t; i++) {
		cin >> A >> B;

		if(A > B) cout << ">" << endl;
		else if (A < B) cout << "<" << endl;
		else if (A == B) cout << "=" << endl;
	}
	return 0;
}