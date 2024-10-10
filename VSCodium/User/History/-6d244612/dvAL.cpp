#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, x; cin >> n >> x;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if((v[i] > i || (i - v[i]) % x != 0) && cout << i << endl) return;
	}

	cout << n << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}