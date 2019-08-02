#include <bits/stdc++.h>

#define MAXA 21 
#define REP(i,N) for (int i = 0; i < N; ++i)
#define REPx(i,N) for (int i = 0; i <= N; ++i)
#define REPi(i,s,N) for (int i = s; i < N; ++i)
#define REPix(i,s,N) for (int i = s; i <= N; ++i)
using namespace std;

typedef long long int bigInt;

int N, A, B, C;
bigInt H[MAXA][MAXA][MAXA];

bigInt rectSum(int a1, int a2, int b1, int b2, int c) {
    bigInt sum = 0;
    REPix(a,a1,a2) REPix(b,b1,b2)
        sum += H[a][b][c];
    return sum;
}

bigInt findMaxSum() { 
    bigInt maxSum = H[0][0][0];
    bigInt sumUntilNow = 0;

    REP(a,A) REP(b,B) REP(c,C)
        maxSum = max(maxSum, H[a][b][c]);

    REP(a,A) REPi(af, a, A) { 
    REP(b,B) REPi(bf, b, B) {
            sumUntilNow = rectSum(a, af, b, bf, 0);
            maxSum = max(maxSum, sumUntilNow);

            // printf("%d-%d %d-%d : %lld\n", a,af,b,bf,sumUntilNow);

            REPi(c,1,C) {
                if(sumUntilNow < 0)
                    sumUntilNow  = rectSum(a, af, b, bf, c);
                else
                    sumUntilNow += rectSum(a, af, b, bf, c);

                maxSum = max(maxSum, sumUntilNow);
            }
        }
    }

    return maxSum;
} 

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d", &A, &B, &C);

		REP(a,A) REP(b,B) REP(c,C) {
			scanf("%lld", &H[a][b][c]);
        }

        if(i > 0) printf("\n");
        printf("%lld\n", findMaxSum());
	}

	return 0;
}