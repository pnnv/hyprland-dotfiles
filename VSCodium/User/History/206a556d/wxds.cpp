#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	bool imp = false;
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	char c = 'a'; 
	map <int, char> mp;
	string s(n, '?');

	for (int i = 0; i < n; i++) {
		if(mp.count(v[i])) s[i] = mp[v[i]];
		else {
			mp[v[i]] = c++;
			s[i] = mp[v[i]];
		}

		if(c > char('z' + 1)) imp = true;
	}

	int m; cin >> m;
	while(m--) {
		string t; cin >> t;
		if(imp && cout << "NO\n") continue;
		if(t.size() != n && cout << "NO\n") continue;

		char c = 'a'; 
		map <char, char> tt;
		string nt(n, '?');
		for (int i = 0; i < n; i++) {
			if(tt.count(t[i])) nt[i] = tt[t[i]];
			else {
				tt[t[i]] = c++;
				nt[i] = tt[t[i]];
			}
		}
		cout << (nt == s ? "YES\n" : "NO\n");
	}

}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}