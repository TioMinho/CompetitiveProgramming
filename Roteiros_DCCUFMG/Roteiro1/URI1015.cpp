#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double point[2][2];

	cin >> point[0][0] >> point[0][1];
	cin >> point[1][0] >> point[1][1];

	cout << fixed << setprecision(4) << sqrt(pow(point[0][0] - point[1][0], 2) + pow(point[0][1] - point[1][1], 2)) << endl;

	return 0;
}