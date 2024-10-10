#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, a, b; cin >> n >> a >> b;
	map <int, int> m;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) m[v[i]] = i;


	vector <vector <int>> g(n);
	vector <int> deg(n);

	for (int i = 0; i < n; i++) {
		if(m.count(a - v[i])) g[i].push_back(m[a - v[i]]), deg[m[a - v[i]]]++;
		if(m.count(b - v[i])) g[i].push_back(m[b - v[i]]), deg[m[b - v[i]]]++;
	}

	for(auto i: g) {
		for(auto ii: i) cout << ii << ' ';
		cout << endl;
	}
	vector <int> id(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), 
		[&](int x, int y) { return deg[x] < deg[y]; });

	vector <int> c(n), vis(n, -1);


 
	for(auto i: id) {
		if(vis[i] != -1) continue;
		vis[i] = 0;
		int sz = 1;
		queue <int> q; q.push(i);
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			for(auto j: g[cur]) {
				if(vis[j] == -1) {
					sz++;
					q.push(j);
					vis[j] = (vis[cur] ^ 1);
					if(vis[j] == 1) {
						if(v[cur] + v[j] == a) {
							c[cur] = 0; c[j] = 0;
						} else {
							c[cur] = 1; c[j] = 1;
						}``
					}
				}
			}
		}

		if((sz & 1) && cout << "NO\n") return 0;
	}

	for(auto i: c) cout << i << ' ';
	cout << endl;
}