#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, q; cin >> n >> q;
	vector<int> v(n + 1);
	vector<vector<int>> f(1 << 18);

	for (int i = 0; i < n; i++) {
		cin >> v[i + 1];
		v[i + 1] ^= v[i];
		f[v[i + 1]].push_back(i + 1);
	}

	auto lower_bound_custom = [](const vector<int> &vec, int val) {
		int lo = 0, hi = vec.size();
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (vec[mid] >= val) hi = mid;
			else lo = mid + 1;
		}
		return lo;
	};

	for(;q--;) {
		int l, r; cin >> l >> r;
		if(v[l - 1] == v[r]) {
			cout << "YES\n";
			continue;
		}

		const auto &fv_r = f[v[r]];
		if(fv_r.empty() || fv_r.back() < l) {
			cout << "NO\n";
			continue;
		}

		int lb_index = lower_bound_custom(fv_r, l);
		if(lb_index == fv_r.size()) {
			cout << "NO\n";
			continue;
		}

		const auto &fv_lm1 = f[v[l - 1]];
		if(fv_lm1.empty() || fv_lm1.back() < fv_r[lb_index]) {
			cout << "NO\n";
			continue;
		}

		int llb_index = lower_bound_custom(fv_lm1, fv_r[lb_index]);
		cout << (fv_lm1[llb_index] < r ? "YES\n" : "NO\n");
	}

	cout << endl;
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}