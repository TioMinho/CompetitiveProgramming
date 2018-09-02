#include <iostream>

using namespace std;

int main() {
	long long int R,G,B;

	cin >> hex >> R >> G >> B;

	long long int verde = (R >= G)* (R/G)*(R/G);
	long long int azul = (G >= B)* verde*(G/B)*(G/B);
	long long int total = azul+verde+1;

	cout << hex << total << endl;
	
	return 0;
}