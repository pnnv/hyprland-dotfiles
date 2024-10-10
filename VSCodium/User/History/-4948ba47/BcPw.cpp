#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef long long ll;

void snu() {
	ll n; cin >> n;
	vector <ll> v(n);
	ll sm = 0;
	for(auto &i: v) cin >> i, sm += i;
	map <ll, ll> m, pp; ll mx = 0;
	vector <ll> suf(n);

	for (int i = 0; i < n; i++) {
		m[v[i]]++;
		if(m[v[i]] > 1) mx = max(mx, v[i]);
		suf[i] = mx; pp[suf[i]]++;
	}
	sm += accumulate(suf.begin(), suf.end(), 0);
	for (int i = 1; i < n; i++) {
		if(pp[suf[i]] == 1) suf[i] = suf[i - 1];
	}

	for (int i = 1; i < n - 1; i++) {
		suf[i] += suf[i - 1];
		sm += suf[i];
	}

	cout << sm << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}