#include <iostream>
#include <set>

using namespace std;

int main() {
	set<string> database;
	string aux;
	int N;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> aux;

		size_t posP = aux.find_first_of('+', 0);
		size_t posA = aux.find_first_of('@', posP);
	
		if(posP != string::npos)
			aux.erase(aux.begin()+posP, aux.begin()+posA);

		posA = aux.find_first_of('@', 0);
		aux.erase(remove(aux.begin(), aux.begin()+posA, '.'), aux.begin()+posA);

		database.insert(aux);
	}

	cout << database.size() << endl;

	return 0;
}