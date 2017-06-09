#include <stdio.h>

int main()
{
	int valores[100];
	int maior, indice, i;

	for(i = 0; i < 100; i++){
		scanf("%d", &valores[i]);

		if(i == 0 || valores[i] >= maior) {
			maior = valores[i];
			indice = (i+1);
		}
	}

	printf("%d\n%d\n", maior, indice);

	return 0;
}