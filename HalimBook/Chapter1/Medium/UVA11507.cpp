#include <iostream>
#include <string>

using namespace std;

int main() {
	int L;
	string act, curr;

	while(cin >> L && L != 0) {
		curr = "+x";
		for (int i = 0; i < L-1; ++i) {
			cin >> act;

			if(act == "+y") {
				if(curr == "+x") curr = "+y";
				else if(curr == "-x") curr = "-y";
				else if(curr == "+y") curr = "-x";
				else if(curr == "-y") curr = "+x";
			} else if(act == "-y") {
				if(curr == "+x") curr = "-y";
				else if(curr == "-x") curr = "+y";
				else if(curr == "+y") curr = "+x";
				else if(curr == "-y") curr = "-x";
			} else if(act == "+z") {
				if(curr == "+x") curr = "+z";
				else if(curr == "-x") curr = "-z";
				else if(curr == "+z") curr = "-x";
				else if(curr == "-z") curr = "+x";
			} else if(act == "-z") {
				if(curr == "+x") curr = "-z";
				else if(curr == "-x") curr = "+z";
				else if(curr == "+z") curr = "+x";
				else if(curr == "-z") curr = "-x";
			}
		}
		cout << curr << endl;
	}

	return 0;
}