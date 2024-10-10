#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll l, r; cin >> l >> r;
	ll dif = 0, cnt = 0;
	for(int i = l; i <= r; i += (dif++)) cnt++;
	cout << cnt << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}