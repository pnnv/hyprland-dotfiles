#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct item {
	ll seg, pref, suf, sum;
};

struct segtree {
	int sz;
	vector <item> val;

	item neutral = {0, 0, 0, 0};

	item single(int v) {
		if(v > 0) return {v, v, v, v};
		else return {0, 0, 0, v};
	}

	item merge(item a, item b) {
		return {
			max({a.seg, b.seg, a.suf + b.pref}),
			max(a.pref, a.sum + b.pref),
			max(b.suf, b.sum + b.pref),
			a.sum + b.sum 
		};
	}

	void init(int n) {
		sz = 1;
		while(sz < n) sz <<= 1;
		val.resize(sz << 1);
	}

	void build(vector <int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < a.size()) {
				val[x] = single(a[lx]);
			}
			return;
		}
		int m = (lx + rx) >> 1;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		val[x] = merge(val[2 * x + 1], val[2 * x + 2]);
	}

	void build(vector <int> &a) {
		build(a, 0, 0, sz);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			val[x] = single(v);
			return;
		}
		int m = (lx + rx) >> 1;
		if(i < m) set(i, v, 2 * x + 1, lx, m);
		else set(i, v, 2 * x + 2, m, rx);
		val[x] = merge(val[2 * x + 1], val[2 * x + 2]);
	}

	void set(int i, int v) {
		set(i, v, 0, 0, sz);
	}

	item calc(int l, int r, int x, int lx, int rx) {
		if(lx >= r || rx <= l) return neutral;
		if(lx >= l && rx <= r) return val[x];
		int m = (lx + rx) >> 1;
		item s1 = calc(l, r, 2 * x + 1, lx, m);
		item s2 = calc(l, r, 2 * x + 2, m, rx);
		return merge(s1, s2);
	}

	item calc(int l, int r) {
		return calc(l, r, 0, 0, sz);
	}
};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	vector <int> v(n);
	for(auto &i: v) cin >> i;

	for(auto i: v) cout << i << ' '; cout << endl;

	segtree st;
	st.init(n); st.build(v);
	cout << st.calc(0, n).seg << endl;

	while(m--) {
		int i, x; cin >> i >> x;
		st.set(i, x);
		cout << st.calc(0, n).seg << endl;
	}
}