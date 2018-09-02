#include <iostream>

using namespace std;

int main() {

	long int D, nD, M, nM;
	long int l, r;
	cin >> D >> nD >> M >> nM;

	long int menor = M+1;
	for (long int n = 1; n*n <= M; n++)	{
		l = n; r = (M/n);

		if(l % nD != 0 && nM % l != 0 && l % D == 0 && M % l == 0
			&& l < menor) {
			menor = l;
		}
		else if(r % nD != 0 && nM % r != 0 && r % D == 0 && M % r == 0
			&& r < menor) {
			menor = r;
		}
	}

	if( menor < M+1 )
		cout << menor << endl;
	else
		cout << -1 << endl;
	return 0;
}