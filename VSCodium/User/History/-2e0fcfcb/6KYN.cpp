#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mxs(vector <ll> v) {
	ll score = 0;
	int n = v.size();
	vector <ll>  dif;
	for (int i = 0; i < n; i++) 
		score += (i + 1) * v[i];

	for(int i = 0; i < n - 1; i++) 
		dif.push_back(v[i] - v[i + 1]);

	vector <vector <ll>> dp(n, vector <ll> (2, -1));

	function <ll(int, int)> f = [&](int i, int x) {
		if(i >= n - 1) return 0LL;
		if(dp[i][x] != -1) return dp[i][x];

		ll cur = 0;
		if(x == 0) cur = max(f(i + 1, 0), dif[i] + f(i + 1, 1));
		else cur = f(i + 1, 0);

		return dp[i][x] = cur;
	};

	return score + f(0, 0);
}


long long ms(vector<long long> a) {
    long long s = 0;
    int n = a.size();
    vector<long long> d;

    for (int i = 0; i < n; i++) 
        s += (i + 1) * a[i];

    for (int i = 0; i < n - 1; i++) 
        d.push_back(a[i] - a[i + 1]);

    vector<vector<long long>> dp(n, vector<long long>(2, -1));

    function<long long(int, int)> f = [&](int i, int x) {
        if (i >= n - 1) return 0LL;
        if (dp[i][x] != -1) return dp[i][x];

        long long cur = 0;
        if (x == 0) cur = max(f(i + 1, 0), d[i] + f(i + 1, 1));
        else cur = f(i + 1, 0);

        return dp[i][x] = cur;
    };

    return s + f(0, 0);
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	cout << ms(v) << endl;
}