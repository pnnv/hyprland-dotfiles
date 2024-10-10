#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
	string s; cin >> s;

	vector <int> b(n), vis(n);

	function <int(int)> f = [&](int cur) {
		int x = 0;
		if(p[cur] == cur) return b[cur] = int(s[cur] == '0');
		if(vis[p[cur]] == 0) {
			vis[p[cur]] = 1;
			x += f(p[cur]) + int(s[cur] == '0');
		}
		else x += b[p[cur]];

		return b[cur] = x;
	};

	for (int i = 0; i < n; i++) cout << f(i) << ' ';
	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}