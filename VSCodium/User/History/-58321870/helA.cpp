#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);

	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	
	int o = -1, e = 0;

	for (int i = 0; i < n; i++) {
		if(v[i] & 1LL) o = i;
	}

	if(o == -1 && cout << 0 << endl) return;
	ll mx = v[o];

	for(int i = 0; i < o; i++) {
		if(v[i] % 2 == 0) mx += v[i];
	}

	for(int i = o; i >= 0; i--) 
		if(v[i] % 2LL == 0) 
			mx += v[i];
	
	bool chinchin = false;
	for(int i = o + 1; i < n; i++) {
		if(mx > v[i]) {
			mx += v[i];
		} else {
			chinchin = true;
			break;
		}
	}
	int p = 0;
	for(int i = 0; i < n; i++) 
			if(v[i] % 2LL == 0)  p++;
	
	cout << (chinchin ? p + 1 : p) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}