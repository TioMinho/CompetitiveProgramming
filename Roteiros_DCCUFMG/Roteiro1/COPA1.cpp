#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	queue<char> equipes;

	for(int i = 0; i < 16; i++)
		equipes.push((char)65+i);

	char player1, player2;
	int score1, score2;
	for(int i = 0; i < 15; i++)
	{
		player1 = equipes.front(); equipes.pop();
		player2 = equipes.front(); equipes.pop();

		cin >> score1 >> score2;

		equipes.push((score1 > score2) ? player1 : player2);
	}

	cout << equipes.front() << endl;

	return 0;
}