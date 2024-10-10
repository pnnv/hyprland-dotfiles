#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end(), greater<>());

	ll a = 0;
	if(n & 1) {
		a += v.back();
		v.pop_back();
	}

	ll fin = 0;
	for(int i = 0; i < v.size(); i += 2) {
		if(v[i] - v[i + 1] <= k) {
			k -= (v[i] - v[i + 1]);
		} else {
			fin += ((v[i] - v[i + 1]) - k);
			k = 0;
		}
	}

	cout << a + k << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}