#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for(int j = 0; j < 4; j++) 
			if(s[j] == '#') v.push_back(j + 1);
	}

	reverse(v.begin(), v.end());
	for(auto i: v) cout << i << ' '; cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}