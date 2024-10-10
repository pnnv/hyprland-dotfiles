#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	ll n; cin >> n;
	map <ll, ll> g;

	function <ll(ll)> f = [&](ll x) {
		if(x == 1) return 0LL;
		if(g.count(x)) return g[x];
		set <int> st;
		for(ll i = 2; i <= 9; i++)
			if(x % i == 0) st.insert(f(x / i));
		ll m;
		for(int i = 0; i <= st.size(); i++) {
			if(!st.count(i)) { m = i; break; }
		}
		return g[x] = m;
	};

	cout << (f(n) == 0 ? "Ollie wins.\n" : "Stan wins.\n");
}