#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	map <string, int> m;
	string ans = "uh-oh";

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		m[s]++;
	}

	for(auto &[a, b]: m) {
		if(b > (n / 2)) {
			cout << a << endl;
			return 0;
		}
	}
	cout << ans << endl;
}