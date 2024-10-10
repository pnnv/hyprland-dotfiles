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

	int i, cnt;
	set <int> st, taken;
	
	function <void (int)> f =  [&](int c) {
		if(c <= m && !taken.count(c)) {
			fin -= c; fin += i;
			taken.insert(c);
		} 
		for(auto u: v[c]) f(u);
	};
	
	for(auto it = t.rbegin(); it != t.rend(); it++) {
		int cur = *it;
		i = cur; f(cur);
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}