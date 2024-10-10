#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int pp = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <vector <int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
	}

	vector <ll> t(n), nt(n);
	
	function <void (int, int)> f = [&](int p, int c) {
		ll tk = 1, ntk = 1;
		for(auto i: g[c]) {
			if (i == p) continue;
			f(c, i);
			tk *= nt[i];
			ntk *= (t[i] + nt[i]);
		}
		t[c] = tk;
		nt[c] = ntk;
	}; f(-1, 0);

	cout << t[0] + nt[0] << endl;
}