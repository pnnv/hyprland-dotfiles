#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void snu() {
	int n; cin >> n;
	vector <ld> v(n);
	for(auto &i: v) cin >> i;
	ll op = 0;
	vector <ll> ops(n, 0); 
	int p = 0;
	while(v[p] == 1 && p < n) p++;

	for(int i = max(p, 1); i < n; i++) {
		if(v[i] == 1 && cout << -1 << endl) return;
		if(v[i - 1] == 1) continue;
		ld a  = log2l(v[i - 1]), b = log2l(v[i]);
		ops[i] = ops[i - 1];
		ld x = ops[i], y = ops[i];
		if(a < b) {
			y += ld(log2l(b / a));
			while(y - 1 >= x) y -= 1, ops[i]--;
		}  else if(b < a) {
			x += ld(log2l(a / b));
			while(y < x) y += 1, ops[i]++; 
		}
	}
	for(auto i: ops) cout << i << ' '; cout << endl;
	// for(auto i: ops) op += i;
	// cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}