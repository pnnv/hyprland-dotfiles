#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	bool nop = true;
	vector <ll> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) {
		cin >> i;
		if(i > 0) nop = false;
	}
	vector <ll> id(n); iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), 
		[&](int x, int y) { return a[x] < b[x]; });
	if(nop && cout << a[id.back()] + a[id[(n / 2) - 1]] << endl) return;

	auto mxm = [&](ll t, ll p) {
		vector <int> neg; int x = 0;
		for(auto i: id) {
			if(a[i] >= t) x++;
			else {
				x--;
				if(b[i] == 1) neg.push_back(i);
			}
		}
		ll req  = 0;
		while(x < ((n & 1) ? 3 : 2) && !neg.empty()) {
			req += (t - a[neg.back()]);
			neg.pop_back();
			x += 2;
		}
		if(x < ((n & 1) ? 3 : 2)) return false;
		else return req <= p;
	};

	ll mx = 0;

	auto c = [&](ll pp) {
		ll tt = k - pp;
		ll lo = 0, hi = 1e9;
		while(lo < hi) {
			ll mid = lo + (hi - lo + 1) / 2LL;
			if(mxm(mid, pp)) lo = mid;
			else hi = mid - 1;
		}

		cout << lo << ": ";
		vector <int> neg; int x = 0;
		for(auto i: id) {
			if(a[i] >= lo) x++;
			else {
				x--;
				if(b[i] == 1) neg.push_back(i);
			}
		}
		vector <ll> tmp = a, tid = id;

		while(x < ((n & 1) ? 3 : 2)) {
			pp -= (lo - tmp[neg.back()]);
			tmp[neg.back()] = lo;
			neg.pop_back();
			x += 2;
		}
		tt += pp;
		ll mxi = 0, mxx = 0;
		for(int i = 0; i < n; i++) {
			if(tmp[tid[i]] > mxx && b[tid[i]] == 1) {
				mxx = tmp[tid[i]]; mxi = tid[i];
			}
		}
		tmp[mxi] += tt;
		sort(tmp.begin(), tmp.end());
		for(auto i: tmp) cout << i << ' '; cout << endl;
		mx = max(mx, (tmp.back() + tmp[(n / 2) - 1]));
		return (tmp.back() + tmp[(n / 2) - 1]);
	};

	c(k);

	// int xD = 300;
	// ll lo = 0, hi = k;
	// while(xD--) {
	// 	ll m1 = lo + (hi - lo) / 3LL, m2 = hi - (hi - lo) / 3LL;
	// 	ll p1 = c(m1), p2 = c(m2);
	// 	if(p1 < p2) lo = m1;
	// 	else hi = m2; 
	// }

	// cout << max({c(lo), c(hi), c(k), c(0), mx}) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}