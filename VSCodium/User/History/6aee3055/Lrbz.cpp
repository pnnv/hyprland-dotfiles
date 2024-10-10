#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	vector <string> g(n);
	for (int i = 0; i < n; i++) cin >> g[i];
	for(int i = 0; i < n; i += k) {
		string pp;
		for(int j = 0; j < n; j += k) 
			pp.push_back((g[i][j] == '1' ? '1' : '0'));
		cout << pp << endl;
	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}