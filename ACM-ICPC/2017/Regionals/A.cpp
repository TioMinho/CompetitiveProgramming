#include <iostream>
#include <vector>

#define MAXN 4e4
#define INF 1e8

using namespace std;

class Node {
public:
	int f[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	// Methods
	Node() {}
	Node(int f_0[9]) {
		copy(f, f+9, f_0);
	}

	int getF() {
		int f_i = 0;
		for (int i = 1; i < 9; ++i)	
			if(f[f_i] <= f[i]) f_i = i;

		return f_i;
	}

	void add(int val) {
		val %= 9;
		int f_old[9]; copy(f, f+9, f_old);

		for (int i = 0; i < 9; ++i) f[(val+i) % 9] = f_old[i];
	}

	void merge(Node n) {
		for (int i = 0; i < 9; ++i) f[i] += n.f[i];
	}
};

class SegmentTree {
public:
	vector<Node> st;
	vector<int> lz, A;
	int n;
	int left(int p)  { return p << 1; }
	int right(int p) { return (p << 1)+1; }

	void build(int p, int L, int R) {  // O(n)
		if (L==R) { 
			Node newNode; newNode.f[1] = 1; 
			st[p] = newNode; 
		}
		else {
			build(left(p) ,  L         , (L+R)/2);
			build(right(p), (L+R)/2 + 1, R      );

			Node p1 = st[left(p)], p2 = st[right(p)];

			// CHANGE TO THE DESIRED TREE
			p1.merge(p2);
			st[p] = p1;
	}}

	void update(int p, int L, int R, int l, int r, int val) { // O(lg n)
		if(lz[p] != 0) {
			st[p].add(lz[p]);

			if(L != R) {
				lz[left(p)]  += lz[p];
				lz[right(p)] += lz[p];
			} else A[L] += lz[p]; 
			lz[p] = 0;
		}

		if (l >  R || r <  L) return;			// Out of query range
		if (L >= l && R <= r) {
			st[p].add(val);	

			if(L != R) {
				lz[left(p)]  += val;
				lz[right(p)] += val;
			} else A[L] += val; 
			return;
		}

		update(left(p) ,  L         , (L+R)/2, l, r, val);
		update(right(p), (L+R)/2 + 1,  R,      l, r, val);

		// CHANGE TO THE DESIRED TREE
		Node p1 = st[left(p)], p2 = st[right(p)];
		p1.merge(p2);
		st[p] = p1;
	}

	Node query(int p, int L, int R, int l, int r) { // O(lg n)
		if (l >  R || r <  L) return Node();		// Out of query range (CHANGE)

		// LAZY
		if(lz[p] != 0) {
			st[p].add(lz[p]);		// IF SUM USE st[p] += (R-L+1)*lz[p]

			if(L != R) {
				lz[left(p)]  += lz[p];
				lz[right(p)] += lz[p];
			} else A[L] += lz[p]; 
			lz[p] = 0;
		}
		// ---

		if (L >= l && R <= r) return st[p];		// Inside query range

		Node p1 = query(left(p) ,  L        , (L+R)/2 , l, r);
		Node p2 = query(right(p), (L+R)/2 +1,  R      , l, r);

		// CHANGE TO THE DESIRED TREE
		p1.merge(p2);
		return p1;
	}

	void dfs(int p, int L, int R) { // O(n)
		if(R == L) {
			st[p].add(lz[p]);
			A[L] += lz[p];
			lz[p] = 0;
		} else {
			if(lz[p] != 0) {
				st[p].add(lz[p]);

				if(L != R) {
					lz[left(p)]  += lz[p];
					lz[right(p)] += lz[p];
				} else A[L] += lz[p]; 
				lz[p] = 0;
			}

			dfs(left(p) ,  L        , (L+R)/2);
			dfs(right(p), (L+R)/2 +1,  R     );

			return;
		}
	}

// Use only those methods:
	SegmentTree(const vector<int> &_A) {
		A = _A; n = (int)A.size();
		
		Node aux;
		st.assign(4*n, aux);
		
		lz.assign(4*n, 0);
		build(1, 0, n-1);
	}

	Node query(int i, int j) { return query(1, 0, n-1, i, j); }
	void update(int l, int r, int val) { return update(1, 0, n-1, l, r, val); }
	void dfs() { return dfs(1, 0, n-1); }
};

int main() {

	int N, Q, l, r;
	cin >> N >> Q;

	vector<int> A(N, 1);
	SegmentTree st(A);

	for (int i = 0; i < Q; ++i)	{
		cin >> l >> r;

		Node n = st.query(l, r);
		st.update(l, r, n.getF());
	}

	st.dfs();

	for (int i = 0; i < N; ++i)
		cout << st.A[i] % 9 << endl;

	return 0;
}