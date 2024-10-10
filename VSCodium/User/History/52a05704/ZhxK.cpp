#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	multiset <ll> s;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i]; s.insert(i);
	}
	cout << "YES\n";
	vector <pair <int, int>> ans;
	for (int r = n - 1 ; r >= 1; r--) {
		map <int, int> m;
		for(auto i: s) {
			if(m.count(v[i] % r)) {
				ans.push_back({i + 1, m[v[i]] + 1});
				s.erase(i);
				break;
			} else m[v[i] % r] = i;
		}
	}
	reverse(ans.begin(), ans.end());
	for(auto &[a, b]: ans) cout << a << ' ' << b << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}