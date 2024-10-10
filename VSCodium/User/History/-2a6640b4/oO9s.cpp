#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int a = 1, b = 100;
	while(a != b) {
		int c = abs(a - b);
		cout << c << endl;
		a = b; b = c;
	}
}