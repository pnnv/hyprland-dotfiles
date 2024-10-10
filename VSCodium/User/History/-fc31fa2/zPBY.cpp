#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	if(n == 1 && cout  << 1 << endl) return;

	vector <int> a = {1, 2, 1};
	int ptr = 1;

	for(int i = 0; i < n - 1; i++) {
		if(a[ptr] == 1) {
			a.push_back(2);
			a.push_back(1);
		} else {
			a.push_back(a[ptr] << 1);
			a.push_back(1);
		}
		ptr++;
	} 
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}