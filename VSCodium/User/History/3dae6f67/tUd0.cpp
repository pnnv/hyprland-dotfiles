#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	if(k * (k - 1) < n && cout << "NO\n") return;
	cout  << "YES\n";

	for (int i = 0; i < n; i++) 
		cout << (i % k) + 1 << ' ' << (i + 1 +  i / k) % k + 1 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}