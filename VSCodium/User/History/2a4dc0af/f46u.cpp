#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(NULL) -> ios::sync_with_stdio(0);
    int n; cin >> n;
    set <pair <int, int>> bad;
    vector <vector <int>> g(n);

    for(int i = 0; i < n - 1; i++) {
        int x, y, t; cin  >> x >> y >> t;
        g[--x].push_back(--y);
        g[y].push_back(x);
        if(t == 2) {
            bad.insert({x, y});
            bad.insert({y, x});
        }
    }

	vector <int> fin;
	int cnt = 0;

	function <void (int, int)> dfs = [&](int p, int c) {
		for(auto i: g[c]) {
			if(i == p) continue;
			if(bad.count({i, c})) cnt++;
			dfs(c, i);
		}
		if(g[c].size() == 1) {
			if(cnt > 0) {
				fin.push_back(c + 1);
				cnt = 0;
			}
		}
	}; dfs(-1, 0);

	cout << fin.size() << endl;
	for(auto i: fin) cout << i << ' ';
	cout << endl;
}
