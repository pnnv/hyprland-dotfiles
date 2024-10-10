#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <ll> v(n);

	for(auto &i: v) cin >> i;
	vector <vector <ll> > mx(n, vector <ll> (2, -1));

	function <ll(int, int)> f = [&](int i, int x) {
		if(i >= n) return 0LL;
		if(mx[i][x] != -1) return mx[i][x];

		ll cur = 0;

		if(x == 1) cur = max(2LL * v[i] + f(i + 1, 0), f(i + 1, 1)); 
		else cur = max(v[i] + f(i + 1, 1), f(i + 1, 0));

		return mx[i][x] = cur;
	}; cout << f(0, 0) << endl;
}