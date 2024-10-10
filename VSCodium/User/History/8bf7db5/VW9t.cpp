#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n; cin >> n;
	int ptr = (ll(log2l(n)));
	cout << ptr + 2 << endl;
	vector <int> pp;
	while(ptr >= 0) {
		if((n >> ptr) & 1) pp.push_back(ptr);
		ptr--;
	}
	for(auto i: pp) cout << (n ^ (1LL << i)) << ' ';
	cout << n << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}