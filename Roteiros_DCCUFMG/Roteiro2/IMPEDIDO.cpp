#include <iostream>
#include <vector>
#include <algorithm>

#define all(c) c.begin(),c.end()

using namespace std;

bool isImpedido(vector<int> &distAtac, vector<int> &distDefens) {
	sort(all(distAtac));
	sort(all(distDefens));

	if(distAtac[0] >= distDefens[1] || (distAtac[0] == distDefens[0] && distAtac[0] == distDefens[1]))
		return false;
	else return true;
}

int main()
{
	int A, D;
	vector<int> atacantes;
	vector<int> defensores;

	while(cin >> A >> D && (A+D) > 0){
		atacantes.clear(); atacantes.resize(A, 0);
		defensores.clear(); defensores.resize(D, 0);

		for (int i = 0; i < A; ++i)
			cin >> atacantes[i];

		for (int i = 0; i < D; ++i)
			cin >> defensores[i];

		if(isImpedido(atacantes, defensores))
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}

	return 0;
}