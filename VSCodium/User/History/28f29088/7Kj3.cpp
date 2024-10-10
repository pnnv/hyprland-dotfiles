#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, m; cin >> n >> m;
	vector <vector <int>> dp(n, vector <int> (5, -1));
	vector <string> st(n);
	for(auto &i: st) cin >> i;
	map <char, int> x; x['n'] = 0, x['a'] = 1, x['r'] = 2, x['e'] = 3, x['k'] = 4; 
	string s = "narek";

	function <int(int, int)> f = [&](int i, int l) {
		if(i >= n) return -2 * ((l + 1) % 5);
		if(dp[i][l] != -1) return dp[i][l];
		int cur = f(i + 1, l);

		int score = 0, p = l;
		for(auto c: st[i]) 
			if(x.count(c)) score--;
		for(auto c: st[i]) {
			if(c == s[p]) {
				p = (p + 1) % 5;
				score += 2; 
			}
		}
		cout << score << ' ';
		cur = max(cur, score + f(i + 1, p));
		return dp[i][l] = cur;
	};

	cout << f(0, 4) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}