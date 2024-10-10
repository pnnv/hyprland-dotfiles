#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		if(n == 1) {
			cout << 1 << endl;
			continue;
		}

		vector <ll> a = {1, 2, 1};
		ll ptr = 1;

		for(int i = 0; i < (n - 3) / 2; i++) {
			if(a[ptr] == 1) {
				a.push_back(2LL);
				a.push_back(1LL);
			} else {
				a.push_back(a[ptr] << 1LL);
				a.push_back(1LL);
			}
			ptr++;
		}

		for(int i = 0; i < a.size(); i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}