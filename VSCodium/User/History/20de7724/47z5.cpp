#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void snu() {
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	if(n > m) swap(n, m);

	if(s == t && cout << 0 << endl) return;
	if(s.front() != t.front() && cout << -1 << endl) return;

	for (int i = 0; i < n; i++) {
		if(s[i] != t[i] && cout << 2 << endl) return;
	}

	cout << 1 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}