#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m, k; cin >> n >> m >> k; n += 2;
	string s = "L"; 
	string t; cin >> t; s += t; s.push_back('L');
	bool c = false;
	int len = 0, lc = -1, lnd = -1;
	for(int j = 0; j < n; j++) {
		char i = s[j];
		if(i == 'L') {
			if(len == 0 || (len + 1) <= m) continue;
			if(c) {
				if(lc - lnd + 1 < m && cout << "NO\n") return;
				if(j - lc - 1 < k && cout  << "NO\n") return;
				else k -= max(j - lc - 1, 0);
			} else {
				cout  << "PENIS";
				if((len - m + 1) < k && cout << "NO\n") return;
				else k -= max(0, (len - m + 1));
			}
			len = 0; c = false; lnd = j;
		}  else {
			len++;
			if(i == 'C')  { c = true; lc = j; }
		}
	}
	cout << "YES\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}