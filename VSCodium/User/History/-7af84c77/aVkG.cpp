#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(1 << n);

	for(auto &i: v) cin >> i;
	set <int> st;
	
	for(int c = 1; c <= n; c++) {
		for(int i = 0; i < (1 << (c - 1)); i++)
			if((v[i] ^ v[(1 << c) - i - 1]) != v[(1 << c) - 1] && cout << "NO\n") return;
	}

	cout << "YES\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}