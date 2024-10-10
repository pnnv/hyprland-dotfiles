#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll nxt() {
	ll x; cin >> x;
	return x;
}

void snu() {
	int n; cin >> n;
	ll p = 0;
	for (int i = 0; i < n; i++)
		p ^= nxt();
	cout  << (p == 0 ? "second\n" : "first\n");
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}