#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	map <int, int> m;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		m[x]++;
	}
	for(auto [a, b]: m) {
		if(b & 1) {
			cout << "YES\n";
			return;
		}
	}
	cout  << "NO\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}