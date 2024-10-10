#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, q; cin >> n >> q;
	vector <int> v(n + 1);
	vector <vector <int>> f(1 << 18);
	for (int i = 0; i < n; i++) {
		cin >> v[i + 1];
		v[i + 1] ^= v[i];
		f[v[i + 1]].push_back(i + 1);
	}

	for(;q--;) {
		int l, r; cin >> l >> r;
		if(v[l - 1] == v[r] && cout << "YES\n") continue;
		if(f[v[r]].empty() && cout  << "NO\n") continue;
		auto lb = lower_bound(f[v[r]].begin(), f[v[r]].end(), l);
		auto llb = lower_bound(f[v[l - 1]].begin(), f[v[l - 1]].end(), *lb);
		cout << ((*llb < r ? "YES\n" : "NO\n"));
	}
	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}