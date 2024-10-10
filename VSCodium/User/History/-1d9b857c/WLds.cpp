#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, s, m; cin >> n >> s >> m;
	vector <pair <int, int>> v(n);
	for(auto &[a, b]: v) cin >> a >> b;
	if((v[0].first >= s || (m -  v[n - 1].second >= s)) && cout  << "YES\n") return;
	for(int i = 0; i < n - 1; i++) 
		if(v[i + 1].first - v[i].second >= s && cout  << "YES\n") return;
	cout << "NO\n"; 
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}