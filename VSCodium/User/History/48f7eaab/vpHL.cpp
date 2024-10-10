#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int x, y, k; cin >> x >> y >> k;
	cout  << (abs(x - y) <= k ? "Yes\n" : "No\n");
}