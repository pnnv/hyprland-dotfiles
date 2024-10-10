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

	ll fin = 0;
	if(!a.empty()) for(int i = 0; i < a.size() - 1; i++) fin += abs(a[i + 1] - a[i]);
	if(!b.empty()) for(int i = 0; i < b.size() - 1; i++) fin += abs(b[i + 1] - b[i]);

	cout << fin << endl;

}