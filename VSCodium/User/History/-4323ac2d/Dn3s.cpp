#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	ll fin = n;
	
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	
	vector <ll> d;
	for (int i = 0; i < n - 1; i++) d.push_back(v[i + 1] - v[i]); 

	ll cnt = 1;
	for(int i = 1; i < d.size(); i++) {
		if(d[i] == d[i - 1]) cnt++;
		else {
			fin += (cnt * (cnt + 1LL) / 2LL);
			cnt = 1;
		}
	}
	fin += (cnt * (cnt + 1LL) / 2LL);

	cout << fin << endl;
}