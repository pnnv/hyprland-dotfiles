#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, x, y; cin >> n >> x >> y;
	ll mn = min(x, y);
	cout << (n / mn) + (n % mn == 0 ? 0 : 1) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}