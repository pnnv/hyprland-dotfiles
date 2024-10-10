#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <ll> l(n), r(n);
	ll sm = 0;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i]; sm += l[i];
	}
	if(sm > 0 && cout << "No\n") return 0;
	sm *= (-1LL);
	vector <ll> ans;
	for (int i = 0; i < n; i++) {
		if(r[i] - l[i] <= sm) {
			sm += (r[i] - l[i]);
			ans.push_back(r[i]);
		} else {
			ans.push_back(l[i] + sm);
			sm = 0;
		}
	}

	if(sm != 0 && cout << "No\n") return 0;
	cout << "Yes\n";
	for(auto i: ans) cout << i << ' '; cout << '\n';
}