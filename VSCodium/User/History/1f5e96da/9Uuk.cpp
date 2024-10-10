#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	string s; cin >> s;
	if(s.size() < 3 && cout << "NO\n") return;
	if(s[0] == '1' && s[1] == '0') {
		if(s[2] >= '2') cout << "YES\n";
		else if(s[2] == '1') {
			if(s.size() > 3) cout << "YES\n";
			else cout << "NO\n";
		} else cout << "NO\n";
		return;
	}
	cout << "NO\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}