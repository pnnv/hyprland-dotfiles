#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <int> v(n), p(n);
	stack <int> st;

	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && st.top() > v[i]) st.pop();
		p[i] = st.size();
		st.push(v[i]);
	}

	for(auto i: p) cout << i << ' '; cout << '\n';
}