#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string l = "pp";
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if(s == "sweet" && l == "sweet") {
			cout << "No\n";
			return;
		}
		l = s;
	}
	cout << "Yes\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}