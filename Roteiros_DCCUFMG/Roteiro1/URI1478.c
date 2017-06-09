#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i, j, k;

	while(scanf("%d", &N) && N != 0)
	{
		int* matrix = (int*)malloc(N*N*sizeof(int));

		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				if(i == j) matrix[i * N + j] = 1;

		for(k = 0; k < N; k++)
		{
			for(i = k; i < N - 1; i++)
				matrix[(i+1) * N + k] = matrix[i * N + k] + 1;

			for(j = k; j < N - 1; j++)
				matrix[k * N + (j+1)] = matrix[k * N + j] + 1;
		}

		for(i = 0; i < N; i++) {
			for(j = 0; j < N; j++) {
				if(j == 0) printf("%3d", matrix[i * N + j]);
				else printf("%4d", matrix[i * N + j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
