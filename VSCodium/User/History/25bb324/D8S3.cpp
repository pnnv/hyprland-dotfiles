#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q; cin >> n >> q;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());

	int b;
	auto num = [&](int dist, int cur) {
		int lo = 0, hi = cur + 1;
		while(lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if(abs(b - v[mid]) <= dist) hi = mid;
			else lo = mid + 1;
		}
		int l = (cur - lo + 1);

		lo = cur, hi = n - 1;
		while(lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if(abs(b - v[mid]) <= dist) lo = mid;
			else hi = mid - 1; 
		}
		int r = (lo - cur);
		return (l + r);
	};

	auto bs = [&](ll b, int k) {
		int lo = -1, hi = n - 1;
		while(lo < hi) {
			int mid = lo  + (hi - lo + 1) / 2;
			if(v[mid] <= b) lo = mid;
			else hi = mid - 1;
		}
		int cur = lo;
		lo = 0, hi = max(abs(b - v[0]), abs(b - v[n - 1])) + 1;
		while(lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if(num(mid, cur) >= k) hi = mid;
			else lo = mid + 1;
		}
		return lo;
	};

	for(;q--;) {
		int k; cin >> b >> k;
		cout <<  bs(b, k) << endl;
	}
}