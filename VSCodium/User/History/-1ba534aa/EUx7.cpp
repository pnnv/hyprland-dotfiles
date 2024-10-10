#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll fin = 0;
	ll n, m; cin >> n >> m;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;

	vector <ll> pre = v, suf = v;
	
	map <ll, ll> pp; pp[0]++;
	for(int i = 1; i < n; i++) pre[i] += pre[i - 1];
	for(int i = n - 2; i >= 0; i--) suf[i] += suf[i + 1];

	for(int i = 0; i < n; i++) 
		fin += pp[pre[i] % m], pp[pre[i] % m]++;
	
	pp.clear(); 
	
	for(int i = n - 1; i >= 0; i--) {
		fin += pp[(m - (pre[i] % m)) % m];
		if(i < n - 1) pp[suf[i + 1] % m]++;
	}

	cout  << fin << endl;
}