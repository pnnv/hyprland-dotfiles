#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	vector <int> bs, bt;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n - 1; i++) {
		if(s[i] == s[i + 1]) c1++;
		else bs.push_back(c1), c1 = 1;

		if(t[i] == t[i + 1]) c2++;
		else bt.push_back(c2), c2 = 1;
	}
	bs.push_back(c1); bt.push_back(c2);
	
	if(bs.size() != bt.size() && cout << -1 << endl) return;

	int op = 0;
	for(int i = 0; i < bs.size(); i++) op += abs(bs[i] - bt[i]);

	cout << op << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}