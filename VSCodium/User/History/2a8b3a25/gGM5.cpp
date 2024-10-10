#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> f(n);
	int x = 0;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		f[--a]++; f[--b]++;
	}
	string s; cin >> s;
	int o = 0, z = 0, q = 0;
	for (int i = 1; i < n; i++) {
		if(f[i] == 1) {
			if(s[i] == '1') o++;
			else if(s[i] == '0') z++;
			else q++;
		} else if(s[i] == '?') ++x;
	}

	if(s[0] == '?') {
		if(z == o && cout << z + ((x & 1) ? (q + 1) / 2 : q / 2) << endl) return;
		else if(z < o) swap(z, o);
		cout << z + (q / 2) << endl;
	} else {
		if(s[0] == '0') swap(o, z);
		cout << z + ((q + 1) / 2) << endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}