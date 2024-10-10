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
	cout << "PENIS\n";
}