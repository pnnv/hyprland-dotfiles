#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, x, y; cin >> n >> x >> y;
	vector <int> v(n + 1);
	for(int i = y; i <= x; i++) v[i] = 1;
	for(int i = x + 1; i <= n; i++) {
		if(v[i - 1] == 1) v[i] = -1;
		else v[i] = 1; 
	}
	for(int i = y - 1; i >= 1; i--) {
		if(v[i + 1] == 1) v[i] = -1;
		else v[i] = 1; 
	}

	for (int i = 0; i < n; i++) cout << v[i + 1] << ' ';
	cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}