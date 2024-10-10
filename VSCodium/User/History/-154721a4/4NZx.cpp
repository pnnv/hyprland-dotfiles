#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;


int maxEnvelopes(vector<vector<int>>& e) {
	int n = e.size(); 
    if(n == 1) return 1;
	vector <int> iw(n);
	iota(iw.begin(), iw.end(), 0); 
	auto ih = iw;

	sort(iw.begin(), iw.end(), [&](int a, int b) { 
		if(e[a][0] != e[b][0]) return e[a][0] < e[b][0];
		else return e[a][1] < e[b][1];
	 });
	sort(ih.begin(), ih.end(), [&](int a, int b) { 
		if(e[a][1] != e[b][1]) return e[a][1] < e[b][1];
		else return e[a][0] < e[b][0];
	});
	vector <int> dp(n, 1);
	auto fst  =[&](int l) {
		int lo = 0, hi = n;
		while(lo < hi) {
			int mid = lo + ((hi - lo) >> 1);
			if(e[ih[mid]][1] >= l) hi = mid;
			else lo = mid + 1;
		} return lo;
	};
	auto lst = [&](int l) {
		int lo = -1, hi = n - 1;
		while(lo < hi) {
			int mid = lo + ((hi - lo + 1) >> 1);
			if(e[ih[mid]][1] <= l) lo = mid;
			else hi = mid - 1;
		} return lo;
 	};
	auto pp = [&](int w, int h) {
		int lo = fst(h), hi = lst(h) + 1;
        int tmp = hi;
		while(lo < hi) {
			int mid = lo + ((hi - lo) >> 1);
			if(e[ih[mid]][0] > w) hi = mid;
			else lo = mid + 1;
		}
        return (lo != tmp ? ih[lo] : -1);
	};
	int mx = 1;

	oset <int> hs; hs.insert(e[iw.back()][1]);
	for(int i = n - 1; i >= 0; i--) {
		int ord = hs.order_of_key(e[iw[i]][1] + 1);
		if(!hs.empty() && ord != hs.size()) {
			int h = *hs.find_by_order(ord);
            int tt = pp(e[iw[i]][0], h);
			if(tt != -1) {
                dp[iw[i]] += dp[tt];
			    mx = max(mx, dp[iw[i]]);
            }
        }
        if(i > 0 && e[iw[i - 1]][0] != e[iw[i]][0]) {
            int p = i;
            while(p < n && e[iw[p]][0] == e[iw[i]][0])
                hs.insert(e[iw[p++]][1]);
        }
	}
	return mx;
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