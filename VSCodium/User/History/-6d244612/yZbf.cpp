#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, x; cin >> n >> x;
	vector <int> v(n);
	map <int, vector <ll>> rem;
	for(auto &i: v) {
		cin >> i;
		rem[i % x].push_back(i);
	}	

	for(auto &[a, b] : rem) 
		sort(b.begin(), b.end(), greater<>());
	
	for(int i = 0; i < n; i++) {
		if((!rem.count(i % x) || rem[i % x].empty()) && cout << i << endl) return;
		if(rem[i % x].back() > i && cout << i << endl)  return;
		rem[i % x].pop_back();
	}
	
	cout << n << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}