#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, q; cin >> n >> q;
	string a, b; cin >> a >> b;
	vector <vector <int>> pa(26, vector <int> (n + 1));
	auto pb = pa;

	for (int i = 0; i < n; i++) {
		pa[int(a[i] - 'a')][i + 1]++; pb[int(b[i] - 'a')][i + 1]++;
	}
	for(int i = 0; i < 26; i++) {
		for(int j = 1; j <= n; j++) {
			pa[i][j] += pa[i][j - 1];
			pb[i][j] += pb[i][j - 1];
		}
	}

	for(;q--;) {
		int l, r, dif = 0; cin >> l >> r;
		for(int i = 0; i < 26; i++) 
			dif += abs((pa[i][r] - pa[i][l - 1]) - (pb[i][r] - pb[i][l - 1]));
		cout << (dif >> 1) << endl;
	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}