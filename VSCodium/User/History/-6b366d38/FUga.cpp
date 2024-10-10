#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector  <int> a, b;
	for(;n--;) {
		int x; char c; cin >> x >> c;
		if(c == 'R') b.push_back(x);
		else a.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	cout << (a.empty() ? 0 : a.back() - a.front()) + (b.empty() ? 0 : b.back() - b.front()) << endl;
}