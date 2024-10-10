#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector <int> p(n);
		for(auto &i: p) cin >> i;

		int k; cin >> k;

		set <int> st;
		bool imp = false;

		for(auto i: p) {
			if(i < k) {
				cout << -1 << endl;
				imp = true;
				break;
			} else if(i > k) st.insert(i);
		}

		if(imp) cout << -1 << endl;
		else cout << st.size() << endl;
	}
}