#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, k; cin >> n >> k;	
	vector <pair <ll, ll>> vp(n);
	for(auto &[a, b]: vp) cin >> a >> b;

	ll pp = 1;
	for(int i = 0; i < k; i++) {
		sort(vp.begin() + i, vp.end(), [&](pair <int, int> a, pair <int, int> b) {
			if((a.first * pp + a.second) == (b.first * pp + b.second)) return a.first < b.first;
			else  return (a.first * pp + a.second) >= (b.first * pp + b.second);
		});
		pp = vp[i].first * pp + vp[i].second;
	}

	cout << pp << endl;
}