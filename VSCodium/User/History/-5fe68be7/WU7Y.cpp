#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	
}

int32_t main() {
	int t; cin >> t;
	while(t--) {
		ll n, m; cin >> n >> m;
		n += m;
		ll po = ll(log2l(n));
		cout << (1LL << (po + 1LL)) - 1LL << endl;
	}
}