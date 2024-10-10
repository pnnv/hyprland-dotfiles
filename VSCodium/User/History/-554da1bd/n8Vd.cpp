#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class K>
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int h, w, q; cin >> h >> w >> q;

	vector <oset <int>> row(h), col(w);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++)
			row[i].insert(j);
	}
	for(int i = 0; i < w; i++) {
		for(int j = 0; j < w; j++)	
			col[j].insert(j);
	}

	for(auto st: row) {
		for(auto i: st) cout << i << ' ';
		cout << endl;
	}
		cout << endl;
	for(auto st: col) {
		for(auto i: st) cout << i << ' ';
		cout  << endl;
	}

	int rem = h * w;

	while(q--) {
		int a, b; cin >> a >> b; --a; --b;
		if(row[a].find(b) != row[a].end() && col[b].find(a) != col[b].end()) {
			row[a].erase(b); col[b].erase(a); rem--;
			continue;
		}

		auto r = row[a].order_of_key(b);
		if(r != row[a].size()) {
			int nxt = *row[a].find_by_order(r);
			col[nxt].erase(a); row[a].erase(nxt);
			rem--;
		}
		if(r != 0) {
			int pr = *row[a].find_by_order(r - 1);
			col[pr].erase(a); row[a].erase(pr);
			rem--;
		}

		r = col[b].order_of_key(a);

		if(r != col[b].size()) {
			int nxt = *col[b].find_by_order(r);
			row[nxt].erase(b); col[b].erase(nxt);
			rem--;
		}
		if(r != 0) {
			int pr = *col[b].find_by_order(r - 1);
			row[pr].erase(b); col[b].erase(pr);
			rem--;
		}
	}

	cout << rem;	
}