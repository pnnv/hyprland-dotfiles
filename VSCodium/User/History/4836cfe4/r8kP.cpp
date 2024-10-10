#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	map <ll, ll> m;
	ll n, a , x, y; cin >> n >> a >> x >> y;
	
	function <ll(ll)> f = [&](ll c)  {
		if(m.count(c)) return m[c];
		return m[c] = min(x + f(n / a), ())
	}
}