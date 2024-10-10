#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(1 << n);
	int x = 0, xx = 0; 
	for(int i = 0; i < (1 << n); i++) x ^= i;
	for(auto &i: v) cin >> i, xx ^= i;

	for(int i = 0; i < (1 << n); i++) {
		x ^= i; xx ^= v[i];
		if(v[x] != xx && cout << "NO\n") return;
	}

	cout << "YES\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}