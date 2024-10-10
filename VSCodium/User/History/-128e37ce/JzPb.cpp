#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair <ll, ll>> factor(long long n) {
  vector<long long> factorization;
  for (int d : {2, 3, 5}) {
	while (n % d == 0) {
	  factorization.push_back(d);
	  n /= d;
	}
  }
  static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
  int i = 0;
  for (long long d = 7; d * d <= n; d += increments[i++]) {
	while (n % d == 0) {
	  factorization.push_back(d);
	  n /= d;
	}
	if (i == 8)
	  i = 0;
  }
  if (n > 1) factorization.push_back(n);
  vector <pair <ll, ll>> fx;
  map <ll, ll> pp;
  for(auto i: factorization) pp[i]++;
  for(auto i: pp) fx.push_back({i.first, i.second});
  return fx;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	map <ll, vector <int>> f;
	
	for(auto i: v) {
		auto fax = factor(i);
		for(auto &[a, b]: fax)
			f[a].push_back(b);
	}

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

	ll nim = 0;

	for(auto &[a, b]: f) {
		ll mask = 0;
		for(auto i: b) mask |= (1 << i);
		nim ^= g(mask);
	}

	cout << (nim == 0 ? "Mojtaba\n" : "Arpa\n");
}