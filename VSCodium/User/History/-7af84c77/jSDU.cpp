#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(1 << n);

	for(auto &i: v) cin >> i;
	set <int> st;
	for(int i = 0; i < v.size() / 2; i++) 
		st.insert(v[i] ^ v[n - i - 1]);
	cout  << (st.size() == 1 ? "Yes\n" : "No\n");
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}