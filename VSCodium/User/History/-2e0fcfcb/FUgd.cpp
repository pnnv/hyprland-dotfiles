#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector <int> z(n), o(n);
	for (int i = 0; i < n; i++) {
		if(s[i] == '0') o[i]++;
		else z[i]++;
	}

	for(int i = 1; i < n; i++)
		o[i] += o[i - 1], z[i] += z[i - 1];

	for(int i = 0; i <= n - k; i++) {
		if(o[i + k - 1] - (i == 0 ? 0 : o[i - 1]) == o.back() && cout << )
	}
}