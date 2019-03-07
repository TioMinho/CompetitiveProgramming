#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN 10000

double C[MAXN+2], D[MAXN+2], DP[MAXN+2];

int main() {
	int N;

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> D[i] >> C[i]; 
		DP[i] = 1e15;
	}

	for (int i = 1; i <= N; ++i) {
		// Take trip after last discount ends
		DP[i] = min(DP[i], DP[i-1] + C[i]);

		// Take next trip using discount for this trip (after wait interval)
		if(D[i] < 120)
			DP[i+1] = min(DP[i+1], DP[i-1] + C[i] + .5*C[i+1]);

		// Propagate the discount for the next 4 trips
		double Ctotal = 0;
		int Dtotal = D[i];

		for (int j = i+1; j <= 4; ++j) {
			Dtotal += D[j];
			Ctotal += C[j+1]; 
			
			if(Dtotal < 120)
				DP[j+1] = min(DP[j+1], DP[i-1] + C[i] + .5*C[i+1] + .25*Ctotal);
		}
	}

	printf("%.2f\n", DP[N]);

	return 0;
}