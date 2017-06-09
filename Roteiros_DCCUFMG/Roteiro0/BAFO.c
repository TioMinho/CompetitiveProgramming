#include <stdio.h>

int main()
{
	int n, i, acc = 0;
	int play1 = 0, play2 = 0;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		scanf("%d", &acc);
		play1 += acc;

		scanf("%d", &acc);
		play2 += acc;
	}

	printf("%s", (play1 >= play2) ? "Jogador 1" : "Jogador 2");

	return 0;
}