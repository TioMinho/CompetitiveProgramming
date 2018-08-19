#include <iostream>
#include <string>

using namespace std;

int main(){
	string N;
	cin >> N;

	int total = 0;
	for(int i = 0; i < N.size(); i++) {
		total += N[i] - '0';
	}

	cout << total % 3 << endl;
}