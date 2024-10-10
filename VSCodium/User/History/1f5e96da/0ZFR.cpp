#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	string s; cin >> s;
	if(s.size() < 3 && cout << "NO\n") return;
	if(s[0] == '1' && s[1] == '0' && s[2] != '0' && s[2] != '1' && cout << "YES\n") return;
	cout << "NO\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}