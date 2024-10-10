#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <vector <int>> g(n);
	set <pair <int, int>> p;
	for(int i = 0; i < n - 1; i++) {
		int x, y, t; cin >> x >> y >> t; --x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
		if(t == 2)  {
			p.insert({x, y});
			p.insert({y, x});
		}
	}

	
}