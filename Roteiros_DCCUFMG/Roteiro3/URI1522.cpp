#include <iostream>
#include <stack>
#include <cstdint>

using namespace std;

bool canWin(stack<int> p[3])
{
	if(p[0].empty() && p[1].empty() && p[2].empty())
		return true;
	else {
		int tops[] = {	p[0].empty() ? 0 : p[0].top(),
						p[1].empty() ? 0 : p[1].top(),
						p[2].empty() ? 0 : p[2].top() };

		if((tops[0] + tops[1] + tops[2]) % 3 == 0) {
			p[0].pop(); p[1].pop(); p[2].pop();
			
			if(canWin(p)) return true;
			
			p[0].push(tops[0]); p[1].push(tops[1]); p[2].push(tops[2]);
		}
		else {
			for (int i = 0; i < 3; i++)	{
				for (int j = i+1; j < 3; j++) {
					if((tops[i] + tops[j]) % 3 == 0) {
						p[i].pop(); p[j].pop();

						if(canWin(p)) return true;

						p[i].push(tops[i]); p[j].push(tops[j]);
					}
				}
				p[i].pop();

				if(canWin(p)) return true;

				p[i].push(tops[i]);
			}

		}

		return false;
	}
}


int main()
{
	uint64_t x;
	stack<int> pilha[3];

	pilha[0].push(1);
	pilha[0].push(0);
	pilha[0].push(0);
	pilha[1].push(0);
	pilha[1].push(1);
	pilha[1].push(0);
	pilha[2].push(0);
	pilha[2].push(0);
	pilha[2].push(0);

	cout << canWin(pilha) << endl;

	//cout << canWin(pilha[0], pilha[1], pilha[2]) << endl;

	// while(cin >> x && x != 0) {
	// 	V = (int*) malloc(sizeof(int) * x);
	// 	for(int i = 0; i < x; i++)
	// 		cin >> V[i];

	// 	int times = invCount(V, x);
	// 	if(times % 2 == 1)
	// 		cout << "Marcelo" << endl;
	// 	else
	// 		cout << "Carlos" << endl;
	// }

	return 0;
}