#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n; cin >> n;
	int ptr = (ll(log2l(n)));
	cout << ptr + 1 << endl;
	while(ptr >= 0) {
		while(((n >> ptr) & 1) != 1) ptr--;
		cout  << (n ^ (1LL << ptr)) << ' ';
	}
	cout << n << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}