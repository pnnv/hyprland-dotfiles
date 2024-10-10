#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	set <int> v;
	bool b = false;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.insert(x);
	}
	cout << ((v.size() > 1) ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}