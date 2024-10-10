#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	map <int, vector <int>> m;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		m[x].push_back(i + 1);
	}

	ll fin = 0;

	for(auto &[a, v]: m) {
		ll tmp = n * (n + 1LL) / 2LL;
		ll neg = ((v.front()) * (v.front() - 1LL)) / 2LL + (n + 1LL - v.back()) * (n - v.back()) / 2LL;
		for(int i = 0; i < v.size() - 1; i++) 
			neg += (v[i + 1] - v[i]) * (v[i + 1] - v[i] - 1LL) / 2LL;
		fin += (tmp - neg);
	}

	cout << fin << endl;
}