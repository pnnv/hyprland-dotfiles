#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);

	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	
	int o = -1, e = 0;

	for (int i = 0; i < n; i++) {
		if(v[i] & 1) o = i;
		else e++;
	}
	if(o == -1 && cout << 0 << endl) return;
	ll mx = v[o];
	for(int i = o; i  >= 0; i--) 
		if(v[i] % 2 == 0) 
			mx += v[i];

	for(int i = o; i < n; i++) {
		if(v[i] % 2 == 0) {
			if(v[i] < mx) {
				mx += v[i];
			} else {
				e++; mx += (2ll * v[i]);
			}
		}
	}
	cout << e << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}