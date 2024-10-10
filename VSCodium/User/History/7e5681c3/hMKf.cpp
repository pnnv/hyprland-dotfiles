#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	string pp = ""; pp.push_back(s[0]);
	int c = 1;
	for(auto i: s)
		if(i != pp.back()) pp.push_back(i);

	if(pp.size() == 1)  {
		if(s[0] == '1') cout  << 0 << endl;
		else if(n <= 2) cout << n << endl;
		else cout << 2 << endl;
		return;
	} else if(pp.size() & 1) cout << 0 << endl;
	else cout << 1 << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}