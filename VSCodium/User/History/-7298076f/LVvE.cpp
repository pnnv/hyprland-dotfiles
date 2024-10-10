#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m, N = 1e5 + 5; cin >> n >> m;
	ll mx = 0, fin = (m * (m + 1LL) / 2LL);
	vector <vector <int>> v(N);
	set<int> t, st;

	for(int _ = 0; _ < n; _++) {
		int l; cin >> l;
		st.clear();
		for(int j = 0; j < l; j++) {
			int xx; cin >> xx;
			st.insert(xx);
		}
		int a = -1, b = -1;
		for(int i = 0; i <= l + 2; i++) {
			if(!st.count(i)) {
				if(a == -1) a = i;
				else {
					b = i; break;
				}
			}
		}
		v[b].push_back(a);
	}

	int i, cnt;
	vector <bool> taken(N, false);	
	
	function <void (int)> f =  [&](int c) {
		if(v[c].size() > 1) mx = i;
		if(c <= m && !taken[c]) {
			fin -= c; fin += i;
			taken[c] = true;
		} 
		for(auto u: v[c]) if(!taken[u]) f(u);
	};
	
	for(int cur = N - 1; cur >= 0; cur--) {
		if(taken[cur]) continue;
		i = cur; f(cur);
		if(mx != 0) break;
	}
	for(int j = 0; j <= min(m, mx); j++) 
		if(!taken[j]) fin -= j, fin += mx;

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}