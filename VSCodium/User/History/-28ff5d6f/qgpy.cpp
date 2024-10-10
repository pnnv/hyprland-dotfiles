#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n, k; cin >> n >> k;
	string a = "Alice", b = "Bob";
	if(n == 0 && cout << b << endl) return;
	if((k % 3 != 0 || k > n) && cout << (n % 3 == 0 ? b : a) << endl) return;
	n = (n % k == 0 ? k : n % (k + 1));
	cout << ((n == k || n % 3 != 0) ? a : b) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}