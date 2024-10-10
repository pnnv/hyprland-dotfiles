#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, q; cin >> n >> q;
	vector <int> V(n);
	for(auto &i: V) cin >> i;

	for(int _ = 0; _ < q; _++) {
		int l, r, k; cin >> l >> r >> k;
		vector <int> v;
		for(int i = l - 1; i < r; i++)
			if(v.empty() || v.back() != V[i]) v.push_back(V[i]);
		
		int dif = 0;
		for(int i = 1; i < v.size(); i++) dif += abs(v[i] - v[i - 1]);

		cout  << (dif < k ? 0 : dif - k) << endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}