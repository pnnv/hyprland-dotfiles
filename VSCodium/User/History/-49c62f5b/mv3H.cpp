#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	int p = 1;
	vector <int> v;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i - 1]) p++;
		else v.push_back(p), p = 1;
	}
	v.push_back(p);
	int cnt = 0;
	for(auto i: v) cnt += max(0, i - 1);
	int fin = cnt * (v.size() - 1);
	fin += ((v.size() - 1) * (v.size()) / 2);

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}