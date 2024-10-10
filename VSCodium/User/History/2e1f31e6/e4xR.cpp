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
				cyc.push_back(p[cur]);
				return int(s[cur] == '0');
			} else {
				x += b[p[cur]];
			}
		}

		return b[cur] = x + int(s[cur] == '0');
	};
	for (int i = 0; i < n; i++) {
		c = tmp;
		if(vis[i] == 0) f(i);
	}

	for (auto i: cyc)  {
		vector <int> ele; ele.push_back(i);
		int pp = p[i], x = int(s[i] == '0');

		while(pp != i) {
			x += int(s[pp] == '0');
			ele.push_back(pp);
			pp = p[pp];	
		}

		for(auto j: ele) b[j] = x;
	}

	for(auto i: b) cout << i << ' ';
	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}