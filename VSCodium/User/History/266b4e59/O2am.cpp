#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int l, r; cin >> l >> r;
	if(l == r && cout << "Invalid") return 0;
	cout << (l == 1 ? "Yes" : "No");
}