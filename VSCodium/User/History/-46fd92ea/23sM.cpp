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

	vector <ll> t(n, 1), nt(n);
	
	function <void (int, int)> f = [&](int p, int c) {
		for(auto i: g[c]) {
			if (i == p) continue;
			f(c, i);
			t[c] += nt[i];
			nt[c] += (t[i] + nt[i]);
		}
		// if(t[c] == 0) t[c] = 1;
		// if(nt[c] == 0) nt[c] = 1;
	}; f(-1, 0);

	cout << t[0] + nt[0] << endl;
}