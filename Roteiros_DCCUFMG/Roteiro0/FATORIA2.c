#include <stdio.h>

int main()
{
	int n;
	long int fat = 1;

	scanf("%d", &n);

	for(int i = 1; i <= n; fat *= i++);

	printf("%ld", fat);

	return 0;
}