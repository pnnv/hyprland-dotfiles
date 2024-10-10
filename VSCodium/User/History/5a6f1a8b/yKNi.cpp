#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin  >> n;
	map <string, bool> m;
	auto q = [&](string &tt) {
		if(m.find(tt) != m.end()) return m[tt];
		cout << '?' << ' ' << tt << endl; cout.flush();
		int b; cin >> b; cout.flush();
		return m[tt] = (b == 1);
	};
	string t = "";
	while(1) {
		if(t.size() >= n) break;
		t.push_back('1');
		if(q(t)) continue;
		t.pop_back(); t.push_back('0');
		if(q(t)) continue;
		t.pop_back();
		break;
	}

	while(1) {
		if(t.size() >= n) break;
		string nt = "1"; nt += t;
		if(q(nt)) {
			t = nt;
			continue;
		} else if(nt.size() == n) {
			nt = "0"; nt += t;
			cout << '!' << ' ' << nt << endl;
			cout.flush(); return;
		}

		nt = "0"; nt += t;
		if(q(nt)) {
			t = nt;
			continue;
		}
		break;
	}

	cout << '!' << ' ' << t << endl;
	cout.flush();
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}