#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	string s, t; cin >> s >> t;
	
	ll pp = 0, fin = 0, ptr = 2;
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == 'W') pp ^= (1LL << ptr);
		if(t[i] == 'W') fin ^= (1LL << ptr);
		ptr <<= 1LL;
	}

	if(__popcount(pp) != __popcount(fin) && cout << -1 << endl) return 0;
	cout << "penis ";
}