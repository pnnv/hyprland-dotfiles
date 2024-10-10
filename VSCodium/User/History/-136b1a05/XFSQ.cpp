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

	for(auto i: v) {
		ll dif = abs(i - t);
		ll r = -1, l = -1;
		ll p = 0;
		while(dif >= 0) {
			if(~dif & 1) {
				if(r != -1 && cout << "No\n") return;
				else if(l != -1) r = p;
			} else {
				if(l == -1) l = p;
				else r = p;
			}
			if(dif == 0) break;
			p++;
		}
	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}