#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

typedef struct Edge Edge;
typedef struct Vertex Vertex;

struct Vertex {
	int idx;
	bool visited;
	int tax;
	vector< pair<Vertex*, int> > adj;
};

void initVertex(Vertex *x, int ttax, int iidx) {
	x->visited = false;
	x->idx = iidx;
	x->tax = ttax;
}

void addEdge(Vertex *src, Vertex *dst, int W) {
	src->adj.push_back(make_pair(dst, W));
	dst->adj.push_back(make_pair(src, W));
}

int DFS(Vertex *root, int C) {
	int total = 0; Vertex* node;
	int travels;
	stack<Vertex*> pilha;
	
	pilha.push(root);
	while(!pilha.empty()) {
		node = pilha.top(); pilha.pop();

		for(int i = 0; i < node->adj.size(); i++) {
			if(node->adj[i].first->adj.size() == 1 &&
				node->adj[i].first->tax > 0) {
				travels = node->adj[i].first->tax / C;
				travels += (node->adj[i].first->tax % C > 0);

				total += 2 * travels * node->adj[i].second;
				node->tax += node->adj[i].first->tax;
				node->adj[i].first->tax = 0;
			}
			else if(!node->adj[i].first->visited){
				node->adj[i].first->visited = true;
				pilha.push(node->adj[i].first);
			}
		}
	}
	
}

int main() {
	int N, C;
	int aux[3];

	cin >> N >> C;

	vector<Vertex> reign(N);

	for(int i = 0; i < N; i++) {
		cin >> aux[0];
		initVertex(&reign[i], aux[0], i);
	}

	for(int i = 0; i < N-1; i++) {
		cin >> aux[0] >> aux[1] >> aux[2];
		addEdge(&reign[aux[0]-1], &reign[aux[1]-1], aux[2]);
	}

	for(int i = 0; i < N; i++) {
		cout << i+1 << " | Tax: " << reign[i].tax << " | Adj: ";
		for(int j = 0; j < reign[i].adj.size(); j++) {
			cout << reign[i].adj[j].first->idx+1 << "  ";
		} cout << endl;
	}


	return 0;
}
