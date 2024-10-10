#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s, t; cin >> s >> t;
	vector <int> a, b;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] != t[i]) {
			if(s[i] < t[i]) b.push_back(i);
			else a.push_back(i);
		}
	}
	reverse(b.begin(), b.end());
	vector <string> x;

	for(int i = 0; i < a.size(); i++) {
		s[a[i]] = t[a[i]];
		x.push_back(s);
	}

	for(int i = 0; i < b.size(); i++) {
		s[b[i]] = t[b[i]];
		x.push_back(s);
	}


	cout << x.size() << endl;
	for(auto i: x) cout  << i << endl;
}