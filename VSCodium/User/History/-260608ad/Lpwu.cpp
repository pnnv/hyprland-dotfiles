#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll n; cin >> n;
	vector <int> v(n);
	vector <int> f(4), l(4);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if(f[x] == 0) {
			f[x] = i + 1;
			l[x] = i + 1;
		} else l[x] = i + 1;
	}

	ll ans = n * (n + 1LL) / 2LL;

	for(int i = 1; i <= 3; i++)
		ans -= (f[i] * (n - l[i] + 1LL));

	for(int i = 1; i < 3; i++) {
		for(int j = i + 1; j <= 3; j++) {
			ans += (min(f[i], f[j]) * (n - max(l[i], l[j]) + 1LL));
		}
	}

	cout << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}