#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int V[3];

	cin >> V[0] >> V[1] >> V[2];

	bool isPre = false;
	isPre = (V[0] == V[1] || V[1] == V[2] || V[0] == V[2]
		     || (V[0]+V[1]) == V[2] || (V[0]+V[2]) == V[1] || (V[1]+V[2]) == V[0]);

	if(isPre)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
	return 0;
}