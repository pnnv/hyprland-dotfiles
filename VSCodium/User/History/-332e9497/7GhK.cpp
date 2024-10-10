#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n, t, p; cin >> n >> t >> p;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());

	cout << max(0, t - v[n - p]) << endl;
}