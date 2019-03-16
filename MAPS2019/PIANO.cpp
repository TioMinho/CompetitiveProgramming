#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>

#define MAXN 1000
#define MAXM 1000

using namespace std;

int N, M;

vector< bitset<MAXM> > S_bs;

bool compare(bitset<MAXM> &lhs, bitset<MAXM> &rhs) {
	return lhs.count() < rhs.count();
}

int main() {
	int t, aux;
	bitset<MAXM> aux_bs;

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		aux_bs.reset();

		cin >> t;
		for (int j = 0; j < t; ++j) {
			cin >> aux;
			aux_bs.set(aux-1);
		}

		S_bs.push_back(aux_bs);
	}

	sort(S_bs.begin(), S_bs.end(), compare);

	int count = 0;
	for (int i = 0; i < M; ++i)	{
		for (int j = 0; j < S_bs.size(); ++j) {
			if(S_bs[j].test(i)) {
				count++;
				S_bs.erase(S_bs.begin()+j);
				break;
			}
		}

		for (int j = 0; j < S_bs.size(); ++j) S_bs[j].reset(i);
		sort(S_bs.begin(), S_bs.end(), compare);
	}

	// for (int i = 0; i < S_bs.size(); ++i)
	// 	cout << S_bs[i] << endl;

	cout << count << endl;

	return 0;
}