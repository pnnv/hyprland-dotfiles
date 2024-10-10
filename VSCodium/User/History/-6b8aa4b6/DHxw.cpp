#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector <int> g(1e5 + 1, -1); g[1] = 0;

	function <int(int)> gen = [&](int k) {
		if(g[k] != -1) return g[k];
		set <int> st; st.insert(0);
		for(int i = 2; i * i <= k; i++) {
			if(k % i == 0) {
				st.insert(gen(k / i));
				st.insert(gen(i));
			}
		}
		int mex = 0;
		for(int i = 0; i <= st.size(); i++) {
			if(!st.count(i)) {
				mex = i;
				break;
			}
		} 
		return g[k] = mex;
	};
	int xx = 0;
	for (int i = 0; i < n; i++)  {
		int x; cin >> x;
		xx ^= gen(x);
	}
	cout << (xx == 0 ? "Bruno" : "Anna");
}