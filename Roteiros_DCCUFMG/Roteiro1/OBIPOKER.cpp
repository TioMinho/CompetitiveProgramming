#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	int N, card[5], points;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < 5; j++) cin >> card[j];

		points = 0;
		sort(card, card+5);

		// Straight
		bool isStraight = true;
		for(int j = 0; j < 4; j++)
			if(card[j+1] != card[j] + 1){
				isStraight = false;
				break;
			}
		if(isStraight) points = 200 + card[0];

		// Jogadas restante
		if(points == 0)
		{
			int count[5] = {0, 0, 0, 0, 0};
			int trio = 0, duo[2] = {0, 0};

			for(int j = 0; j < 5; j++)
				for(int k = 0; k < 5; k++)
					if(card[j] == card[k]) count[j]++;

			// Quadra
			for(int j = 0; j < 5; j++) 
			{
				if(count[j] == 4) {
					points = 180 + card[j];
					break;
				}
				if(count[j] == 2) {
					if(duo[0] == 0) duo[0] = card[j];
					else if(duo[1] == 0 && card[j] != duo[0]) duo[1] = card[j];
				}
				if(count[j] == 3) trio = card[j];				
			}
			// Full House
			if(trio != 0 && duo[0] != 0)
				points = 160 + trio;
			else if(trio != 0)
				points = 140 + trio;
			else if(duo[0] != 0 && duo[1] != 0) {
				int maior = (duo[0] > duo[1]) ? 0 : 1;
				points = duo[maior] * 3 + duo[abs(maior - 1)] * 2 + 20;
			}
			else if(duo[0] != 0)
				points = duo[0];
		}

		cout << "Teste " << i+1 << endl;
		cout << points << endl;
		cout << endl;
	}
	
	return 0;
}