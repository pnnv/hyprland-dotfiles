#include <bits/stdc++.h>
using namespace std;

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

	if(__popcount(pp) != __popcount(fin) && cout << -1 << endl)
		return 0;

	vector <vector <ll>> vis(1LL << (n + 2), vector <ll> (n + 1, -1));

	queue <pair <ll, ll>> q;
	q.push({pp, 0}); vis[pp][0] = 0;
	
	cout << bitset <16> (fin) << ":\n";

	while(!q.empty()) {
		ll c = q.front().first, x = q.front().second; q.pop();
		cout << bitset <16> (c) << "| " << x <<  ": ";
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

			if(vis[tc][i] == -1) {
				q.push({tc, i});
				vis[tc][i] = vis[c][x] + 1;
				if(tc == fin && x == 0 && cout << vis[tc][0] << endl)
					return 0; 
			}

			cout << bitset <16> (tc) << ' ';
		}
		cout  << endl;
	}
	cout << -1 << endl;
}

/*

0000000000110000| 0: 0000000000110000 0000000000100010 0000000000000011 
0000000000110000| 2: 0000000000110000 0000000000001100 
0000000000100010| 3: 0000000000110000 0000000000101000 
0000000000000011| 4: 0000000000110000 0000000000010001 0000000000000011 
0000000000001100| 4: 0000000000001100 0000000000101000 0000000000110000 
0000000000101000| 1: 0000000000100010 0000000000001100 
0000000000010001| 1: 0000000000000101 0000000000000011 
0000000000000011| 2: 0000000000001100 0000000000000011 
0000000000001100| 0: 0000000000000011 0000000000000101 0000000000001100 
0000000000000101| 3: 0000000000001100 0000000000010001 
-1


*/