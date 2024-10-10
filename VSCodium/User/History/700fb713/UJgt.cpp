#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int a, b, x; cin >> a >> b >> x;
	int fin = 0;
	while(a * b < x * x) {
		if(a < b) swap(a, b);
		b++; fin++;
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}