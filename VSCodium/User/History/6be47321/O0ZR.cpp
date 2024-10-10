#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	vector <int> bs, bt;
	for (int i = 1; i < n; i++) {
		if(s[i] != s[i - 1]) bs.push_back(i);
		if(t[i] != t[i - 1]) bt.push_back(i);
	}
	
	if((bs.size() != bt.size() || s.front() != t.front()) && cout << -1 << endl) return;

	ll op = 0;
	for(int i = 0; i < bs.size(); i++) op += abs(bs[i] - bt[i]);

	cout << op << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}