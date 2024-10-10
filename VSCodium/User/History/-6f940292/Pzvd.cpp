#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, a, b; cin >> n >> a >> b;
	vector <ll> v(n);
	map <ll, int> m; 
	for (int i = 0; i < n; i++) {
		cin >> v[i]; m[v[i]] = i;
	}	
	vector <int> col(n, -1), vis(n, -1);

	for (int i = 0; i < n; i++) {
		if()
		if(m.count(a - v[i]))  
	}
}