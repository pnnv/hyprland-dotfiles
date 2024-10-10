#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, q; cin >> n >> q;
	vector <vector <int>> t(n);
	for (int i = 0; i < n - 1; i++)  {
		int x; cin >> x;
		t[x - 1].push_back(i + 1);
	}
	vector <int> p(n);
	for(auto &i: p) cin >> i;
	
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}