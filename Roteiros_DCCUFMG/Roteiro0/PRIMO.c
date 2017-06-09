#include <stdio.h>

int main()
{
	int N;

	scanf("%d", &N);

	for(int i = 2; i < N; i++)
		if(N % i == 0) {
			printf("%d nao eh um numero primo.\n", N);
			return 0;
		}

	printf("%d eh um numero primo.\n", N);

	return 0;
}