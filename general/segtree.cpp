#include <iostream>
#include <vector>

using namespace std;

#define INF 1e8

class SegmentTree {
public:
	vector<int> st, lz, A;
	int n;
	int left(int p)  { return p << 1; }
	int right(int p) { return (p << 1)+1; }

	void build(int p, int L, int R) {  // O(n)
		if (L==R) st[p] = A[L];
		else {
			build(left(p) ,  L         , (L+R)/2);
			build(right(p), (L+R)/2 + 1, R      );

			int p1 = st[left(p)], p2 = st[right(p)];

			// CHANGE TO THE DESIRED TREE
			st[p] = min(p1, p2);
				//  max(p1, p2);
				//  p1 + p2;
				//  p1 * p2;
				//  ...
	}}

	void lazyprop(int p, int L, int R, int val) {
		if(!val) return;

		st[p] += val;		// IF SUM USE st[p] += (R-L+1)*val

		if(L != R) {
			lz[left(p)]  += val;
			lz[right(p)] += val;
	}}

	void update(int p, int L, int R, int l, int r, int val) { // O(lg n)
		lazyprop(p, L, R, lz[p]); lz[p] = 0;

		if (l >  R || r <  L) return;			// Out of query range
		if (L >= l && R <= r) {
			lazyprop(p, L, R, val);
			return;
		}

		update(left(p) ,  L         , (L+R)/2, l, r, val);
		update(right(p), (L+R)/2 + 1,  R,      l, r, val);

		// CHANGE TO THE DESIRED TREE
		st[p] = min(st[left(p)], st[right(p)]);
			//  max(st[left(p)], st[right(p));
			//  st[left(p)] + st[right(p);
			//  st[left(p)] * st[right(p);
			//  ...
	}

	int query(int p, int L, int R, int l, int r) { // O(lg n)
		if (l >  R || r <  L) return INF;		// Out of query range (CHANGE)

		// LAZY
		lazyprop(p, L, R, lz[p]); lz[p] = 0;
		// ---

		if (L >= l && R <= r) return st[p];		// Inside query range

		int p1 = query(left(p) ,  L        , (L+R)/2 , l, r);
		int p2 = query(right(p), (L+R)/2 +1,  R      , l, r);

		// CHANGE TO THE DESIRED TREE
		return min(p1, p2);
			// max(p1, p2);
			//  p1 + p2;
			//  p1 * p2;
			//  ...
	}

// Use only those methods:
	SegmentTree(const vector<int> &_A) {
		A = _A; n = (int)A.size();
		st.assign(4*n, 0);
		lz.assign(4*n, 0);
		build(1, 0, n-1);
	}

	int query(int i, int j) { return query(1, 0, n-1, i, j); }
	void update(int l, int r, int val) { return update(1, 0, n-1, l, r, val); }
};

int main() {
	int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
	vector<int> A(arr, arr+7);

	SegmentTree st(A);

	for (int i = 1; i <= 4*st.n; ++i) cout << st.st[i] << " "; cout << endl;
	for (int i = 1; i <= 4*st.n; ++i) cout << st.lz[i] << " "; cout << endl;

	printf("RMQ(1,3) = %d\n", st.query(1, 3));
	printf("RMQ(4,6) = %d\n", st.query(4, 6));

	st.update(2, 5, 3);

	for (int i = 1; i <= 4*st.n; ++i) cout << st.st[i] << " "; cout << endl;
	for (int i = 1; i <= 4*st.n; ++i) cout << st.lz[i] << " "; cout << endl;

	printf("RMQ(1,3) = %d\n", st.query(1, 3));
	printf("RMQ(4,6) = %d\n", st.query(4, 6));

	return 0;
}