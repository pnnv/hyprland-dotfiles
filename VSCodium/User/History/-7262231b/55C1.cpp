#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n , m; cin >> n >> m;
	vector <vector <pair <int, int>>> g(n);

	for(int i = 0; i < m; i++)  {
		int a, b; char c; cin >> a >> b >> c;
		g[a - 1].push_back({b - 1, int(c - 'a')});
	}

	vector <int> p(n);

	function <int(int, int)> f = [&](int cur, int l) {
		int mx = 0;
		for(auto &[v, w]: g[cur]) {
			if(w >= l) mx = max(mx, f(v, w));
		}
		return mx + 1;
	};
	for (int i = 0; i < n; i++) p[i] = f(i, -1);

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << ((p[i] <= p[j]) ? 'A' : 'B'); 
		}
		cout << endl;
	}
}