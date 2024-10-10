#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m, N = 1e5 + 5; cin >> n >> m;
	ll mx = 0, fin = (m * (m + 1LL) / 2LL);
	vector <vector <int>> v(N);
	set<int> t;

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
		t.insert(b);
		if(t.count(a)) t.erase(a);
	}
	vector <bool> vis(N, false);
	int i, cnt;
	set <int> st, taken;
	
	function <void (int)> f =  [&](int c) {
		st.insert(c);
		if(v[c].empty()) { cnt++;  return; }
		for(auto u: v[c]) f(u);
	};
	
	for(auto cur: t) {
		i = cur; cnt = 0; st.clear();
		f(cur);
		int nt = 0;
		while(nt < cnt && !st.empty()) {
			int c = *st.begin();
			if(c <= m) {
				if(taken.count(c)) continue;
				taken.insert(c);
				fin -= c, fin += cur; nt++;
			} else break;
			st.erase(c);
		}
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}