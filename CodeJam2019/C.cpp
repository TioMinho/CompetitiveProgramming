#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()

#define MAXN 1e4
#define MAXT 100
#define MAXL 100

using namespace std;

vector<int> sieveErastophenes(int n) {
	vector<bool> A(n+1, true);

	for(int i = 2; i < sqrt(n); i++) {
		if(A[i]) {
			int k = 0, j = i*i;
			while(j <= n) {
				A[j] = false;
				
				j = i*i + k*i;
				k++;
			} 
		}
	}

	vector<int> primes;
	for (int i = 2; i < A.size(); ++i)
		if(A[i]) primes.push_back(i);

	return primes;
}

int text[MAXL];

int main()
{
	vector<int> primes;
	set<int> subprimes;
	map<int,char> cypher;
	map<char,int> cypher_r;
	int T, N, L;

	cin >> T;
	for (int i = 0; i < T; ++i) {

		cin >> N >> L;
		for (int j = 0; j < L; ++j) cin >> text[j];

		primes = sieveErastophenes(N);

		subprimes.clear();
		for(int a = 0; a < L; a++) {
			for(int m = 0; m < primes.size(); m++) {
				for(int n = m; n < primes.size(); n++) {
					if(primes[m] * primes[n] == text[a]) {
						subprimes.insert(primes[m]);
						subprimes.insert(primes[n]);
					}
			}	}	
			if(subprimes.size() == 26) break;
		}

		string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		set<int>::iterator it; int a = 0;
		for (it = subprimes.begin(); it != subprimes.end(); ++it) {
			cypher[*it] = alphabet[a];
			cypher_r[alphabet[a]] = *it;

			a++; 
		}

		string real_text = "";
		bool leave = false;

		set<int>::iterator a1, a2;
		for (a1 = subprimes.begin(); a1 != subprimes.end(); ++a1) {
			for (a2 = subprimes.begin(); a2 != subprimes.end(); ++a2) {
				if((*a1) * (*a2) == text[0]) {
					real_text += cypher[*a1]; real_text += cypher[*a2];
					leave = true;
					break;
				}
			}	
			if(leave) break;
		}

		for(int j = 1; j < L; j++){
			for(it = subprimes.begin(); it != subprimes.end(); it++){
				if(cypher_r[real_text[j]] * (*it) == text[j]){
					real_text += cypher[*it];
					break;
				}
			}
		}

		cout << "Case #" << i+1 << ": " << real_text << endl;
	}


	return 0;
}