#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int pp = 1e9 + 7;

void snu() {
	int n, k; cin >> n >> k;
	vector <int> v; map <ll, ll> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; m[x]++;
	}
	for (auto i: m) v.push_back(i.first);
	vector <int> x, tt;
	int req;
	vector <vector <ll>> dp;

	function <bool (int)> chk = [&](int mask) {
		int nd = -1;
		for(int i = 0; i < x.size(); i++) 
			if(mask & (1 << i)) nd &= x[i];
		return nd == req;
	};

	ll tot = 0;
	for(int i = 0; i < (1 << 6); i++) {
		if(__builtin_popcount(i) != k) continue;
		x = tt;
		for(auto [a, b] : m)
			if((a & i) == i) x.push_back(a);
		ll cnt = 0; req = i;
		for(int j = 0; j < (1 << x.size()); j++) 
			if(chk(j)) cnt++;
		tot = (tot % pp + cnt % pp) % pp; 
	}
	cout << tot << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}