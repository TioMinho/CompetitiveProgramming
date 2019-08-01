#include <iostream>
#include <climits>

#define INF INT_MIN
#define SUP INT_MAX

#define MAXS 20001

using namespace std;

// Kadane's Algorithm for Longest Subsequent Product
long long Kadane_Modified(int a[], int size) {
	int max_so_far = INF, max_ending_here = 0;

	for (int i = 0; i < size; ++i)	{
		max_ending_here *= a[i];

		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if(max_ending_here <= 0)
			max_ending_here = 0;
	}

	return max_so_far;
}
// --

int seq[MAXS];

int main() {
	int cnt = 0;
	while(cin >> seq[0]) {
		cnt = 1;
		while(cin >> seq[cnt] && seq[cnt] != -999999) cnt++;

		cout << cnt << endl;
		printf("%d\n", Kadane_Modified(route, cnt));
	} 
    
	return 0;
}