#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	vector <int> p;
	int n; cin >> n;
	vector <int> a(n), id(n); vector <ll> c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; --a[i];
		id[a[i]]++;
	}
	for(auto &i: c) cin >> i;

	queue <int> q;
	for (int i = 0; i < n; i++) 
		if(id[i] == 0) q.push(i);

	while(!q.empty()) {
		id[a[q.front()]]--; p.push_back(q.front());
		if(id[a[q.front()]] == 0) q.push(a[q.front()]);
		q.pop();
	}
	vector <bool> vis(n);
	vector <vector <int>> cy; 
	
	for (int i = 0; i < n; i++) {
		if(!vis[i] && id[i] > 0) {
			int p = i;
			vector <int> cur;
			while(!vis[p]) {
				cur.push_back(p);
				vis[p] = true; p = a[p];
			}
			cy.push_back(cur);
		}
	}

	for(auto cc: cy) {
		for(auto i: cc) cout << i << ' ';
		cout  << endl;
	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}