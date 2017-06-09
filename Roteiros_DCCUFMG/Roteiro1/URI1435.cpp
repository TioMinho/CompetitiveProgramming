#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i, j;

	while(scanf("%d", &N) && N != 0)
	{
		int* matrix = (int*)malloc(N*N*sizeof(int));

		for(i = 0; i < N*N; i++)
			matrix[i] = 0;

		int ini = 0, nAux = N;
		do {
			for(i = ini; i < N - ini; i++) {
				for(j = ini; j < N - ini; j++) {
					matrix[i * N + j] += 1;
				}
			}

			ini++;
			nAux -= 2;
		} while(nAux > 0);

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
