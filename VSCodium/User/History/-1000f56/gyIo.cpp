#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m, k; cin >> n >> m >> k;
	string s = "L"; 
	string t; cin >> t; s += t; s.push_back('L');
	bool c = false;
	int len = 0;
	for(int j = 1; j < s.size(); j++) {
		char i = s[j];
		if(i == 'L') {
			len++;
			if(c) { if(len > m && cout << "NO\n") return; }
			else if((len - m) > k && cout  << "NO\n") return;
			len = 0; c = false;
		}  else {
			len++;
			if(i == 'C') c = true;
		}
	}
	cout << "YES\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}