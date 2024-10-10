#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m, N = 1e5 + 1; cin >> n >> m;
	vector <vector <int>> v(N);
	int p = 1;
	for(int _ = 0; _ < n; _++) {
		int l; cin >> l;
		set <int> st;
		for(;l--;) {
			int xx; cin >> xx;
			st.insert(xx);
		}
		int a = -1, b = -1;
		for(int i = 0; i < l + 2; i++) {
			if(!st.count(i)) {
				if(a == -1) a = i;
				else if(b == -1) {
					b = i;
					break;
				}
			}
		}
		v[b].push_back(a);
	}
	ll fin = (m * (m + 1LL)) >> 1LL;
	vector <int> vis(N, false);
	
	for(int i = N - 1; i >= 0; i--) {
		if(!vis[i]) {
			vis[i] = true;
			queue <int> q; q.push(i);
			while(!q.empty()) {
				int cur = q.front(); q.pop();
				if(cur <= m) fin -= cur, fin += i; 
				for(auto u: v[cur]) {
					if(!vis[u]) {
						q.push(u); 
						vis[u] = true;
					}
				}
			}
		}
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}