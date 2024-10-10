#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	int mn = 1e9 + 1, mni = -1;
	for(int i = 0; i < n - 1; i++) {
		if(v[i + 1] - v[i] < mn) {
			mn = v[i + 1] - v[i];
			mni = i;
		} 
	}

	for(int i = mni + 1; i < n; i++) cout << v[i] << ' ';
	for(int i = 0; i <= mni; i++) cout << v[i] << ' ';
	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}