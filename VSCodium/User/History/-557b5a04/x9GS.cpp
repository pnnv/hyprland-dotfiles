#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	if(n == 1 && cout  << 0 << endl) return;	
	else if(k == 2 && cout << n - 1 << endl) return;
	ll ans =(n / (k - 1));
	if((n % (k - 1)) > 1) ans++;
	cout  << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}