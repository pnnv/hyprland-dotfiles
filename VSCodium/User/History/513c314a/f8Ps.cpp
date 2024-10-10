#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	int f = -1, l = -1;
	for (int i = 0; i < n; i++) {
		if(v[i] > 0) {
			f = i; break;
		}
	}

	for(int i = n - 1; i >= 0; i--) {
		if(v[i] > 0) {
			l = i; break;
		}
	}

	if((l == -1 || f == -1) && cout  << 0 << endl) return;

	int cnt = 0;
	for(int i = f; i <= l; i++)
		if(v[i] < 0) cnt++;
	
	cout  << cnt << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}