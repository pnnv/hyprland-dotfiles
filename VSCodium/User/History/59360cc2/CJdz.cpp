#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	int n, x, k; cin >> n >> x >> k;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	
	oset <int> al, dup;
	for(auto i: v) {
		if(al.find(i) != al.end()) dup.insert(i);
		al.insert(i);
	}

	int fin = al.order_of_key(k * x);
	int c = al.order_of_key(x);
	int cur = c;

	for(auto i: al) {
		if(i >= x) break;
		int pp = dup.order_of_key(min(x, i * k)) - dup.order_of_key(i);
		if(i * k > x) pp += al.order_of_key(i * k) - al.order_of_key(x);
		cur = max(cur, c + pp);
	}

	cout << max(fin, cur) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}