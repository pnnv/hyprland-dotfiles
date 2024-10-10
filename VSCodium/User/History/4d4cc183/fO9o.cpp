#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll ans = 0;
	string s; cin >> s;
	ll e = 0, o = 0;
	for(char i: s) {
		e++;
		if(i == '0') {
			ans += o; ans += (2LL * e);
			e += o; o = 0;
		} else {
			ans += (2LL * o); ans += e;
			o += e; e = 0;
		}
	}

	cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}