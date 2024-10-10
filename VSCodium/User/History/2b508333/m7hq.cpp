#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int l, r; cin >> l >> r;
	if((r - l) & 1) {
		cout << (r - l + 1) / 4 << endl;
	} else {
		if(l & 1) cout << (r - l + 2) / 4;
		else cout << (r - l + 1) / 4;
		cout  << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}