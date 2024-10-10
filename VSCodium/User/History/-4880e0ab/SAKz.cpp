#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll fin = 0;
	int n; cin >> n;
	vector <int> v(n);
	map <ll, ll> f;
	for(auto &i: v) cin >> i, f[i]++;
	ll mxf = 0, mx = -1;

	for(auto &[a, b]: f) {
		if(a == 0) continue;
		fin += (b * (b - 1LL)) / 2LL;
		if(b > mxf) {
			mxf = b; mx = a;
		}
	}

	fin -= (mxf * (mxf - 1LL)) / 2LL;
	mxf += f[0];
	fin -= (mxf * (mxf - 1LL)) / 2LL;

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}