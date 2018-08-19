#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int F[3];

	for(int i = 0; i < 3; i++)
		cin >> F[i];

	int results[3] = {F[0] * 4 + F[1] * 2,
				      F[0] * 2 + F[2] * 2,
				      F[1] * 2 + F[2] * 4};
	
	cout << *min_element(results, results+3) << endl;

	return 0;
}