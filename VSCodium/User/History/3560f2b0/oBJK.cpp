#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	map <int, int> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; m[x]++;
	}
	ll tot = 0;
	for(auto &[a, b]: m)
		tot += b;
	cout << n - (n % m.size()) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}