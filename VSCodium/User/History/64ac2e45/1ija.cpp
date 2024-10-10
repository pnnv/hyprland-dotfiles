#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	vector <ll> v(n);
	ll s = 0;
	for(auto &i: v) cin >> i, s += i;

	auto c = [&](ll pp) {
		if((pp - (s & pp)) % pp > k) return false;
		ll tt = ((s + k) /  pp);
		for(auto i: v) if(i > tt) return false;
		return true;
	};

	for(int i = 1; i <= n; i++) {
		if(c(i)) cout << "YE ";
		else cout << "NE ";
	}
	cout << endl;

	ll lo = 0, hi = 1e6;
	while(lo < hi) {
		ll mid = lo + (hi - lo + 1LL) / 2LL;
		if(c(mid)) lo = mid;
		else hi = mid - 1;
	}

	cout << lo << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}