#include <bits/stdc++.h>
#include <climits>
#include <utility>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	int n, q; cin >> n >> q;
	vector <string> v(n);
	for(auto &i: v) {
		cin >> i;
		if(i[0] > i[1]) swap(i[0], i[1]);
	}
	map <string, int> pp;
	pp["BG"] = 0;  pp["BR"] = 1;  pp["BY"] = 2;  pp["GR"] = 3;  pp["GY"] = 4;  pp["RY"] = 5; 
	vector <oset <int>> xx(6);

	for (int i = 0; i < n; i++) 
		xx[pp[v[i]]].insert(i);

	auto lr = [&](int r, int id) {
		int p = xx[id].order_of_key(r);
		int L = -1, R = -1;
		if(!xx[id].empty()) R = *xx[id].find_by_order(p);
		if(p != 0) L = *xx[id].find_by_order(p - 1);
		return make_pair(L, R);
	};

	for(;q--;) {
		int a, b; cin >> a >> b; --a; --b;
		if(a > b) swap(a, b);
		if(v[a][0] != v[b][0] && v[a][1] != v[b][1] && v[a][1] != v[b][0] && v[a][0] != v[b][1]) {
			ll mn = INT_MAX;
			for(int i = 0; i < 6; i++) {
				if(pp[v[a]] == i || pp[v[b]] == i) continue;
				auto cur = lr(b, i);
				if(cur.first > a) mn = 0;
				else {
					if(cur.first != -1) mn = min(int(mn), a - cur.first);
					if(cur.second != -1) mn = min(int(mn), cur.second - b);
				}
			}
			if(mn == INT_MAX) cout << -1 << endl;
			else cout << b - a + mn << endl;
		} else cout << b - a << endl;
	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}