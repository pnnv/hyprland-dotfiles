#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	if(n == 1 && cout  << 0 << endl) return;	
	// else if()
	ll ans = n / (k - 1);
	if((ans % (k - 1)) > 1) ans++;
	cout  << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}