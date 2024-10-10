#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int l, r; cin >> l >> r;
	int x = (r / 4) - (l / 4);
	cout << r - l + 1 - x << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}