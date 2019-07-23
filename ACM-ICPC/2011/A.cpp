#include <bits/stdc++.h> 
#include <string>
#include <stack>

using namespace std;

// Abordagem Gulosa (Sempre que há duas ligações, essa escolha é ótima)
int stackVerify(string fita) {
	stack<char> baseStack;
	
	baseStack.push(fita[0]);
	int numLigacoes = 0;

	for(int i = 1; i < fita.size(); i++) {	
		if(!baseStack.empty()) {
			char temp = baseStack.top();
			if((temp == 'B' && fita[i] == 'S') ||
	 			(temp == 'S' && fita[i] == 'B') ||
	 			(temp == 'F' && fita[i] == 'C') ||
	 			(temp == 'C' && fita[i] == 'F')) 
			{
				numLigacoes++;
				baseStack.pop();
			}
			else
				baseStack.push(fita[i]);
		}
		else
			baseStack.push(fita[i]);
	}

	return numLigacoes;
}

int main() {
	string fitaRNAA;

	while(cin >> fitaRNAA) printf("%d\n", stackVerify(fitaRNAA));

	return 0;
}