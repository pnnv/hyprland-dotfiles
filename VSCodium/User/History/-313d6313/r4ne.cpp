#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	string s; cin >> s;
	string ans = 0;
	bool p = false;
	for(int i = 0; i < s.size() - 1; i++) {
		if(p) {
			ans.push_back(s[i]);
			continue;
		}
		if(s[i] == s[i + 1]) {
			ans.push_back(s[i]);
			ans.push_back((s[i] == 'a' ? 'b' : 'a'));
			p = true;
		} else {
			ans.push_back(s[i]);
		}
	}
	ans.push_back(s.back());
	if(!p) ans.push_back((s.back() == 'a' ? 'b' : 'a'));
	cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}