#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	vector <vector <int>> t(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		t[--a].push_back(--b);
		t[b].push_back(a);
	}

	vector <vector <int>> d(n, vector <int> (k + 1));
	for (int i = 0; i < n; i++) d[i][0] = 1;
	function <void (int, int)> dfs = [&](int p, int c) {
		for(auto i: t[c]) {
			if(i != p) {
				dfs(c, i);
				for(int j = 1; j <= k; j++) 
					d[c][j] += d[i][j - 1];
			}
		}
	}; dfs(-1, 0);
	
	ll fin = d[0][k];

	function <void(int, int)> reroot = [&](int p, int c) {
		for(auto i: t[c]) {
			if(i == p) continue;
			for(int j = 1; j <= k; j++)
				d[c][j] -= d[i][j - 1];
			for(int j = 1; j <= k; j++)
				d[i][j] += d[c][j - 1];
			reroot(c, i);
		}	
	};

	cout << fin << '\n';
}