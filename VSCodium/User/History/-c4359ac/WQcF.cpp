#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m, q; cin >> n >> m >> q;
	int a, b; cin >> a >> b;
	int x;  cin >> x;

	if(x > a && x > b && cout << n -  max(a, b) << endl) return;
	else if(x < a && x < b && cout << min(a, b) - 1 << endl) return;

	cout << abs(b - a) / 2 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}