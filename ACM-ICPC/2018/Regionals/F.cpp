#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXM 1000 
#define MAXP 10

using namespace std;

// Struct dos Shows
typedef struct show Show;

struct show {
	int i, f, o, p;
	show() {
		i = f = o = p = 0;
	}
};

void initShow(Show *s, int i, int f, int o, int p) {
	s->i = i;
	s->f = f;
	s->o = o;
	s->p = 1 << p;
}

bool comp(Show s1, Show s2) {
	return s1.i < s2.i;
}

// -----------------

// Variáveis Globais
Show M[MAXM];
int DP[MAXM][1 << MAXP];
int to[MAXM];

// -----------------

// Busca Recursiva da Solução por Programação Dinâmica
int DPSearch(int s, int p, int N, int P) {
	// s == N --> Não há mais shows.
	if(s == N) {
		if(p == (1 << P) -1) return 0;			// Fim do Tempo com todos os palcos assistidos: possível solução.
		else				 return -9999999;	// Fim do Tempo mas ainda faltam palcos: não é possível solução.
	}

	// Se já calculamos um estado, apenas retornamos o seu valor.
	if(DP[s][p] != -1) return DP[s][p];

	// Transições: 
	// -> Não assistir ao show (s, p) e ir para o próximo show (s+1, p).
	// -> Assistir ao show (s, p), absorver o valor M[s].o, e ir para o próximo show (to(s), p | M[s].p)
	DP[s][p] = max(DPSearch(s+1, p, N, P), DPSearch(to[s], p | M[s].p, N, P) + M[s].o);

	return DP[s][p];
}

// --------------------------------------------------

int main() {

	int P, N=0, aux, attr[3];

	// Leitura da Entrada e Inicialização dos Structs
	cin >> P;
	for (int i = 0; i < P; ++i)	{
		cin >> aux;
		
		for (int j = 0; j < aux; ++j) {
			cin >> attr[0] >> attr[1] >> attr[2];
			initShow(&M[N+j], attr[0], attr[1], attr[2], i);
		}

		N += aux;
	}

	// Ordena os Shows pelo Tempo de Início.
	sort(M, M+N, comp);

	// Pré-calcula o vetor to[i], que indica o próximo show que pode ser assistido
	// depois de assistirmos o show i
	for (int i = 0; i < N; ++i) {
		to[i] = N;

		for (int j = i; j < N && to[i] == N; ++j) {
			if(M[j].i >= M[i].f) {
				to[i] = j;
				break;
			}
		}
	}

	// DEBUG: Imprime todos os shows
	// for (int i = 0; i < N; ++i)	{
	// 	cout << "Show " << i << endl;
	// 	cout << "I: " << M[i].i << endl;
	// 	cout << "F: " << M[i].f << endl;
	// 	cout << "O: " << M[i].o << endl;
	// 	cout << "P: " << M[i].p << endl;
	// 	cout << "To: " << to[i] << endl;
	// 	cout << endl;
	// }

	// Inicializa a matrix da PD
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 1<<P; ++j)
			DP[i][j] = -1;

	// Busca a solução recursivamente
	int maxRes = DPSearch(0, 0, N, P);

	// DEBUG: Imprime a matriz da DP
	// for (int i = 0; i < N; ++i)	{
	// 	for (int j = 0; j < 1<<P; ++j)	{
	// 		cout << DP[i][j] << " ";
	// 	} cout << endl;
	// }

	// Se maxRes < 0, é porque não houve nenhuma solução válida e todas foram infectadas (-9999999),
	// logo a resposta é -1 indicando que não há solução válida.
	if(maxRes > 0) cout << maxRes << endl;
	else		   cout << -1 << endl;

	return 0;
}