#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	ll ans = (m * (m + 1LL) / 2LL) + ((2 * m + 2 * n - 2) * (2 * m + 2 * n - 1) / 2LL);
	cout << ans << endl;	
}