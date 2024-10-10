#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, k; cin >> n >> k;
	vector <ll> v(n);
	ll s = 0;
	for(auto &i: v) cin >> i, s += i;
	sort(v.begin(), v.end(), greater<>());

	cout << s / 2 << endl;
}