#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <vector <int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
	}
	
	vector <int> mxt(n);
	int tmp = n;
	function <int(int, int)> pp = [&](int p, int c) {
		int sz = 1, mx = 0;
		for(auto i: g[c]) {
			if(i != p) {
				int cur = pp(c, i); sz += cur;
				mx = max(mx, cur);
			}
		}
		mx = max(mx, n - sz); tmp = min(tmp, mx);
		mxt[c] = mx; return sz;
	}; pp(-1, 0);
	int cnt = count(mxt.begin(), mxt.end(), tmp);
	if(cnt == 1 && cout << 1 << ' ' << g[0][0] + 1 
						<< '\n' << 1 << ' ' << g[0][0] + 1 << endl) return;

	int a = -1, b = -1;
	for (int i = 0; i < n; i++) {
		if(mxt[i] == tmp) {
			if(a == -1) a = i;
			else b = i;
		}
	}
	cout << a << ' ' << b << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}