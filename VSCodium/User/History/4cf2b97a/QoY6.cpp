#include <bits/stdc++.h>
#include <numeric>
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

	vector <ll> prev(n, 1), cur(n);
	function <void (int, int)> dfs = [&](int p, int c) {
		int x = 0;
		for(auto i: t[c]) {
			if(i != p) {
				x += prev[i];
				dfs(c, i);
			}
		}
		cur[c] = x;
	};

	for(int j = 0; j < k; j++) 
		dfs(-1, 0), prev = cur;
	
	cout  << accumulate(prev.begin(), prev.end(), 0LL) << endl;
}