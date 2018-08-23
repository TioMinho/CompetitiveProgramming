#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector< vector<long long int> > matrix;

#define MOD 100000

matrix mul(matrix A, matrix B) {
	matrix C(3, vector<long long int>(3));

	for(int i = 1; i < 3; i++)
		for(int j = 1; j < 3; j++)
			for(int k = 1; k < 3; k++)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;

	return C;
}

matrix pow(matrix A, int P) {
	
	if(P == 1) return A;
	if(P % 2 == 1) return mul(A, pow(A, P-1));

	matrix X = pow(A, P/2);

	return mul(X, X);
}

int main() {
	int A, B, N, K;

	cin >> A >> B >> N >> K;

	matrix T(3, vector<long long int>(3));
	T[1][1] = 0;   T[1][2] = 1;
	T[2][1] = (B - A*A); T[2][2] = 2*A; 

	T = pow(T, N);

	long long int res = 2 * T[1][1] + (2*A) * T[1][2];

	cout << res << endl;

	return 0;
}
