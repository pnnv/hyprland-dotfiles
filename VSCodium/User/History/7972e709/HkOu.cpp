#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector <int> v(n + 1);

	for(int i = 0; i < m; i++) {
		int f; char g; cin >> f >> g;
		if(g == 'M' && v[f] == 0) {
			cout << "Yes\n";
			v[f]++; 
		} else cout << "No\n";
	}
}