#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	int l = 0, r = n - 1, t = 0;
	while(l < r) {
		if(t & 1) r--;
		else l++;
		t++;
	}
	cout << v[l] << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}