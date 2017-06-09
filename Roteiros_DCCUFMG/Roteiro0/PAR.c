#include <stdio.h>
#include <string.h>

int main()
{
	char names[2][256];
	int n, num[2];

	scanf("%s", &names[0]);
	scanf("%s", &names[1]);

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &num[0], &num[1]);

		printf("%s\n", names[(num[0] + num[1]) % 2 == 1]);
	}	

	return 0;
}