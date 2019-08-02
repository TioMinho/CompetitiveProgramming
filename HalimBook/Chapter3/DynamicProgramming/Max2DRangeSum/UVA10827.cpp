#include <bits/stdc++.h> 

#define MAXN 100*2
#define INF  999999999

using namespace std;

int sumArray(int A[], int N) {
	int sum = A[0];
	for (int i = 1; i < N; ++i)	
		 sum += A[i];
	return sum;
}

int kadane(int A[], int N) {
	int A_res = -INF, sumHere = -INF;
	for (int i = 0; i < N; ++i) {
		if(sumHere < 0)
			sumHere =  A[i];
		else 
			sumHere += A[i];

		A_res = max(A_res, sumHere);
	}

	return A_res;
}

int kadane2D_mod(int A[][MAXN], int N, int l, int r) {
	int temp[N], maxUntilNow = -INF;
	
	for (int i = l; i < N+l; ++i)	{
		for (int j = i; j < N+l; ++j) {
			for(int k = r; k < N+r; ++k) temp[k-r] = sumArray(A[k]+i, j-i+1);

			maxUntilNow = max(maxUntilNow, kadane(temp, N));
		}
	}

	return maxUntilNow;
}

void printRect(int A[][MAXN], int N) {
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) {
			printf("%d ", A[i][j]);
		} printf("\n");
	}
}

int main() {
	int T, N, A[MAXN][MAXN];
	int maximum;

	scanf("%d", &T);
	for (int t = 0; t < T; ++t)	{
		scanf("%d", &N);

		for (int i = 0; i < N; ++i)	{
			for (int j = 0; j < N; ++j){
				scanf("%d", &A[i][j]);

				A[i+N][j] = A[i][j+N] = A[i+N][j+N] = A[i][j];
			}
		}

		maximum = -INF;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				maximum = max(maximum, kadane2D_mod(A, N, i, j));

		printf("%d\n", maximum);
	}

	return 0;
}