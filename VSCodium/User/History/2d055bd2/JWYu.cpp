#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int a, b; cin >> a >> b;
	b %= 2;
	if(b != 0) a -= 2;
	if(a & 1) cout << "NO\n";
	else cout << "YES\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}