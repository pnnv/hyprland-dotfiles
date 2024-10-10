#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	if(k == 1 && cout << n << endl) return;
	int cnt = 0;
	while(n > k) {
		ll t = k;
		while(t * k <= n) t *= k, cnt++;
		n -= t;
	}
	cout << n + cnt << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}