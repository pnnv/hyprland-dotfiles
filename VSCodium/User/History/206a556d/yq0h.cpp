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
			mp[v[i]] = ++c;
			s[i] = c;
		}

		if(c > 'z') imp = true;
	}

	int m; cin >> m;
	while(m--) {
		string sxx; cin >> sxx;
	}

	cout << s << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}