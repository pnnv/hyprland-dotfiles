#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, k; cin >> n >> k;
	vector <ll> m, l;
	ll s = 0;
	int tt = 0;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if(x > k) m.push_back(x);
		else if(x == (2LL * k)) tt++, s += k;
		else l.push_back(x);
	}
	sort(l.begin(), l.end(), greater<>());
	sort(m.begin(), m.end(), greater<>());

	for(int i = 0; i < l.size(); i += 2)	
		s += l[i]; 

	ll p = ((l.size() & 1) ^ 1 ^ (tt & 1));

	for(auto i: m)  
		s += (i + p) / 2LL;
	cout << s  << endl;
}