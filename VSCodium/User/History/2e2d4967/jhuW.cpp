#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	vector <vector <int>> f(26, vector <int> (n));
	if(!(n & 1)) {
		map <char, int> e, o;
		for (int i = 0; i < n; i++) {
			if(i & 1) o[s[i]]++;
			else e[s[i]]++;
		}
		int mxe = 0, mxo = 0;
		for(auto i: e) mxe = max(mxe, i.second); 
		for(auto i: o) mxo = max(mxo, i.second); 

		cout << n - (mxe + mxo) << endl;
	} else {
		cout << "PNUS\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}