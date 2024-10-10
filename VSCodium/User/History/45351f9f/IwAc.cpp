#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	if(n == 1 && cout << 0 << endl) return 0;
	ll dig = 0; n--;
	
	for(int i = 1; i < 69; i++) {
		ll pp = (9LL * (ll(pow(10LL, ((i - 1LL) / 2LL)))));
		cout << pp << ' ';
		if(pp < n) n -= pp;
		else {
			dig = i; break;
		}
	}
	string st = to_string(n + 1);
	string p = st;
	if(dig & 1) p.pop_back();
	reverse(p.begin(), p.end());
	st += p;
	cout  << st << endl;
}