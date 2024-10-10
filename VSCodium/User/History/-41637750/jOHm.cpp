#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(4);
	for(auto &i: v) {
		cin >> i; i = max(i, i - (n - 2));
	}
	cout << (v[1] + v[3] != v[0] + v[2] ? "NO\n" : "YES\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}