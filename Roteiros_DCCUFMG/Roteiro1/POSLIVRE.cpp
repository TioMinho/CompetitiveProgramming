#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	bool M[500][500];
	int W, H, N;
	int X1, X2, Y1, Y2;
	int count;

	while(cin >> W && cin >> H && cin >> N
		&& !(W == 0 && H == 0 && N == 0))
	{
		for(int i = 0; i < W; i++)
			for(int j = 0; j < H; j++)
				M[i][j] = 1;

		count = 0;

		for(int i = 0; i < N; i++) {
			cin >> X1 >> Y1 >> X2 >> Y2;

			if(X1 > X2) {
				int aux = X1;
				X1 = X2;
				X2 = aux;
			}
			if(Y1 > Y2){
				int aux = Y1;
				Y1 = Y2;
				Y2 = aux;
			}

			for(int j = X1; j <= X2; j++)
				for(int k = Y1; k <= Y2; k++)
					M[j-1][k-1] = 0;
		}

		for(int i = 0; i < W; i++)
			for(int j = 0; j < H; j++)
				count += M[i][j];

		if(count == 0)
			cout << "There is no empty spots." << endl;
		else if(count == 1)
			cout << "There is one empty spot." << endl;
		else if(count > 1)
			cout << "There are " << count << " empty spots." << endl;
	}

	return 0;
}