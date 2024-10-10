#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {

	ll op = 0;
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) {
		cin >> i; op += i;
	}
	ll t = op;
	cout << t << ' ';
	sort(v.begin(), v.end(), greater <>());
	
	for(int i = 0; i < n; i++) {
		t -= v[i];
		if(i < n - 1) t -= v[i - 1];
		op += t; i += 2;
	}

	cout << op << endl;
}
