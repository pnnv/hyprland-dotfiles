#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	string s, t; cin >> s >> t;
	int p = 0;
	for(auto &i : s) {
		if(i == t[p] || i == '?') i = t[p++];
		if(p == t.size()) break;
	}
	for(auto &i: s) if(i == '?') i = 'x';
	cout << s << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}