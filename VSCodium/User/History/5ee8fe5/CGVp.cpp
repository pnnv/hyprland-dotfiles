#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <int> t, nt;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x & 1) t.push_back(i);
		else nt.push_back(i);
	}

	vector <vector <int>> dp(t.size(), vector <int>(nt.size(), -1));

	function <int(int, int)> f = [&](int i, int j) {
		if(i >= t.size() || j >= nt.size()) return 0;
		if(dp[i][j] != -1) return dp[i][j];
		int cur  = abs(t[i] - nt[j]) + f(i + 1, j + 1);
		if(nt.size() - j - 1 > t.size() - i - 1) cur = min(cur, f(i, j + 1));
		return dp[i][j] = cur;
	};

	cout << f(0, 0) << endl;
}