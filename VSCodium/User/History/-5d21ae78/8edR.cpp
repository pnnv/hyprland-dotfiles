#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, m; cin >> n >> m;
	if(m < n && cout << 0 << endl) return;

	for(int i = 0; i < n + m; i++) {
		if(m < (n ^ i)) {
			cout << i << endl;
			return;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}