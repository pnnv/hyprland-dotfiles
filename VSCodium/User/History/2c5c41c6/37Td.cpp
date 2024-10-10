#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, a, b; cin >> n >> a >> b;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	ll del = gcd<int64_t>(a, b);
	vector <ll> rem;
	for(auto i: v) 
		rem.push_back(i % del);
	
	sort(rem.begin(), rem.end());

	ll fin = rem.back() - rem.front();

	for (int i = 1; i < n; i++) 
		fin = min(fin, v[i - 1] + del - v[i]);
	
	cout  << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}