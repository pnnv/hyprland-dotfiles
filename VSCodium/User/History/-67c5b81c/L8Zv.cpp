#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	bool zero = true;
	vector <int> v(n);
	set <int> st;
	for(auto &i: v) {
		cin >> i;
		st.insert(i);
		if(i != k) zero = false;
	}
	if(zero && cout << 0 << endl) return;
	int pp = k;
	for(auto i: v) 
		pp = gcd<int32_t>(i, pp);
	if((pp == k || st.size() == 1) && cout << 1 << endl) return;
	cout << 2 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}