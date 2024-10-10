#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	int ct = 1, l = v[0];
	for (int i = 0; i < n; i++) {
		if(v[i] != l) {
			ct++; l = v[i];
		}
	}

	if(ct == 1 || (ct == 2 && v[0] == 0)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}