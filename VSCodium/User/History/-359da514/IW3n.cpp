#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m, q; cin >> n >> m >> q;
	vector <int> v(n), p(m);
	for(auto &i: v) cin >> i;
	for(auto &i: p) cin >> i;

	set <int> s;
	int i = 0;
	for(auto pp: p) {
		if(!s.count(pp)) {
			if(v[i] != pp) {
				cout << "TIDAK\n";
				return;
			}
			s.insert(v[i]);
			i++;
		} 
	}

	cout << "YA\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}