#include <iostream>

using namespace std;

#define MAXN 52

int C[MAXN];

int main() {
	int N;
	int size;

	cin >> N; size = N;

	cin >> C[0];
	for (int i = 1; i < N; ++i)	{
		cin >> C[i];

		if(C[i-1] >= C[i])
			size--;
	}

	cout << size << endl;

	return 0;
}