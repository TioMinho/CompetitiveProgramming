#include <bits/stdc++.h> 

#define MAXN 100
#define INF  999999999

using namespace std;

int sumArray(int A[], int N) {
	int sum = 0;
	for (int i = 0; i < N; ++i)	
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

int kadane2D(int A[][MAXN], int N) {
	int temp[N], maxUntilNow = -INF;
	
	for (int i = 0; i < N; ++i)	{
		for (int j = i; j < N; ++j) {
			for(int k = 0; k < N; ++k) temp[k] = sumArray(A[k]+i, j-i+1);

			maxUntilNow = max(maxUntilNow, kadane(temp, N));
		}
	}

	return maxUntilNow;
}

int main() {
	int N, A[MAXN][MAXN];

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)	
		for (int j = 0; j < N; ++j)
			scanf("%d", &A[i][j]);

	printf("%d\n", kadane2D(A, N));

	return 0;
}