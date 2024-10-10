#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	vector <ll> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(),[&](int a, int b) { return v[a] > v[b]; });

	cout << ind[1] + 1 << endl;
}