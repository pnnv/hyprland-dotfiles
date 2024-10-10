#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

void snu() {
	int n, q; cin >> n >> q;
	vector <vector <int>> g(3, vector <int> (n));
	
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		g[x - 1][i]++;
	}
	for(int i = 0; i < 3; i++) 
		for(int j = 1; j < n; j++)
			g[i][j] += g[i][j - 1];
	

	while(q--) {
		int l, r; cin >> l >> r; --l; --r;
		bool b = true;
		if((r - l) % 2 == 0 && cout << "No\n") continue;
		vector <int> pp(3);
		for(int i = 0; i < 3; i++) {
			pp[i] = g[i][r] - (l == 0 ? 0 : g[i][l - 1]);
		}

		if(*max_element(pp.begin(), pp.end()) != (r - l + 1) / 2) b = false;
		cout << (b ? "Yes\n" : "No\n");
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}