#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int a, b, x; cin >> a >> b >> x;
	int fin = 0;

	if(a * b <= x * x) cout << 0 << endl;
	else if(min(a, b) <= x) cout << 1 << endl;
	else cout << 2 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}