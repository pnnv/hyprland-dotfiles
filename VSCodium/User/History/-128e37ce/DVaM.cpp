#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll nim = 0;
	int n; cin >> n;
	vector <ll> v(n);
	map <ll, ll> mem; mem[0] = 0;

	function <ll (ll)> g = [&](ll mask) {
		if(mem.count(mask)) return mem[mask];
		vector <int> mex;
		for(int i = 1; i < 30; i++) {
			ll nxt = ((mask >> i) | (mask & ((1 << i) - 1)));
			if(nxt != mask) mex.push_back(g(nxt));
		}
		sort(mex.begin(), mex.end());
		ll ex = 0;
		for(ll i = 0; i < mex.size(); i++) 
			if(mex[i] != i) 
				return 	mem[mask] = i;
		return mem[mask] = mex.size();
	};

	map <int, int> pps;

	for (;n--;) {
		ll x; cin >> x;
		ll tmp = x;
		for(ll i = 2; i * i <= x; i++) {
			int cnt = 0;
			while(tmp % i == 0) {
				tmp /= i; cnt++;
			}
			if(cnt > 0) pps[i] |= (1 << (cnt - 1));
		}
		if(tmp > 1) pps[tmp] |= 1;
	}

	for(auto &[a, mask]: pps)
		nim ^= g(mask);

	cout << (nim == 0 ? "Arpa\n" : "Mojtaba\n");
}