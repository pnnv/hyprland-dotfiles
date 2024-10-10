#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <vector <int>> t(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		t[--a].push_back(--b);
		t[b].push_back(a);
	}
	vector <ll> c(n);
	for(auto &i: c) cin >> i;
	vector <ll> dist(n);
	ll x = 0;

	function <void (int, int)> calc = [&](int p, int v) {
		for(auto i: t[v]) {
			if(i == p) continue;
			dist[i] = dist[v] + 1;
			x += dist[i] * c[i];
		}
	}; calc(-1, 0);

	cout << x << endl;
	// function <void (int, int)> f = [&](int p, int c) {
	// };	
}