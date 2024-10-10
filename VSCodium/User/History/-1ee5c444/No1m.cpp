#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m; cin >> n >> m;
	set <vector <int>> st;
	int mx = 0;

	for (;n--;) {
		vector <int> p(m), cur, ind(n);
		iota(ind.begin(), ind.end(), 1);
		for(auto &i: p) {
			cin >> i; cur.push_back(i);
			st.insert(cur);
		}
		sort(ind.begin(), ind.end(), [&](int a, int b) { return p[a] < p[b]; });
		vector <int> chk;
		for (int i = 0; i < n; i++) {
			chk.push_back(ind[i]);
			if(st.find(chk) != st.end())  mx = max(mx, i + 1);
		}
 	}

	cout << mx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}