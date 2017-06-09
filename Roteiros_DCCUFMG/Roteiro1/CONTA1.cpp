#include <iostream>

using namespace std;

int main()
{
	int m3, custo;

	cin >> m3;

	custo = 7;

	if(m3 > 10 && m3 <= 30)
		custo += m3 - 10;
	else if(m3 > 30 && m3 <= 100)
		custo += 20 + 2*(m3 - 30);
	else if(m3 > 100)
		custo += 160 + 5*(m3 - 100);

	cout << custo << endl;

	return 0;
}