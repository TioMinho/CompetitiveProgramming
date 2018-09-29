#include <iostream>

#define MAXN 100+1
#define MAXT 50+1

using namespace std;

int main() {
	int T,N,aux,max;

	cin >> T;
	for(int i = 0; i < T; i++) {
		max = 0;
		
		cin >> N;
		for(int j = 0; j < N; j++){
			cin >> aux;
			if(aux > max) max = aux;
		}

		cout << "Case " << i+1 << ": " << max << endl;
	}

	return 0;
}