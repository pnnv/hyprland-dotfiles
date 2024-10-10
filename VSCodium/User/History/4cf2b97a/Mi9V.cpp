#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll fin = 0;

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
		ll cur = 0;
		for(auto i: t[c]) {
			if(i == p) continue;
			dfs(c, i);
			vector <int> tmp(k + 1); 
			for(int j = 1; j <= k; j++) {
				d[c][j] += d[i][j - 1];
				tmp[j] += d[i][j - 1];
			}
			for(int j = 0; j <= (k >> 1); j++) {
				if(2 * j == k) cur -= (tmp[j] * (tmp[j] - 1) / 2);
				else cur -= tmp[j] * tmp[k - j];
			}
		}
		for(int j = 0; j <= (k >> 1); j++) {
			if(2 * j == k) cur += (d[c][j] * (d[c][j] - 1) / 2);
			else cur += d[c][j] * d[c][k - j];
		}
		fin += cur;
	}; dfs(-1, 0);

	cout << fin << '\n';
}