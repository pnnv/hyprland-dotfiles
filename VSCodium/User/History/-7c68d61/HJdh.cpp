#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sol(vector <int> &A, vector <int> &B) {
	int n = A.size();
	vector <vector <int>> g;
	g.emplace_back(A); g.emplace_back(B);

	for(auto v: g) {
		for(auto i: v) cout << i << ' ';
		cout << endl;
	}

	int cur;
	vector <vector <bool>> vis(n, vector <bool> (2, false));
	auto tmp = vis;

	function <void (int, int)> c = [&](int x, int y) {
		if(x >= n || y >= 2) return;
		if(vis[x][y] || g[x][y] > cur) return;
		vis[x][y] = true;
		c(x + 1, y); c(x, y + 1);
	};

	ll lo = ll(-1e9) - 1, hi = 1e9;

	while(lo < hi) {
		cur = lo + (hi - lo + 1LL) / 2LL;
		vis = tmp;
		c(0, 0);
		if(vis[n - 1][1]) lo = cur;
		else hi = cur - 1;
	}

	return lo;
}

int32_t main() {
	vector <int> a = {3, 4, 6}, b = {6, 5, 4};

	cout << sol(a, b) << endl;
}