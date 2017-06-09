#include <stdio.h>

int main()
{
	int n, i;
	double num, soma = 0;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%lf", &num);
		soma += num;
	}

	printf("%lf", soma);

	return 0;
}