#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll fin = 0;
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i, fin += i;

	vector <int> o(30), z(30);
	for(auto x: v) {
		for(int i = 0; i < 30; i++) {
			if((x >> i) & 1) o[i]++;
			else z[i]++;
		}
	}

	for(auto x: v) {
		ll cur = 0;
		for(int i = 0; i < 30; i++) 
			cur += (1 << i) * (((x >> i) & 1) ? z[i] : o[i]);
		fin = max(fin, cur);
	}
	
	cout << fin << endl; 
}