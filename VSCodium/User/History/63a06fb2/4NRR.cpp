#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> e, o;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if(i & 1) o.push_back(x);
		else e.push_back(x);
	}

	cout << max(*max_element(o.begin(), o.end()) + o.size(), 
	*max_element(e.begin(), e.end()) + e.size()) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}