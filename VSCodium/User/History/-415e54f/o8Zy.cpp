#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	if(n == 1 && s[0] == '1') {
		cout  << "Yes\n"; return;
	}
	int cnt = 0;
	for(auto  i: s) if(i == '1') cnt++;

	cout  << ((cnt > 1) ? "Yes\n": "No\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}