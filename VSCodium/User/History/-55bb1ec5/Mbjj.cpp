#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	vector <vector <int>> dp(n, vector <int>(3, -1));

	function <int(int, int)> f = [&](int i, int c) {
		if(i >= n) return 0;
		if(dp[i][c] != -1) return dp[i][c];
		int cur;
		if(s[i] == 'R') {
			if(c == 0) cur = 1 + f(i + 1, 1);
			else if(c == 0) cur = f(i + 1, 0);
			else cur = max(1 + f(i + 1, 1), f(i + 1, 0));
		} else if(s[i] == 'P') {
			if(c == 1) cur = 1 + f(i + 1, 2);
			else if(c == 2) cur = f(i + 1, 1);
			else cur = max(1 + f(i + 1, 2), f(i + 1, 1));
		} else {
			if(c == 2) cur = 1 + f(i + 1, 0);
			else if(c == 0) cur = f(i + 1, 2);
			else cur = max(1 + f(i + 1, 0), f(i + 1, 2));
		}
		return dp[i][c] = cur;
	};

	cout << max({f(0, 0), f(0, 1), f(0, 2)});
}