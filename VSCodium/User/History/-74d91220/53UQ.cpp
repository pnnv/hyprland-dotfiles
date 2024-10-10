#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int a, b; cin >> a >> b;
	if(a == b) cout << 1 << endl;
	else cout << ((abs(a - b) & 1) ? 2 : 3) << endl;
}