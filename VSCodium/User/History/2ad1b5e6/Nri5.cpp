#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m; cin >> n >> m;
	vector <ll> o(n), z(n), q(n);
	for(int i = 0; i < m; i++) {
		string s; cin >> s;
		for(int j = 0; j < n; j++) {
			if(s[j] == '0') z[j]++;
			else if(s[j] == '1') o[j]++;
			else q[j]++;
		}
	}
	ll fin = 0;

	for (int i = 0; i < n; i++) {
		ll a = o[i], b = z[i], c = q[i];
		if(a > b)  swap(a, b);
		if(c >= b - a) {
			c -= (b - a);
			a = b;
		} else {
			a += c;
			c = 0;
		}
		a += (c / 2LL);
		b += ((c + 1LL) / 2LL);

		fin += (a * b);
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}