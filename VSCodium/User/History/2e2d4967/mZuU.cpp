#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
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
		return;
	} 
	n--;

	vector <vector <int>> e(26, vector <int> (n));
	auto o = e;
	for (int i = 0; i < n; i++) {
		if(i & 1) o[int(s[i] - 'a')][i]++;
		else e[int(s[i] - 'a')][i]++;
	}

	for(int i = 0; i < 26; i++) {
		for(int j = 1; j < n; j++) {
			e[i][j] += e[i][j - 1]; o[i][j] += o[i][j - 1];
		}
	}

	int mxe = 0, mxo = 0;
	for(int i = 0; i < 26; i++) {
		mxe = max(mxe, e[i][n - 1] - e[i][0]);
		mxo = max(mxo, o[i][n - 1] - o[i][0]);
	}
	int op = n - mxe - mxo;

	for (int i = 0; i < n; i++) {
		mxe = 0, mxo = 0;
		for(int j = 0; j < 26; j++) {
			mxe = max(mxe, e[j][i - 1] + o[j][n - 1] - e[j][i]);
			mxo = max(mxo, o[j][i - 1] + e[j][n - 1] - e[j][i]);
		}
		op = min(op, n - mxe - mxo);
	}

	cout << op + 1 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}