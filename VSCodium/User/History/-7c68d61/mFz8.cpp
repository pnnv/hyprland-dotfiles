#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i;

	vector <int> o(30), z(30);
	for(auto x: v) {
		for(int i = 0; i < 30; i++) {
			if((x >> i) & 1) o[i]++;
			else z[i]++;
		}
	}

	ll fin = 0;
	for(auto x: v) 
		for(int i = 0; i < 30; i++) 
			fin += (1 << i) * (((x >> i) & 1) ? z[i] : o[i]);
	cout << fin << endl; 
}