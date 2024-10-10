#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector <vector <pair <int, int>>> g(n);
	for(int i = 0; i < m; i++) {
		int a, b; char c; cin >> a >> b >> c;
		g[a - 1].push_back({b - 1, int(c - 'a')});
	}

	// for(auto i: g) {
	// 	for(auto [u, v]: i) {
	// 		cout << u << ' ' << char('a' + v) << endl; 
	// 	}
	// 	cout << endl;
	// }

	vector <vector <vector <int>>> dp(n, vector <vector <int>> (n, vector <int> (26, -1)));

	function <int(int, int, int)> f = [&](int i, int j, int mn) {
		if(dp[i][j][mn] != -1) return dp[i][j][mn];
		
		set <int> tmp;
		for(auto &[v, w]: g[i]) {
			cout  << v  << ' ' << w <<  endl;
			if(w >= mn) tmp.insert(f(j, v, w));
		}
		int cur = -1;

		for(auto t: tmp) cout << t << ' ';
		cout << endl;

		for(int j = 0; j < tmp.size(); j++) {
			if(!tmp.count(j)) {
				cur = j; break;
			}
		}
		return dp[i][j][mn] = cur;
	};

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			// cout << (f(i, j, -1) == 0 ? 'B' : 'A');
			// cout << f(i, j, -1) << ' ';
			f(i, j, 0);
		}
		cout << endl;
	}
}
