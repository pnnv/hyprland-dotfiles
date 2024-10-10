#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	const ll mod = 1000000007;

	int n; cin >> n;
	vector <ll> val(n);
	for(auto &i: val) cin >> i;

	int m; cin >> m;
	vector <vector <int>> g(n), rg(n);
	
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[--a].push_back(--b);
		rg[b].push_back(a);
	}

	vector <bool> vis(n, false);
	stack <int> st;
	
	function <void (int)> dfs1 = [&](int c)  {
		vis[c] = true;
		for(auto i: g[c]) 
			if(!vis[i]) dfs1(i);
		st.push(c);
	}; 
	for (int i = 0; i < n; i++) 
		if(!vis[i]) dfs1(i);

	vis.assign(n, false);

	vector <vector <int>> comp;
	vector <int> tmp;

	function <void (int)> dfs2 = [&](int c) {
		vis[c] = true;
		tmp.push_back(c);
		for(auto i: rg[c]) 
			if(!vis[i]) dfs2(i);
	};

	while(!st.empty()) {
		int cur = st.top(); st.pop();
		if(!vis[cur]) {
			dfs2(cur);
			comp.push_back(tmp); tmp.clear();
		}
	}
	mi num = 1, cost = 0;

	for(auto c: comp) {
		map <ll, ll> mp;
		ll mn = 1e9 + 1;
		for(auto i: c) 
			mn = min(val[i], mn), mp[val[i]]++;
		num *= mp[mn];
		cost += mn;
	}

	cout << (int)cost << ' ' << (int)num << endl;
}