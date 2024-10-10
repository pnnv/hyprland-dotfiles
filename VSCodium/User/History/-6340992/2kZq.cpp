#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	ll mn = n;
	for(auto &i: v) cin >> i;

	for(int i = 0; i < 33; i++) {
		ll o = 0, tmp = 0;
		for(int j = 0; j < n; j++) {
			if(v[j] < (1LL << i)) o |= v[j];
			else tmp++;
		}
		if(o + 1 == (1LL << i)) mn = min(mn, tmp);
	}

	cout  << mn << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}