#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <string> s(n);
	int mx = 0;
	for(auto &i: s) {
		cin >> i; mx = max(mx, int(i.size()));
	}
	vector <string> pp(mx);
	reverse(s.begin(), s.end());

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < s[i].size(); j++) {
			if(pp[j].size() < i) pp[j].push_back('*');
			pp[j].push_back(s[i][j]);
		}
	}

	for(auto i: pp) cout << i << endl;
}