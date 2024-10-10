#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	map <ll, ll> m;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x; m[x]++;
	}	
	vector <pair <ll, ll>> v;
	for(auto &[a, b]: m) v.push_back({a, b});

	for(int cur = 0; cur < v.size(); cur++) {
		ll sum = 0;
		
	}
}