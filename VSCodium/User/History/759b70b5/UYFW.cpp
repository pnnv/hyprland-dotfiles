#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	ll t = 0, rem = 0;
	for(auto i: v) {
		t += 3LL * (i / 5LL);
		ll x = i % 5;
		if(x == 1) {
			t++;
			rem = (rem + 1) % 3;
		} else if(x == 2) {
			if(rem <= 1) {
				t += 2;
				rem = (rem + 2) % 3;
			} else  {
				t += 1;
				rem = 0;
			}
		} else if(x == 3) {
			if(rem == 2) {
				t++; rem = 0; 
			} else if(rem == 1) {
				t += 2; rem = 0;
			} else if(rem == 0) {
				t += 3; rem = 0;
			}
		} else if(x == 4) {
			if(rem >= 1) {
				t += 2; rem = (rem + 2) % 3;
			} else {
				t += 3;
			}
		}
	}

	cout << t << endl;
}