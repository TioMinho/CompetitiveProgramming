#include <iostream>
#include <algorithm>

#define all(c) c.begin(),c.end()

using namespace std;

int main() {

	string L, aux = "";
	cin >> L;

	for (int i = 0; i < L.size(); ++i) 
		if(L[i] == 'a' || L[i] == 'e' || L[i] == 'i' || L[i] == 'o' || L[i] == 'u')
			aux += L[i];

	for (int i = 0; i < aux.size() / 2; ++i) {
		if(aux[i] != aux[aux.size()-i-1]) {
			cout << "N" << endl;
			return 0;
		}

	}

	cout << "S" << endl;
	return 0;
}