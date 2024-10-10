#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <vector <int>> t(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		t[--a].push_back(--b);
		t[b].push_back(a);
	}
	cout << ((n & 1) ? 0 : 1) << endl;

	function <void(int, int)> dfs = [&](int p, int c) {
		for(auto i: t[c]) 
			if(i != p) dfs(c, i);
		if(c == 0) return;
		cout << p + 1 << ' ' << c + 1 << ' ' << c << endl;
	}; dfs(-1, 0);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}