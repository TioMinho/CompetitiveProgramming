#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

uint64_t countInv(int* V, int size) {
	int i = 0, size1 = size - (size/2), j = 0, size2 = size/2;
	int *V1 = (int*) malloc(sizeof(int) * size1);
	int *V2 = (int*) malloc(sizeof(int) * size2);

	uint64_t count = 0;

	for (int k = 0; k < size; k++) {
		if(k < size1)
			V1[i++] = V[k];
		else
			V2[j++] = V[k];
	}

	sort(V1, V1+size1);
	sort(V2, V2+size2);

	i = j = 0;

	for (int k = 0; k < size; k++) {
		if(size2 == 0) {
			count += size1;
			size1--;
		}
		else if(size1 > 0) {
			if(V1[i] > V2[j]) {
				count += size1;
				size2--;
				j++;
			}
			else{
				size1--;
				i++;
			}
		}
	}

	return count;
}

int main()
{
	int T, N;
	int *V;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		V = (int*) malloc(sizeof(int) * N);
		
		for (int j = 0; j < N; j++)
			cin >> V[j];

		cout << countInv(V, N) << endl;			

	}

	return 0;
	
}