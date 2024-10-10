#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector <vector <int>> t(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		t[--a].push_back(--b);
		t[b].push_back(a);
	}
	vector <int> v(n);
	for(int i = 0; i < k; i++) {
		int x; cin >> x;
		v[x - 1] = 1;
	}

	int rem = 0;

	function <int(int, int)> cnt = [&](int p, int c)  {
		int x = 0, sub = 0;
		for(auto i: t[c]) {
			if(i != p) {
				int cur = cnt(c, i);
				if(cur > 0) x++;
				sub += cur;
			}
		}

		if(x == 0 && cout << c + 1 << endl) rem++;
		else if(x == 1 && sub == k && cout << c + 1 << endl) rem++;

		return sub + v[c]; 
	}; cnt(-1, 0);

	cout << n - rem << endl;
}