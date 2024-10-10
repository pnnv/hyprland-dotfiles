#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	vector <int> v(4);
	for(int i = 0; i < (4 * n); i++) {
		if(s[i] == 'A') v[0]++;
		else if(s[i] == 'B') v[1]++;
		else if(s[i] == 'C') v[2]++;
		else if(s[i] == 'D') v[3]++;
	}
	int mx = 0;
	for(auto i: v) {
		mx +=  min(i, n);
	} 

	cout << mx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}