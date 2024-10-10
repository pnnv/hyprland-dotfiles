#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	string s, t; cin >> s >> t;
	
	ll pp = 0, fin = 0, ptr = 2;
	for(int i = n - 1; i >= 0; i--, ptr++) {
		if(s[i] == 'W') pp ^= (1LL << ptr);
		if(t[i] == 'W') fin ^= (1LL << ptr);
	}
	vector <vector <ll>> vis(1LL << (n + 2), vector <ll> (n + 1, -1));

	queue <pair <ll, ll>> q;
	q.push({pp, 0}); vis[pp][0] = 0;

	while(!q.empty()) {
		ll c = q.front().first, x = q.front().second; q.pop();
		for(int i = 0; i <= n; i++) {
			if(abs(i - x) <= 1) continue;
			ll tc = c;
			if((c >> i) & 1LL) {
				tc |= (1LL << x);
				tc ^= (1LL << i);
			}
			if((c >> (i + 1)) & 1LL) {
				tc |= (1LL << (x + 1LL));
				tc ^= (1LL << (i + 1LL));
			}

			if(vis[tc][i] == -1 || vis[tc][i] > (vis[c][x] + 1)) {
				q.push({tc, i});
				vis[tc][i] = vis[c][x] + 1;
			}

		}
	}
	cout << vis[fin][0] << endl;
}
