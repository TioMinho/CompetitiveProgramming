#include <stdio.h>
#include <math.h>

int main()
{
	int N;

	scanf("%d", &N);

	printf("%.0lf", pow(2, N) - 1);

	return 0;
}