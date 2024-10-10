#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	if(n == 1 && cout << 'x' << endl) return; 
	string ans = "";
	ans += string(n / 2, 'x');
	ans += ((n & 1) ? "yz" : "y");
	if((n / 2) != 0) ans += string(n / 2 - 1, 'x');

	cout << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}