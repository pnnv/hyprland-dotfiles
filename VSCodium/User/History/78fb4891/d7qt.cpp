#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<ll> dis(1e7, 1e13);

	int n, q; cin >> n >> q;
	map <int, ll> m;
	vector <int> a(1), b(1);
	vector <ll> az(1), bz(1);

	for (int i = 0; i < n; i++) {
		int x; cin >> x; a.push_back(x);
		if(!m.count(a[i + 1])) m[a[i + 1]] = dis(gen);
		az.push_back(m[a[i + 1]]);
	}

	for (int i = 0; i < n; i++) {
		int x; cin >> x; b.push_back(x);
		if(!m.count(b[i + 1])) m[b[i + 1]] = dis(gen);
		bz.push_back(m[b[i + 1]]);
	}

	for(int i = 1; i <= n; i++)
		az[i] += az[i - 1], bz[i] += bz[i - 1];
	for(auto i: az) cout << i << ' ';
	cout  << endl;
	for(auto i: bz) cout << i << ' ';
	cout  << endl;


	for(;q--;) {
		int l, r, L, R; cin >> l >> r >> L >> R;
		cout << ((az[r] - az[l - 1] == bz[R] - bz[L - 1]) ? "Yes\n" : "No\n");
	}
}