#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {

	int n; cin >> n;
	vector <vector <int>> t(n);
	vector <ll> val(n);
	for(auto &i: val) cin >> i;

	for(int i = 1; i < n; i++) {
		int p; cin >> p;
		t[i].push_back(p - 1);
		t[p - 1].push_back(i);
	}
	vector <ll> f(n);

	function <ll(int, int)> dfs = [&](int p, int c) {
		ll mn = 1e18;
		for(auto i: t[c]) 
			if(i != p) 
				mn = min(mn, dfs(c, i));
		
		if(mn == 1e18) return val[c];
		else if(c != 0) return (mn > val[c] ? ((val[c] + mn) / 2LL) : mn);
		else return val[c] + mn;
		
	};
	cout << dfs(-1, 0) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}