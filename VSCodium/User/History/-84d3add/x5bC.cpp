#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s, t; cin >> s >> t;
	vector <string> x;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] != t[i]) {
			s[i] = t[i];
			x.push_back(s);
		}
	}

	cout << x.size() << endl;
	for(auto i: x) cout  << i << endl;
}