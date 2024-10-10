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

	vector <int> sub(n);
	
	function <int(int, int)> f = [&](int c, int p) {
		int cur = 0;
		for(auto i: g[c]) {
			if(i == p) continue;
			if(bad.count({i, c})) cur++;
			cur += f(i, c);
		}
		return sub[c] = cur;
	}; f(0, -1);

	vector <int> fin;

	function <void (int, int, int)> ff = [&](int c, int p, int x) {
		bool pp = false;
		for(auto i: g[c]) {
			if(i == p) continue;
			if(sub[i] != 0) pp = true, ff(i, c, 1);
			else ff(i, c, 0);
		}
		if((!pp) && x == 1) fin.push_back(c + 1);
	}; ff(0, -1, (sub[0] == 0 ? 0 : 1));

	cout << fin.size() << endl;
	for(auto i: fin) cout << i << ' ';
	cout << endl;
}
