#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	int o = 0, z = 0;
	for(auto i: s) {
		if(i == '1') o++;
		else z++;
	}
	int fin = 0;

	cout << o << ' ' << z << ' ';

	for(int i = 1; i <= n; i++) {
		int pp = 0;
		if(n >= o && ((n - o) % 2) == 0) pp = 1;
		swap(o, z);
		if(n >= o && ((n - o) % 2) == 0) pp = 1;
		swap(o, z);
		fin += pp;
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}