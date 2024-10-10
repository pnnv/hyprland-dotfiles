#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, a, b; cin >> n >> a >> b;
	map <int, int> m;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		m[x] = i;
	}
	vector <vector <int>> g(n);

	for(auto &[a, b]: m) {
		
	}
}