#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m, k; cin >> n >> m >> k; n += 2;
	string s = "L"; 
	string t; cin >> t; s += t; s.push_back('L');
	bool c = false;
	int lc = -1, lnd = -1;
	int sw = 0;
	for(int j = 0; j < n; j++) {
		char i = s[j];
		if(i != 'L') {
			if(i == 'C'){ lc = j; c = true;}
		} else {
			if((j - lnd) <= m) {
				lnd = j; c = false; continue;
			}
			if(c) {
				if((lc + 1 - lnd) > m && cout << "NO\n") return;
				sw += (j - lc - 1);
			} else sw += (j - lnd - m);
			lnd = j; c = false;
		}
	}
	cout << ((sw <= k) ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}