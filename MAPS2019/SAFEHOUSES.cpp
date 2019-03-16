#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

#define MAXN 100

using namespace std;

char CITY[MAXN][MAXN];
vector< pair<int,int> > H;
vector< pair<int,int> > S;
int minDist[MAXN*MAXN];

int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
		cin >> CITY[i][j];
		if(CITY[i][j] == 'H')
			H.push_back(make_pair(i, j));
		else if(CITY[i][j] == 'S')
			S.push_back(make_pair(i, j));
	}

	int min = 1e6;
	for (int i = 0; i < S.size(); ++i) {
		for (int j = 0; j < H.size(); ++j) {
			int aux = abs(S[i].first - H[j].first) + abs(S[i].second - H[j].second);
			if(aux <= min) min = aux;
		}

		minDist[i] = min;
		min = 1e6;
	}

	cout << *max_element(minDist, minDist+S.size()) << endl;

	return 0;
}