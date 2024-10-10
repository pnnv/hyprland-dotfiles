#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	map <char, int> m;
	for(auto i: s) m[i]++;
	sort(s.begin(), s.end(), [&](char a, char b) {
		if(m[a] != m[b]) return m[a] > m[b];
		else return a < b;
	});

	cout << s << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}