#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	for(int i = 1; i < n; i++) v[i] += v[i - 1];
	string s; cin >> s;
	int l = 0, r = n - 1;
	while(s[l] == 'R' && l < n) l++;
	while(s[r] == 'L' && r >= 0) r--;
	if(((l == n || r == -1)|| l > r) && cout << 0 << endl) return;
	auto pp = [&](int l, int r) {return v[r] - (l == 0 ? 0 : v[l - 1]); };
	ll ans = 0;
	while(l < r && l < n && r >= 0) {
		if(s[l] == 'L' && s[r] == 'R') {
			ans += pp(l, r);
			l++; r--;
		} else {
			if(s[l] == 'R') l++;
			if(s[r] == 'L') r--;
		}
	}

	cout << ans << endl;
}


int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}