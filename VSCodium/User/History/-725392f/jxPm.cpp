#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	ll mn = 6942069420;
	for(int i = 0; i < n - 1; i++)	
		mn = min(mn, v[i + 1] - v[i]);
	cout << (v[n - 1] + v[n - 2] - mn - 1) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}