#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> a(n), b(n), l(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;
	
	stack <int> st; st.push(-1);
	for (int i = 0; i < n; i++) {
		while(st.top() != -1 && b[st.top()] <= b[i]) st.pop();
		l[i] = st.top(); st.push(i);
	}
	while(!st.empty()) st.pop();
	st.push(n);
	map <int, set <pair <int, int>>> m;

	for(int i = n - 1; i >= 0; i--) {
		if(b[i] > a[i] && cout << "NO\n") return;
		while(st.top() != n && b[st.top()] < b[i]) st.pop();
		if(b[i] != a[i]) m[b[i]].insert({l[i], st.top()});
		st.push(i);
	}
	cin >> n; map <int, int> x;
	for (int i = 0; i < n; i++) {
		int pp; cin >> pp; x[pp]++;
	}

	for(auto &[xx, req]: m) 
		if(req.size() > x[xx] && cout << "NO\n") return;
	cout << "YES\n"; 
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}