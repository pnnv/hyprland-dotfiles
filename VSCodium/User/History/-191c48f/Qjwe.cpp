#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	bool z = false, o = false;
	for (int i = 0; i < n; i++) {
		if(s[i] != t[i])  {
			if(s[i] == '0') {
				if(!o && cout << "NO\n") return;
				z = true;
			} 
		} else {
			if(t[i] == '1') o = true;
			else z = true;
		}
	}
	cout << "YES\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}