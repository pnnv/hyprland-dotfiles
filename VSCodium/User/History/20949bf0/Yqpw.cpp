#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i]; 
	vector <int> id(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&](int x, int y) {
		if(a[x] * b[x] != a[y] * b[y]) return a[x] * b[x] < a[y] * b[y];
		else return  (a[x] + b[x]) < (a[y] + b[y]);
	});

	auto calc = [&](int x, int y, int K) {
		int ops = 0;
		int r = 0, c = 0;
		for(int i = 0; i < K; i++) {
			if(x - c < y - r) {
				ops += (x - c);
				r++;
			} else {
				ops += (y - r);
				c++;
			}
		}
		return ops;
	};

	ll op = 0;
	int mn = INT_MAX;
	vector <int> rem;

	for(auto i: id) {
		if(a[i] + b[i] <= k) {
			k -= (a[i] + b[i]);
			op += a[i] * b[i];
		}
		else rem.push_back(i);
	}


	if(rem.empty() && k != 0) {
		cout  << -1 << endl;
		return;

	for(auto i: rem) mn = min(mn, calc(a[i], b[i], k));
	cout << op + (mn == INT_MAX ? 0) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}

}