#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector <string> v(n);
	for(auto &i: v) cin >> i;

	for (int i = 0; i < n - 1; i++) {
		if((v[i] == v[i + 1]) && (v[i] == "sweet")) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}