#include <iostream>

using namespace std;

#define MAXN 10000

long long int C[MAXN];

long long int MDC(long long int A, long long int B) {
	long long int r;
	while (B != 0){
       r = A % B;
       A = B;
       B = r;
   }
	
	return A;
}

long long int MMC(long long int A, long long int B) {
	if (A == B || B == 1)return A;
	if (A == 1) return B;
	return (A * B) / MDC(A,B);
}

int main()
{
	int N, L;
	long long int mmc_initial;

	cin >> N >> L;
	for(int i = 0; i < N; i++) 
		cin >> C[i];

	mmc_initial = MMC(C[0], C[1]);
	for(int i = 2; i < N; i++)
		mmc_initial = MMC(mmc_initial, C[i]);
	
	long long int max_mmc = -1, atual_mmc;
	int best = 0;
	for (int i = 1; i <= L; i++) {
		atual_mmc = MMC(mmc_initial, i);
		if(atual_mmc > max_mmc && atual_mmc <= L) {
			best = i;
			max_mmc = atual_mmc;
		}
	}

	cout << best << endl;

	return 0;
}