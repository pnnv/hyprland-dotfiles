#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	stack <ll> st; st.push(0);
	vector <ll> v(n + 1); v[0] = 1e9 + 1;
	for (int i = 0; i < n; i++) cin >> v[i + 1];
	vector <ll> fin(n + 1); fin[0] = 1;
	for(int i = 1; i <= n; i++) {
		while(v[st.top()] < v[i]) st.pop();
		fin[i] = fin[st.top()] + v[i] * (i - st.top());
		st.push(i);
	}

	for (int i = 0; i < n; i++) cout << fin[i + 1] << ' ';
}