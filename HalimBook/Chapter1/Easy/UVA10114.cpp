#include <iostream>

#define MAXN 100

using namespace std;

double D[MAXN+1];

int main() {
	int M, aux1;
	double P, L, Dm, aux2;

	while(1) {
		cin >> M >> P >> L >> Dm;

		if(M < 0) break;

		for (int i = 0; i < Dm; ++i) {
			cin >> aux1 >> aux2;
			
			for(int i = aux1; i < MAXN+1; i++)
				D[i] = aux2;
		}

		double carV = L + P, currL = L + (L / M);
		for (int i = 0; i <= M; ++i) {
			carV *= (1 - D[i]);
			currL -= (L / M);
			
			// cout << "L: " << currL << " carV: " << carV << " D[i]: " << D[i] << endl;
			
			if(currL <= carV) { M = i; break; };
		}

		if(M == 1) printf("%d month\n", M);
		else	   printf("%d months\n", M);
	}

	return 0;
}