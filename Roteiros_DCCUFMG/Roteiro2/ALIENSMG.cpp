#include <iostream>
#include <string>
#include <set>
#include <algorithm>

#define all(c) c.begin(),c.end()

using namespace std;

int main()
{
	int n;
	string aux;
	set<string> individuals;

	while(cin >> n && n != 0) {
		individuals.clear();
		for(int i = 0; i < n; i++){
			cin >> aux;
			sort(all(aux));
			individuals.insert(aux);
		}

		cout << individuals.size() << endl;
	}

	return 0;
}