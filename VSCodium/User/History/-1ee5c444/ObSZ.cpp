#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m; cin >> n >> m;
	vector <vector <int>> v(n);
	set <vector <int>> st;
	vector <int> ind(m);
	iota(ind.begin(), ind.end(), 1);

	for (int _ = 0; _ < n; _++) {
		vector <int> p(m), cur;
		for(auto &i: p) cin >> i; 
		sort(ind.begin(), ind.end(), [&](int a, int b) { return p[a - 1] < p[b - 1]; });
		v[_] = p;
		for(auto i: ind) {
			cur.push_back(i); st.insert(cur);
		}
 	}

	for(auto p: v) {
		vector <int> pp;
		int mx = 0;
		for(int i = 0; i < m; i++) {
			pp.push_back(p[i]);
			if(st.count(pp)) mx = i + 1;
		}
		cout << mx << ' ';
	}
	cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}