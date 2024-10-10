#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	bool div = true;
	vector <int> tmp(n);
	for(auto &i: tmp) cin >> i;
	vector <int> v;
	for(auto i: tmp) {
		if(v.empty() && i == k) continue;
		else v.push_back(i);
	}
	while(!v.empty() && v.back() == k) v.pop_back();
	if(v.empty() && cout << 0 << endl) return;

	set <int> st;
	for(auto i: v) {
		st.insert(i);
		if(i % k != 0) div = false;
	}
	if((div || st.size() == 1 || k == 1) && cout << 1 << endl) return;
	cout << 2 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}