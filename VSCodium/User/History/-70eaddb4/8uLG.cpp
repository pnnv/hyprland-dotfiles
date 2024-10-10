#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <int> v(n), p(n);
	for(auto &i: v) cin >> i;

	stack <int> st;

	for(int i = n - 1; i >= 0; i--) {
		p[i] = st.size();
		while(!st.empty() && st.top() < v[i]) st.pop();
		st.push(v[i]);
	}

	for(auto i: p) cout << i << ' '; cout << '\n';
}