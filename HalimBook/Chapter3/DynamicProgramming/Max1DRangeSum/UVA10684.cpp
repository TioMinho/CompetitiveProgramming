#include <iostream>

#define MAXN 10000

using namespace std;

long int kadane(int A[], int N) {
	long int A_res = -1, sumHere = -1;
	for (int i = 0; i < N; ++i) {
		if(sumHere < 0)
			sumHere =  A[i];
		else {
			sumHere += A[i];
		}

		A_res = max(A_res, sumHere);
	}

	return A_res;
}

int main() {
	int A[MAXN], N, i;
	long int A_res;

	while(scanf("%d", &N) && N != 0) {
		i = 0;
		while(scanf("%d", &A[i++]) && i != N);

		A_res = kadane(A, N);
		if(A_res <= 0)  printf("Losing streak.\n");
		else			printf("The maximum winning streak is %ld.\n", A_res);
	}

	return 0;
}