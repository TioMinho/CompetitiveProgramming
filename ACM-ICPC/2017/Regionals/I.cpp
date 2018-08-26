#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

typedef struct Edge Edge;
typedef struct Vertex Vertex;
int N, C;

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

int DFS(Vertex *node, int w) {
	
	node->visited = true;
	int dist = 0;
	

	for(int i = 0; i < node->adj.size(); i++) {
		if(!node->adj[i].first->visited) {
			dist += DFS(node->adj[i].first, node->adj[i].second);
			node->tax += node->adj[i].first->tax;
		}
	}
	int travels = (node->tax / C) + (node->tax % C > 0);
	return dist + 2*w*travels;
}

int main() {
	
	int aux[3];

	cin >> N >> C;

	vector<Vertex> reign(N);

	for(int i = 0; i < N; i++) {
		cin >> aux[0];
		initVertex(&reign[i], aux[0], i+1);
	}

	for(int i = 0; i < N-1; i++) {
		cin >> aux[0] >> aux[1] >> aux[2];
		addEdge(&reign[aux[0]-1], &reign[aux[1]-1], aux[2]);
	}
	
	cout << DFS(&reign[0], 0) << endl;

	return 0;
}