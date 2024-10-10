#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	string t; t.push_back(s.front());
	int z = 0, o = 0;
	if(t.front() == '1') o++;
	else z++;
	for (int i = 1; i < n; i++) {
		if(s[i] == '1') {
			t.push_back('1'); o++;
		} else {
			if(t.back() == '1') {
				z++; t.push_back('0');
			}
		}
	}

	cout << ((o > z) ? "Yes\n" : "No\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}