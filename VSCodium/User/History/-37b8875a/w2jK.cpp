#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int x, y, k; cin >> x >> y >> k;
	for(int i = 1; i <= k - (k & 1); i++) {
		cout << x + i << ' ' << y << endl;
		cout << x - i << ' ' << y << endl;
	}
	
	if(k & 1) cout << x << ' ' << y << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}