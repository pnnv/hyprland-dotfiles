#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> pos, neg;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; s += abs(x);
		if(x < 0) neg.push_back(x);
		else pos.push_back(x);

	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	if(((neg.size() & 1) || neg.empty()) && cout  << s << endl) return;
	if(pos.empty()) cout << s + (2 * neg.back()) << endl;
	else cout << s - (2 * min(abs(neg.back()), pos.front())) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}