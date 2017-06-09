#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPrimo(int num)
{
	int cnt = 2;
	
	for(int i = 2; i <= sqrt(num); i++)
		if(num % i == 0) cnt++;
 
	return (cnt <= 2);
}

int main()
{
	string palavra;
	int valor = 0;

	while(cin >> palavra) 
	{
		valor = 0;
		for(int i = 0; i < palavra.size(); i++) {
			if((int)palavra[i] >= 97)
				valor += (int)palavra[i] - 96;
			else
				valor += (int)palavra[i] - 38;
		}
	
		if(isPrimo(valor))
			cout << "It is a prime word." << endl;
		else
			cout << "It is not a prime word." << endl;
	}

	return 0;
}