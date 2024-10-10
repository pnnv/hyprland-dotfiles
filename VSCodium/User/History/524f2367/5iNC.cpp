#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	map <int, int> m;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mx = max(mx, x);
		m[x]++;
	}

	cout << ((m[mx] & 1) ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}