#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(n);
	iota(v.begin(), v.end(), 1);
	if(n > 2) swap(v[1], v[2]);
	for(auto i: v) cout << i << ' '; cout << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}