#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k; cin >> n >> k;
	vector <ll> v(n), st(n);
	iota(st.begin(), st.end(), 0);

	for(auto &i: v) cin >> i;
	for(int i = 1; i < n; i++) v[i] += v[i - 1];
	
	auto ps = [&](int l, int r) {
		return (v[r] - (l == 0 ? 0 : v[l - 1]));
	};

	vector <ll> dp(n);

	for(int i = k - 1; i < n; i++) {
		if(dp[i - 1] >= ps(i - k + 1, i)) 
			st[i] = st[i - 1], dp[i] = dp[i - 1];
		else
			dp[i] = ps(i - k + 1, i), st[i] = i - k + 1;
	}

	

	ll mx = 0;
	int a = -1, b = -1;

	for(int i = k; i <= n - k; i++)  {
		if(dp[i - 1] + ps(i, i + k - 1) > mx) {
			mx = dp[i - 1] + ps(i, i + k - 1);
			a = st[i - 1], b = i;
		}
	}

	cout <<  a + 1 << ' ' << b + 1 << endl;
}
