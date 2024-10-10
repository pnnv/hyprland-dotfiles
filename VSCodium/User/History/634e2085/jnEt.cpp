#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	auto op = [&]() {
		ll o = 0;
		vector <ll> a = v;
		for (int i = 1; i < n; i++) {
			a[i] -= o;
			if(a[i] > a[i - 1]) {
				o += abs(a[i - 1] - a[i]);
				a[i] = a[i - 1];
			}
		}
		o += abs(a[0] - a[n - 1]) + abs(a[n - 1]);
		return o;
	};
	ll fin = op(); 
	reverse(v.begin(), v.end());
	cout << min(fin, op()) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}