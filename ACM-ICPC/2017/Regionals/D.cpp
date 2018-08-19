#include <iostream>
#include <vector>
#include <cmath>

#define MAXN 10000000

using namespace std;

bool sieve[MAXN];

int main(){
	long long int num;
	std::vector<int> primes;

	for(int i = 2; i < MAXN; i++) {
		if(!sieve[i]) {
			primes.push_back(i);
			for (int j=i+i; j < MAXN; j += j) {
				sieve[j] = 1;
			}
		}
	}

	cin >> num;

	int N = 0;
	for(int i = 0; i < primes.size() && num >= primes[i]; i++) {
		if(num % primes[i] == 0) {
			N++;
			while(num % primes[i] == 0) num /= primes[i];
		}
	} 
	N += (num > 1);

	cout << pow(2, N) - N - 1 << endl;

	return 0;
}