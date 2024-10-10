#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	int m; cin >> m;
	int l = m - 1, r = m + 1;
	bool c = true;
	for(int i = 0; i < n - 1; i++) {
		int x; cin >> x;
		if(x == l) l--;
		else if(x == r) r++;
		else c = false;
	}

	cout << (c ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}