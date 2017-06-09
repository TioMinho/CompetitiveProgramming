#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	int** matrix;
	int sum, max = 0;

	scanf("%d %d", &n, &m);

	matrix = (int**)malloc(sizeof(int*) * n);
	for(int i = 0; i < n; i++)
		matrix[i] = (int*)malloc(sizeof(int) * m);

	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = 0; j < m; j++){
			scanf("%d", &matrix[i][j]);
			sum += matrix[i][j];
		}
	
		if(i == 0 || (i > 0 && sum > max))
			max = sum;
	}	

	for(int i = 0; i < m; i++) {
		sum = 0;
		for(int j = 0; j < n; j++) 
			sum += matrix[j][i];

		if(sum > max)
			max = sum;
	}

	printf("%d\n", max);

	return 0;
}