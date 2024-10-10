#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	ll n, k; cin >> n >> k;
	if(k * (k - 1LL) < n && cout << "NO\n") return 0;
	cout  << "YES\n";

	for (int i = 0; i < n; i++) 
		cout << (i % k) + 1 << ' ' << ((i + 1 +  i / k) % k) + 1 << endl;
}