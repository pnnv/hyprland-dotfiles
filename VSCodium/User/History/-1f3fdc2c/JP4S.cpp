#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	map <int, int> s;
	ll x = 0;
	int n; cin >> n;
	vector <int> a(n), b(n);
	for(auto &i: a) cin >> i;
	for (int i = 0; i < n; i++) {
		cin >> b[i]; s[b[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		if(a[i] != b[i]) {
			if(s.find(a[i]) == s.end() && cout << "NO\n") return;
			x += (s[a[i]] - i); s[b[i]] = s[a[i]];
			s.erase(a[i]);
		}
	}

	cout << ((x & 1) ? "NO\n" : "YES\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}