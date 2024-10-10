#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	k--;
	// if(n == 1 && cout  << 0 << endl) return;
	cout  << ((n + k - 1) / k) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}