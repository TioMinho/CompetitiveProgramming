#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

// Definitions
#define INF 987654321
#define MAXN 100
#define MAXK 10

typedef pair<int, int> City;

// Global Variables
double SteinerDP[MAXN][1<<MAXK];
double distances[MAXN][MAXN];
City C[MAXN];

// Functions
double SteinerTree(int N, int K) {
	fill(SteinerDP[0], SteinerDP[0] + MAXN*(1<<MAXK), INF);

	for (int i = 0; i < K; ++i)	{
		SteinerDP[i][1<<i] = 0;
	}

	for (int mask = 0; mask < (1<<K); ++mask) {
		for (int i = 0; i < N; ++i) {
			for (int ss = mask; ss > 0; ss = (ss-1) & mask) {
				SteinerDP[i][mask] = min(SteinerDP[i][mask], SteinerDP[i][ss]+SteinerDP[i][mask-ss]);
			}

			if(SteinerDP[i][mask] < INF) {
				for (int j = 0; j < N; ++j)
					SteinerDP[j][mask] = min(SteinerDP[j][mask], SteinerDP[i][mask]+distances[i][j]);
			}
		}
	}

	double minTotal = INF;
	for (int i = 0; i < N; ++i)	
		minTotal = min(minTotal, SteinerDP[i][(1<<K)-1]);

	return minTotal;
}

// Main
int main() {
	int N, K, aux1, aux2;	

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> aux1 >> aux2;
		C[i] = make_pair(aux1, aux2);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) { 
			if(i < K and j < K)
				distances[j][i] = distances[i][j] = INF;
			else
				distances[j][i] = distances[i][j] = sqrt(pow(C[i].first - C[j].first, 2) + pow(C[i].second - C[j].second, 2));
		}
	}

	printf("%.5f\n", SteinerTree(N, K));

	return 0;
}