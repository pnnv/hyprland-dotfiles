#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	vector <int> p = v, s = v;
	for(int i = 1; i < n; i++) p[i] += p[i - 1];
	for(int i = n - 2; i >= 0; i--) s[i] += s[i + 1];

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if(v[i] == 0) {
			if(p[i] == s[i]) ans += 2;
			else if(abs(p[i] - s[i]) == 1) ans++;
		}
	}

	cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}