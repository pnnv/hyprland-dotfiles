#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void snu() {
	int n; cin >> n;
	vector <ld> v(n);
	for(auto &i: v) cin >> i;
	ll op = 0;
	vector <ld> ops(n); ops[0] = 1;
	for(int i = 1; i < n; i++) {
		if(v[i] == 1 && cout << -1 << endl) return;
		ld chinchin = (ops[i - 1] * (logl(v[i - 1]) / logl(v[i])));
		chinchin = ceil(chinchin);
		ll cc = chinchin;
		if(cc != (cc & (-cc))) cc = ll(1LL << (ll(log2l(cc)) + 1));
		else if(cc == 0) cc = 1;
		else op += ll(log2l(cc) - 1);
		ops[i] = cc;		
	}
	cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}