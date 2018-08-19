#include <iostream>
#include <algorithm>
#include <vector>

#define rall(c) c.rbegin(), c.rend()

using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	vector<int> C(N);
	for(int i = 0; i < N; i++) cin >> C[i];

	sort(rall(C));
	for(int i = K; i < N; i++) {
		if(C[i] == C[i-1]) K++;
		else break;
	}

	cout << K << endl;

	return 0;
}