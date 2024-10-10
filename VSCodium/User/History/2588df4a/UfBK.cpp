#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	map <char, int> m;
	for(auto i: s) m[i]++;
	string ns = "";

	while(!m.empty()) {
		for(char c = 'a'; c <= 'z'; c++) {
			if(m[c] > 0) ns.push_back(c), m[c]--;
			else m.erase(c);
		}
	}

	cout << ns << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}