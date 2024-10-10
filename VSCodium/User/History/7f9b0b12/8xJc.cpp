#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector <ll> w(n);
	for(auto &i: w) cin >> i;

	auto c = [&](ll mn) {
		ll s = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if(s < mn)  s += w[i];
			else s = w[i], cnt++;
		}
		if(s < mn && cnt <= k - 1) return false;
		else cnt++;
		return cnt >= k; 
	};

	for(int i = 1; i <= 100; i++) {
		if(c(i)) cout << i  << endl;
	}

	ll lo = 0, hi = 1e9;
	while(lo < hi) {
		ll mid = lo + ((hi - lo + 1LL) / 2LL);
		if(c(lo)) lo = mid;
		else hi = mid - 1;
	}

	cout << lo << endl;
}

