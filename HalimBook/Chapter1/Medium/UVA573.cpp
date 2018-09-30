#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int H,U,D,F;

	while(cin >> H >> U >> D >> F && H > 0) {

		int day = 1; 
		double actualHeight = 0;
		while(1){
			actualHeight += max(U * (1 - (day-1) * (F*1.0/100)), 0.0);
			// cout << "Day: " << day << " - " << actualHeight << endl;
			if(actualHeight > H) {
				cout << "success on day " << day << endl;
				break;
			} 

			actualHeight -= D;
			// cout << "Night: " << day << " - " << actualHeight << endl;
			if(actualHeight < 0) {
				cout << "failure on day " << day << endl;
				break;
			} 

			day++;
		}
	}

	return 0;
}