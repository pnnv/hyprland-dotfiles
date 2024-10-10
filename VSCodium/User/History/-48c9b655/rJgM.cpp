#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, op = 0; cin >> n;
	vector <vector <int>> t(n);
	for (int i = 1; i <= n - 1; i++) {
		int p; cin >> p;
		t[i].push_back(--p);
		t[p].push_back(i);
	} 
	vector <ll> l(n), r(n);
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
	function <ll (int, int)> dfs = [&](int p, int c) {
		ll lo = 0;
		for(auto i: t[c]) 
			if(i != p) 
				lo += dfs(c, i);
		if(lo < l[c]) {
			op++; return r[c];
		} else return min(r[c], lo);
	}; dfs(-1, 0);

	cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}