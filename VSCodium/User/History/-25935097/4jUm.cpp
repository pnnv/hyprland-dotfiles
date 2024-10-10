#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	ll s = 0;
	for(int i = 0; i < k; i++) s += v[i];
	for(int i = k; i < n - 1; i++) cout << v[i] << ' ';
	cout << v[n - 1] + s << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}