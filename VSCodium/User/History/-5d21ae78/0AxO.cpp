#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m; cin >> n >> m;
	if(m < n && cout << 0 << endl) return;
	else cout << (n ^ (m + 1)) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}