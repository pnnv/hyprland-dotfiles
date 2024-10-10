#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <int> v(n);
	for(auto &i: v) cin >> i;

	vector <int> fin(n);
	stack <int> st;
	
	for (int i = 0; i < n; i++) {
		int cur = 0;
		while(!st.empty() && v[st.top()] < v[i]) {
			cur = max(cur, fin[st.top()] + 1);
			st.pop();
		}
		fin[i] = (st.empty() ? -1 : cur);
		st.push(i);
	}
	cout << *max_element(fin.begin(), fin.end()) + 1 << endl;
}