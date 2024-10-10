#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m, k; cin >> n >> m >> k;
	for(int i = k; i <= n; i++) cout  << i << ' ';
	for(int i = k + 1; i < m; i++) cout  << i << ' ';
	for(int i = 1; i <= m; i++) cout << i << ' ';
	cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}