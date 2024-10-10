#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	map <ll, set <int>> fx;

	for(auto &i: v) cin >> i;
	for (int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(v[i] == v[j] && cout << "NO\n") return;
			ll c = abs(v[i] - v[j]);
			if(c > 1) fx[c].insert(((c - v[i] % c)) % c);
		}
	}

	for(auto &[a, b]: fx)
		if(a == b.size() && cout << "NO\n") return;

	cout << "YES\n";	
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}