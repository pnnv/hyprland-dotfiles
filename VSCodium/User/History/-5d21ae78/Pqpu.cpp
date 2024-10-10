#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m; cin >> n >> m;
	// if(m < n && cout << 0 << endl) return;

	cout << bitset <12> (n) << "\n";
	cout << bitset <12> (m) << endl << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}