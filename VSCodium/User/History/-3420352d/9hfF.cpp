#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	string a = "", b = "";
	
	auto ck = [&]() {
		for(int i = 1; i < a.size(); i++) if(a[i] > a[i - 1]) return false;
		for(int i = 1; i < b.size(); i++) if(b[i] > b[i - 1]) return false;
		return true;
	};

	for(int i = -1; i <= 9; i++) {
		vector <int> pp(n);
		string sa = "", sb = "";
		for(int j = 0; j < n; j++) {
			if(int(s[j] - '0') < i) sa.push_back(s[j]), pp[j] = 1;
			else sb.push_back(s[j]), pp[j] = 2;
		}
		a = sa; b = sb;
		if(ck()) {
			for(auto x: pp) cout << x; cout << endl; 
			return;
		}
	}

	cout << '-' << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}