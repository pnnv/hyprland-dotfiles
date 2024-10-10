#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	map <char, int> l, h;
	string s, t; cin >> s >> t;

	for (int i = 0; i < n; i++) {
		if(l.count(s[i])) h[s[i]] = i;
		else l[s[i]] = i; 
	}
	int mx = 0;

	for(int i = 0; i < m - 1; i++) 
		mx = max(mx, h[t[i + 1]] - l[t[i]]);
	cout  << mx << endl;
}