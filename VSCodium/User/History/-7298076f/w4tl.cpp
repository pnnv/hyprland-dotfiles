#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m, N = 1e5 + 5; cin >> n >> m;
	ll mx = 0, fin = (m * (m + 1LL) / 2LL);
	vector <vector <int>> v(N);

	for(int _ = 0; _ < n; _++) {
		int l; cin >> l;
		set <int> st;
		for(int j = 0; j < l; j++) {
			int xx; cin >> xx;
			st.insert(xx);
		}
		int a = -1, b = -1;
		for(int i = 0; i < l + 2; i++) {
			if(!st.count(i)) {
				if(a == -1) a = i;
				else if(b == -1) {
					b = i; break;
				}
			}
		}
		v[b].push_back(a);
	}
	vector <bool> vis(N, false);
	int i;
	function <void(int, int)> dfs = [&](int p, int c) {
		vis[c] = true;
		if(v[c].empty()) {
			if(c <= m) {
				fin -= c; fin += i;
				return;
			}
			for(auto u: v[c]) 
				if(i != p) dfs(c, u);
		}
	};

	for(i = N - 1; i >= 0; i--) {
		if(!vis[i]) {
			vis[i] = true;
			dfs(0, i);
		}
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}