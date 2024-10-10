#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, op = 0; cin >> n;
	vector <vector <int>> t(n);
	for (int i = 0; i < n - 1; i++) {
		int p; cin >> p;
		t[i].push_back(--p);
		t[p].push_back(i);
	} 
	vector <int> l(n), r(n);
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
	function <void (int, int)> dfs = [&](int p, int c) {
		bool b = true;
		for(auto i: t[c]) {
			if(i != p) {
				if(r[i] >= l[c]) b = false;
				dfs(c, i);
			}
		}
		op += (b ? 1 : 0);
		cout << op << ' ';
	}; dfs(-1, 0);

	cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}