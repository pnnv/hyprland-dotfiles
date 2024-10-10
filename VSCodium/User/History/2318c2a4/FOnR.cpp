#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct segtree {
	int sz;
	vector <ll> sums;

	void init(int n) {
		sz = 1;
		while(sz < n) sz <<= 1;
		sums.assign(sz << 1, 0LL);
	}

	void set(int i, int x, int cur, int lx, int rx) {
		if(rx - lx == 1) {
			sums[cur] = x;
			return; 
		}
		int m = (lx + rx) >> 1;
		if(i < m) set(i, x, 2 * cur + 1, lx, m);
		else set(i, x, 2 * cur + 2, m, rx);
		sums[cur] = sums[2 * cur + 1] + sums[2 * cur + 2];
 	}

	void set(int i, int x) {
		set(i, x, 0, 0, sz);
	}

	void build(vector <int> &a, int cur, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < a.size()) {
				sums[cur] = a[lx];
			}
			return;
		}
		int m = (lx + rx) >> 1;
		build(a, 2 * cur + 1, lx, m);
		build(a, 2 * cur + 2, m, rx);
	}

	void build(vector <int> & a) {
		build(a, 0, 0, sz);
	}

	ll get(int l, int r, int cur, int lx, int rx) {
		if(lx >= r || l >= rx) return 0LL;
		if(lx >= l && rx <= r) return sums[cur];
		int m = (lx + rx) >> 1;
		return get(l, r, 2 * cur + 1, lx, m)
				+ get(l, r, 2 * cur + 2, m, rx);
	}

	ll get(int l, int r) {
		return get(l, r, 0, 0, sz);
	}
};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	
	segtree st;
	st.build(v);

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		st.set(i, x);
	}

	for(; m-- ;) {
		int op; cin >> op;
		if(op == 1) {
			int i, x; cin >> i >> x;
			st.set(i, x);
		} else {
			int l, r; cin >> l >> r;
			cout << st.get(l, r) << endl;
		}
	}
}