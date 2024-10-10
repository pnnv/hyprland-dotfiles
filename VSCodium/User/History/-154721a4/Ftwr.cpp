#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;


int maxEnvelopes(vector<vector<int>>& e) {
	int n = e.size(); 
	vector <int> iw(n);
	iota(iw.begin(), iw.end(), 0); 
	auto ih = iw;

	sort(iw.begin(), iw.end(), [&](int a, int b) { return e[a][0] > e[b][0]; });
	sort(ih.begin(), ih.end(), [&](int a, int b) { return e[a][1] < e[b][1]; });    
	

}

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