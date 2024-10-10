#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	ll n, a, b, k; cin >> n >> a >> b >> k;
	vector <ll> h(n);
	for(auto &i: h) cin >> i;

	ll w = 0;
	vector <int> p;
	for(auto i: h) {
		int rem = ((i % (a + b)) == 0 ? a + b : (i % (a + b)));
		if(rem <= a) {
			w++; continue;
		}
		rem -= a;
		p.push_back(((rem - 1) / a) + 1);
	}
	sort(p.begin(), p.end());

	for(auto i: p) {
		if(i <= k) {
			w++; k -= i;
		} else break;
	}

	cout << w << endl;
}