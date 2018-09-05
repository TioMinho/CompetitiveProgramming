#include <iostream>
#include <algorithm>

#define MAXN 500

using namespace std;

int GO[MAXN][MAXN];
int PP[MAXN][MAXN];
int PB[MAXN][MAXN];

int main() {

	int N, P, L, C;
	int maxB=0, maxP=0;
	cin >> N >> P;

	for (int i = 1; i <= 2; ++i) for (int j = 0; j < P; ++j) {
		cin >> L >> C;
		GO[L-1][C-1] = i;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if(GO[i][j] != 2){
				if(i-1 < 0 || j-1 < 0)
					PP[i][j] = 1;
				
				else {
					int minK = min({PP[i-1][j], PP[i-1][j-1], PP[i][j-1]});
					PP[i][j] = minK+1;
				}
			}

			if(GO[i][j] != 1){
				if(i-1 < 0 || j-1 < 0)
					PB[i][j] = 1;
				
				else {
					int minK = min({PB[i-1][j], PB[i-1][j-1], PB[i][j-1]});
					PB[i][j] = minK+1;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			maxP += max(0, PP[i][j]-PB[i][j]);
			maxB += max(0, PB[i][j]-PP[i][j]);
		}
	}

	cout << maxP << " " << maxB << endl;

	return 0;
		
}