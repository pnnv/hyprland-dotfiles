#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void snu() {
	int n; cin >> n;
	vector <ll> v(n + 1);
	for (int i = 0; i < n; i++) cin >> v[i + 1];
	vector <ll> pre = v; v.push_back(0);
	for(int i = 1; i <= n; i++) pre[i] += pre[i - 1];
	oset <int> inv; inv.insert(0); inv.insert(n + 1);
	
	for(int i = 1; i <= n; i++)
		if(v[i] != v[i - 1]) inv.insert(i);
	
	auto lft = [&](int i) {
		if(v[i - 1] > v[i]) return 1;
		int lo = 0, hi = *inv.find_by_order(inv.order_of_key(i) - 1);
		if(hi == 0 || pre[i - 1] <= v[i]) return int(1e6);
		while(lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if(pre[i - 1] - pre[mid - 1] > v[i]) lo = mid;
			else hi = mid - 1;
		}
		return i - lo;
	};
	auto rt = [&](int i) {
		if(v[i + 1] > v[i]) return 1;
		int lo =  *inv.find_by_order(inv.order_of_key(i + 2)), hi = n + 1;
		if(lo == n + 1 || pre[n] - pre[i] <= v[i]) return int(1e6);
		while(lo < hi) {
			int mid = lo + (hi - lo)/ 2;
			if(pre[mid] - pre[i] > v[i]) hi = mid;
			else lo = mid + 1;
		}
		return lo - i;
	};

	cout  << *inv.find_by_order(inv.order_of_key(2) - 1);
	for (int i = 1; i <= n; i++) {
		// int pnus = min(lft(i), rt(i));
		// cout  << lft(i) << ' ' <<  rt(i) << endl;
		// cout << (pnus == int(1e6) ? -1 : pnus) << ' ';
	}
	cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}