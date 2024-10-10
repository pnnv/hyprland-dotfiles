#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	map <ll, ll> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		m[x]++;
	}

	for(auto &[a, b]: m) if(b > 1 && cout << "NO\n") return;
	cout << "YES\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}