#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	if(n == 1 && s[0] == '1') {
		cout  << "Yes\n"; return;
	}
	for (int i = 0; i < n - 1; i++) {
		if(s[i] == s[i + 1] && s[i] == '1') {
			cout  << "Yes\n"; return;
		}
	}
	cout  << "No\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}