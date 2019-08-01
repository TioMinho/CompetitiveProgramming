#include <iostream>
#include <climits>

#define INF INT_MIN
#define SUP INT_MAX

#define MAXS 20001

using namespace std;

// Kadane's Algorithm for Longest Subsequent Sum
int sq_start, sq_end, maxSum;

void Kadane(int a[], int size) {
	int max_so_far = INF, max_ending_here = 0, startAux = 0;

	for (int i = 0; i < size; ++i)	{
		max_ending_here += a[i];

		if(max_so_far == max_ending_here && (sq_end - sq_start) < (i - startAux)){
			sq_start = startAux;
			sq_end = i;
		}

		if(max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
			sq_start = startAux;
			sq_end = i;
		}

		if(max_ending_here < 0) {
			max_ending_here = 0;
			startAux = i+1;
		}
	}

	maxSum = max_so_far;
}
// --

int route[MAXS];

int main() {
	int B, R;

	cin >> B;
	for (int i = 0; i < B; ++i)	{
		cin >> R;
		for (int j = 0; j < R-1; ++j) cin >> route[j];

		Kadane(route, R-1);

		if(maxSum < 0) 	printf("Route %d has no nice parts\n", i+1);
		else			printf("The nicest part of route %d is between stops %d and %d\n", i+1, sq_start+1, sq_end+2);
	}
    
	return 0;
}