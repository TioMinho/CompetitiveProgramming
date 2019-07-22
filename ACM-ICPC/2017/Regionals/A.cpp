#include <bits/stdc++.h> 
#include <algorithm>
#include <vector>

#define MAXN 100001

using namespace std;

// --- NODE ----
struct Node {
	int f[9];

	Node(){
		memset(f, 0, sizeof(f));
	}
};

int getF(Node *node) {
	int f_i = 0;
	for (int i = 1; i < 9; ++i)	
		if(node->f[f_i] <= node->f[i]) f_i = i;

	return f_i;
}

void add(Node *node, int val) {
	val %= 9;
	Node newNode = *node;
	for (int i = 0; i < 9; ++i) 
		node->f[(val+i) % 9] = newNode.f[i];
}

Node merge(Node *n1, Node *n2) {
	Node nt;
	for (int i = 0; i < 9; ++i) 
		nt.f[i] = n1->f[i] + n2->f[i];
	return nt;
}
// -----

// --- SEGTREE ----
Node st[MAXN << 2];
int lz[MAXN << 2];
int N, Q, l, r;

int left(int p)  { return p << 1; }
int right(int p) { return (p << 1)+1; }

void build(int p, int L, int R) {  // O(n)
	if (L==R) { 
		st[p].f[1] = 1; 
		return;
	}
	else {
		build(left(p) ,  L         , (L+R)/2);
		build(right(p), (L+R)/2 + 1, R      );

		st[p].f[1] = R-L+1;
}}

void lazyProp(int p, int L, int R, int val) { // O(1)
	if(val != 0) {
		add(&st[p], val);

		if(L != R) {
			lz[left(p)]  += val;
			lz[right(p)] += val;
		} lz[p] = 0;
	}
}

void update(int p, int L, int R, int l, int r, int val) { // O(lg n)
	lazyProp(p, L, R, lz[p]);

	if (l >  R || r <  L) return;			// Out of query range
	if (L >= l && R <= r) {
		lazyProp(p, L, R, val);
		return;
	}

	update(left(p) ,  L         , (L+R)/2, l, r, val);
	update(right(p), (L+R)/2 + 1,  R,      l, r, val);

	// CHANGE TO THE DESIRED TREE
	st[p] = merge(&st[left(p)], &st[right(p)]);
}

Node query(int p, int L, int R, int l, int r) { // O(lg n)
	if (l >  R || r <  L) return Node();		// Out of query range (CHANGE)

	// LAZY
	lazyProp(p, L, R, lz[p]);
	// ---

	if (L >= l && R <= r) return st[p];		// Inside query range

	Node p1 = query(left(p) ,  L        , (L+R)/2 , l, r);
	Node p2 = query(right(p), (L+R)/2 +1,  R      , l, r);

	// CHANGE TO THE DESIRED TREE
	return merge(&p1, &p2);
}

void dfs(int p, int L, int R) { // O(n)
	lazyProp(p, L, R, lz[p]);

	if(R == L) {
		printf("%d\n", (max_element(st[p].f, st[p].f+9) - st[p].f));
		return;
	}

	dfs(left(p) ,  L        , (L+R)/2);
	dfs(right(p), (L+R)/2 +1,  R     );
}

Node query(int i, int j) { return query(1, 0, N-1, i, j); }
void update(int l, int r, int val) { return update(1, 0, N-1, l, r, val); }
void dfs() { return dfs(1, 0, N-1); }
// -----

int main() {
	scanf("%d%d", &N, &Q);

	build(1, 0, N-1);

	for (int i = 0; i < Q; ++i)	{
		scanf("%d%d", &l, &r);

		Node n = query(l, r);
		update(l, r, getF(&n));
	}

	dfs();
    return 0; 
}