#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	string s; cin >> s;
	string t = "";
	for(auto i: s) {
		if(t.empty() || t.back() != i) t.push_back(i);
	}
	int z = 0;
	for(auto i: t) {
		if(i == '0') z++;
	}

	if(z == 1) {
		cout << "Draw\n";
	} else if(z & 1) {
		cout << "Koga\n";
	} else {
		cout << "Janine\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}