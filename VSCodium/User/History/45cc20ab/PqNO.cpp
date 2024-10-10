#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	int op = 0;
	while(true) {
		sort(v.begin(), v.end(), greater<>());
		if(v[1] <= 0) break;
		--v[0]; --v[1];
		++op;
	}
	cout << op << endl;
}