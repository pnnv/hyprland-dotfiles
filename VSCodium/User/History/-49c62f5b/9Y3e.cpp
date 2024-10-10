#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n; cin >> n;
	string s; cin >> s;
	ll p = 1;
	vector <ll> v;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i - 1]) p++;
		else v.push_back(p), p = 1;
	}
	v.push_back(p);
	ll cnt = 0;
	for(auto i: v) cnt += max(0LL, i - 1);
	ll fin = cnt * (v.size() - 1);
	fin += ((v.size() - 1LL) * (v.size() - 2LL) / 2LL);

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}