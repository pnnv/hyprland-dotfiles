#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll tot = 0;
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
		id[a[q.front()]]--; tot += (2LL * c[q.front()]);
		if(id[a[q.front()]] == 0) q.push(a[q.front()]);
		q.pop();
	}
	vector <bool> vis(n);
	
	for (int i = 0; i < n; i++) {

	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}