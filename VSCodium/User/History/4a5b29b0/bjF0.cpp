#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int x = 0;
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i, x ^= i;
	if(x != 0 && cout << -1 << endl) return  0;

	sort(v.begin(), v.end(), greater<>());
	v.push_back(0);
	
	unordered_map <int, int> f;
	vector <int> suf = v; 
	for(int i = n - 1; i >= 0; i--) suf[i] ^= suf[i + 1];
	
	auto fax = [&](int v) {
		f[v]++;
		for(int i = 2; i * i <= v; i++) {
			if(v % i == 0) {
				f[i]++;
				if(i * i != v) f[v / i]++;
			}
		}
	};
	

	for (int i = 0; i < n; i++) {
		if(v[i] != v[i + 1]) {
			int d = (i - f[v[i]]) & 1;
			if((d ^ min(suf[i + 1], 1)) && cout << v[i] - 1 << endl) return 0;
		}
		fax(v[i]);
	}

	cout << 0 << endl;
}