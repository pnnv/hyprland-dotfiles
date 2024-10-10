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


	function <char (int, int, int, int)> gaem = [&](int cur, int i, int j, int l) {
		int v = (cur == 0 ? i : j);
		int mx = -1, mxv = -1;
		for(auto &[u, w]: g[v]) {
			if(w >= l && w > mx) {
				mx = w; mxv = u;
			}	
		}
		if(mx == -1) return (cur == 0 ? 'B' : 'A');
		return (cur == 0 ? gaem(1, mxv, j, mx) : gaem(0, i, mxv, mx));
	};

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			// cout << ((p[i] > p[j]) ? 'A' : 'B'); 
			cout << gaem(0, i, j, -1);
		}
		cout << endl;
	}
}