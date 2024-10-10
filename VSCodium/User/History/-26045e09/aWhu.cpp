#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	bool pp = false;
	function <void (int, int)> f = [&](int x, int t) {
		if(pp) return;
		if(x > n) return;
		if(x == n && t == 1)  {
			pp = true;
			return;
		}
		f(x + 1, t ^ 1); f(x + 2, t ^ 1);
	}; f(0, 0);

	cout << (pp ? "BOB\n" : "ALICE\n");
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}