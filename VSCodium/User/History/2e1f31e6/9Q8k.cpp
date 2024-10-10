#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
	string s; cin >> s;

	vector <int> b(n), vis(n), cyc, tmp(n), c(n);

	function <int(int)> f = [&](int cur) {
		int x = 0;

		if(vis[p[cur]] == 0) {
			c[p[cur]] = 1;
			vis[p[cur]] = 1;
			x += f(p[cur]);
		} else {
			if(c[p[cur]] == 1) {
				cyc.push_back(cur);
				return int(s[cur] == '0');
			} else {
				x += b[p[cur]];
			}
		}

		return b[cur] = x + int(s[cur] == '0');
	};

	for (auto i: cyc) cout << i << ' ';
	cout  << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}