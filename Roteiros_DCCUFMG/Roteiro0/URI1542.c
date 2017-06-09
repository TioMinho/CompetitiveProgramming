#include <stdio.h>
#include <math.h>

int main()
{
	int Q, D, P;
	int X;

	while(scanf("%d", &Q) && Q != 0)
	{
		scanf("%d", &D);
		scanf("%d", &P);

		X = (P*D*Q)/(P-Q);
		printf("%d pagina", X);

		if(X != 1)
			printf("s");

		printf("\n");
	}

	return 0;
}