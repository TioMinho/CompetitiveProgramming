#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double raio;

	cin >> raio;

	cout << "A=" << fixed << setprecision(4) << 3.14159 * raio * raio << endl;

	return 0;
}