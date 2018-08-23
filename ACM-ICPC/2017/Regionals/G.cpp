#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000+7

int main() {
	int T, M, N;

	cin >> T >> M >> N;

	vector< vector<long long int> > F(T, vector<long long int>(N-M+1, 1));
	for(int i = 1; i < T; i++) {
		F[i][0] = F[i-1][1];
		F[i][N-M] = F[i-1][N-M-1];

		for(int j = 1; j < N-M; j++)
			F[i][j] = (F[i-1][j-1] + F[i-1][j+1]) % (MOD);
	}

	long long int res = 0;
	for(int i = 0; i < N-M+1; i++)
		res += F[T-1][i];

	cout << res % (MOD) << endl;

	return 0;
}