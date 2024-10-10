#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector <vector <int>> t(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		t[--a].push_back(--b);
		t[b].push_back(a);
	}

	vector <int> a, b;
	function <int(int, int)> dfs = [&](int p, int c) {
		int ch = 0;
		for(auto i: t[c])
			if(i != p)
				ch += dfs(c, i);
		a.push_back(n - ch - 1); b.push_back(ch);
		return ch + 1;
	}; dfs(-1, 0);

	cout << a.size() << endl;
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << ' ' << b[i] << endl;
}