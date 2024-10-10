#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
    int n, m; cin >> n >> m;
	vector <vector <int>> g(n, vector <int> (m));
	for (int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) cin >> g[i][j];
	if(!((n + m) & 1) && cout << "NO\n") return;
	cout << "{ENIS}\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}
