#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> e, o;
	int mxe = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if(i & 1) {
			o.push_back(x);
			mx = max(mx, x);
		} else {
			mxe = max(mxe, x);
			e.push_back(x);
		} 
	}

	cout << max(e.size() + mxe, o.size() + mx) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}