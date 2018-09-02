#include <iostream>

#define MAXN 50000

using namespace std;

int M[MAXN];
int H[MAXN];
int N;

int main() {
	int maior = 0, prev;

	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> M[i];

	prev = 0;
	for(int i = 0; i < N; i++) {
		H[i] = (M[i] > prev) ? prev+1 : M[i];
		prev = H[i];
	}

	prev = 0;
	for(int i = N-1; i >= 0; i--) {
		prev = (M[i] > prev) ? prev+1 : M[i];
		

		int min = (prev < H[i]) ? prev : H[i];
		if(maior < min) maior = min; 
	}

	cout << maior << endl;

	return 0;
}