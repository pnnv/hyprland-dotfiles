#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <int> t, nt;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x & 1) t.push_back(i);
		else nt.push_back(i);
	}

	
}