#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	if(n % 2 == 0 && cout << -1  << endl) return;
	n /= 2;

	vector <int> f, b;
	for(int i = 1; i <= n; i++) {
		f.push_back((i << 1) + 1);
		b.push_back((i << 1));
	}

	reverse(f.begin(), f.end());
	for(auto i: f) cout << i << ' ';
	cout << 1 << ' ';
	for(auto i: b) cout << i << ' ';
	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}