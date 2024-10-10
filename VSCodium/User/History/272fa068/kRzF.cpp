#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int l, r, L, R; cin >> l >> r >> L >> R;
	int i = max(0, min(r, R) - max(l, L) + 1);
	int x = 0;

	if(i == 0) {
		if(min(r, R) == max(l, L) - 1) cout << 1 << endl;
		else cout  << 0 << endl;
	} else {
		if(r != R && min(r, R) < 100) x++;
		if(l != L) x++;
		cout << i - 1 + x << endl;
	}

}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}