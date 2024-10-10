#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <vector>
using namespace std;
typedef long long ll;

struct HashedString {
    vector<ll> hash, power;
    ll base = 31, mod = 1e9 + 7;

    HashedString(const string &s) {
        int n = s.size();
        hash.resize(n + 1, 0);
        power.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * base + s[i]) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
    }

    ll getHash(int l, int r) {
        return (hash[r + 1] - hash[l] * power[r - l + 1] % mod + mod) % mod;
    }
	ll getFullHash() {
        return hash.back();  // Hash of the full string
    }
};


void snu() {
	int n, m; cin >> n >> m;
	vector <vector <int>> dp(n, vector <int> (5, -1));
	vector <string> st(n);
	for(auto &i: st) cin >> i;
	set <char> x({'n', 'a', 'r', 'e', 'k'}); 
	string s = "narek";

	function <int(int, int)> f = [&](int i, int l) {
		if(i >= n) return -2 * l;
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

		cur = max(cur, score + f(i + 1, p));
		return dp[i][l] = cur;
	};

	cout << f(0, 0) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	HashedString pp("");
	cout << pp.getFullHash() << endl;
}