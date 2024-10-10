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
	vector <ll> C(n);
	for(auto &i: C) cin >> i;
	vector <ll> fn(n), s(n);

	function <void (int, int)> calc = [&](int p, int c) {
		for(auto i: t[c]) {
			if(i == p) continue;
			calc(c, i);	
			fn[c] += fn[i] + s[i] + C[i];
			s[c] += s[i] + C[i];
		}
	}; calc(-1, 0);

	auto reroot = [&](int u, int v) {
		fn[u] -= (fn[v] + s[v] + C[v]);
		s[u] -= (s[v] + C[v]);
		fn[v] += (fn[u] + s[u] + C[u]);
		s[v] += (s[u] + C[u]);
	};
	ll fin = fn[0];
	function <void (int, int)> f = [&](int p, int c) {
		for(auto i: t[c]) {
			if(i == p) continue;
			reroot(c, i);
			fin = min(fin, fn[i]);
			f(c, i);
			reroot(i, c);
		}
	}; f(-1, 0);

	cout << fin  << endl;
}