#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	vector <ll> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;

	vector <int> in(n);
	iota(in.begin(), in.end(), 0);

	sort(in.begin(), in.end(), [&](int x, int y) {
		return (a[x] - b[])
	}) 
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}