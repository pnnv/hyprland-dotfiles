#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m, N = 1e5 + 5; cin >> n >> m;
	ll mx = 0;

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
		mx = max(mx, ll(b));
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}