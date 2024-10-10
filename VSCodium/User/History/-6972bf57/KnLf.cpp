#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll fin = 0;
	int n, m; ll k; cin >> n >> m >> k;
	vector <vector <ll>> a((n + 1) / 2, vector <ll> (m)), b((n / 2), vector <ll> (m));

	for(int i = 0; i < (n + 1) / 2; i++)
		for(int j =  0; j < m; j++) cin >> a[i][j];
	for(int i = 0; i < n / 2; i++)
		for(int j =  0; j < m; j++) cin >> b[i][j];

	reverse(b.begin(), b.end());
	for(auto &v: b)
		reverse(v.begin(), v.end());
		
	vector <vector <ll>> prev(m), cur(m), tp(m);

	auto gen = [&](vector <vector <ll>> g) {
		int t = g.size();
		cur[0].push_back(g[0][0]);
		for(int i = 0; i < t; i++) {
			for(int j = 0; j < m; j++) {
				vector <ll> tmp;
				if(i != 0) {
					for(auto x: prev[j])
						tmp.push_back(x ^ g[i][j]);
				}
				if(j != 0) {
					for(auto x: cur[j - 1])
						tmp.push_back(x ^ g[i][j]);
				}
				if(!tmp.empty()) cur[j] = tmp;
			}
			swap(prev, cur);
		}
	};
	gen(a);
	vector <map <ll, ll>> vm(m);

	for(int i = 0; i < m; i++) 
		for(auto x: cur[i])
			vm[i][x]++;

	if(n == 1 && cout << vm[m - 1][k] << endl) return 0;
	cur = tp;
	gen(b);
	for(int i = 0; i < m; i++) 
		for(auto x: cur[i]) 
			fin += vm[m - i - 1][x ^ k];

	cout << fin << endl;
}