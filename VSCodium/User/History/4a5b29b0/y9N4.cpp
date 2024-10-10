#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	n = (1 << 31);
	int fin = 0;

	for(int i = 0;  i <= 32; i++) {
		if(n & (1 << i)) {
			fin = (1 << (i + 1)) - 1 - fin;
		}
	}
	cout << fin << endl;
}