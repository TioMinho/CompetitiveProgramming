#include <iostream>
#include <map>
#include <string>
#include <algorithm>

#define all(c) c.begin(),c.end()

using namespace std;

typedef struct {
	int points = 0;
	int goalsMade = 0;
	int goalsSuff = 0;
	int games = 0;
	float percent = 0;
} Team;


void printTable(string name, Team score) {
	string temp = (score.points > 0) ? to_string(score.percent) : "N/A";
	cout << name << "  " << score.games << "  " << score.points << "  " << score.goalsMade
		<< "  " << score.goalsSuff << "  " << temp << endl;
}

int main()
{
	int T, G, aux[2];
	string team1, team2, lixo;
	map<string, Team> scoreBoard;

	while(cin >> T >> G && (T+G) > 0) 
	{
		scoreBoard.clear();

		for (int i = 0; i < T; i++) {
			cin >> team1;
			Team temp;
			scoreBoard[team1] = temp;
		}

		for (int i = 0; i < G; ++i) {
			cin >> team1;
			cin >> aux[0];
			scoreBoard[team1].goalsMade += aux[0];

			cin >> lixo;

			cin >> aux[1];
			cin >> team2;
			scoreBoard[team2].goalsMade += aux[1];

			scoreBoard[team1].games += 1;
			scoreBoard[team1].goalsSuff += aux[1];

			scoreBoard[team2].games += 1;
			scoreBoard[team2].goalsSuff += aux[0];

			if(aux[0] == aux[1]) {
				scoreBoard[team1].points += 1;
				scoreBoard[team2].points += 1;
			}
			else if (aux[0] > aux[1])
				scoreBoard[team1].points += 3;
			else
				scoreBoard[team2].points += 3;

			scoreBoard[team1].percent = scoreBoard[team1].points / G;
			scoreBoard[team2].percent = scoreBoard[team2].points / G;
		}

		for(auto it = scoreBoard.begin(); it != scoreBoard.end(); it++)
			printTable(it->first, it->second);
	}

	return 0;
}

/*
	Não vou tratar aquela saída lascada
	Se virem com a que tem aí.

*/