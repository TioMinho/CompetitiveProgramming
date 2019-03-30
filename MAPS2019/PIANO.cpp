#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define MAXN 1000
#define MAXM 1000

using namespace std;

int N, M;

struct Aresta
{
	int v; //Aresta u-v
	int fluxo;
	int capacidade;
	int arestaRev; // Facilitar o encontro da aresta reversa
};

class Grafo {
	int nVert;
	int *nivel;
	vector< Aresta > *listaAdj;

public:
	Grafo(int nVert) {
		listaAdj = new vector< Aresta > [nVert];
		this->nVert = nVert;
		nivel = new int[nVert];
	}

	void addAresta(int u, int v, int capacidade) {
		Aresta a{v,0,capacidade, listaAdj[v].size()};

		Aresta b{u,0,0,listaAdj[u].size()};

		listaAdj[u].push_back(a);
		listaAdj[v].push_back(b);
	}

	bool BFS(int s, int t);
	int sendFlow(int s, int flow, int t, int ptr[]);
	int DinicMaxFlow(int s, int t);
};

//Montar grafo de nível com BFS
bool Grafo::BFS(int s, int t) { 
	for(int i=0;i<nVert;i++)
		nivel[i] = -1;

	nivel[s] = 0;

	queue<int> fila;
	fila.push(s);
	while(!fila.empty()){

		int atual = fila.front();
		fila.pop();
		for(auto i = listaAdj[atual].begin(); i != listaAdj[atual].end(); ++i ) {
			auto edge = *i;

			if(nivel[edge.v] < 0 && edge.fluxo < edge.capacidade){
				nivel[edge.v] = nivel[atual] + 1;
				fila.push(edge.v);
			}
		}
	}

	return !(nivel[t] < 0);
}

//Encontrar caminho aumentante com DFS
int Grafo::sendFlow(int u, int flow,int t, int start[]) { 
	if(u == t)
		return flow;

	for ( ; start[u] < listaAdj[u].size(); start[u]++) {
		Aresta &edge = listaAdj[u][start[u]];

		if(nivel[edge.v] == nivel[u] + 1 && edge.fluxo < edge.capacidade) {

			int fluxo_atual= min(flow, edge.capacidade - edge.fluxo);

			int fluxo_tempor= sendFlow(edge.v, fluxo_atual, t, start);

			if(fluxo_tempor > 0) {
				edge.fluxo += fluxo_tempor;

				listaAdj[edge.v][edge.arestaRev].fluxo -= fluxo_tempor;
				return fluxo_tempor;
			}
		}
	}

	return 0;
}

int Grafo::DinicMaxFlow(int s,int t) { //Dinic em sí!
	if(s == t)
		return -1;

	int total = 0;

	//Enquanto o grafo de nível chega no sumidouro...					     
	while(BFS(s,t) == true) { 
		int *start = new int[nVert+1]();

		//Enquanto houver caminho aumentante...
		while(int flow = sendFlow(s, 1e5, t, start)) total += flow;
	}

	return total;
}


int main() {
	int t, aux;

	cin >> N >> M;

	Grafo G(N*M+2);

	for (int i = 0; i < M; ++i) G.addAresta(0, i+1, 1);

	for (int i = 0; i < N; ++i) {
		G.addAresta(M+1+i, N*M+1, 1);
		cin >> t;

		for (int j = 0; j < t; ++j) {
			cin >> aux;
			G.addAresta(aux, M+1+i, 1);
		}
	}

	cout << G.DinicMaxFlow(0, N*M+1) << endl;

	return 0;
}