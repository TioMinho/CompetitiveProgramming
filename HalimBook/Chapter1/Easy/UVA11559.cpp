#include <iostream>

#define MAXN 200
#define MAXB 500000
#define MAXH 18
#define MAXW 13

using namespace std;

int main() {
	int N, B, H, W, aux1, aux2, min;

	while(cin >> N >> B >> H >> W) {
		min = 0;
		for (int i = 0; i < H; ++i) {
			cin >> aux1;
			
			bool isFit = false;
			for(int j = 0; j < W; ++j)
				if(cin >> aux2 && aux2 >= N) isFit = true;

			if(isFit){
				int cost = N*aux1;
				if(cost <= B && (min == 0 || cost < min)) min = cost;
			}
		}

		if(min > 0)	cout << min << endl;
		else 		cout << "stay home" << endl;
	}

	return 0;
}