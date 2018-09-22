#include <iostream>

using namespace std;

int main(){
	int T=1;
	int K,N,M,X,Y; 
	
	while(cin >> K && K != 0){
		cin >> N >> M;

		for (int i = 0; i < K; ++i) {
			cin >> X >> Y;

			if(X == N || Y == M)
				cout << "divisa" << endl;
			else if(X < N && Y < M)
				cout << "SO" << endl;
			else if(X < N && Y > M)
				cout << "NO" << endl;
			else if(X > N && Y < M)
				cout << "SE" << endl;
			else if(X > N && Y > M)
				cout << "NE" << endl;
		}
	} 

	return 0;
}