#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s; cin >> s;
	int l = 0, u = 0;
	for(auto i: s) {
		if(i < 'a') u++;
		else l++; 
	}

	if(u > l) {
		transform(s.begin(), s.end(), s.begin(), [&](char c) {
			return toupper(c);
		});
	} else {
		transform(s.begin(), s.end(), s.begin(), [&](char c) {
			return tolower(c);
		});
	}

	cout << s << endl;
}