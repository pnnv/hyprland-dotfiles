#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, oki = 0, x = 0; cin >> n;
	vector <ll> v(n);
	ll t = 0;
	for(auto &i: v) cin >> i, t += i;
	if(t % n != 0 && cout << "No\n") return;
	t /= n;
	map <ll, ll> m;

	for(auto i: v) {
		ll dif = abs(i - t);
		if(dif == 0) {
			oki++; continue;
		}
		ll r = (dif & (-dif));
		ll l = r;
		while((dif & l) != 0) l <<= 1;
		if((l - r) != dif && cout << "No\n") return;
		
		if(i < t) {
			m[l]--; m[r]++;
		} else {
			m[l]++; m[r]--;
		}
	}
	for(auto &[a, b]: m) 
		if(b != 0 && cout << "No\n") return;
	cout  << "Yes\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}