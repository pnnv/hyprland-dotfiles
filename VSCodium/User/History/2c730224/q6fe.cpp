#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	vector <int> v(n);
	for(auto &i: v) cin >> i;

	vector <int> wl(k + 1, -1);
	wl[0] = 0;
	for(int i = 1; i <= k; i++) {
		int tt = 1;
		for(auto m: v) {
			if(m > i) break;
			tt &= wl[i - m];
		}
		wl[i] = (tt == 1 ? 0 : 1);
	}
	cout << (wl[k] == 1 ? "First" : "Second");
}