#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		if(a[i] > b[i]) swap(a[i], b[i]);
	} 
	vector <int> id(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&](int x, int y) {
		if(a[x] * b[x] != a[y] * b[y]) return a[x] * b[x] < a[y] * b[y];
		else return  (a[x] + b[x]) > (a[y] + b[y]);
	});

	auto calc = [&](int x, int y) {
		int ops = 0;
		int r = 0, c = 0;
		for(int i = 0; i < k; i++) {
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
	for(auto i: id) {
		if(a[i] + b[i] <= k) {
			k -= (a[i] + b[i]);
			op += a[i] * b[i];
		}
		else {
			cout << op + calc(a[i], b[i]) << endl;
			return;
		}
	}
	cout << (k == 0 ? op : -1) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}