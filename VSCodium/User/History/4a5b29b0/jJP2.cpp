#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	int fin = 0;

	cout << bitset <10>(n) << endl;

	for(int i = 0;  i <= 32; i++) {
		if(n & (1LL << i)) {
			fin = (1LL << (i + 1)) - 1 - fin;
		}
	}
	cout << fin << endl;
}