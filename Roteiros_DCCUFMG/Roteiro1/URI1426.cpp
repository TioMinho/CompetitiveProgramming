#include <iostream>

using namespace std;

int main()
{
	int m[9][9];
	int n;

	cin >> n;

	for(int l = 0; l < n; l++)
	{
		for(int i = 0; i < 9; i++)
			for(int j = 0; j <= i; j++)
				if(i % 2 == 0 && j % 2 == 0) cin >> m[i][j];
	
		for(int i = 0; i < 4; i++) 
			m[8][i*2 + 1] = (m[6][i*2] - (m[8][i*2] + m[8][i*2+2])) / 2;
	
		for(int i = 7; i >= 0; i--) 
			for(int j = 0; j <= i; j++)
				m[i][j] = m[i+1][j] + m[i+1][j+1];
	
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j <= i; j++) {
				cout << m[i][j];
				if(j != i) cout << " ";
			}
			cout << endl;
		}
	}


	return 0;
}