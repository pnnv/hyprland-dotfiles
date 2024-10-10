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
	sort(v.begin(), v.end(), greater <>());
	
	for(int i = 0; i < n - 1; i++) {
		t -= v[i];
		if(i + 2 < n - 1){
			t -= v[i + 1]; 
			op += t; i++;
		}
	}

	cout << op << endl;
}
