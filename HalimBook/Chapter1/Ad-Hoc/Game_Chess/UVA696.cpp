#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int m, n, res;

	while(cin >> m >> n && m+n != 0) {
		if(m == 1 || n == 1)
			res = max(n,m);
		if(m < 3 && n < 3)
			res = n*m;
		else if((m == 2 && n > 2) || (n == 2 && m > 2)) {
			
			res = ceil(n*m*1.0/8)*4;

		}
		else
			res = ceil(n*m*1.0/2);


		printf("%d knights may be placed on a %d row %d column board.\n", (int) res, m, n);
	}

	return 0;
}