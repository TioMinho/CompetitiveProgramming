#include <iostream>
#include <vector>
#include <algorithm>

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

using namespace std;

string notes_elem[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si", "desafinado"};
int pattern[] = {2, 2, 1, 2, 2, 2, 1};

int main() {
	int N, aux;
	vector<int> notes;
	

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> aux;
		notes.push_back((aux-1) % 12);
	}

	vector< vector<int> > scales(12, vector<int>(7));
	for(int i = 0; i < 12; i++) {
		scales[i][0] = i;
		for(int j = 0; j < 7; j++) {
			scales[i][j+1] = (scales[i][j] + pattern[j]) % 12;
		}
	}
	
	int i; aux = 0; bool isComplete;
	for(i = 0; i < scales.size(); i++) {
		isComplete = true;

		for(int j = 0; j < notes.size(); j++) {
			if(find(all(scales[i]), notes[j]) == scales[i].end()) {
				isComplete = false;
				break;
			}
		}

		if(isComplete) break;
	}

	cout << notes_elem[i] << endl;

	return 0;
}