#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int x, y, n; cin >> n >> x >> y;
	string s; cin >> s;
	int a = 0, b = 0;
	int m = 0;

	for(auto i: s) {
		if(i == 'L') a--;
		else if(i == 'R') a++;
		else if(i == 'U') b++;
		else b--;
		m++;
		if((abs(a - x) + abs(b - y) == m) && cout << "Yes\n") return;
	}

	cout << "No\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}