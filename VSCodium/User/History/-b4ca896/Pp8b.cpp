#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	map <char, int> m;
	for (int i = 0; i <= (n << 1) ; i++) {
		string s; cin >> s;
		for(auto c: s) m[c]++;
	}
	string st;
	for(auto &[a, b]: m)
		if(b & 1) st.push_back(a);
	cout << st << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}