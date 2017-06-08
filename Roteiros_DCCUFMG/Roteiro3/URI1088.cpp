#include <iostream>
#include <stdlib.h>

using namespace std;

int invCount(int* V, int size)
{
	int times = 0;
	int aux;

	for(int i = 0; i < size; i++) {
		if(V[i] != i+1) {
			times += 2*abs(V[i]-1 - i) - 1;

			aux = V[i];
			V[i] = V[V[i]-1];
			V[aux-1] = aux;

			i--;
		}
	}

	return times;
}


int main()
{
	int *V;
	int x;

	while(cin >> x && x != 0) {
		V = (int*) malloc(sizeof(int) * x);
		for(int i = 0; i < x; i++)
			cin >> V[i];

		int times = invCount(V, x);
		if(times % 2 == 1)
			cout << "Marcelo" << endl;
		else
			cout << "Carlos" << endl;
	}

	return 0;
}