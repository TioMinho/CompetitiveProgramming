#include <iostream>
#include <algorithm>

#define MAXN 1000
#define MAXM 1000

using namespace std;

int S[MAXN];
int DP[MAXN+1];
int N, M;

int DPSearch(int m, int s, int v) {
	if(m > M) return v;

	int max_m = 0;
	for (int i = 0; i < N; ++i)	{
		if(S[i] & (1 << m) && !(s & (1 << i)))
			max_m = max(max_m, DPSearch(m+1, s | (1 << i), v+1));
	}

	return max(max_m, DPSearch(m+1, s, v));
}

int main() {
	int t, aux;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		S[i] = 0;

		cin >> t;
		for (int j = 0; j < t; ++j) {
			cin >> aux;
			S[i] |= 1 << (aux-1);
		}
	}

	// for (int i = 0; i < N; ++i)
	// 	cout << S[i] << endl;

	cout << DPSearch(0, 0, 0) << endl;

	cout << (1 << 10000) << endl;

	return 0;
}