#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	if(n > 2 && cout << "NO\n") return;
	if(v[0] == v[1] - 1 && cout  << "NO\n") return;
	cout << "YES\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}