#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct segtree {
	vector <pair <int, int>> t;
	int sz;

	pair <int, int> merge(pair <int, int> a, pair <int, int> b) {
		if(a.first < b.first) return a;
		else if(a.first > b.first) return b;
		else return {a.first, a.second + b.second};
	}

	void init(int n) {
		sz = 1;
		while(sz < n) sz <<= 1;
		t.resize(sz << 1, {INT_MAX, 0});
	}

	void build(vector <int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < a.size()) {
				t[x] = {a[lx], 1}; 
			}
			return;
		}
		int m = (lx + rx) >> 1;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
	}

	void build(vector <int> &a) {
		build(a, 0, 0, sz);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			t[x] = {v, 1};
			return;
		}
		int m = (lx + rx) >> 1;
		if(i < m) set(i, v, 2 * x + 1, lx, m);
		else set(i, v, 2 * x + 2, m, rx);
		t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
	}

	void set(int i, int v) {
		set(i, v, 0, 0, sz);
	}

	pair <int, int> get(int l, int r, int x, int lx, int rx) {
		if(l >= rx || r <= lx) return {INT_MAX, 0};
		if (l <= lx && rx <= r) return t[x];
		int m = (lx + rx) >> 1;
		pair <int, int> a = get(l, r, 2 * x + 1, lx, m), b = get(l, r, 2 * x + 2, m, rx);
		return merge(a, b);
	}

	pair <int, int>  get(int l, int r) {
		return get(l, r, 0, 0, sz);
	}
};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector <int> v(n);
	for(auto &i: v) cin >> i;

	segtree st;
	st.init(n);
	st.build(v);				
	
	for(; m-- ;) {
		int op; cin >> op;
		if(op == 1) {
			int i, x; cin >> i >> x;
			st.set(i, x);
		} else {
			int l, r; cin >> l >> r;
			pair <int, int> pp = st.get(l, r);
			cout << pp.first << " " << pp.second << endl;
		}
	}
}
