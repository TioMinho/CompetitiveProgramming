#include <iostream>
#include <limits>
#include <string.h>

using namespace std;

int main() {
	int RFP = 1;
	char bestN[81], trash[81];
	double bestP, bestC, auxP;
	int N, P, auxC;

	while(cin >> N >> P && N*P != 0) {
		bestC = -1; bestP = 0;

		cin.ignore();
		for (int i = 0; i < N; ++i)	cin.getline(trash, 81);  
		
		for (int i = 0; i < P; ++i) {
			cin.getline(trash, 81);
			cin >> auxP >> auxC;

			// cout << trash << " " << auxP << " " << auxC << endl;
			if(auxC*1.0/N > bestC || (auxC*1.0/N == bestC && (auxP < bestP || auxP == 0))) {
				strcpy(bestN, trash); bestP = auxP; bestC = auxC*1.0/N;

				// cout << bestP << " " << bestC << endl;
			}

			cin.ignore();
			for (int i = 0; i < auxC; ++i) cin.getline(trash, 81);
		}

		if(RFP > 1) cout << endl;
		cout << "RFP #" << RFP << endl << bestN << endl;

		RFP++;
	}

	return 0;
}