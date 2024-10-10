#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m; cin >> n >> m;
	vector <vector <int>> g(n, vector <int>(m));
	vector <int> v;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int x; cin >> x; v.push_back(x);
		}
	}
	if(n == 1 && m == 1 && cout << -1 << endl) return;

	cout << v[0] << ' ';
	reverse(v.begin(), v.end());
	v.pop_back();
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			if(i == 0 && j == 0) continue;
			cout << v.back() << ' ';
			v.pop_back();
		}
		cout  << endl;
	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}