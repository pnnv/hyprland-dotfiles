#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	ll s = 0;
	for(int i = 0; i < n - 2; i++) s += v[i];
	v[n - 2] -= s;
	cout << (v[n - 1] - v[n - 2]) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}