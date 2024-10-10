#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	int r = int(sqrt(n));
	if(r * r != n && cout << "No\n") return;
	
	int cnt = 1;
	vector <string> v;
	for(int i = 0; i < n; i+=r) {
		string tmp = "";
		for(int j = i; j < i + r; j++) tmp.push_back(s[i + j]);
		v.push_back(tmp);
	}

	for(auto i: v) cout << i << endl;

	// for(int i = 0; i < r; i++) {
	// 	for(int j = 0; j < r; j++) {
	// 		if(i == 0 || i == r - 1 || j == 0 || j == r - 1) {
	// 			if(v[i][j] == '0' && cout << "No\n") return;
	// 		} else {
	// 			if(v[i][j] == '1' && cout << "No\n") return;
	// 		}
	// 	}
	// }

	cout << "Yes\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}