#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, m; cin >> n >> m;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	auto c = [&](ll x) {
		ll s = 0;
		for(auto i: v) s += min(i, x);
		return s <= m;
	};

	ll lo = -1, hi = 2e15;
	while(lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2LL;
		if(c(mid)) lo = mid;
		else hi = mid - 1;
	}

	if(lo != 2e15) cout << lo << endl;
	else  cout << "infinite\n";
}