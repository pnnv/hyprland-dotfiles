#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;

vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> f;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int c = 0;
            while (n % i == 0) n /= i, c++;
            f.push_back({i, c});
        }
    }
    if (n > 1) f.push_back({n, 1});
    return f;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	map <ll, vector <int>> f;
	
	for(auto i: v) {
		auto fax = factor(i);
		for(auto &[a, b]: fax)
			f[a].push_back(b);
	}

	function <ll (ll)> g = [&](ll mask) {
		if(mask == 0) return 0ll;
		vector <int> mex;
		for(int i = 1; i < 30; i++) {
			ll nxt = ((mask >> i) | (mask & ((1 << i) - 1)));
			if(nxt != mask) mex.push_back(g(nxt));
		}
		sort(mex.begin(), mex.end());
		ll ex = 0;
		for(ll i = 0; i < mex.size(); i++) 
			if(mex[i] != i) 
				return 	i;
		return ll(mex.size());
	};

	ll nim = 0;

	for(auto &[a, b]: f) {
		ll mask = 0;
		for(auto i: b) mask |= (1 << i);
		nim ^= g(mask);
	}

	cout << (nim == 0 ? "Arpa\n" : "Mojtaba\n");
}