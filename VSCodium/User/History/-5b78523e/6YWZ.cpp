#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());

	ll f = v[n - 1] - v[0];

	for(int i = 0; i <= 2; i++) {
		for(int j = 0; j <= 2; j++) {
			if(i + j > 2) continue;
			f = min(f, v[n - j - 1] - v[i]);
		}
	}
	cout  << f << endl;
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}