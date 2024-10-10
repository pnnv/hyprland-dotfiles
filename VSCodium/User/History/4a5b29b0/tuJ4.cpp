#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n = (1LL << 31);
	int fin = 0;

	cout << n << endl;

	for(int i = 0;  i <= 32; i++) {
		if(n & (1LL << i)) {
			fin = (1LL << (i + 1)) - 1 - fin;
		}
	}
	cout << fin << endl;
}