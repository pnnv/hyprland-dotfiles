#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x % v[i] == 0) {
			x += 90;
		}	
	}
	cout << "oene\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}